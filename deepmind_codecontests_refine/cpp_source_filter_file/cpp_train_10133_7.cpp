#include <bits/stdc++.h>
const int maxi = 2000000000;
const int maxq = 1000000000;
const double eps = 1e-10;
const double pi = 3.1415926535897932;
const double inf = 1e+18;
const int mo = 1000000007;
using namespace std;
int n;
double _time[111111], a, d;
set<double> k;
set<double>::iterator it;
pair<int, int> aa[1111111];
int main() {
  cin >> n >> a >> d;
  for (int i = 0; i < n; i++) scanf("%d%d", &aa[i].first, &aa[i].second);
  double t = aa[0].second / a;
  double s = (a * ((t) * (t))) / 2.;
  if (s >= d)
    _time[0] = sqrt((2. * d) / a);
  else
    _time[0] = t + (d - s) / aa[0].second;
  _time[0] += aa[0].first;
  k.insert(_time[0]);
  for (int i = 1; i < n; i++) {
    double t = aa[i].second / a;
    double s = a * ((t) * (t)) / 2.;
    if (s >= d)
      _time[i] = sqrt((2. * s) / a);
    else
      _time[i] = t + (d - s) / aa[i].second;
    _time[i] += aa[i].first;
    it = k.end();
    it--;
    _time[i] = max(_time[i], (*it));
    k.insert(_time[i]);
  }
  for (int i = 0; i < n; i++) printf("%.7lf\n", _time[i]);
  return 0;
}
