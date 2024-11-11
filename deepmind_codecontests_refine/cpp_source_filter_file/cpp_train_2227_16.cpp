#include <bits/stdc++.h>
#pragma comment(linker, "/STACK:600000000")
using namespace std;
template <class T>
T sqr(T x) {
  return x * x;
}
double const pi = 3.1415926535897932384626433832795;
int const inf = (int)1e9;
long long const inf64 = (long long)4e18;
const string name = "a";
const int NMAX = 101010;
int n, minyl, maxyl, yy[NMAX], used[NMAX];
double x[NMAX], y[NMAX], zn[NMAX];
pair<double, double> q[NMAX];
pair<double, int> qq[NMAX];
int may(double r) {
  memset(used, 0, sizeof(used));
  double _max = -1e10, _min = 1e10;
  int yl = 0;
  minyl = 0, maxyl = n - 1;
  for (int i = 0; i < (int)n; i++) {
    while (yl < n && x[yl] - x[i] <= 2 * r) {
      used[yy[yl]] = 1;
      while (maxyl >= 0 && used[maxyl]) maxyl--;
      while (minyl < n && used[minyl]) minyl++;
      yl++;
    }
    double tmp_max = _max;
    if (maxyl >= 0) tmp_max = max(tmp_max, zn[maxyl]);
    double tmp_min = _min;
    if (minyl < n) tmp_min = min(tmp_min, zn[minyl]);
    if (tmp_max - tmp_min <= 2 * r) return 1;
    _max = max(_max, y[i]);
    _min = min(_min, y[i]);
  }
  return 0;
}
int main() {
  cin >> n;
  for (int i = 0; i < (int)n; i++) {
    int xx, yy;
    scanf("%d%d", &xx, &yy);
    q[i] = make_pair(xx + yy, xx - yy);
    cerr << q[i].first << " " << q[i].second << endl;
  }
  sort(q, q + n);
  for (int i = 0; i < (int)n; i++) {
    x[i] = q[i].first, y[i] = q[i].second;
    qq[i] = make_pair(y[i], i);
  }
  sort(qq, qq + n);
  for (int i = 0; i < (int)n; i++) zn[i] = qq[i].first, yy[qq[i].second] = i;
  double l = 0, r = 1e10;
  may(0);
  for (int i = 0; i < (int)50; i++) {
    double m = (l + r) / 2;
    if (may(m))
      r = m;
    else
      l = m;
  }
  printf("%.10lf\n", l);
  return 0;
}
