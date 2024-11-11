#include <bits/stdc++.h>
using namespace std;
int n, k, x, a[10];
double p;
int countInversions() {
  int i, j, ans = 0;
  for (i = 0; i < n; ++i)
    for (j = i + 1; j < n; ++j)
      if (a[i] > a[j]) ++ans;
  return ans;
}
double solve(int rem) {
  if (rem == 0) return countInversions() * p;
  double ans = 0;
  for (int i = 0; i < n; ++i) {
    for (int j = i; j < n; ++j) {
      reverse(a + i, a + j + 1);
      ans += solve(rem - 1);
      reverse(a + i, a + j + 1);
    }
  }
  return ans;
}
int main() {
  cin >> n >> k;
  for (int i = 0; i < n; ++i) cin >> a[i], x += n - i;
  p = pow(1.0 / x, k);
  cout << fixed << setprecision(15) << solve(k) << endl;
  return 0;
}
