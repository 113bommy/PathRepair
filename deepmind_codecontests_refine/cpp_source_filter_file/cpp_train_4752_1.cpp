#include <bits/stdc++.h>
const int N = 1 << 20;
int v[N];
long long pwm(long long n, long long p, long long m) {
  long long ans = 1;
  for (long long tmp = n; p > 0; p >>= 1, tmp = (tmp * tmp) % m)
    if (p & 1) ans = (ans * tmp) % m;
  return ans;
}
long long inv(long long n, long long m) { return pwm(n, m - 2, m); }
int main() {
  long long a, b, p, x;
  scanf("%lld %lld %lld %lld", &a, &b, &p, &x);
  v[0] = 1;
  for (int i = 1; i < p - 1; i++) v[i] = a * v[i - 1];
  long long ans = 0;
  long long pp = p * (p - 1);
  for (int i = 0; i < p - 1; i++) {
    long long n = inv(v[i], p) * b % p;
    long long q = (i + (p - 1) * (i - n + p));
    ans += (x / pp) + (x % pp >= q % pp);
  }
  printf("%lld\n", ans);
  return 0;
}
