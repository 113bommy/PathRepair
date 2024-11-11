#include <bits/stdc++.h>
using namespace std;
const long long mod = 1000000007;
long long powmod(long long a, long long b) {
  long long res = 1;
  a %= mod;
  for (; b; b >>= 1) {
    if (b & 1) res = res * a % mod;
    a = a * a % mod;
  }
  return res;
}
const long long e6 = 1000000;
struct task {
  long long ss, sl, pr;
  int ts, tl;
} t[1010];
bool cmp(const task &a, const task &b) {
  return a.tl * a.pr * (e6 - b.pr) < b.tl * b.pr * (e6 - b.pr);
}
int n, T, ss, sl;
double pr;
pair<long long, double> dp[1010][1600];
inline void upd(int i, int j, pair<long long, double> c) {
  if (j <= T) dp[i][j] = min(dp[i][j], c);
}
int main() {
  scanf("%d%d", &n, &T);
  for (int i = 0; i < n; i++) {
    scanf("%d%d%d%d%lf", &ss, &sl, &t[i].ts, &t[i].tl, &pr);
    t[i].ss = ss * e6;
    t[i].pr = pr * e6 + 0.1;
    t[i].sl = sl * (e6 - t[i].pr);
  }
  sort(t, t + n, cmp);
  for (int i = 0; i < n; i++)
    for (int j = 0; j < T + 1; j++) {
      upd(i + 1, j, dp[i][j]);
      upd(i + 1, j + t[i].ts,
          make_pair(dp[i][j].first - t[i].ss, dp[i][j].second + t[i].ts));
      upd(i + 1, j + t[i].ts + t[i].tl,
          make_pair(dp[i][j].first - t[i].ss - t[i].sl,
                    (j + t[i].tl) * (1 - 1e-6 * t[i].pr) +
                        1e-6 * t[i].pr * dp[i][j].second + t[i].ts));
    }
  pair<long long, double> ret = make_pair(0, 0);
  for (int j = 0; j < T + 1; j++) ret = min(ret, dp[n][j]);
  printf("%.10f %.10f\n", -1e-6 * ret.first, ret.second);
}
