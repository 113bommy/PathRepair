#include <bits/stdc++.h>
using namespace std;
template <class X, class Y>
void amax(X &x, const Y &y) {
  if (x < y) x = y;
}
template <class X, class Y>
void amin(X &x, const Y &y) {
  if (x > y) x = y;
}
const int INF = 1e9 + 10;
const long long INFL = (long long)1e18 + 10;
int n, m;
void process() {
  cin >> n >> m;
  bool m1 = m == 1;
  if (m1) swap(m, n);
  vector<pair<int, int> > res;
  for (int i = 1; i <= (n - 1) / 2 + 1; i++) {
    int x = n - 2 * i + 1;
    int sx = 1;
    int sy = 1;
    res.push_back(make_pair(i, 1));
    if (x == 0) {
      for (int j = m - 1; j >= 1; j--) {
        pair<int, int> last = res.back();
        res.push_back(make_pair(last.first, last.second + sy * j));
        sy = -sy;
      }
    } else {
      for (int j = -(m - 1); j <= m - 1; j++) {
        pair<int, int> last = res.back();
        res.push_back(
            make_pair(last.first + sx * x, last.second + sy * abs(j)));
        sx = -sx;
        sy = -sy;
        if (j == 0) sy = 1;
      }
    }
  }
  if (m1) {
    for (const auto &p : res) cout << p.second << " " << p.first << '\n';
  } else {
    for (const auto &p : res) cout << p.first << " " << p.second << '\n';
  }
}
int main() {
  ios_base::sync_with_stdio(false);
  process();
}
