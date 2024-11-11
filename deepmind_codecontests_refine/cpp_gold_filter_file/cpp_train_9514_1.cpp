#include <bits/stdc++.h>
using namespace std;
const int mod = 1e9 + 7;
double rast(int x1, int y1, int x2, int y2) {
  return sqrt((x2 - x1) * (x2 - x1) + (y2 - y1) * (y2 - y1));
}
bool OK(int x, int a, int b) {
  bool res = true;
  while (x) {
    res &= (x % 10 == a || x % 10 == b);
    x /= 10;
  }
  return res;
}
long long fact[1000005];
int bin_pow(long long x, int st) {
  long long ans = 1;
  while (st) {
    if (st & 1) {
      ans *= x;
      ans %= mod;
    }
    x *= x;
    x %= mod;
    st /= 2;
  }
  return ans;
}
int C(int n, int i) {
  return fact[n] * bin_pow(fact[i] * fact[n - i] % mod, mod - 2) % mod;
}
int main() {
  ios_base::sync_with_stdio(false);
  int a, b, n;
  cin >> a >> b >> n;
  fact[0] = 1;
  for (int i = 1; i <= 1000000; i++) fact[i] = (fact[i - 1] * i) % mod;
  long long ans = 0;
  for (int i = 0; i <= n; i++) {
    int j = n - i;
    if (OK(i * a + j * b, a, b)) ans = (ans + C(n, i)) % mod;
  }
  cout << ans;
}
