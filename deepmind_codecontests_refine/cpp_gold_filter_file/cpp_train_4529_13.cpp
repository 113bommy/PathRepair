#include <bits/stdc++.h>
using namespace std;
const int maxn = 3e5 + 50;
const int inf = 0x3f3f3f3f;
const int MOD = 1e9 + 7;
long long a[maxn], dp[5005][5005];
int dis, n, k;
long long dfs(int id, int d1, int d2) {
  if (id > n) return 0;
  long long &res = dp[d1][d2];
  if (res >= 0) return res;
  res = 1e16;
  if (d2) res = min(res, dfs(id + dis + 1, d1, d2 - 1) + a[id + dis] - a[id]);
  if (d1) res = min(res, dfs(id + dis, d1 - 1, d2) + a[id + dis - 1] - a[id]);
  return res;
}
int main() {
  scanf("%d%d", &n, &k);
  for (int i = 1; i <= n; i++) scanf("%I64d", a + i);
  sort(a + 1, a + 1 + n);
  int d2 = n % k, d1 = k - d2;
  dis = n / k;
  memset(dp, -1, sizeof dp);
  printf("%I64d\n", dfs(1, d1, d2));
  return 0;
}
