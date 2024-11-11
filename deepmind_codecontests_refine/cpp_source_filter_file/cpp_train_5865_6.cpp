#include <bits/stdc++.h>
using namespace std;
const long long INF = 1e18;
const int INFi = 1e9 * 2;
const int maxN = 3e5 + 100;
long long md = 1000000007;
void solve() {
  int n, le, v1, v2;
  cin >> n >> le >> v1 >> v2;
  double x = le - (double)le * v2 / (v1 + v2);
  vector<pair<double, int>> a;
  int b = 0;
  for (int i = 0; (i) < n; ++(i)) {
    int c;
    cin >> c;
    if (c < x) {
      b++;
      a.emplace_back(c - x + 2 * le, -1);
    } else {
      a.emplace_back(c - x, -1);
    }
    a.emplace_back(c, 1);
  }
  sort((a).begin(), (a).end());
  vector<double> ans(n + 1, 0);
  a.emplace_back(2 * le, -1);
  for (int i = 0; (i) < n * 2 + 1; ++(i)) {
    if (i && a[i].first != a[i - 1].first) {
      ans[b] += a[i].first - a[i - 1].first;
    }
    if (!i) ans[b] += a[i].first;
    b -= a[i].second;
  }
  cout << setprecision(15) << fixed;
  for (int i = 0; (i) < n + 1; ++(i)) {
    cout << ans[i] / (2 * le) << "\n";
  }
}
int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);
  int tests = 1;
  for (int _ = 0; (_) < tests; ++(_)) {
    solve();
  }
  return 0;
}
