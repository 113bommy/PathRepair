#include <bits/stdc++.h>
using namespace std;
long long gcd(long long a, long long b) { return b == 0 ? a : gcd(b, a % b); }
long long lcm(long long a, long long b) { return a / gcd(a, b) * b; }
long long int power(long long int x, long long int y,
                    long long int m = 1000000007) {
  long long int ans = 1;
  x %= m;
  while (y) {
    if (y & 1) ans = (x * ans) % m;
    x = (x * x) % m;
    y >>= 1;
  }
  return ans;
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  long long int a, b, n, ans = 0;
  cin >> a >> b >> n;
  vector<long long int> fac(n + 1);
  fac[0] = 1;
  for (int i = 1; i <= n; i++) fac[i] = (fac[i - 1] * i) % 1000000007;
  for (int i = 0; i <= n; i++) {
    long long int sum = a * i + b * (n - i);
    while (sum) {
      if (sum % 10 == a || sum % 10 == b) {
        sum /= 10;
      } else
        break;
    }
    if (!sum)
      ans = (ans + (fac[n] *
                    power((fac[i] * fac[n - i]) % 1000000007, 1000000007 - 2)) %
                       1000000007) %
            1000000007;
  }
  cout << ans;
  return 0;
}
