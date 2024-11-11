#include <bits/stdc++.h>
using namespace std;
double check(int n, double mid, int a[], int b[]) {
  double sum = 0;
  for (int i = 0; i <= n - 1; i++) {
    if (a[i] * mid > b[i]) {
      return INFINITY;
    } else {
      sum += a[i] * mid;
    }
  }
  return sum;
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  int t;
  t = 1;
  while (t--) {
    int n;
    double v;
    cin >> n >> v;
    int a[n];
    for (int i = 0; i <= n - 1; i++) {
      cin >> a[i];
    };
    int b[n];
    for (int i = 0; i <= n - 1; i++) {
      cin >> b[i];
    };
    double l = 0, r = v;
    double sum = 0, ans = 0;
    while (abs(r - l) > 0.00001) {
      double mid = l + (r - l) / 2.0;
      sum = check(n, mid, a, b);
      if (sum <= v) {
        ans = max(ans, sum);
        l = mid;
      } else {
        r = mid;
      }
    }
    cout << fixed << setprecision(4) << ans;
  }
  return 0;
}
