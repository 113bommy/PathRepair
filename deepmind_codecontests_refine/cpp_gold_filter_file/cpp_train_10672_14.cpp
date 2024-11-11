#include <bits/stdc++.h>
using namespace std;
long double np(long long a, long long b, long long p) {
  long long na = (a - 1) / p;
  long long nb = b / p;
  long long ans = nb - na;
  return ans;
}
int main() {
  long long n;
  long double t;
  cin >> n >> t;
  long double a[n], b[n], ans = 0;
  for (int i = 0; i < n; i++) cin >> a[i] >> b[i];
  for (int i = 1; i < n; i++) {
    long double lf = b[i - 1] - a[i - 1] + 1, ls = b[i] - a[i] + 1;
    long double p = lf - np(a[i - 1], b[i - 1], t), q = ls - np(a[i], b[i], t);
    ans += (1.0 - ((p / lf) * (q / ls)));
  }
  long double lf = b[n - 1] - a[n - 1] + 1, ls = b[0] - a[0] + 1;
  long double p = ls - np(a[0], b[0], t), q = lf - np(a[n - 1], b[n - 1], t);
  ans += (1.0 - ((p / ls) * (q / lf)));
  ans *= 2000;
  cout << setprecision(9) << fixed;
  cout << ans << endl;
  return 0;
}
