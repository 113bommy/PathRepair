#include <bits/stdc++.h>
using namespace std;
vector<double> a;
const double pi = acos(-1.0);
int main() {
  int n;
  scanf("%d", &n);
  for (int i = 0; i < n; i++) {
    double x, y;
    scanf("%lf %lf", &x, &y);
    double tmp = atan2(y, x);
    if (tmp < 0)
      a.push_back(2 * pi + tmp);
    else
      a.push_back(tmp);
  }
  sort(a.begin(), a.end());
  double ans;
  for (int i = 1; i < a.size(); i++) ans = max(ans, a[i] - a[i - 1]);
  ans = max(ans, 2 * pi - (a[n - 1] - a[0]));
  printf("%.10f\n", 360.0 - ans * 180 / pi);
}
