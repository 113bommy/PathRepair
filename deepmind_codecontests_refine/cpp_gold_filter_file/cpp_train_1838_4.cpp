#include <bits/stdc++.h>
using namespace std;
const long long mod = 1000000007;
long long powmod(long long a, long long b) {
  long long res = 1;
  a %= mod;
  assert(b >= 0);
  for (; b; b >>= 1) {
    if (b & 1) res = res * a % mod;
    a = a * a % mod;
  }
  return res;
}
long long gcd(long long a, long long b) { return b ? gcd(b, a % b) : a; }
int getInt() {
  int x;
  scanf("%d", &x);
  return x;
}
long long getLong() {
  long long x;
  cin >> x;
  return x;
}
double getDouble() {
  double x;
  scanf("%lf", &x);
  return x;
}
int f(long long p, int k) {
  int t = p % k;
  t += t < 0 ? k : 0;
  return t % k;
}
int main() {
  long long p = getLong();
  int k = getInt();
  int c = 0, a[200];
  while (p) {
    int m = f(p, k);
    ++c;
    a[c] = m;
    p -= m;
    p /= (k * (-1));
  }
  printf("%d\n", c);
  for (int i = 1; i < c + 1; i++) {
    printf("%d ", a[i]);
  }
}
