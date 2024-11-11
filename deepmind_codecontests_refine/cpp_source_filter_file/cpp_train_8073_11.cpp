#include <bits/stdc++.h>
using namespace std;
const int MaxN = 2e5 + 10;
const int MOD = 1e9 + 7;
const int INF = 1e9;
int main() {
  int L, n, p, t;
  cin >> L >> n >> p >> t;
  if (n == 0) {
    cout << 0 << '\n';
    exit(0);
  }
  vector<pair<int, int> > seg(n);
  for (int i = 0; i < n; ++i) {
    cin >> seg[i].first >> seg[i].second;
  }
  sort(seg.begin(), seg.end());
  set<pair<int, int> > st;
  map<int, int> f;
  for (int i = 0; i < n; ++i) {
    st.insert(make_pair(seg[i].first, i));
  }
  int ans = 0;
  while (!st.empty()) {
    int x = st.begin()->first, where = st.begin()->second;
    ans = max(ans, f[x]);
    st.erase(st.begin());
    int ex = seg[where].second;
    if (where + 1 < (int)seg.size()) {
      f[seg[where + 1].first] = max(f[seg[where + 1].first], f[x]);
    }
    int can = (ex - x) / p;
    int val = f[x] + can;
    ans = max(ans, f[x] + can);
    if (where + 1 < n && f[seg[where + 1].first] >= val) {
      continue;
    }
    x += (ex - x) / p * p + t;
    if (where + 1 < n && seg[where + 1].first >= x) {
      f[seg[where + 1].first] = max(f[seg[where + 1].first], val);
      continue;
    }
    int pos = lower_bound(seg.begin(), seg.end(), make_pair(x + 1, INF)) -
              seg.begin() - 1;
    if (pos < n && seg[pos].first <= x && x <= seg[pos].second) {
      st.insert(make_pair(x, pos));
      f[x] = max(f[x], val);
    } else if (pos + 1 != n) {
      f[seg[pos + 1].first] = max(f[seg[pos + 1].first], val);
    }
  }
  cout << ans << '\n';
  return 0;
}
