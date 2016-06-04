#include <halley/support/exception.h>
#include "halley/tools/cli_tool.h"
#include "halley/tools/codegen/codegen_tool.h"
#include "halley/tools/distance_field/distance_field_tool.h"
#include "halley/tools/make_font/make_font_tool.h"

using namespace Halley;

Vector<std::string> CommandLineTool::getToolNames()
{
	return {"codegen", "distField", "makeFont"};
}

std::unique_ptr<CommandLineTool> CommandLineTool::getTool(std::string name)
{
	if (name == "codegen") {
		return std::make_unique<CodegenTool>();
	} else if (name == "distField") {
		return std::make_unique<DistanceFieldTool>();
	} else if (name == "makeFont") {
		return std::make_unique<MakeFontTool>();
	} else {
		throw Exception("Unknown tool name");
	}
}

int CommandLineTool::runRaw(int argc, char** argv)
{
	Vector<std::string> args(argc);
	for (int i = 0; i < argc; i++) {
		args[i] = argv[i];
	}
	return run(args);
}
