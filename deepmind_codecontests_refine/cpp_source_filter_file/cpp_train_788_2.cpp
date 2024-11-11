#include <bits/stdc++.h>
using namespace std;
vector<long long> a;
long long mod = 1e9 + 7;
void next_mass(int &cur) {
  int n = a.size();
  vector<long long> b(n - 1);
  for (int i = 1; i < n; i++) {
    if (cur == 0)
      b[i - 1] = a[i - 1] + a[i];
    else
      b[i - 1] = a[i - 1] - a[i];
    cur = !cur;
    b[i - 1] %= mod;
  }
  a.clear();
  a = b;
}
void gcd(long long a, long long b, long long &x, long long &y) {
  if (a == 0) {
    x = 0;
    y = 1;
    return;
  }
  long long x1 = 0, y1 = 0;
  gcd(b % a, a, x1, y1);
  x = (y1 - (b / a) * x1) % mod;
  y = x1 % mod;
}
int main() {
  int n;
  cin >> n;
  a.resize(n);
  vector<long long> f(n + 1), f2(n + 1);
  f[0] = 1;
  f2[0] = 1;
  for (int i = 1; i <= n; i++) {
    f[i] = (f[i - 1] * i);
    long long x = 0, y = 0;
    gcd(f[i], mod, x, y);
    f2[i] = x % mod;
  }
  for (int i = 0; i < n; i++) cin >> a[i];
  if (n == 1) {
    cout << a[0];
    return 0;
  }
  int cur = 0;
  if (n % 2 == 1) next_mass(cur), n--;
  long long sum1 = 0, sum2 = 0;
  for (int i = 0; i < n; i++) {
    if (i % 2 == 0)
      sum1 += (((a[i] * f[n / 2 - 1]) % mod) *
               ((f2[n / 2 - i / 2 - 1] * f2[i / 2]) % mod)) %
              mod;
    else
      sum2 += (((a[i] * f[n / 2 - 1]) % mod) *
               ((f2[n / 2 - i / 2 - 1] * f2[i / 2]) % mod)) %
              mod;
    sum1 %= mod;
    sum2 %= mod;
  }
  if (n % 4 == 0)
    cout << (sum1 - sum2 + mod) % mod << endl;
  else
    cout << (sum1 + sum2 + mod) % mod << endl;
  return 0;
}
