#include <bits/stdc++.h>
using namespace std;
const int N = 1005;
const int MOD = 1000 * 1000 * 1000 + 7;
int n, m, C[N][N], f[N];
long long s[N];
map<long long, int> M;
inline void add(int& x, int y) { x = x + y >= MOD ? x + y - MOD : x + y; }
int main() {
  int i, j;
  scanf("%d%d", &m, &n);
  for (i = 0; i < n; ++i) {
    long long t;
    for (j = 0; j < m; ++j) scanf("%1d", &t), s[j] |= t << i;
  }
  for (i = 0; i < m; ++i) ++M[s[i]];
  for (C[0][0] = i = 1; i <= m; ++i) {
    for (C[i][0] = j = 1; j <= i; ++j) {
      C[i][j] = (C[i - 1][j - 1] + C[i - 1][j]) % MOD;
    }
  }
  for (f[0] = i = 1; i <= m; ++i) {
    for (j = 0; j < i; ++j) {
      add(f[i], 1LL * f[j] * C[i - 1][j] % MOD);
    }
  }
  int ans = 1;
  for (auto it : M) {
    ans = 1LL * ans * f[it.second] % MOD;
  }
  printf("%d", ans);
  return 0;
}
