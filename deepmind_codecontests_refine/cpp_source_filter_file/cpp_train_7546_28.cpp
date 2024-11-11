#include <bits/stdc++.h>
using namespace std;
const long long N = 1e5 + 9, mod = 1e9 + 7, inf = 1e17;
set<long long> getDivisors(long long val) {
  set<long long> st;
  for (long long i = 1; i < sqrt(val) + 1; i++)
    if (val % i == 0) st.insert(i), st.insert(val / i);
  return st;
}
long long gcdRecursive(long long a, long long b) {
  if (b == 0) return a;
  return gcdRecursive(b, a % b);
}
long long lcm(long long a, long long b) { return (a * b) / gcdRecursive(a, b); }
long long fact[N];
void pre(int n) {
  fact[0] = 1;
  for (int i = 1; i <= n; i++) {
    fact[i] = (i * fact[i - 1]) % mod;
  }
}
long long fastPower(long long b, long long p) {
  if (p == 0) return 1;
  long long hp = fastPower(b, p / 2);
  long long ret = hp * hp % mod;
  if (p % 2 != 0) ret *= b;
  return ret % mod;
}
void move1step(long long& a, long long& b, long long q) {
  long long next = a - q * b;
  a = b;
  b = next;
}
long long euclidGcd(long long a, long long b, long long& x0, long long& y0) {
  long long r0 = a, r1 = b;
  long long x1, y1;
  y0 = x1 = 0;
  x0 = y1 = 1;
  while (r1 != 0) {
    long long q = r0 / r1;
    move1step(x0, x1, q);
    move1step(y0, y1, q);
    move1step(r0, r1, q);
  }
  return r0;
}
long long modInv(long long c) {
  long long x, y;
  euclidGcd(c, mod, x, y);
  return (x + mod) % mod;
}
long long ncr(long long n, long long r) {
  return (fact[n] * modInv((fact[n - r] * fact[r]) % mod)) % mod;
}
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  pre(1e5 + 1);
  int n;
  cin >> n;
  cout << 2 * ncr(n + n - 1, n - 1) % mod - n << "\n";
}
