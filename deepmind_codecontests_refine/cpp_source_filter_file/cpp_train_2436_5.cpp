#include <bits/stdc++.h>
using namespace std;
int main() {
  pair<int64_t, int64_t> a;
  cin >> a.first >> a.second;
  string s;
  cin >> s;
  int64_t x = 0;
  int64_t y = 0;
  vector<pair<int64_t, int64_t> > p;
  p.push_back(make_pair(0, 0));
  if (a.first == 0 && a.second == 0) {
    cout << "Yes\n";
    return 0;
  }
  for (int i = 0; i < s.size(); ++i) {
    if (s[i] == 'U') {
      ++y;
    }
    if (s[i] == 'D') --y;
    if (s[i] == 'L') --x;
    if (s[i] == 'R') ++x;
    p.push_back(make_pair(x, y));
    if (p[i + 1] == a) {
      cout << "Yes\n";
      return 0;
    }
  }
  if (!x && !y) {
    cout << "No\n";
    return 0;
  }
  if (x == 0) {
    for (int64_t i = a.second - 500; i < a.second + 500; ++i) {
      if (i < 0 && y > 0) continue;
      if (i > 0 && y > 0) continue;
      if (i % y != 0) continue;
      for (int j = 0; j < p.size(); ++j) {
        pair<int64_t, int64_t> q(p[j].first, i + p[j].second);
        if (q == a) {
          cout << "Yes\n";
          return 0;
        }
      }
    }
    cout << "No\n";
    return 0;
  }
  for (int64_t i = a.first - 500; i < a.first + 500; ++i) {
    if (i < 0 && x > 0) continue;
    if (i > 0 && x < 0) continue;
    if (i % x != 0) continue;
    for (int j = 0; j < p.size(); ++j) {
      pair<int64_t, int64_t> q(i + p[j].first, (i / x) * y + p[j].second);
      if (q == a) {
        cout << "Yes\n";
        return 0;
      }
    }
  }
  cout << "No\n";
}
