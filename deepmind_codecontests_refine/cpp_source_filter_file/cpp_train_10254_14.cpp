#include <bits/stdc++.h>
using namespace std;
bool checkEquivalent(string &s1, string &s2, int i1, int i2, int l) {
  bool eq = true;
  for (int i = 0; i < l; i++) {
    if (s1[i1 + i] != s2[i2 + i]) eq = false;
  }
  if (eq) return true;
  if (((l >> 2) << 2) != l) return false;
  return (checkEquivalent(s1, s2, i1, i2, l / 2) &&
          checkEquivalent(s1, s2, i1 + l / 2, i2 + l / 2, l / 2)) ||
         (checkEquivalent(s1, s2, i1 + l / 2, i2, l / 2) &&
          checkEquivalent(s1, s2, i1, i2 + l / 2, l / 2));
}
int main() {
  string s1, s2;
  cin >> s1 >> s2;
  cout << (checkEquivalent(s1, s2, 0, 0, s1.length()) ? "YES" : "NO");
  return 0;
}
