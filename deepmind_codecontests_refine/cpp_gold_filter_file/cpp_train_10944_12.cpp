#include <bits/stdc++.h>
using namespace std;
struct wf {
  long long s, t, d, w;
  bool operator<(const wf& a) const {
    if (w == a.w)
      return d < a.d;
    else
      return w < a.w;
  }
} a[100005];
long long n, m, dp[100005][220], to[100005], val[100005], cnt, ans, k;
priority_queue<wf> Q;
bool cmp(wf a, wf b) { return a.s < b.s; }
int main() {
  ans = 9999999999999999;
  to[0] = 1;
  scanf("%lld%lld%lld", &n, &m, &k);
  for (long long i = 1; i <= k; ++i)
    scanf("%lld%lld%lld%lld", &a[i].s, &a[i].t, &a[i].d, &a[i].w);
  sort(a + 1, a + k + 1, cmp);
  cnt = 1;
  for (long long i = 1; i <= n; ++i) {
    while (a[cnt].s <= i && cnt <= k) Q.push(a[cnt++]);
    if (!Q.empty()) {
      wf b = Q.top();
      if (i > b.t) {
        --i;
        Q.pop();
        continue;
      }
      val[i] = b.w;
      to[i] = b.d + 1;
    } else
      to[i] = i + 1;
  }
  ans = 9999999999999999;
  memset(dp, 0x3f, sizeof(dp));
  dp[0][0] = 0;
  for (long long i = 0; i <= n; ++i)
    for (long long j = 0; j <= m; ++j) {
      dp[to[i]][j] = min(dp[to[i]][j], dp[i][j] + val[i]);
      dp[i + 1][j + 1] = min(dp[i + 1][j + 1], dp[i][j]);
    }
  for (long long i = 0; i <= m; ++i) ans = min(ans, dp[n + 1][i]);
  printf("%lld", ans);
  return 0;
}
