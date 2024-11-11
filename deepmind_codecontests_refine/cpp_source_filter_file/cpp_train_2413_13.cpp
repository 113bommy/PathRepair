#include <bits/stdc++.h>
using namespace std;
const int MOD = 1e9 + 7;
const int INF = 1e9;
const int MAXN = 2e5 + 10;
const int MAXM = 2e5 + 10;
int n, m, k, q;
vector<int> p[MAXN];
int c[MAXN];
int lp[MAXN], rp[MAXN];
long long dp[MAXN][2];
long long cal(int y1, int y2, int mid) {
  return (long long)abs(y1 - mid) + (long long)abs(y2 - mid);
}
long long dis(int x1, int y1, int x2, int y2) {
  long long disx = abs(x1 - x2);
  long long disy = min(
      cal(y1, y2, lp[y1]),
      min(cal(y1, y2, rp[y1]), min(cal(y1, y2, lp[y2]), cal(y1, y2, rp[y2]))));
  return disx + disy;
}
int main() {
  ios::sync_with_stdio(false);
  cin.tie(0), cout.tie(0);
  scanf("%d%d%d%d", &n, &m, &k, &q);
  for (int i = 1, r, c; i <= k; i++) {
    scanf("%d%d", &r, &c);
    p[r].push_back(c);
  }
  for (int i = 1; i <= n; i++) sort(p[i].begin(), p[i].end());
  for (int i = 1; i <= q; i++) scanf("%d", &c[i]);
  sort(c + 1, c + 1 + q);
  c[0] = c[q + 1] = INF;
  for (int i = 1; i <= m; i++) {
    lp[i] = c[lower_bound(c + 1, c + 1 + q, i) - c - 1];
    rp[i] = c[lower_bound(c + 1, c + 1 + q, i) - c];
  }
  if (p[1].empty()) {
    dp[1][0] = dp[1][1] = 1;
    p[1].push_back(1);
  } else {
    dp[1][0] = dp[1][1] = p[1].back() - 1;
    p[1][0] = p[1].back();
  }
  int last = 1;
  for (int i = 2; i <= n; i++) {
    if (p[i].empty()) continue;
    long long l_to_l =
        dp[last][0] + dis(last, p[last].front(), i, p[i].front());
    long long l_to_r = dp[last][0] + dis(last, p[last].front(), i, p[i].back());
    long long r_to_l = dp[last][1] + dis(last, p[last].back(), i, p[i].front());
    long long r_to_r = dp[last][1] + dis(last, p[last].back(), i, p[i].back());
    long long tmp = p[i].back() - p[i].front();
    dp[i][0] = min(l_to_r, r_to_r) + tmp;
    dp[i][1] = min(l_to_l, r_to_l) + tmp;
    last = i;
  }
  printf("%lld\n", min(dp[last][0], dp[last][1]));
  return 0;
}
