#include <bits/stdc++.h>
using namespace std;
const int N = 1e5 + 7, M = 18;
const int MOD = 1e9 + 7;
int n, m, k, t;
pair<long long, int> a[N];
long long p[N];
int ans[N];
long long sum(int l, int r) { return p[r] - p[l - 1]; }
bool check(int r, int mn, long long money) {
  int j =
      lower_bound(a + 1, a + n + 1 - r, pair<long long, int>(mn, -1)) - a - 1;
  return 1LL * mn * j <= money + sum(1, j);
}
pair<long long, int> solve(int num, long long money) {
  long long tmp = money + sum(n - num + 1, n) - 1LL * m * num;
  if (tmp < 0) return pair<long long, int>(-1, -1);
  int l = a[1].first, r = m, mid, ans = a[1].first;
  while (l <= r) {
    mid = (l + r) / 2;
    if (check(num, mid, tmp))
      l = mid + 1, ans = mid;
    else
      r = mid - 1;
  }
  return pair<long long, int>(num * k + 1LL * ans * t, ans);
}
signed main() {
  long long c, bans = 0;
  int num = -1, mn = -1;
  p[0] = 0;
  scanf("%d%d%d%d%lld", &n, &m, &k, &t, &c);
  for (int i = 1; i <= n; i++) {
    scanf("%d", &a[i].first);
    a[i].second = i;
  }
  sort(a + 1, a + n + 1);
  for (int i = 1; i <= n; i++) p[i] = p[i - 1] + a[i].first;
  for (int i = 0; i <= n; i++) {
    pair<long long, int> res = solve(i, c);
    if (res.first > bans) bans = res.first, num = i, mn = res.second;
  }
  for (int i = 1; i <= n; i++)
    if (i + num > n)
      ans[a[i].second] = m;
    else
      ans[a[i].second] = max(int(a[i].first), mn);
  printf("%lld\n", bans);
  for (int i = 1; i <= n; i++) printf("%d ", ans[i]);
  return 0;
}
