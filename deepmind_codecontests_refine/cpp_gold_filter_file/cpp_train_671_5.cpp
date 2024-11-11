#include <bits/stdc++.h>
#pragma comment(linker, "/STACK:256000000")
using namespace std;
const long long mod = 1000000007;
const int NMAX = 100005;
int n, k;
long long fact[NMAX];
long long inv[NMAX];
long long p10[NMAX];
long long cpk[NMAX], cpk1[NMAX];
long long gcd(long long a, long long b, long long &x, long long &y) {
  if (b == 0) {
    x = 1;
    y = 0;
    return a;
  } else {
    long long x0, y0;
    long long d = gcd(b, a % b, x0, y0);
    x = y0;
    y = x0 - (a / b) * y0;
    return d;
  }
}
long long cnk(long long n, long long k) {
  return (((fact[n] * inv[n - k]) % mod) * inv[k]) % mod;
}
long long inverse(long long a) {
  long long x, y;
  gcd(a, mod, x, y);
  return ((x % mod) + mod) % mod;
}
void init() {
  fact[0] = 1;
  for (int i = 1; i <= int(NMAX - 1); i++) fact[i] = (fact[i - 1] * i) % mod;
  for (int i = 0; i < int(NMAX); i++) inv[i] = inverse(fact[i]);
  p10[0] = 1;
  for (int i = 1; i <= int(NMAX - 1); i++) p10[i] = (p10[i - 1] * 10) % mod;
  for (int p = k; p < NMAX; p++) cpk[p] = cnk(p, k);
  for (int p = k + 1; p < NMAX; p++) cpk1[p] = cnk(p, k + 1);
}
string s;
int c[NMAX];
int main() {
  scanf("%d %d\n", &n, &k);
  getline(cin, s);
  for (int i = 0; i < int(s.size()); i++) c[i] = s[i] - '0';
  if (k == 0) {
    long long ans = 0;
    for (int i = 0; i < int(n); i++) ans = (ans * 10 + c[i]) % mod;
    cout << ans << endl;
    return 0;
  }
  k--;
  init();
  long long sum = 0;
  long long ans = 0;
  for (int p = n - 1; p >= 0; p--) {
    if (p < n - 1 && p >= k) sum = (sum + cpk[p] * p10[n - p - 2]) % mod;
    if (p > k) ans = (ans + c[p] * ((cpk1[p] * p10[n - p - 1]) % mod)) % mod;
    ans = (ans + c[p] * sum) % mod;
  }
  cout << ans << endl;
  return 0;
}
