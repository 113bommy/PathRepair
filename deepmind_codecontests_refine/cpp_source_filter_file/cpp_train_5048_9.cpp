#include <bits/stdc++.h>
using namespace std;
const int sz = 2001;
int gcd(int a, int b) { return b ? gcd(b, a % b) : a; }
struct point {
  int x;
  int y;
};
int n;
point pnt[sz];
inline void solve() {
  cin >> n;
  for (int i = 0; i < n; i++) cin >> pnt[i].x >> pnt[i].y;
  map<pair<pair<int, int>, pair<int, int>>, uint64_t> lines;
  map<int, uint64_t> zero_x, zero_y;
  for (int i = 0; i < n; i++) {
    for (int j = i + 1; j < n; j++) {
      point a = pnt[i], b = pnt[j];
      if (a.x > b.x) swap(a, b);
      int x = b.x - a.x;
      int y = b.y - a.y;
      if (x == 0) continue;
      if (y == 0) continue;
      int g = gcd(abs(x), abs(y));
      pair<int, int> k = {y / g, x / g};
      int p = a.y * k.second - a.x * k.first;
      int q = k.second;
      g = gcd(abs(p), abs(q));
      pair<int, int> bb = {p / g, q / g};
      pair<pair<int, int>, pair<int, int>> line = make_pair(k, bb);
      lines[line]++;
    }
  }
  for (int i = 0; i < n; i++) {
    zero_x[pnt[i].y]++;
    zero_y[pnt[i].x]++;
  }
  uint64_t all = n * (n - 1) * (n - 2) / 6;
  for (auto x : lines) {
    uint64_t cnt = (1 + (uint64_t)round(sqrt(1 + 8 * x.second))) / 2;
    all -= cnt * (cnt - 1) * (cnt - 2) / 6;
  }
  for (auto x : zero_x) all -= x.second * (x.second - 1) * (x.second - 2) / 6;
  for (auto x : zero_y) all -= x.second * (x.second - 1) * (x.second - 2) / 6;
  cout << all;
}
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  int q = 1;
  for (; q > 0; q--) {
    solve();
    cout << '\n';
  }
}
