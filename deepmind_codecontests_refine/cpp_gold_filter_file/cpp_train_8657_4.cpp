#include <bits/stdc++.h>
using namespace std;
int main() {
  ios::sync_with_stdio(false);
  int n;
  cin >> n;
  vector<pair<int, int> > v(n);
  for (int i = 0; i < n; i++) {
    cin >> v[i].first;
    v[i].second = i;
  }
  sort(v.begin(), v.end());
  vector<int> vv;
  for (int i = 1; i < n - 1; i++) {
    if (2 * v[i].first != (v[i - 1].first + v[i + 1].first)) {
      vv.push_back(i);
    }
  }
  if (vv.size() > 10) {
    cout << -1;
  } else {
    vector<int> t;
    for (auto x : vv) {
      t.push_back(x);
      t.push_back(max(0, x - 1));
      t.push_back(max(0, x - 2));
      t.push_back(min(n - 1, x + 1));
      t.push_back(min(n - 1, x + 2));
    }
    t.push_back(0);
    t.push_back(min(n - 1, 2));
    t.push_back(max(0, n - 2));
    t.push_back(n - 1);
    for (auto x : t) {
      vector<int> buf;
      for (int i = 0; i < n; i++) {
        if (i != x) {
          buf.push_back(v[i].first);
        }
      }
      bool tr = true;
      for (int i = 1; i < buf.size() - 1; i++) {
        if (2 * buf[i] != (buf[i - 1] + buf[i + 1])) {
          tr = false;
        }
      }
      if (tr) {
        cout << v[x].second + 1;
        return 0;
      }
    }
    cout << -1;
  }
  return 0;
}
