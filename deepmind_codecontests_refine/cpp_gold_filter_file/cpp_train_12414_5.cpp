#include <bits/stdc++.h>
long long gcd(long long m, long long n) { return n == 0 ? m : gcd(n, m % n); }
long long lcm(long long m, long long n) { return m * n / gcd(m, n); }
long long pows(long long base, long long power, long long mod) {
  long long result = 1;
  while (power > 0) {
    if (power & 1) {
      result = result * base % mod;
    }
    power >>= 1;
    base = (base * base) % mod;
  }
  return result;
}
long long poww(long long base, long long power) {
  long long result = 1;
  while (power > 0) {
    if (power & 1) {
      result = result * base;
    }
    power >>= 1;
    base = (base * base);
  }
  return result;
}
const long long inf = 1e9;
const long long MAX = 1e18;
const int N = 6e5 + 10 + 10;
const int M = 1e9 + 10;
const long long mod = 1e9 + 7;
using namespace std;
long long arr[N];
long long n, a, b, c;
long long ans = MAX, pd;
long long check(long long x) {
  long long z = 0, f = 0;
  for (long long i = 1; i <= n; i++) {
    long long fs = arr[i] - x;
    if (fs < 0)
      f += abs(fs);
    else
      z += fs;
  }
  long long sum = MAX;
  if (z == 0 && f == 0) sum = 0;
  sum = min(sum, f * a + z * b);
  long long fgq = min(z, f);
  long long zs = z - fgq, fs = f - fgq;
  fgq = fgq * c;
  fgq += zs * b + fs * a;
  sum = min(sum, fgq);
  ans = min(sum, ans);
  return sum;
}
int main() {
  scanf("%lld %lld %lld %lld", &n, &a, &b, &c);
  long long l = 0, r = inf;
  long long mx = 0;
  for (long long i = 1; i <= n; i++) scanf("%lld", &arr[i]), r = max(r, arr[i]);
  mx = r;
  sort(arr + 1, arr + 1 + n);
  while (l < r) {
    long long ls = (l + ((r - l) / 3));
    long long rs = (r - ((r - l) / 3));
    if (check(ls) > check(rs)) {
      l = ls + 1;
    } else {
      r = rs - 1;
    }
  }
  printf("%lld\n", ans);
  return 0;
}
