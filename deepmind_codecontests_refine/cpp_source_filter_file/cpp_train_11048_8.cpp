#include <bits/stdc++.h>
using namespace std;
const long long MOD = (long long)1e9 + 7;
const int inf = (int)1e9 + 7;
const double eps = 1e-7;
const double pi = 3.14159265359;
const int N = (int)1e3;
int n;
pair<int, int> a[N], b[N];
set<pair<int, int> > r;
signed main() {
  cin >> n;
  for (int i = 0; i < n; ++i) cin >> a[i].first >> a[i].second;
  for (int i = 0; i < n; ++i) {
    cin >> b[i].first >> b[i].second;
    r.insert(b[i]);
  }
  for (int i = 0; i < n; ++i) {
    bool f = true;
    int x = a[i].first + b[0].first;
    int y = a[i].second + b[0].second;
    for (int j = 0; j < n; ++j) {
      int x_ = x - a[j].first;
      int y_ = y - a[j].second;
      if (r.find(make_pair(x_, y_)) != r.end())
        r.erase(make_pair(x_, y_));
      else {
        f = false;
        break;
      }
    }
    if (f) {
      cout << x << " " << y;
      return 0;
    }
    for (int j = 0; j < n; ++j) r.insert(b[i]);
  }
  return 0;
}
