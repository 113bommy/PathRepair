#include <bits/stdc++.h>
using namespace std;
const long long inf = 1e17;
const int MAXM = 1e6 + 5;
const int MAXN = 1e6 + 4;
vector<pair<double, double> > v;
double p, ret = -1.0;
bool cal(double val) {
  double tt = 0.00;
  for (int i = 0; i < v.size(); i++) {
    double a = v[i].first;
    double b = v[i].second;
    double totalcharge = a * val;
    if (b > totalcharge) continue;
    tt += ((totalcharge - b) / p);
  }
  return tt <= val;
}
int main() {
  int n, k, i, j;
  scanf("%d", &n);
  scanf("%lf", &p);
  for (i = 1; i <= n; i++) {
    double x, y;
    scanf("%lf%lf", &x, &y);
    v.push_back(make_pair(x, y));
  }
  double hi = 1e18, lo = 0.00;
  int cn = 0;
  while (cn <= 500) {
    double mid = (lo + hi) / 2.0;
    if (cal(mid)) {
      lo = mid + 0.0000001;
      ret = mid;
    } else {
      hi = mid - 0.0000001;
      if (hi <= 0) break;
    }
    cn++;
  }
  if (ret > 1e15)
    printf("-1\n");
  else
    printf("%0.6lf\n", ret);
  return 0;
}
