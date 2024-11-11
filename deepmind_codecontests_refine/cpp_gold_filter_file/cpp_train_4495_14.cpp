#include <bits/stdc++.h>
using namespace std;
int main() {
  basic_string<char> input, comp = "aAeEiIoOuUyY";
  char *output;
  cin >> input;
  output = (char *)malloc(sizeof(input) + 1);
  int flag = 1;
  int count = 0;
  for (basic_string<char>::size_type i = 0; i < input.size(); ++i) {
    flag = 1;
    if ((input[i] >= 'a' && input[i] <= 'z') ||
        (input[i] >= 'A' && input[i] <= 'Z')) {
      for (basic_string<char>::size_type j = 0; j < comp.size(); ++j) {
        if (input[i] == comp[j]) {
          flag = 0;
          break;
        }
      }
    }
    if (flag == 1) {
      output[count++] = '.';
      output[count++] = tolower(input[i]);
    }
  }
  output[count] = '\0';
  cout << output << endl;
  return 0;
}
