#include <bits/stdc++.h>
using namespace std;
const int maxn = 500000 + 50;
const double eps = 1e-10;
const int mod = 1e9 + 7;
long long gcd(long long a, long long b) {
  return a % b == 0 ? b : gcd(b, a % b);
}
long long lcm(long long a, long long b) { return (a * (b / gcd(a, b))); }
int n, m, k, q;
int x[maxn], y[maxn], t[maxn];
int use[1000][1000];
int dp[1000][1000];
bool check(int now) {
  memset(use, 0, sizeof(use));
  for (int i = 0; i < q; i++) {
    if (t[i] <= now) {
      use[x[i]][y[i]] = 1;
    }
  }
  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= m; j++) {
      if (use[i][j]) {
        dp[i][j] = min(dp[i - 1][j], min(dp[i][j - 1], dp[i - 1][j - 1])) + 1;
        if (dp[i][j] >= k) return true;
      } else
        dp[i][j] = 0;
    }
  }
  return false;
}
int main() {
  memset(dp, 0, sizeof(0));
  scanf("%d %d %d %d", &n, &m, &k, &q);
  int maxx = 0;
  for (int i = 0; i < q; i++) {
    scanf("%d %d %d", &x[i], &y[i], &t[i]);
    maxx = max(maxx, t[i]);
  }
  int l = 0, r = maxx + 10;
  int mid, ans = 0;
  while (l < r) {
    mid = (l + r) / 2;
    if (check(mid)) {
      ans = mid;
      r = mid;
    } else
      l = mid + 1;
  }
  if (ans == 0)
    printf("-1\n");
  else
    printf("%d\n", ans);
  return 0;
}
