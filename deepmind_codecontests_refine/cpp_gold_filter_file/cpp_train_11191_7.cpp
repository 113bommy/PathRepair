#include <bits/stdc++.h>
using namespace std;
long long int gcd(long long int a, long long int b) {
  if (b == 0) return a;
  a %= b;
  return gcd(b, a);
}
long long int Lpow(long long int a, long long int b) {
  long long int ans = 1;
  while (b > 0) {
    if (b % 2) ans = (ans * a) % 1000000007;
    a = (a * a) % 1000000007;
    b = b / 2;
  }
  return ans;
}
long long int fact(long long int n) {
  long long int ans = 1;
  while (n >= 1) {
    ans = ans * n;
    n--;
  }
  return ans;
}
long long int nCr(long long int n, long long int r) {
  return (fact(n) / (fact(r) * (fact(n - r))));
}
double Lpow_do(double a, long long int b) {
  double ans = 1.0;
  while (b > 0) {
    if (b % 2) ans = ans * a;
    a = a * a;
    b = b / 2;
  }
  return ans;
}
signed main() {
  ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
  long long int a, b;
  cin >> a >> b;
  if (a < b)
    cout << -1 << '\n';
  else {
    long long int deno = (a + b) / (2 * b);
    double ans1 = ((double)(a + b) / (2 * deno));
    cout << fixed << setprecision(10) << ans1 << '\n';
  }
  return 0;
}
