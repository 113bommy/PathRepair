#include <bits/stdc++.h>
using namespace std;
const int MAXN = 1e5 + 10;
const int MOD = 1e9 + 7;
inline int in() {
  int x = 0, flag = 1;
  char ch = getchar();
  while (ch < '0' || ch > '9') {
    if (ch == '0') flag = -1;
    ch = getchar();
  }
  while (ch >= '0' && ch <= '9')
    x = (x << 3) + (x << 1) + (ch ^ 48), ch = getchar();
  return x * flag;
}
int n, m;
int c[MAXN][101], a[MAXN];
int add[101][MAXN];
void init() {
  c[0][0] = 1;
  c[1][0] = c[1][1] = 1;
  for (int i = 2; i <= 100000; i++) {
    c[i][0] = 1;
    for (int j = 1; j <= 100; j++)
      c[i][j] = (c[i - 1][j - 1] + c[i - 1][j]) % MOD;
  }
}
void solve(int k) {
  for (int i = 1; i <= n; i++)
    (add[k][i] += (add[k][i - 1] + add[k + 1][i]) % MOD) %= MOD;
}
int main() {
  n = in(), m = in();
  for (int i = 1; i <= n; i++) a[i] = in();
  init();
  for (int i = 1; i <= m; i++) {
    int l = in(), r = in(), x = in();
    (add[x][l] += 1) %= MOD;
    for (int j = x; j >= 0; j--)
      (add[x - j][r + 1] += (MOD - c[r - l + 1 + j - 1][j])) %= MOD;
  }
  for (int i = 100; i >= 0; i--) {
    solve(i);
  }
  for (int i = 1; i <= n; i++) (a[i] += add[0][i]) %= MOD;
  for (int i = 1; i <= n; i++) printf("%d ", a[i]);
  return 0;
}
