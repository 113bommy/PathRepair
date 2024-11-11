#include <bits/stdc++.h>
using namespace std;
void show(vector<int> v) {
  for (auto it = v.begin(); it != v.end(); ++it) {
    cout << *it << " ";
  }
  cout << "\n";
}
bool sorter(pair<int, int> a, pair<int, int> b) {
  if (a.first == b.first) return a.second < b.second;
  return a.first > b.first;
}
void solve() {
  int n, k;
  cin >> n >> k;
  vector<pair<int, int>> v(n);
  for (int i = 0; i < n; i++) {
    int p, t;
    cin >> p >> t;
    v[i] = make_pair(p, t);
  }
  sort(v.begin(), v.end(), sorter);
  int cnt = 0;
  for (int i = 0; i < n; i++)
    cnt += int(v[i].first == v[k - 1].first && v[i].second == v[k - 1].second);
  cout << cnt;
}
signed main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  solve();
  return 0;
}
