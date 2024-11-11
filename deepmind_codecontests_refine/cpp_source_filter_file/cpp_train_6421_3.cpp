#include <bits/stdc++.h>
using namespace std;
int main() {
  int n, m;
  cin >> n >> m;
  std::vector<pair<int, int>> v1;
  std::vector<pair<int, int>> v2;
  int a, b;
  for (int i = 0; i < n; i++) {
    cin >> a >> b;
    if (a > b) swap(a, b);
    v1.push_back({a, b});
  }
  for (int i = 0; i < m; i++) {
    cin >> a >> b;
    if (a > b) swap(a, b);
    v2.push_back({a, b});
  }
  int ans = 0;
  set<int> f;
  for (int i = 0; i < n; i++) {
    int ans1 = -1;
    set<int> s;
    for (int j = 0; j < m; j++) {
      if (v1[i] == v2[j]) continue;
      if (v1[i].first == v2[j].first) {
        s.insert(v1[i].first);
        f.insert(v1[i].first);
      } else if (v1[i].second == v2[j].second) {
        s.insert(v1[i].second);
        f.insert(v1[i].second);
      } else if (v1[i].first == v2[j].second) {
        s.insert(v1[i].first);
        f.insert(v1[i].first);
      } else if (v1[i].second == v2[j].first) {
        s.insert(v1[i].second);
        f.insert(v1[i].second);
      }
    }
    if (s.size() > 1) ans = -1;
  }
  for (int j = 0; j < m; j++) {
    set<int> s;
    for (int i = 0; i < n; i++) {
      if (v1[i] == v2[j]) continue;
      if (v1[i].first == v2[j].first) {
        s.insert(v1[i].first);
        f.insert(v1[i].first);
      } else if (v1[i].second == v2[j].second) {
        s.insert(v1[i].second);
        f.insert(v1[i].second);
      } else if (v1[i].first == v2[j].second) {
        s.insert(v1[i].first);
        f.insert(v1[i].first);
      } else if (v1[i].second == v2[j].first) {
        s.insert(v1[i].second);
        f.insert(v1[i].second);
      }
    }
    if (s.size() > 2) ans = -1;
  }
  if (f.size() == 1) ans = *f.begin();
  cout << ans << endl;
}
