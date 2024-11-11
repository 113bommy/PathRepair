#include <bits/stdc++.h>
const double EPS = 0.00000001;
const long long mod = 1000000000 + 7;
using namespace std;
long long myPow(long long a, long long b, long long MOD) {
  long long x = 1, y = a;
  while (b > 0) {
    if (b % 2 == 1) {
      x = (x * y);
      if (x > MOD) x %= MOD;
    }
    y = (y * y);
    if (y > MOD) y %= MOD;
    b /= 2;
  }
  return x;
}
long long a[1000010], m = 998244353, n, sum[1000010];
int main() {
  cout.sync_with_stdio(0);
  cin >> n;
  for (int i = 0; i < n; i++) cin >> a[i];
  sum[0] = a[0];
  for (int i = 1; i < n; i++)
    sum[i] = ((2 * sum[i - 1]) % m - a[i - 1] % m + a[i] + m) % m;
  long long ans = 0;
  for (int i = 0; i < n; i++) {
    ans = (ans + sum[i] * myPow(2, n - 1 - i, m));
  }
  cout << ans << endl;
  return 0;
}
