#include <bits/stdc++.h>
using namespace std;
const int INF = 0x3f3f3f3f;
const int MAXN = 5e5 + 50;
const long long LINF = 0x3f3f3f3f3f3f3f3f;
const long long MOD = 1e9 + 7;
const double EPS = 1e-6;
const double Pi = acos(-1);
void test() { cerr << "\n"; }
template <typename T, typename... Args>
void test(T x, Args... args) {
  cerr << x << " ";
  test(args...);
}
long long qpow(long long a, long long b) {
  return b ? ((b & 1) ? a * qpow(a * a % MOD, b >> 1) % MOD
                      : qpow(a * a % MOD, b >> 1)) %
                 MOD
           : 1;
}
long long qpow(long long a, long long b, long long c) {
  return b ? ((b & 1) ? a * qpow(a * a % c, b >> 1) % c
                      : qpow(a * a % c, b >> 1)) %
                 c
           : 1;
}
long long gcd(long long a, long long b) { return b ? gcd(b, a % b) : a; }
int sign(double x) { return x < -EPS ? -1 : x > EPS; }
int dbcmp(double l, double r) { return sign(l - r); }
long long a[MAXN];
int mi[MAXN];
int tot[33];
int main() {
  int n;
  scanf("%d", &n);
  int maxv = 0, maxi = 0;
  for (int i = 1; i <= n; i++) {
    long long x;
    scanf("%lld", &x);
    a[i] = x;
    int cnt = 0;
    while (x % 2 == 0) {
      x /= 2;
      cnt++;
    }
    tot[cnt]++;
    mi[i] = cnt;
    if (maxv < tot[cnt]) {
      maxi = cnt;
      maxv = tot[cnt];
    }
  }
  printf("%d\n", n - maxv);
  for (int i = 1; i <= n; i++)
    if (mi[i] != maxi) printf("%lld ", a[i]);
}
