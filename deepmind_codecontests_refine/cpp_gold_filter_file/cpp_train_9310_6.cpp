#include <bits/stdc++.h>
using namespace std;
int main() {
  char input[101] = {0};
  cin >> input;
  int len = strlen(input);
  bool isAtReplace = false;
  for (int i = 0; i < len; i++) {
    if (input[i] == 'a' && !isAtReplace && i + 1 < len - 1 && i != 0) {
      if (input[i + 1] == 't') {
        input[i] = '@';
        isAtReplace = true;
      }
    }
    if (input[i] == 'd' && i + 2 < len - 1 && i != 0) {
      if (input[i + 1] == 'o' && input[i + 2] == 't') {
        input[i] = '.';
      }
    }
  }
  for (int i = 0; i < len;) {
    cout << input[i];
    if (input[i] == '@')
      i += 2;
    else if (input[i] == '.')
      i += 3;
    else
      i++;
  }
  cout << endl;
}
