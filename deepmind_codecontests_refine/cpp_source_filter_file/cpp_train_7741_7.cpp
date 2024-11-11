#include <bits/stdc++.h>
using namespace std;
const int N = int(1e5);
int n, m, a, b;
double yb[N], t[N];
pair<double, int> ya[N];
double dist(double x1, double y1, double x2, double y2) {
  return sqrt(((x2 - x1) * (x2 - x1)) + ((y2 - y1) * (y2 - y1)));
}
int main() {
  cin >> n >> m;
  cin >> a >> b;
  for (int i = 0; i < n; i++) {
    cin >> ya[i].first;
    ya[i].second = i;
  }
  sort(ya, ya + n);
  for (int i = 0; i < m; i++) cin >> yb[i];
  for (int i = 0; i < m; i++) cin >> t[i];
  double min = 1e18;
  int ind1 = 0, ind2 = 0;
  for (int i = 0; i < m; i++) {
    int l = 0, r = n - 1, md;
    while (r - l > 1) {
      md = (l + r) / 2;
      if (ya[md].first > yb[i])
        r = md;
      else
        l = md;
    }
    double d =
        dist(0, 0, a, ya[l].first) + dist(a, ya[l].first, b, yb[i]) + t[i];
    if (d < min) {
      min = d;
      ind1 = ya[l].second;
      ind2 = i;
    }
  }
  cout << ind1 + 1 << " " << ind2 + 1;
  return 0;
}
