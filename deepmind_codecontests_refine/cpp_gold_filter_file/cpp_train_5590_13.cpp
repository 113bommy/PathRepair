#include <bits/stdc++.h>
using namespace std;
int main() {
  string s;
  cin >> s;
  int i;
  for (i = 0; i < s.length(); i++)
    if (s[i] == '.') break;
  if (s[i - 1] == '9') {
    cout << "GOTO Vasilisa.";
    return 0;
  }
  if (s[i + 1] >= '5') s[i - 1]++;
  for (int i = 0; s[i] != '.' && i < s.length(); i++) cout << s[i];
}
