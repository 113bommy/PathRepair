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
long long int A[1000010], B[1000010], C[1000010];
int main() {
  long long int T, i, p, j, l, n, e, r, b, c, k, m, q, a, d, w, x, y, u, v, z,
      t, curr, prev, sum, ans, pos, val, countA, indicator;
  scanf("%lld", &n);
  for (long long int i = (1); i <= (n); ++i) scanf("%lld", &A[i]);
  ans = 0;
  for (long long int i = (1); i <= (n); ++i) {
    if (C[i] == 1) continue;
    curr = i;
    countA = 0;
    while (C[curr] != 1) {
      countA++;
      C[curr] = 1;
      curr = A[curr];
    }
    ans += countA - 1;
  }
  if (ans % 2 == n % 2)
    printf("Petr\n");
  else
    printf("Um_nik\n");
  return 0;
}
