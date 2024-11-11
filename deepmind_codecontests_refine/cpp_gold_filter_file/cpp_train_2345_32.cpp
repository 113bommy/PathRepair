#include <bits/stdc++.h>
using namespace std;
long long mod = 1e9 + 7;
inline long long int sqr(long long int x) { return x * x; }
long long int one, zero, ansR, numNodes;
long long int powP(long long int a, long long int b) {
  if (b == 0) return 1 % mod;
  long long int k;
  k = powP(a, b / 2);
  k = k * k % mod;
  if (b % 2 == 0)
    return k;
  else
    return a * k % mod;
}
int main() {
  long long int T, i, j, h, l, r, k, s, a, b, c, d, q, p, n, m, w, x, y, v, z,
      t, curr, prev, sum, ans, pos, val, countA, secondMin, indicator;
  t = 2520;
  scanf("%lld", &n);
  printf("%lld\n", (n) / t);
  return 0;
}
