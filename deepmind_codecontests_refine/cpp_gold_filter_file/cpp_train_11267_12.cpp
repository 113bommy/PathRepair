#include <bits/stdc++.h>
const double PI = 3.1415926535897932384626433;
const int KL = 1e5 + 10;
const long long MOD = 1e9 + 7;
using namespace std;
long long n, p, k, s[KL][7], pp[KL], pw[KL];
pair<long long, long long> a[KL];
long long dp[KL][(1 << 7)], vis[KL][(1 << 7)];
long long solve(int i, int mask) {
  if (pp[mask] == p && i - p >= k) {
    return 0;
  }
  if (i == n) return -1e17;
  if (vis[i][mask]) return dp[i][mask];
  vis[i][mask] = 1;
  long long ret = -1e17;
  if (i - pp[mask] < k)
    ret = max(ret, a[i].first + solve(i + 1, mask));
  else
    ret = max(ret, solve(i + 1, mask));
  for (int j = 0; j < p; j++) {
    if (!(mask & pw[j]))
      ret = max(ret, s[a[i].second][j] + solve(i + 1, (mask | pw[j])));
  }
  return dp[i][mask] = ret;
}
int main() {
  pw[0] = 1;
  for (int i = 1; i <= 7; i++) {
    pw[i] = 2 * pw[i - 1];
  }
  for (int j = 0; j <= pw[7]; j++) {
    int x = j;
    while (x != 0) {
      pp[j] += x % 2;
      x /= 2;
    }
  }
  scanf("%lld", &n);
  scanf("%lld", &p);
  scanf("%lld", &k);
  for (int i = 0; i < n; i++) {
    scanf("%lld", &a[i].first);
    a[i].second = i;
  }
  sort(a, a + n);
  reverse(a, a + n);
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < p; j++) scanf("%lld", &s[i][j]);
  }
  printf("%lld\n", solve(0, 0));
  return 0;
}
