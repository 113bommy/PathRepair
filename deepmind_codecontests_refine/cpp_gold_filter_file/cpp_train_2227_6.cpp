#include <bits/stdc++.h>
using namespace std;
const int MAXN = 100005;
int n, x, y, pmin[MAXN], pmax[MAXN], smin[MAXN], smax[MAXN];
pair<int, int> v[MAXN];
bool check(double dis) {
  int r = 1;
  for (int l = 1; l <= n; ++l) {
    while (r <= n && v[r].first - v[l].first <= 2 * dis) ++r;
    if (max(pmax[l - 1], smax[r]) - min(pmin[l - 1], smin[r]) <= 2 * dis)
      return 1;
  }
  return 0;
}
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cin >> n;
  for (int i = 1; i <= n; ++i) {
    cin >> x >> y;
    v[i] = make_pair(x - y, x + y);
  }
  sort(v + 1, v + n + 1);
  pmin[0] = 2e9;
  pmax[0] = -2e9;
  smin[n + 1] = 2e9;
  smax[n + 1] = -2e9;
  for (int i = 1; i <= n; ++i) {
    pmin[i] = min(pmin[i - 1], v[i].second);
    pmax[i] = max(pmax[i - 1], v[i].second);
  }
  for (int i = n; i >= 1; --i) {
    smin[i] = min(smin[i + 1], v[i].second);
    smax[i] = max(smax[i + 1], v[i].second);
  }
  double l = 0.0, r = 2e9;
  for (int i = 0; i < 120; ++i) {
    double md = (l + r) / 2;
    if (check(md))
      r = md;
    else
      l = md;
  }
  cout << setprecision(10) << fixed << l << '\n';
}
