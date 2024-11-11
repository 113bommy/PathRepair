#include <bits/stdc++.h>
using namespace std;
int main() {
  int n;
  cin >> n;
  pair<int, int> a[n];
  for (int i = 0; i < n; i++) {
    cin >> a[i].first;
    a[i].second = -1;
  }
  int q;
  cin >> q;
  vector<pair<int, int>> v;
  for (int i = 0; i < q; i++) {
    int t;
    cin >> t;
    if (t == 1) {
      int p, s;
      cin >> p >> s;
      p--;
      a[p] = {s, i};
    } else {
      int s;
      cin >> s;
      v.push_back({i, s});
    }
  }
  v.push_back({1e6, 0});
  for (int i = v.size() - 2; i >= 0; i--) {
    v[i].second = max(v[i].second, v[i + 1].second);
  }
  for (int i = 0; i < n; i++) {
    int x = (upper_bound(v.begin(), v.end(), make_pair(a[i].second, 0)) -
             v.begin());
    a[i].first = max(a[i].first, v[x].second);
  }
  for (auto i : a) cout << i.first << " ";
  return 0;
}
