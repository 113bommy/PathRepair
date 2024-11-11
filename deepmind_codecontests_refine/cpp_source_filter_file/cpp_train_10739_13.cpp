#include <bits/stdc++.h>
using namespace std;
const int inf = 0x3f3f3f3f;
const int maxn = 505;
const long long mod = 998244353;
long long dp[maxn][maxn];
int n, m;
int a[maxn], b[maxn], c[maxn][maxn];
long long solve(int l, int r) {
  if (l > r) return 1;
  if (dp[l][r] != -1) return dp[l][r];
  dp[l][r] = 0;
  int mid = b[c[l][r]];
  long long L = 0;
  for (int i = l; i <= mid; i++) {
    L += solve(l, i - 1) * solve(i, mid - 1) % mod;
    L %= mod;
  }
  for (int i = mid; i <= r; i++) {
    (dp[l][r] += L * solve(mid + 1, i) * solve(i + 1, r) % mod) %= mod;
  }
  return dp[l][r];
}
int main() {
  memset(dp, -1, sizeof dp);
  scanf("%d%d", &n, &m);
  for (int i = 1; i <= n; i++) {
    scanf("%d", a + i);
    b[a[i]] = i;
  }
  for (int i = 1; i <= n; i++) {
    int mn = a[i];
    for (int j = i; j <= n; j++) {
      if (mn > a[j]) mn = a[j];
      c[i][j] = mn;
    }
  }
  printf("%lld\n", solve(1, n));
  return 0;
}
