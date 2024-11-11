#include <bits/stdc++.h>
using namespace std;
int changes[507][507];
int mem[507][507];
string s;
int n;
int check(int l, int r) {
  int ret = 0;
  for (int i = l, j = r; i < j; i++, j--) {
    if (s[i] != s[j]) ret++;
  }
  return ret;
}
void toPal(int l, int r) {
  for (int i = l, j = r; i < j; i++, j--)
    if (s[i] != s[j]) s[j] = s[i];
}
int dp(int l, int k) {
  if (l == n) return 0;
  if (k == 1) return changes[l][n - 1];
  if (mem[l][k] != -1) {
    return mem[l][k];
  }
  int mn = 1e6;
  for (int r = l; r < n; r++) {
    mn = min(mn, changes[l][r] + dp(r + 1, k - 1));
  }
  return mem[l][k] = mn;
}
void build(int l, int k) {
  if (l == n) return;
  if (k == 1) {
    toPal(l, n - 1);
    for (int i = l; i <= n - 1; i++) cout << s[i];
    return;
  };
  int mn = 1e6;
  for (int r = l; r < n; r++) {
    mn = min(mn, changes[l][r] + dp(r + 1, k - 1));
    if (mn == dp(l, k)) {
      toPal(l, r);
      for (int i = l; i <= r; i++) cout << s[i];
      if (r < n - 1) cout << '+';
      build(r + 1, k - 1);
      return;
    }
  }
}
int main() {
  int k;
  cin >> s >> k;
  n = s.length();
  for (int i = 0; i < 501; i++) {
    for (int j = 0; j < 501; j++) mem[i][j] = -1;
  }
  for (int i = 0; i < s.length(); i++) {
    for (int j = i; j < s.length(); j++) {
      changes[i][j] = check(i, j);
    }
  }
  cout << dp(0, k) << endl;
  build(0, k);
}
