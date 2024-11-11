#include <bits/stdc++.h>
using namespace std;
double a[500008];
long long int n, m, k;
double b[500008];
double f(double mid) {
  double sum = 0.0;
  double arr[n + 7];
  for (int i = 1; i <= n; i++) {
    arr[i] = a[i] - mid;
  }
  double mn = 0;
  double maax = 0;
  for (int i = 1; i <= n; i++) {
    mn += arr[i];
    maax += arr[i];
    mn = min(mn, arr[i]);
    maax = max(maax, arr[i]);
    sum = max(sum, abs(mn));
    sum = max(sum, abs(maax));
  }
  return sum;
}
int main() {
  long long int t = 1;
  while (t--) {
    cin >> n;
    for (int i = 1; i <= n; i++) cin >> a[i];
    double lo = -1e5;
    double hi = 1e5;
    double midl, midr;
    double ans = 123456789;
    for (int i = 1; i <= 200; i++) {
      midl = lo + (hi - lo) / 3;
      midr = hi - (hi - lo) / 3;
      if (f(midl) > f(midr)) {
        lo = midl;
      } else
        hi = midr;
      ans = min(ans, f(midl));
      ans = min(ans, f(midr));
    }
    cout << setprecision(15) << fixed;
    cout << ans << endl;
  }
}
