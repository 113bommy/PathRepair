#include <bits/stdc++.h>
using namespace std;
void print(std::vector<int> decode) {
  for (int i = 0; i < decode.size(); i++) {
    std::cout << decode.at(i);
  }
}
int main() {
  string code;
  cin >> code;
  vector<int> decode;
  for (int i = 0; i < code.length(); i++) {
    if (code[i] == '.' && code[i + 1] == '.' ||
        code[i] == '.' && code[i + 1] == '-' ||
        code[i] == '.' && code[i + 1] != '.' ||
        code[i] == '.' && code[i + 1] != '-') {
      decode.push_back(0);
    } else if (code[i] == '-' && code[i + 1] == '.') {
      decode.push_back(1);
      i += 1;
    } else if (code[i] == '-' && code[i + 1] == '-') {
      decode.push_back(2);
      i += 1;
    }
  }
  print(decode);
}
