#include <bits/stdc++.h>
int main() {
  std::string input;
  int count, output = 0;
  char previous;
  std::cin >> count;
  std::cin >> input;
  previous = input[0];
  for (int i = 1; i < count; i++) {
    if (input[i] == previous)
      output++;
    else
      previous = input[i];
  }
  std::cout << output;
  return 0;
}
