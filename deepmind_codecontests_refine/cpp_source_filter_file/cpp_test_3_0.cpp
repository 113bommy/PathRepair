#include <bits/stdc++.h>
using namespace std;
string s = "";
int n = 0, ans = 0;
void check(string t) {
  int res = 1;
  string s2 = s;
  if (s2[n - 1] == 'X') {
    for (int i = 0; i < n; i++)
      if (s2[i] == 'X') s2[i] = t[1];
  } else if (s2[n - 1] == '_')
    s2[n - 1] = t[1];
  else if (s2[n - 1] != t[1])
    return;
  if (s2[n - 2] == 'X') {
    for (int i = 0; i < n; i++)
      if (s2[i] == 'X') s2[i] = t[0];
  } else if (s2[n - 2] == '_')
    s2[n - 2] == t[0];
  else if (s2[n - 2] != t[0])
    return;
  for (int i = 0; i < n - 2; i++) {
    if (s2[i] == '_') {
      if (i == 0)
        res *= 9;
      else
        res *= 10;
    }
    if (s2[i] == 'X') {
      if (i == 0)
        res *= 9;
      else
        res *= 10;
      for (int j = 0; j < n; j++)
        if (s2[i] == 'X') s2[i] = '?';
    }
  }
  if (s2[0] == '0') return;
  ans += res;
}
int main() {
  cin >> s;
  n = s.length();
  if (s.length() == 1) {
    if (s == "0" || s == "_" || s == "X")
      cout << 1;
    else
      cout << 0;
    return 0;
  }
  check("25");
  check("50");
  check("75");
  check("00");
  cout << ans;
  return 0;
}
