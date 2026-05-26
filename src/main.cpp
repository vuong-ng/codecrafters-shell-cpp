#include <iostream>
#include <string>

int main() {
  // Flush after every std::cout / std:cerr
  std::cout << std::unitbuf;
  std::cerr << std::unitbuf;
  while (true){
    std::cout << "$ ";
    std::string input;
    std::getline(std::cin, input);
    std::string command = input.substr(0, 4);

    // find the first space -> command name
    size_t first_space_index = input.find(" ");
    command = input.substr(0, first_space_index);

    // process command name
    if (command == "exit")
    {
      return 0;
    }
    else if (command == "echo"){
      std::string text = (first_space_index != std::string::npos) ? input.substr(first_space_index+1) : "";
      if (text.length()) {
        printf("%s", text.c_str());
      }
      printf("\n");
    }
    else {
      std::cout << command << ": command not found \n";
    }
  }
}
