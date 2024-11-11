#include <bits/stdc++.h>
using namespace std;
const int N = 2e5 + 7;
int n, q, ans = 0;
int a[N];
vector<int> val[N];
vector<pair<int, pair<int, int> > > seg;
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cin >> n >> q;
  for (int i = 1; i <= n; i++) {
    cin >> a[i];
    val[a[i]].push_back(i);
  }
  for (int i = 1; i < N; i++) {
    if ((int)val[i].size() == 0) continue;
    int t = val[i].size();
    seg.push_back(make_pair(val[i][0], make_pair(val[i][t - 1], t)));
  }
  sort(seg.begin(), seg.end());
  int sz = (int)seg.size();
  for (int i = 0; i < sz; i++) {
    int st = seg[i].first;
    int ed = seg[i].second.first, mx = seg[i].second.second;
    for (int j = i + 1;; j++) {
      if (j == sz) {
        i = j - 1;
        break;
      }
      if (seg[j].first > ed) {
        i = j - 1;
        break;
      }
      ed = max(ed, seg[j].second.first);
      mx = max(mx, seg[i].second.second);
    }
    ans += ed - st + 1 - mx;
  }
  cout << ans;
}
