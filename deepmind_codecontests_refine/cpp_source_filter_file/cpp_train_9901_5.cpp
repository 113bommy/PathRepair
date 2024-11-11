#include <bits/stdc++.h>
using namespace std;
int n, a, b;
vector<pair<int, int>> v, w;
int ob(pair<int, int> a, pair<int, int> b, pair<int, int> c) {
  return abs(a.first - b.first) + abs(b.first - c.first) +
         abs(c.first - a.first) + abs(a.second - b.second) +
         abs(b.second - c.second) + abs(c.second - a.second);
}
bool cmp(pair<int, int> a, pair<int, int> b) {
  if (a.second == b.second) return a.first < b.first;
  return a.second < b.second;
}
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cin >> n;
  for (int i = 0; i < n; ++i) {
    cin >> a >> b;
    v.push_back({a, b});
    w.push_back({a, b});
  }
  sort(v.begin(), v.end());
  sort(w.begin(), w.end(), cmp);
  a = 2 * (abs(v.front().first - v.back().first) +
           abs(w.front().second - w.back().second));
  if ((v.front() == w.front()) || (v.back() == w.back()))
    cout << a << " ";
  else {
    for (int i = 1; i < n; ++i) {
      if (v[i] != w.front()) b = max(b, ob(v.front(), w.front(), v[i]));
    }
    for (int i = 1; i < n; ++i) {
      if (v[i] != w.back()) b = max(b, ob(v.front(), w.back(), v[i]));
    }
    for (int i = 0; i < n - 1; ++i) {
      if (v[i] != w.front()) b = max(b, ob(v.back(), w.front(), v[i]));
    }
    for (int i = 0; i < n - 1; ++i) {
      if (v[i] != w.back()) b = max(b, ob(v.back(), w.back(), v[i]));
    }
    cout << b << " ";
  }
  for (int i = 4; i <= n; ++i) cout << a << " ";
}
