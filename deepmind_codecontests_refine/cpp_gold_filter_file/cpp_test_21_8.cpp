#include <bits/stdc++.h>
using namespace std;
void _io() {
  std::ios::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
}
const int MAXN = 105;
int N, K, M, P, c[MAXN][MAXN], f[MAXN][MAXN][MAXN], fac[MAXN];
int dfs(int i, int j, int k) {
  if (i > 20 && abs(i - j) <= i * 2 / 5) {
    return 0;
  } else if (i == 0) {
    return (j == 0);
  } else if (j == 0 && i < k) {
    return fac[i];
  } else if (i < k) {
    return 0;
  } else if (k == 1) {
    if (j == 1) {
      return fac[i];
    } else {
      return 0;
    }
  } else {
    if (~f[i][j][k]) return f[i][j][k];
    int res = 0;
    for (int p = 0; p <= i - 1; p++) {
      for (int q = 0; q <= min(p, j); q++) {
        int tmp = dfs(p, q, k - 1) * 1ll * dfs(i - p - 1, j - q, k - 1) % P *
                  c[i - 1][p] % P;
        res = (res + tmp) % P;
      }
    }
    f[i][j][k] = res;
    return f[i][j][k];
  }
}
int main() {
  _io();
  memset(f, -1, sizeof f);
  cin >> N >> K >> M >> P;
  for (int i = c[0][0] = 1; i <= N; i++) {
    c[i][0] = c[i][i] = 1;
    for (int j = 1; j < i; j++)
      c[i][j] = (c[i - 1][j - 1] + 0ll + c[i - 1][j]) % P;
  }
  fac[0] = 1;
  for (int i = 1; i < MAXN; i++) fac[i] = fac[i - 1] * 1ll * i % P;
  cout << dfs(N, M, K);
  return 0;
}
