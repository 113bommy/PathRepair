#include <bits/stdc++.h>
using namespace std;
const long long m = 998244353;
long long extgcd(long long a, long long b, long long &x, long long &y) {
  long long d = a;
  if (b != 0) {
    d = extgcd(b, a % b, y, x);
    y -= (a / b) * x;
  } else {
    x = 1;
    y = 0;
  }
  return d;
}
long long mod_inverse(long long a) {
  long long x, y;
  extgcd(a, m, x, y);
  return (m + x % m) % m;
}
const int N = 1e6 + 10;
long long fact[N];
long long C(int n, int k) {
  return fact[n] * mod_inverse(fact[n - k]) % m * mod_inverse(fact[k]) % m;
}
long long reg(long long x) { return (m + x % m) % m; }
void add(long long &a, long long b) {
  a += b;
  a = (m + a % m) % m;
}
long long Pow(long long x, long long n) {
  long long res = 1;
  while (n > 0) {
    if (n & 1) res = res * x % m;
    x = x * x % m;
    n >>= 1;
  }
  return res;
}
int get(int i) { return i % 2 == 0 ? 1 : -1; }
int main() {
  fact[0] = 1;
  for (int i = 1; i < N; i++) fact[i] = fact[i - 1] * i % m;
  int n;
  scanf("%d", &n);
  if (n == 1) {
    puts("3");
    return 0;
  }
  long long ans = 0;
  for (int i = 0; i < n; i++) {
    long long temp = Pow(reg(-Pow(3, i) + 1), n);
    add(temp, get(n + 1) * Pow(Pow(3, i), n));
    add(ans, (i % 2 == 0 ? -1 : 1) * (3 * C(n, i) % m * temp % m));
  }
  for (int i = 1; i <= n; i++)
    add(ans, (i % 2 == 0 ? -1 : 1) * 2 *
                 (C(n, i) * Pow(3, i + (long long)n * (n - i)) % m));
  printf("%lld\n", ans);
}
