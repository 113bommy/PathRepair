#include <bits/stdc++.h>
using namespace std;
int main() {
  int n;
  cin >> n;
  double a[n], ans = 0.;
  for (int i = 0; i < n; i++) {
    cin >> a[i];
  }
  sort(a, a + n);
  for (int i = 0; i < n; i++) {
    if (i % 2 == 0) {
      ans += a[i] * a[i];
    } else {
      ans -= a[i] * a[i];
    }
  }
  ans = ans * 3.1415926536;
  cout << fixed << setprecision(9) << abs(ans) << endl;
}
