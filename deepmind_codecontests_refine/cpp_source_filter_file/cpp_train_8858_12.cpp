#include <bits/stdc++.h>
using namespace std;
long long mod = 1e9 + 7;
long long INF = 1e7;
double EPS = 1e-12;
double tick() {
  static clock_t oldt;
  clock_t newt = clock();
  double diff = 1.0 * (newt - oldt) / CLOCKS_PER_SEC;
  oldt = newt;
  return diff;
}
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
bool bitSet(long long int n, long long int i) {
  if ((n & (1LL << i)) != 0)
    return true;
  else
    return false;
}
long long int findGcd(long long int a, long long int b) {
  if (a == 0)
    return b;
  else
    return findGcd(b % a, a);
}
long long int A[300010], B[300010], C[300010], Taken[300010];
long long int X[300010], Y[300010];
int main() {
  long long int T, i, p, j, l, n, e, r, b, c, k, m, q, a, d, w, x, y, u, v, z,
      t, curr, prev, sum, ans, pos, val, countA, indicator;
  scanf("%lld", &n);
  for (long long int i = (1); i <= (n - 1); ++i) {
    scanf("%lld%lld", &a, &b);
    C[a]++;
    if (b != n) {
      printf("NO\n");
      return 0;
    }
  }
  long long int edges = 1;
  for (long long int i = (n - 1); i >= (1); --i) {
    long long int ind = 1;
    curr = n;
    while (ind < i and C[i] > 1) {
      if (C[ind] == 0 and Taken[ind] == 0) {
        C[i]--;
        Taken[ind] = 1;
        X[edges] = curr;
        Y[edges] = ind;
        edges++;
        curr = ind;
      }
      ind++;
    }
    if (C[i] > 1) {
      printf("NO\n");
      return 0;
    }
    if (C[i] == 1) {
      X[edges] = curr;
      Y[edges] = i;
      edges++;
    }
  }
  assert(edges == n);
  printf("YES\n");
  for (long long int i = (1); i <= (n - 1); ++i) {
    printf("%lld %lld\n", X[i], Y[i]);
  }
  return 0;
}
