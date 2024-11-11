#include <bits/stdc++.h>
using namespace std;
int main() {
  string s;
  cin >> s;
  int index = 0;
  for (int i = 0; i < s.size(); i++) {
    if (s[i] == '.') {
      index = i;
      break;
    }
  }
  if (s[index - 1] - '0' != 9 && s[index + 1] - '0' < 5) {
    for (int i = 0; i < index; i++) cout << s[i];
  } else if (s[index - 1] - '0' != 9 && s[index + 1] - '0' > 5) {
    for (int i = 0; i < index - 1; i++) cout << s[i];
    cout << (s[index - 1] - '0') + 1;
  } else
    cout << "GOTO Vasilisa.";
  return 0;
}
