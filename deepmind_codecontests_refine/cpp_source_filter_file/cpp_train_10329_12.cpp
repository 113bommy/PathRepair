#include <bits/stdc++.h>
using namespace std;
long long mod = 1e9 + 7;
const int N = 1e6 + 10;
long long factorial[N];
long long power(long long a, long long b) {
  if (b < 0) return 1;
  long long res = 1;
  while (b) {
    if (b & 1) res = res * a % mod;
    a = a * a % mod;
    b >>= 1;
  }
  return res;
}
long long mod_inv(long long n) { return power(n, mod - 2); }
long long nck(long long n, long long a) {
  if (n < a) return 0;
  long long top = factorial[n];
  long long bot = mod_inv(factorial[a]) * mod_inv(factorial[n - a]);
  bot %= mod;
  long long res = top * bot % mod;
  return res;
}
void init() {
  factorial[0] = 1;
  for (int i = 1; i < N; i++) {
    factorial[i] = factorial[i - 1] * i;
    factorial[i] %= mod;
  }
}
int main() {
  cin.tie(0);
  cin.sync_with_stdio(0);
  int n, m;
  cin >> n >> m;
  mod = m;
  init();
  long long ans = 0;
  for (int i = 0; i < n; i++) {
    long long order = factorial[i + 1];
    long long rem = factorial[n - i - 1];
    long long tmp = (n - i) * (n - i) % mod;
    tmp *= order;
    tmp %= mod;
    tmp *= rem;
    tmp %= mod;
    ans += tmp;
    ans %= mod;
  }
  cout << ans;
}
