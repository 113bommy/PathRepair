#include <bits/stdc++.h>
using namespace std;
const int INFI = 1 << 28;
const long long int INFL = 1LL << 60;
const double INFD = 1e+300;
const float INFF = 1e+100;
const double EPS = 1e-8;
int extgcd(int a, int b, int &x, int &y) {
  int d = a;
  if (b != 0) {
    d = extgcd(b, a % b, y, x);
    y -= (a / b) * x;
  } else {
    x = 1;
    y = 0;
  }
  return d;
}
int mod_inverse(int a, int m) {
  int x, y;
  extgcd(a, m, x, y);
  return (m + x % m) % m;
}
int main() {
  cout.setf(ios::fixed);
  cout.precision(10);
  ios_base::sync_with_stdio(false);
  long long a, b;
  cin >> a >> b;
  long long ans = 0;
  const long long MOD = 1000000007LL;
  const long long inv_2 = mod_inverse(2, MOD);
  for (int i = 1; i < b; i++) {
    long long h = a * i % MOD;
    ans += (a * i % MOD) + (a * (a + 1) / 2 % MOD * b * i % MOD) % MOD;
    ans %= MOD;
  }
  cout << ans << endl;
  return 0;
}
