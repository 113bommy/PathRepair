#include <bits/stdc++.h>
using namespace std;
int main() {
  string s;
  getline(cin, s);
  char ch;
  for (int i = s.size() - 1; i >= 0; i--) {
    if ((s[i] >= 97 && s[i] <= 122) || (s[i] >= 67 && s[i] <= 92)) {
      ch = s[i];
      break;
    }
  }
  if (ch == 'y' || ch == 'Y' || ch == 'a' || ch == 'A' || ch == 'e' ||
      ch == 'E' || ch == 'I' || ch == 'i' || ch == 'o' || ch == 'O' ||
      ch == 'u' || ch == 'U')
    cout << "YES\n";
  else
    cout << "NO\n";
  return 0;
}
