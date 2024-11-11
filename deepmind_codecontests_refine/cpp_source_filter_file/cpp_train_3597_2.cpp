#include <bits/stdc++.h>
using namespace std;
template <typename T>
inline void Read(T &n) {
  char ch;
  bool flag = 0;
  while (!isdigit(ch = getchar()))
    if (ch == '-') flag = 1;
  for (n = ch ^ 48; isdigit(ch = getchar());
       n = (n << 1) + (n << 3) + (ch ^ 48))
    ;
  if (flag) n = -n;
}
enum { MAXN = 1505, MOD = 1000000007 };
inline int inc(int a, int b) {
  a += b;
  if (a >= MOD) a -= MOD;
  return a;
}
inline void iinc(int &a, int b) { a = inc(a, b); }
inline void iinc(int &a, long long b) { a = (a + b) % MOD; }
inline int dec(int a, int b) {
  a -= b;
  if (a < 0) a += MOD;
  return a;
}
inline void ddec(int &a, int b) { a = dec(a, b); }
inline int ksm(int base, int k = MOD - 2) {
  int res = 1;
  while (k) {
    if (k & 1) res = 1ll * res * base % MOD;
    base = 1ll * base * base % MOD;
    k >>= 1;
  }
  return res;
}
int g[MAXN], sr[2][MAXN], ssr[2][MAXN], S1[MAXN], S2[MAXN];
int n, m, k, p;
int main() {
  Read(n);
  Read(m);
  int pp;
  Read(p);
  Read(pp);
  p = 1ll * p * ksm(pp) % MOD;
  Read(k);
  if (k == 0) return puts("1"), 0;
  g[0] = ksm(dec(1, p), k);
  for (register int i = 1; i <= k and i <= m; i++)
    g[i] = 1ll * g[i - 1] * p % MOD * ksm(dec(1, p)) % MOD * (k - i + 1) % MOD *
           ksm(i) % MOD;
  ssr[0][m] = 1;
  for (register int i = 1; i <= m; i++) S1[i] = inc(S1[i - 1], g[i - 1]);
  for (register int i = 1; i <= n; i++) {
    char opt = i & 1, prv = opt ^ 1;
    for (register int j = 1; j <= m; j++)
      sr[opt][j] = dec(1ll * dec(ssr[prv][m], ssr[prv][m - j]) * g[m - j] %
                           MOD * S1[j] % MOD,
                       1ll * g[m - j] * S2[j] % MOD),
      ssr[opt][j] = inc(ssr[opt][j - 1], sr[opt][j]),
      S2[j] = (S2[j - 1] + 1ll * g[j - 1] * ssr[opt][j - 1]) % MOD;
  }
  cout << ssr[n & 1][m] << endl;
  return 0;
}
