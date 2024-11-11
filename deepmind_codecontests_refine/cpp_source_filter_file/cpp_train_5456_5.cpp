#include <bits/stdc++.h>
using namespace std;
const int N = 2005;
double a[2 * N];
int main() {
  int n;
  cin >> n;
  int zero = 0;
  double tot = 0;
  for (int i = 0; i < 2 * n; i++) {
    cin >> a[i];
    a[i] -= floor(a[i]);
    if (a[i] == 0) zero++;
    tot += a[i];
  }
  double res = abs(tot - n);
  for (int i = 0; i < min(zero, n); i++) {
    res = min(res, abs(tot - (n - i)));
  }
  cout << (fixed) << setprecision(3) << res << "\n";
}
