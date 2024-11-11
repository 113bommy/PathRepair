#include <bits/stdc++.h>
using namespace std;
const int MAXN = 1e5 + 10;
const double PI = acos(-1);
int main() {
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  int n, x, y, a = 0, b = 1;
  double mn = 360.0;
  pair<long double, int> p[MAXN];
  cin >> n;
  for (int i = 0; i < n; i++) {
    cin >> x >> y;
    p[i].first = atan2l(y, x) / PI * 180.0 + 180.0;
    p[i].second = i;
  }
  sort(p, p + n);
  p[n] = {p[0].first + 360.0, p[0].second};
  for (int i = 0; i < n; i++) {
    if (p[i + 1].first - p[i].first < mn) {
      mn = p[i + 1].first - p[i].first;
      a = p[i].second, b = p[i + 1].second;
    }
  }
  cout << a + 1 << ' ' << b + 1;
  return 0;
}
