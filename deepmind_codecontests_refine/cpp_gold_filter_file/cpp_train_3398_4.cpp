#include <bits/stdc++.h>
using namespace std;
const long long INF = 1e18;
vector<long long> g[2];
int n, Size1, Size2;
long long a[20], k, b[20];
void dfs(int k, int x, int y, long long mul) {
  g[k].push_back(mul);
  for (int i = x; i <= y; i++)
    if (INF / b[i] >= mul) dfs(k, i, y, mul * b[i]);
}
int check(long long mid) {
  long long sum = 0;
  for (int i = 0; i < Size1 && g[0][i] <= mid; i++) {
    long long tmp = mid / g[0][i];
    int p = upper_bound(g[1].begin(), g[1].end(), tmp) - g[1].begin() - 1;
    sum += p + 1;
  }
  return sum >= k;
}
int main() {
  while (~scanf("%d", &n)) {
    for (int i = 1; i <= n; i++) scanf("%lld", &a[i]);
    scanf("%lld", &k);
    for (int i = 0; i < 2; i++) g[i].clear();
    int cnt = 1;
    for (int i = 1; i <= n; i++)
      if (i & 1) b[cnt++] = a[i];
    dfs(0, 1, cnt - 1, 1);
    cnt = 1;
    for (int i = 1; i <= n; i++)
      if (i % 2 == 0) b[cnt++] = a[i];
    dfs(1, 1, cnt - 1, 1);
    for (int i = 0; i < 2; i++) sort(g[i].begin(), g[i].end());
    Size1 = g[0].size();
    Size2 = g[1].size();
    long long l = 1, r = INF, ans;
    while (l <= r) {
      long long mid = (l + r) >> 1;
      if (check(mid)) {
        ans = mid;
        r = mid - 1;
      } else
        l = mid + 1;
    }
    printf("%lld\n", ans);
  }
  return 0;
}
