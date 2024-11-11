#include <bits/stdc++.h>
using namespace std;
int n, m;
pair<int, int> a[12], b[12];
int main() {
  ios_base::sync_with_stdio(false);
  cin >> n >> m;
  for (int i = 0; i < n; i++) cin >> a[i].first >> a[i].second;
  for (int i = 0; i < m; i++) cin >> b[i].first >> b[i].second;
  set<int> q;
  for (int i = 0; i < n; i++) {
    set<int> v;
    for (int j = 0; j < m; j++) {
      int c = 0;
      int num;
      if (a[i].first == b[j].first || a[i].first == b[j].second)
        c++, num = a[i].first;
      if (a[i].second == b[j].first || a[i].second == b[j].second)
        c++, num = a[i].second;
      if (c == 1) q.insert(num), v.insert(num);
    }
    if (v.size() > 1) {
      cout << -1 << endl;
      exit(0);
    }
  }
  set<int> q2;
  for (int i = 0; i < m; i++) {
    set<int> v;
    for (int j = 0; j < n; j++) {
      int c = 0;
      int num;
      if (b[i].first == a[j].first || b[i].first == a[j].second)
        c++, num = b[i].first;
      if (b[i].second == a[j].first || b[i].second == a[j].second)
        c++, num = b[i].second;
      if (c == 1) q2.insert(num), v.insert(num);
    }
    if (v.size() > 1) {
      cout << -1 << endl;
      exit(0);
    }
  }
  set<int> all;
  for (auto u : q) all.insert(u);
  for (auto u : q2) all.insert(u);
  if (all.size() == 1)
    cout << *all.begin() << endl;
  else
    cout << 0 << endl;
}
