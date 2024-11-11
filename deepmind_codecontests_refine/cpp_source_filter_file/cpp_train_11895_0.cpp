#include <bits/stdc++.h>
using namespace std;
inline bool Bsearch(vector<pair<int64_t, int64_t> >& v, int64_t l, int64_t r,
                    int64_t k) {
  int64_t st = 0, e = v.size() - 1;
  while (st <= e) {
    int64_t mid = (st + e) / 2;
    if (v[mid].first > k) {
      e = mid - 1;
    } else if (v[mid].second < k) {
      st = mid + 1;
    } else {
      if (v[mid].first >= l && v[mid].second <= r) return 1;
      return 0;
    }
  }
  return 0;
}
int64_t freq(vector<vector<pair<int64_t, int64_t> > >& intervals, int64_t l,
             int64_t r, int64_t k) {
  int64_t ans = 0, n = intervals.size();
  for (int64_t i = 0; i < n; i++) {
    vector<pair<int64_t, int64_t> >& v = intervals[i];
    ans += Bsearch(v, l, r, k);
  }
  return ans;
}
int64_t dp[102][102];
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  int64_t n, m;
  cin >> n >> m;
  vector<vector<pair<int64_t, int64_t> > > intervals(n);
  for (int64_t i = 0; i < n; i++) {
    int64_t num;
    cin >> num;
    while (num--) {
      int64_t x, y;
      cin >> x >> y;
      intervals[i].push_back({x, y});
    }
  }
  for (int64_t l = 1; l <= m; l++) {
    for (int64_t r = l; r <= m; r++) {
      int64_t ans = 0;
      for (int64_t k = l; k <= r; k++) {
        int64_t a = 0, b = 0;
        a = dp[l][k - 1];
        b = dp[k + 1][r];
        int64_t numInter = freq(intervals, l, r, k);
        int64_t res = a + b + numInter * numInter;
        ans = max(ans, res);
      }
      dp[l][r] = ans;
    }
  }
  int64_t ans = dp[1][m];
  printf("%lld\n", ans);
  return 0;
}
