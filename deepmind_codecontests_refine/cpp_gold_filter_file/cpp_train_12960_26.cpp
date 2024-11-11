#include <bits/stdc++.h>
using namespace std;
int MOD = 1000000007;
int main() {
  int n;
  cin >> n;
  vector<std::pair<int, int> > pts;
  vector<int> xs;
  set<int> st;
  for (int i = 0; i < (n); ++i) {
    int x, l;
    cin >> x >> l;
    st.insert(x);
    st.insert(x + l);
    st.insert(x - l);
    pts.push_back(make_pair(x, l));
  }
  sort(pts.begin(), pts.end());
  for (int x : st) xs.push_back(x);
  int m = xs.size();
  vector<vector<int> > dp(n + 1, vector<int>(m, 0));
  for (int i = 0; i < m; ++i) {
    for (int j = 0; j < n; ++j)
      if (pts[j].first >= xs[i]) {
        for (int l = j; l < n; ++l)
          if (pts[j].first >= pts[l].first - pts[l].second) {
            int k = j;
            int left = pts[l].first - pts[l].second;
            int right = pts[l].first;
            while (k < n && pts[k].first <= right) {
              if (k != l) right = max(right, pts[k].first + pts[k].second);
              k += 1;
            }
            int mx = lower_bound(xs.begin(), xs.end(), right) - xs.begin();
            dp[k][mx] = max(dp[k][mx], dp[j][i] + right - max(left, xs[i]));
          }
        int k = j;
        int left = pts[j].first;
        int right = pts[j].first;
        while (k < n && pts[k].first <= right) {
          right = max(right, pts[k].first + pts[k].second);
          k += 1;
        }
        int mx = lower_bound(xs.begin(), xs.end(), right) - xs.begin();
        dp[k][mx] = max(dp[k][mx], dp[j][i] + right - max(left, xs[i]));
      }
  }
  int ans = *max_element(dp[n].begin(), dp[n].end());
  cout << ans << endl;
  return 0;
}
