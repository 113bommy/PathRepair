#include <bits/stdc++.h>
using namespace std;
int main() {
  string s;
  cin >> s;
  if (s[0] > '5' && s[0] != '9') s[0] = (char)(9 - (s[0] - 48) + 48);
  for (int i = 1; i < s.length(); i++) {
    if (s[i] > '5') s[i] = (char)(9 - (s[i] - 48) + 48);
  }
  cout << s;
  return 0;
}
