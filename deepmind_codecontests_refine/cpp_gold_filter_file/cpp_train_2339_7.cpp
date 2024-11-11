#include <bits/stdc++.h>
using namespace std;
int main() {
  string str[] = {"rock", "paper", "scissors"};
  int input[3];
  for (int i = 0; i < 3; i++) {
    string a;
    cin >> a;
    for (int j = 0; j < 3; j++)
      if (a == str[j]) input[i] = j;
  }
  if ((input[0] == 0 && input[1] == 2 && input[2] == 2) ||
      (input[0] == 1 && input[1] == 0 && input[2] == 0) ||
      (input[0] == 2 && input[1] == 1 && input[2] == 1)) {
    cout << "F\n";
    return 0;
  }
  if ((input[1] == 0 && input[0] == 2 && input[2] == 2) ||
      (input[1] == 1 && input[0] == 0 && input[2] == 0) ||
      (input[1] == 2 && input[0] == 1 && input[2] == 1)) {
    cout << "M\n";
    return 0;
  }
  if ((input[2] == 0 && input[1] == 2 && input[0] == 2) ||
      (input[2] == 1 && input[1] == 0 && input[0] == 0) ||
      (input[2] == 2 && input[1] == 1 && input[0] == 1)) {
    cout << "S\n";
    return 0;
  }
  cout << "?\n";
  return 0;
}
