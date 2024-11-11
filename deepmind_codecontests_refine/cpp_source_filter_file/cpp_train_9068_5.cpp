#include <bits/stdc++.h>
using namespace std;
const long double eps = 1e-5;
const long double PI = acos(-1);
const int INF = (int)1e9;
const long long INFF = (long long)1e18;
const int mod = (int)1e9 + 7;
const int MXN = (int)1e6 + 7;
long long a[MXN], x[MXN], y[MXN];
long long b[MXN], per[MXN];
const bool cmp(const int &u, const int &v) { return x[u] > x[v]; }
pair<long long, long long> buf[MXN];
long long dp[MXN];
int main(void) {
  int n;
  scanf("%d", &n);
  for (int i = 1; i < n + 1; ++i) {
    scanf("%lld %lld %lld", x + i, y + i, a + i);
    b[i] = x[i] * y[i] - a[i];
  }
  for (int i = 1; i < n + 1; ++i) per[i] = i;
  sort(per + 1, per + n + 1, cmp);
  long long ans = 0;
  int ll = 1, rr = 1;
  buf[1] = make_pair(b[per[1]], y[per[1]]);
  dp[per[1]] = b[per[1]];
  for (int i = 2; i < n + 1; ++i) {
    int id = per[i];
    while (ll + 1 <= rr) {
      int p1 = ll;
      int p2 = ll + 1;
      long long v1 = buf[p1].first + b[id] - buf[p1].second * x[id];
      long long v2 = buf[p2].first + b[id] - buf[p2].second * x[id];
      if (v2 > v1)
        ll++;
      else
        break;
    }
    dp[id] = buf[ll].first + (b[id] - buf[ll].second * x[id]);
    dp[id] = max(dp[id], b[id]);
    if (buf[rr].first >= dp[id]) continue;
    while (ll + 1 <= rr) {
      int p1 = rr;
      int p2 = rr - 1;
      if ((long double)(dp[id] - buf[p1].first) *
              (buf[p2].second - buf[p1].second) >=
          (long double)(buf[p2].first - buf[p1].first) *
              (y[id] - buf[p1].second))
        rr--;
      else
        break;
    }
    buf[++rr] = (make_pair(dp[id], y[id]));
  }
  for (int i = 1; i < n + 1; ++i) ans = max(ans, dp[i]);
  printf("%lld\n", ans);
  return 0;
}
