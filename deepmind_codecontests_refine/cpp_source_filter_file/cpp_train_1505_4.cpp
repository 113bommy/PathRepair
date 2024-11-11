#include <bits/stdc++.h>
using namespace std;
int i, j, k, m, n, u, v;
int mx1[1000010] = {}, mx2[1000010] = {};
int dp[1000010] = {}, fth[1000010] = {};
void read(int &s) {
  s = 0;
  char ch = getchar();
  while (ch < '0' || ch > '9') ch = getchar();
  while (ch >= '0' && ch <= '9') {
    s = (s << 3) + (s << 1) + ch - '0';
    ch = getchar();
  }
}
bool update(int x, int y) {
  if (mx2[y] > dp[x]) return 0;
  if (mx1[y] < dp[x]) {
    mx2[y] = mx1[y];
    mx1[y] = dp[x];
  } else if (mx2[y] < dp[x]) {
    mx2[y] = dp[x];
  }
  int upd = max(mx1[y], mx2[y] + 1);
  if (upd == dp[y]) return 0;
  dp[y] = upd;
  return 1;
}
int main() {
  read(n);
  dp[1] = 1;
  for (i = 2; i <= n; i++) {
    read(fth[i]);
    dp[i] = 1;
    for (j = i; fth[j] && update(j, fth[j]); j = fth[j])
      ;
    cout << mx1[1] << '\n';
  }
  return 0;
}
