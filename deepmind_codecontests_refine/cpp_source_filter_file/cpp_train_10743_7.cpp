#include <bits/stdc++.h>
using namespace std;
const double eps = 1e-10;
inline int dcmp(double x) {
  if (x < -eps) return -1;
  if (x > eps) return 1;
  return 0;
}
pair<int, int> a[2005];
vector<pair<int, int> > res;
int c[2005];
bool v[2005][2005];
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  int _;
  for (cin >> _; _; --_) {
    int n, m;
    cin >> n >> m;
    for (int i = 1; i <= n; ++i) cin >> a[i].first;
    for (int i = 1; i <= n; ++i) a[i].second = i, c[i] = 2;
    sort(a + 1, a + n + 1);
    if (n == 2 || m < n) {
      cout << -1 << endl;
      break;
    }
    int v = 0;
    for (int i = 1; i <= n; ++i) v += 2 * a[i].first;
    m -= n;
    v += m * (a[1].first + a[2].first);
    cout << v << endl;
    while (m--) cout << a[1].second << ' ' << a[2].second << endl;
    for (int i = 1; i < n; ++i) cout << i << ' ' << i + 1 << endl;
    cout << n << ' ' << 1 << endl;
  }
}
