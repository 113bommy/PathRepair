#include <bits/stdc++.h>
using namespace std;
void solve() {
  long long n, m, i, j, x, y, a, b, c, f = 0;
  cin >> n >> m;
  cin >> x >> y;
  vector<pair<long long, long long> > v, w;
  v.push_back(make_pair(x, y));
  a = x;
  c = y;
  f = 0;
  for (i = 1; i < m; ++i) {
    cin >> x >> y;
    v.push_back(make_pair(x, y));
    if (x != a && y != a) {
      f = 1;
      w.push_back(make_pair(x, y));
    }
  }
  if (f == 0) {
    cout << "YES";
    return;
  }
  b = w[0].first;
  f = 0;
  for (i = 1; i < w.size(); i++) {
    if (w[i].first != b && w[i].second != b) {
      f = 1;
      break;
    }
  }
  if (f == 0) {
    cout << "YES";
    return;
  }
  b = w[0].second;
  f = 0;
  for (i = 1; i < w.size(); i++) {
    if (w[i].first != b && w[i].second != b) {
      f = 1;
      break;
    }
  }
  if (f == 0) {
    cout << "YES";
    return;
  }
  f = 0;
  a = c;
  w.clear();
  for (i = 1; i < v.size(); ++i) {
    if (v[i].first != a && v[i].second != a) {
      w.push_back(make_pair(v[i].first, v[i].second));
    }
  }
  if (w.size() == 0) {
    cout << "YES";
    return;
  }
  b = w[0].first;
  for (i = 1; i < w.size(); i++) {
    if (w[i].first != b && w[i].second != b) {
      f = 1;
      break;
    }
  }
  if (f == 0) {
    cout << "YES";
    return;
  }
  b = w[0].second;
  f = 0;
  for (i = 1; i < w.size(); i++) {
    if (w[i].first != b && w[i].second != b) {
      f = 1;
      break;
    }
  }
  if (f == 0) {
    cout << "YES";
    return;
  }
  cout << "NO";
  return;
}
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  solve();
  return 0;
}
