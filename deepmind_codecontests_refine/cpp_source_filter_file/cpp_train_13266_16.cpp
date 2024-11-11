#include <bits/stdc++.h>
using namespace std;
struct point {
  int k, x, set;
} f[100];
bool operator<(const point &a, const point &b) { return a.k < b.k; }
const long long inf = 2e18;
int n, m, num, x;
long long dp[2][1 << 20], b;
bool p;
int maxn;
int main() {
  scanf("%d%d%I64d", &n, &m, &b);
  int sum = 0;
  for (int i = 0; i < n; i++) {
    scanf("%d%d%d", &f[i].x, &f[i].k, &num);
    f[i].set = 0;
    for (int j = 0; j < num; j++) {
      scanf("%d", &x);
      f[i].set |= 1 << (x - 1);
    }
    sum |= f[i].set;
  }
  maxn = 1 << m;
  if (sum != maxn - 1) {
    cout << -1;
    return 0;
  }
  p = 0;
  for (int i = 0; i < maxn; i++) dp[p][i] = inf;
  dp[p][0] = 0;
  long long ans = inf;
  sort(f, f + n);
  for (int i = 0; i < n; i++) {
    if (ans <= f[i].k * b) break;
    p = !p;
    for (int j = 0; j < maxn; j++) dp[p][j] = inf;
    for (int j = 0; j < maxn; j++)
      if (dp[p][j | f[i].set] > dp[!p][j] + f[i].x)
        dp[p][j | f[i].set] = dp[!p][j] + f[i].x;
    if (dp[p][maxn - 1] != inf && ans > dp[p][maxn - 1] + f[i].k * b)
      ans = dp[p][maxn - 1] + f[i].k * b;
  }
  cout << ans;
  return 0;
}
