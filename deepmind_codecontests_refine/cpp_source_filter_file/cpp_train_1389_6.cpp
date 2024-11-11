#include <bits/stdc++.h>
using namespace std;
const long long N = 4e5 + 10;
const long long MOD = 1e9 + 7;
long long k;
long long nxt[N], cnt, f[N];
char s[N], t[N], t1[N], t2[N];
long long Add(long long x, long long y) {
  return x + y >= MOD ? x + y - MOD : x + y;
}
long long Mul(long long x, long long y) { return 1LL * x * y % MOD; }
struct Matrix {
  static const long long SIZ = 2;
  long long m[SIZ][SIZ];
  Matrix() { memset(m, 0, sizeof(m)); }
  void eye() {
    for (long long i = 0; i < SIZ; i++) m[i][i] = 1;
  }
  friend Matrix operator*(Matrix a, Matrix b) {
    Matrix c;
    for (long long i = 0; i < SIZ; i++)
      for (long long k = 0; k < SIZ; k++) {
        if (!a.m[i][k]) continue;
        for (long long j = 0; j < SIZ; j++)
          c.m[i][j] = Add(c.m[i][j], Mul(a.m[i][k], b.m[k][j]));
      }
    return c;
  }
  friend Matrix operator^(Matrix a, long long b) {
    Matrix c;
    c.eye();
    for (; b; b >>= 1, a = a * a)
      if (b & 1) c = c * a;
    return c;
  }
} g, res;
void print(char *s) {
  long long n = strlen(s + 1);
  for (long long i = 1; i <= n; i++) putchar(s[i]);
  putchar('\n');
}
void init(long long n) {
  long long i;
  f[1] = 1;
  f[2] = 1;
  for (i = 3; f[i - 1] <= n; i++) f[i] = f[i - 1] + f[i - 2];
  cnt = i - 1;
  t[1] = 'b';
  t[2] = 'a';
  for (long long i = 3; i <= cnt; i++) {
    for (long long j = f[i] + 1; j <= f[i] + f[i - 1]; j++) t[j] = t[j - f[i]];
  }
}
void KMP(char *s) {
  long long n = strlen(s + 1), j = 0;
  nxt[1] = 0;
  for (long long i = 1; i < n; i++) {
    while (j && s[i + 1] != s[j + 1]) j = nxt[j];
    if (s[i + 1] == s[j + 1]) j++;
    nxt[i + 1] = j;
  }
}
long long calc(char *t, long long len) {
  long long m = strlen(s + 1), j = 0, res = 0;
  for (long long i = 0; i < len; i++) {
    while (j && s[j + 1] != t[i + 1]) j = nxt[j];
    if (s[j + 1] == t[i + 1]) j++;
    if (j == m) res++;
  }
  return res;
}
long long get_fib(long long n) {
  if (n <= 0) return 0;
  if (n <= 2) return 1;
  res.m[0][0] = res.m[1][0] = 1;
  g.m[0][0] = 1;
  g.m[0][1] = 1;
  g.m[1][0] = 1;
  g.m[1][1] = 0;
  g = g ^ (n - 2);
  res = g * res;
  return res.m[0][0] - (n & 1);
}
long long cal(long long n, long long a, long long b) {
  if (n <= 0) return 0;
  if (n == 1) return a;
  if (n == 2) return b;
  res.m[0][0] = b;
  res.m[1][0] = a;
  g.m[0][0] = 1;
  g.m[0][1] = 1;
  g.m[1][0] = 1;
  g.m[1][1] = 0;
  g = g ^ (n - 2);
  res = g * res;
  return res.m[0][0];
}
long long solve() {
  long long m = strlen(s + 1);
  long long p = lower_bound(f + 1, f + cnt + 1, m) - f;
  KMP(s);
  p = max(p + 1, 3LL);
  if (k == 1) return m == 1 && s[1] == 'a';
  if (k == 2) return m == 1 && s[1] == 'b';
  if (k <= cnt) return calc(t, f[k]);
  for (long long i = 1; i < m; i++) t1[i] = t[f[p - 1] - m + 1 + i];
  for (long long i = 1; i < m; i++) t1[m + i - 1] = t[i];
  for (long long i = 1; i < m; i++) t2[i] = t[f[p] - m + 1 + i];
  for (long long i = 1; i < m; i++) t2[m + i - 1] = t[i];
  long long v1 = calc(t1, m * 2 - 2), v2 = calc(t2, m * 2 - 2);
  long long A = cal(k - p + 2, calc(t, f[p - 1]), calc(t, f[p]));
  long long B = get_fib(k - p), C = get_fib(k - p + 1);
  return Add(Add(A, Mul(v1, B)), Mul(v2, C));
}
int main() {
  long long m;
  scanf("%lld%lld", &k, &m);
  init(1e5);
  for (long long i = 1; i <= m; i++) {
    scanf("%s", s + 1);
    printf("%lld\n", solve());
  }
  return 0;
}
