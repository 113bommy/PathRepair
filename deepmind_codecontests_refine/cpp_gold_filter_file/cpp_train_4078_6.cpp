#include <bits/stdc++.h>
using namespace std;
long double pi = 3.14159265358979323;
const double EPS = 1e-12;
const int N = 1e6 + 5;
const int mod = 998244353;
long long mul(long long x, long long y) {
  return ((x % mod) * (y % mod)) % mod;
}
long long powermod(long long x, long long y) {
  long long ans = 1;
  while (y) {
    if (y & 1) ans = mul(ans, x);
    x = mul(x, x);
    y /= 2;
  }
  return ans % mod;
}
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(NULL);
  cout.tie(NULL);
  long long w, h;
  cin >> w >> h;
  cout << mul(powermod(2, w), powermod(2, h));
  return 0;
}
