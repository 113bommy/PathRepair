#include <bits/stdc++.h>
using namespace std;
struct segment {
  long long l, r;
  segment() {}
  segment(long long l, long long r) : l(l), r(r) {}
} m[1000 + 1];
double pb[1000 + 1], dp[1000 + 1][1000 + 1];
vector<segment> s;
void gen_seg(vector<segment> &s, long long lim) {
  unsigned long long p = 1;
  while (p <= lim) {
    s.push_back(segment(p, 2 * p - 1));
    p *= 10;
  }
}
long long len_of_intersection(const segment &a, const segment &b) {
  long long l = max(a.l, b.l), r = min(a.r, b.r);
  return r - l >= 0 ? r - l + 1 : 0;
}
void count_pb(int n) {
  for (int i = 0; i < (int)s.size(); ++i)
    if (s[i].l > m[n].r)
      break;
    else
      pb[n] += (len_of_intersection(s[i], m[n]) + .0) / (m[n].r - m[n].l + 1);
}
int main() {
  int n;
  scanf("%d", &n);
  long long lim = 0;
  for (int i = 0; i < n; ++i) {
    scanf("%I64d%I64d", &m[i].l, &m[i].r);
    lim = max(lim, m[i].r);
  }
  double k;
  scanf("%lf", &k);
  gen_seg(s, lim);
  for (int i = 0; i < n; ++i) count_pb(i);
  dp[0][0] = 1;
  for (int i = 1; i <= n; ++i)
    for (int j = 0; j <= i; ++j)
      dp[i][j] = (j ? pb[i - 1] * dp[i - 1][j - 1] : 0) +
                 (1 - pb[i - 1]) * dp[i - 1][j];
  double ans = 0;
  for (int j = 1; j <= n; ++j)
    if ((j + .0) / n >= k / 100) ans += dp[n][j];
  printf("%.15lf", k == 0 ? 1 : ans);
  return 0;
}
