#include <bits/stdc++.h>
using namespace std;
double get_angle(long long x, long long y) {
  if (x == 0 && y >= 0) return M_PI / 2;
  if (x == 0) return 3 * M_PI / 2;
  double res = atan(double(y) / x);
  if (x < 0) res += M_PI;
  if (res < 0) res += 2 * M_PI;
  return res;
}
int main() {
  int x0, y0;
  int v, t;
  scanf("%d%d", &x0, &y0);
  scanf("%d%d", &t, &v);
  unsigned long long l = t;
  l *= v;
  unsigned long long l2 = 1e19;
  if (l < (3e9) + 5) l2 = l * l;
  int n;
  scanf("%d", &n);
  vector<pair<double, double> > res;
  while (n--) {
    int tx, ty, tr;
    scanf("%d%d%d", &tx, &ty, &tr);
    long long x = tx - x0;
    long long y = ty - y0;
    long long r = tr;
    long long dist2 = x * x + y * y;
    double dist = sqrt(double(dist2));
    if (dist2 <= r * r) {
      cout << "1.0000" << endl;
      return 0;
    }
    if (dist - r >= l) continue;
    long long hypo2 = dist2 - r * r;
    double hypo = sqrt(double(hypo2));
    double beta;
    if (hypo2 <= l2) {
      beta = atan(r / hypo);
    } else {
      beta = acos((double(l) * l + dist2 - r * r) / (2.0 * l * dist));
    }
    double alfa = get_angle(x, y);
    double z1 = alfa - beta;
    double z2 = alfa + beta;
    if (z1 < 0) {
      res.push_back(make_pair(z1 + 2 * M_PI, 2 * M_PI));
      z1 = 0;
    }
    if (z2 > 2 * M_PI) {
      res.push_back(make_pair(0, z2 - 2 * M_PI));
      z2 = 2 * M_PI;
    }
    res.push_back(make_pair(z1, z2));
  }
  sort(res.begin(), res.end());
  double sum = 0;
  double prev_st = 0;
  double prev_fi = 0;
  for (int i = 0; i < res.size(); i++)
    if (res[i].first <= prev_fi)
      prev_fi = max(prev_fi, res[i].second);
    else {
      sum += prev_fi - prev_st;
      prev_st = res[i].first;
      prev_fi = res[i].second;
    }
  sum += prev_fi - prev_st;
  printf("%.8f", sum / 2 / M_PI);
  return 0;
}
