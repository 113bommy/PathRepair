#include <bits/stdc++.h>
using namespace std;
int n;
double a[101];
vector<double> v;
double ans;
double aa = 1.0;
int main() {
  scanf("%d", &n);
  for (int i = 0; i < n; ++i) {
    scanf("%lf", a + i);
  }
  sort(a, a + n);
  for (int s = 0; s < n; ++s) {
    double cur = 0;
    for (int i = s; i < n; i++) {
      double cc = a[i];
      for (int j = s; j < n; j++)
        if (i != j) cc *= (1.0 - a[i]);
      cur += cc;
    }
    ans = max(ans, cur);
  }
  cout << fixed << setprecision(9) << min(1.0, ans);
  return 0;
}
