#include <bits/stdc++.h>
using namespace std;
int main() {
  int a = 0, b = 0;
  string s;
  char ch;
  cin >> s;
  for (int i = 0; i < s.length(); i++) {
    if (isupper(s[i]))
      a++;
    else
      b++;
  }
  for (int i = 0; i < s.length(); i++) {
    ch = s[i];
    if (a <= b) {
      ch = tolower(ch);
    } else
      ch = toupper(ch);
    cout << ch;
  }
  return 0;
}
