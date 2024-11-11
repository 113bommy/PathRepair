#include <bits/stdc++.h>
using namespace std;
const int N = 2005;
const int M = 101;
const double EPS = 1e-9;
const int INF = 1e9;
long long gcd(long long a, long long b) { return b == 0 ? a : gcd(b, a % b); }
long long lcm(long long a, long long b) { return a * b / gcd(a, b); }
double getDist(complex<double> a, complex<double> b) {
  return sqrt((a.real() - b.real()) * (a.real() - b.real()) +
              (a.imag() - b.imag()) * (a.imag() - b.imag()));
}
int dcmp(double x, double y) { return fabs(x - y) <= EPS ? 0 : x < y ? -1 : 1; }
long long mod = 1000000007, fib[N], dp[N][N];
long long power(long long base, int p) {
  if (!p) return 1;
  long long ret = power(base, p / 2);
  ret *= ret;
  ret %= mod;
  if (p & 1) ret *= base, ret %= mod;
  return ret;
}
long long modInverse(int a) { return power(a, mod - 2); }
long long ncr(int n, int r) {
  return (((fib[n] * modInverse(fib[r])) % mod) * modInverse(fib[n - r])) % mod;
}
bool emty[N], taken[N];
long long solve(int n, int k) {
  if (k == 0) return fib[n];
  if (k == 1) return (fib[n] * n) % mod;
  if (dp[n][k] != -1) return dp[n][k];
  long long ret =
      (solve(n, k - 1) * n) % mod + (solve(n + 1, k - 2) * (k - 1)) % mod;
  return dp[n][k] = ret;
}
int main() {
  fib[0] = fib[1] = 1;
  for (int i = 2; i < N; i++) fib[i] = (fib[i - 1] * i) % mod;
  int n, free = 0, k = 0;
  scanf("%d", &n);
  for (int i = 1; i <= n; i++) {
    int a;
    scanf("%d", &a);
    if (a == -1)
      emty[i] = 1;
    else
      taken[a] = 1;
  }
  for (int i = 1; i <= n; i++) {
    if (emty[i] == 1) {
      if (taken[i] == 1)
        free++;
      else
        k++;
    }
  }
  memset(dp, -1, sizeof(dp));
  cout << solve(free, k);
  return 0;
}
