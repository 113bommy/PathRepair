#include <bits/stdc++.h>
using namespace std;
const int N = 1005, mod = 1e9 + 7;
int C[N << 1][N << 1];
int memo[N][N][55];
int ncr(int n, int r) {
  if (r > n || r < 0 || n < 0) return 0;
  int &res = C[n][r];
  if (~res) return res;
  if (n == r || r == 0)
    res = 1;
  else
    res = (ncr(n - 1, r) + ncr(n - 1, r - 1)) % mod;
  return res;
}
int solve(int l, int v, int k) {
  if (l < 0 || k < 0) return 0;
  if (v == 0) {
    if (l == 0 && k == 0) return 1;
    return 0;
  }
  int &res = memo[l][v][k];
  if (~res) return res;
  res = solve(l, v - 1, k);
  res = (res + solve(l - v, v - 1, k - 1)) % mod;
  return res;
}
int fact[55];
int main() {
  memset(memo, -1, sizeof memo);
  memset(C, -1, sizeof C);
  fact[0] = fact[1] = 1;
  for (int i = 2; i < 51; ++i) {
    fact[i] = (1ll * i * fact[i - 1]) % mod;
  }
  int tc;
  scanf("%d", &tc);
  while (tc--) {
    int n, k;
    scanf("%d %d", &n, &k);
    if (k > 50) {
      puts("0");
      continue;
    }
    int ans = 0;
    for (int i = 1; i <= n; ++i) {
      int v = ncr(k + (n - i), k);
      v = (1ll * v * solve(i, 1000, k)) % mod;
      ans = (ans + v) % mod;
    }
    ans = (1ll * ans * fact[k]) % mod;
    printf("%d\n", ans);
  }
}
