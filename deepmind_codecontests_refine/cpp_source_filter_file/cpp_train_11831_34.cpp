#include <bits/stdc++.h>
using namespace std;
bool isvowel(char ch) {
  if (ch == 'a' || ch == 'e' || ch == 'i' || ch == 'o' || ch == 'u') return 1;
  return 0;
}
int main() {
  string s;
  cin >> s;
  int ctr = 0;
  for (int i = 0; i < s.length(); i++) {
    if (isvowel(s[i])) ctr++;
    if (s[i] >= '0' && s[i] <= '9' && (s[i] - '0') % 2 == 0) ctr++;
  }
  cout << ctr;
  return 0;
}
