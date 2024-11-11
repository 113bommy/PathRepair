#include <bits/stdc++.h>
using namespace std;
int main() {
  int n, c;
  scanf("%d%d", &n, &c);
  long double w = (long double)c;
  vector<long double> a(2 * n);
  for (int i = 0; i < 2 * n; i++) {
    int t;
    scanf("%d", &t);
    long double t1 = (long double)t;
    a[i] = t1;
  };
  sort(a.begin(), a.end());
  long double l = 0;
  long double r = a[n];
  long double eps = 1e-9;
  eps /= 5;
  while (abs(r - l) > eps) {
    long double mid = (l + r) / 2;
    if (3 * mid * n > w)
      r = mid;
    else {
      bool flag = 0;
      for (int i = 0; i < n; i++)
        if (mid > a[i]) flag = 1;
      for (int i = n; i < 2 * n; i++)
        if (mid * 2 > a[i]) flag = 1;
      if (flag == 1)
        r = mid;
      else
        l = mid;
    };
  };
  long double ans = 3 * n * l;
  cout << setprecision(20) << ans << endl;
  cin.get();
  cin.get();
  return 0;
}
