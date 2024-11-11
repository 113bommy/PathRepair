#include <bits/stdc++.h>
using namespace std;
const int maxn = 66, maxm = 200006, maxs = 65536,
          pr[] = {2, 3, 5, 7, 11, 13, 17, 19};
int n, P, a[maxm], b[maxm], f[maxs], s1[maxn], s2[maxn];
long long X, Y, ans, p[maxn];
long long mul(long long x, long long y, long long MOD) {
  x %= MOD;
  y %= MOD;
  return ((x * y - (long long)((long double)x / MOD * y) * MOD) % MOD + MOD) %
         MOD;
}
long long power(long long x, long long y, long long MOD) {
  long long w = x, sum = 1;
  while (y) {
    if (y & 1) sum = mul(sum, w, MOD);
    w = mul(w, w, MOD);
    y >>= 1;
  }
  return sum;
}
bool MR(long long N) {
  for (int i = 0; i < 8; i++)
    if (!(N % pr[i])) return N == pr[i];
  for (int t = 0; t < 8; t++) {
    int k = 0;
    long long x, s;
    for (x = N - 1; !(x & 1); x >>= 1, k++)
      ;
    x = power(rand() % (N - 3) + 2, x, N);
    if (x == 1) continue;
    for (; k; k--, x = s) {
      s = mul(x, x, N);
      if (s == 1) {
        if (x < N - 1) return 0;
        break;
      }
    }
    if (s != 1) return 0;
  }
  return 1;
}
long long AMOD(long long& x, long long tem, long long MOD) {
  if ((x += tem) >= MOD) x -= MOD;
}
long long gcd(long long x, long long y) { return !y ? x : gcd(y, x % y); }
long long _abs(long long x) { return x > 0 ? x : -x; }
long long findD(long long N) {
  long long x = rand() % (N - 1) + 1, y = x, r = rand() % (N - 1) + 1;
  for (int i = 1, k = 1;; i++) {
    AMOD(x = mul(x, x, N), r, N - 1);
    x++;
    if (x == y) return -1;
    long long t = gcd(_abs(x - y), N);
    if (t > 1) return t;
    if (i == k) k <<= 1, y = x;
  }
}
void PR(long long N) {
  if (N == 1) return;
  if (MR(N)) {
    p[++P] = N;
    return;
  }
  long long D;
  for (D = findD(N); D < 0; D = findD(N))
    ;
  PR(D);
  PR(N / D);
}
int main() {
  scanf("%d%lld%lld", &n, &X, &Y);
  if (Y % X) return printf("0"), 0;
  PR(Y);
  sort(p + 1, p + 1 + p[0]);
  P = unique(p + 1, p + 1 + P) - p - 1;
  long long tem = X;
  for (int i = 1; i <= P; i++)
    if (!(tem % p[i]))
      while (!(tem % p[i])) s1[i]++, tem /= p[i];
  tem = Y;
  for (int i = 1; i <= P; i++)
    if (!(tem % p[i]))
      while (!(tem % p[i])) s2[i]++, tem /= p[i];
  for (int i = 1; i <= n; i++) {
    long long x;
    scanf("%lld", &x);
    if (!(x % X)) {
      long long t = x;
      for (int j = 1; j <= P; j++)
        if (s1[j] < s2[j]) {
          int num = 0;
          while (!(t % p[j])) num++, t /= p[j];
          a[i] |= (num > s1[j]) << j - 1;
        }
    } else
      a[i] = -1;
    if (!(Y % x)) {
      long long t = x;
      for (int j = 1; j <= P; j++)
        if (s1[j] < s2[j]) {
          int num = 0;
          while (!(t % p[j])) num++, t /= p[j];
          b[i] |= (num < s2[j]) << j - 1;
        }
    } else
      b[i] = -1;
  }
  for (int i = 1; i <= n; i++)
    if (~b[i]) f[(~b[i]) & ((1 << P) - 1)]++;
  for (int j = 0; j < P; j++)
    for (int i = 0; i < 1 << P; i++)
      if (!((i >> j) & 1)) f[i] += f[i | (1 << j)];
  for (int i = 1; i <= n; i++)
    if (~a[i]) ans += f[a[i]];
  return printf("%lld", ans), 0;
}
