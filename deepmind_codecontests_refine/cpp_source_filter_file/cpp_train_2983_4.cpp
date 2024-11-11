#include <bits/stdc++.h>
using namespace std;
vector<pair<double, double>> v;
double x[3], y[3], r[3];
int match = 0, touch = 0;
void add_point(double x, double y) {
  for (int i = 0; i < v.size(); i++)
    if (fabs(v[i].first - x) < 1e-7 && fabs(v[i].second - y) < 1e-7) {
      match++;
      return;
    }
  v.push_back(make_pair(x, y));
}
void find_intersection(int i, int j) {
  double a = 2 * (x[j] - x[i]), b = 2 * (y[j] - y[i]),
         c = (a * a + b * b) / 4 + r[i] * r[i] - r[j] * r[j];
  double d = a * a + b * b, x0 = a * c / d + x[i], y0 = b * c / d + y[i],
         md = r[i] * r[i] * d - c * c;
  if (fabs(md) < 1e-7) touch++, md = 0;
  if (md >= 0) {
    b *= sqrt(md) / d, a *= sqrt(md) / d;
    add_point(x0 + b, y0 - a);
    if (md) add_point(x0 - b, y0 + a);
  }
}
int main() {
  int n;
  cin >> n;
  for (int i = 0; i < n; i++) cin >> x[i] >> y[i] >> r[i];
  if (n > 1) find_intersection(0, 1);
  if (n > 2) find_intersection(0, 2), find_intersection(1, 2);
  int ans = n + 1;
  switch (v.size() + match - touch) {
    case 6:
      ans = 8 - match / 2;
      break;
    case 4:
      ans = (match || touch) ? 7 : 6;
      break;
    case 2:
      ans = (match || touch > 1) ? 6 : n + 2;
      break;
    case 0:
      ans = (!match && touch > 2) ? n + 2 : n + 1;
      break;
  }
  cout << ans << endl;
  return 0;
}
