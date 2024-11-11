#include <bits/stdc++.h>
using namespace std;
int n, m;
char s[103][103];
bool checkVer() {
  int l = m / 3;
  if (s[1][1] == s[1][1 + l] || s[1][1] == s[1][1 + l + l] ||
      s[1][1 + l] == s[1][1 + l + l])
    return false;
  for (int j = 1; j <= m; ++j) {
    char c = s[1][j];
    for (int i = 0; i < l; ++i)
      for (int k = 1; k <= n; ++k)
        if (s[k][j + i] != c) return false;
  }
  return true;
}
bool checkHor() {
  int l = n / 3;
  if (s[1][1] == s[1 + l][1] || s[1][1] == s[1 + l + l][1] ||
      s[1 + l][1] == s[1 + l + l][1])
    return false;
  for (int i = 1; i <= n; i += l) {
    char c = s[i][1];
    for (int j = 0; j < l; ++j)
      for (int k = 1; k <= m; ++k)
        if (s[i + j][k] != c) return false;
  }
  return true;
}
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  cin >> n >> m;
  for (int i = 1; i <= n; ++i)
    for (int j = 1; j <= m; ++j) cin >> s[i][j];
  bool res = false;
  if (n % 3 == 0 && checkHor()) res = true;
  if (m % 3 == 0 && checkVer()) res = true;
  cout << (res ? "YES" : "NO");
}
