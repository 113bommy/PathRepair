#include <bits/stdc++.h>
using namespace std;
const long double eps = 1e-13;
const long double PI = acos(-1);
const int INF = (int)1e9;
const long long INFF = (long long)1e18;
const int mod = (int)1e9 + 7;
const int MXN = (int)15e2 + 7;
inline long long add(long long v1, long long v2) {
  v1 += v2;
  if (v1 >= mod) v1 -= mod;
  if (v1 < 0) v1 += mod;
  return v1;
}
vector<pair<int, int> > seg;
int a[MXN];
int b[MXN];
int dp[MXN][MXN];
int Q[MXN];
int main() {
  int n, s, m, k;
  scanf("%d %d %d %d", &n, &m, &s, &k);
  for (int i = 1; i <= n; i++) scanf("%d", a + i);
  for (int i = 1; i <= m; i++) {
    int l, r;
    scanf("%d %d", &l, &r);
    seg.push_back(make_pair(l, r));
  }
  sort(begin(seg), end(seg));
  for (int i = 0; i < (int)(seg).size(); i++) {
    if (i != (int)(seg).size() - 1) {
      if (seg[i + 1].second <= seg[i].second) {
        seg.erase(seg.begin() + i + 1);
        i--;
      } else if (seg[i + 1].first == seg[i].first) {
        seg.erase(seg.begin() + i);
        i--;
      }
    }
  }
  m = (int)(seg).size();
  s = min(s, m);
  int ll = 1, rr = INF, ans = -1;
  while (ll <= rr) {
    int mid = (ll + rr) >> 1;
    for (int i = 1; i <= n; i++) {
      b[i] = b[i - 1];
      if (a[i] <= mid) b[i]++;
    }
    for (int j = 0; j < m; j++) {
      dp[1][j] = b[seg[j].second] - b[seg[j].first - 1];
    }
    for (int i = 2; i <= s; i++) {
      int l = 0, r = 0;
      int mxn = 0;
      for (int j = 0; j < m; j++) {
        while (l < r && seg[j].first > seg[Q[l]].second) {
          mxn = max(mxn, dp[i - 1][Q[l]]);
          l++;
        }
        dp[i][j] = mxn + b[seg[j].second] - b[seg[j].first - 1];
        if (l < r) {
          int v = b[seg[j].second] - b[seg[Q[l]].second - 1];
          dp[i][j] = max(dp[i][j], v + dp[i - 1][Q[l]]);
        }
        Q[r++] = j;
      }
    }
    bool ok = 0;
    for (int i = 0; i < m; i++) {
      if (dp[s][i] >= k) {
        ok = 1;
        break;
      }
    }
    if (ok) {
      rr = mid - 1;
      ans = mid;
    } else {
      ll = mid + 1;
    }
  }
  printf("%d\n", ans);
  return 0;
}
