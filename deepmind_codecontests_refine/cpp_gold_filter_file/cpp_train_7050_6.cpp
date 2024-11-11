#include <bits/stdc++.h>
using namespace std;
const int MAXN = 200200;
const long long MOD = (int)1e9 + 7;
const long long INF = (long long)2e18;
const int C = 2e4 + 10;
long long add(long long a, long long b) { return (a + b) % MOD; }
long long sub(long long a, long long b) {
  a -= b;
  a %= MOD;
  if (a < 0) a += MOD;
  return a;
}
long long mult(long long a, long long b) { return (a * b) % MOD; }
long long bin_pow(long long a, long long n) {
  long long res = 1;
  while (n) {
    if (n & 1) res = mult(res, a);
    a = mult(a, a);
    n /= 2;
  }
  return res;
}
long long divide(long long a, long long b) {
  return mult(a, bin_pow(b, MOD - 2));
}
bool is_inf(long long a, long long b) {
  if ((long double)a * b > 2 * INF) return true;
  return a * b > INF;
}
int n;
long long a[MAXN];
int nxt[MAXN];
void solve() {
  long long k;
  scanf("%d%lld", &n, &k);
  for (int i = 0; i < n; ++i) scanf("%lld", &a[i]);
  nxt[n] = n;
  for (int i = n - 1; i >= 0; --i) {
    if (a[i] != 1)
      nxt[i] = i;
    else
      nxt[i] = nxt[i + 1];
  }
  long long ans = 0;
  for (int i = 0; i < n; ++i) {
    long long p = a[i];
    long long s = a[i] * k;
    for (int j = i + 1; j <= n; ++j) {
      if (p == s) ++ans;
      if (j == n) break;
      if (is_inf(p, a[j])) break;
      if (a[j] == 1) {
        long long len = nxt[j] - j;
        if (p > s && p < s + len * k) {
          if ((p - s) % k == 0) ++ans;
        }
        s += len * k;
        j = nxt[j] - 1;
        continue;
      }
      p *= a[j];
      s += a[j] * k;
    }
  }
  printf("%lld\n", ans);
}
int main() {
  solve();
  return 0;
}
