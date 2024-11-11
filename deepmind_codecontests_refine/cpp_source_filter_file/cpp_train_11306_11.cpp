#include <bits/stdc++.h>
using namespace std;
const int MAXSIZE = 10000020;
const int mod = 998244353;
int bufpos;
char buf[MAXSIZE];
void init() {
  buf[fread(buf, 1, MAXSIZE, stdin)] = ' ';
  bufpos = 0;
}
int readint() {
  int val = 0;
  for (; !isdigit(buf[bufpos]); bufpos++)
    ;
  for (; isdigit(buf[bufpos]); bufpos++) val = val * 10 + buf[bufpos] - '0';
  return val;
}
char readchar() {
  for (; isspace(buf[bufpos]); bufpos++)
    ;
  return buf[bufpos++];
}
int readstr(char* s) {
  int cur = 0;
  for (; isspace(buf[bufpos]); bufpos++)
    ;
  for (; !isspace(buf[bufpos]); bufpos++) s[cur++] = buf[bufpos];
  s[cur] = '\0';
  return cur;
}
long long power(long long x, long long y) {
  long long ans = 1;
  while (y) {
    if (y & 1) ans = ans * x % mod;
    x = x * x % mod;
    y >>= 1;
  }
  return ans;
}
const int maxn = (1 << 20) + 2;
struct fft {
  int n, k;
  int bitrev[maxn];
  long long omega[maxn];
  void init(int l) {
    n = 1;
    while (n <= l) n <<= 1, k++;
    omega[0] = 1;
    long long wn = power(3, (mod - 1) / n);
    for (int i = 1; i < n; i++) {
      omega[i] = omega[i - 1] * wn % mod;
      bitrev[i] = (bitrev[i >> 1] >> 1) | ((i & 1) << (k - 1));
    }
  }
  long long wn[maxn];
  void trans(long long* a, bool rev) {
    for (int i = 0; i < n; i++)
      if (bitrev[i] < i) swap(a[bitrev[i]], a[i]);
    for (int i = 1, qwq = k - 1; i < n; i <<= 1, qwq--) {
      for (int j = 0; j < i; j++) wn[j] = omega[j << qwq];
      for (int j = 0; j < n; j += (i << 1))
        for (int k = j; k < j + i; k++) {
          long long t = wn[k - j] * a[k + i];
          a[k + i] = (a[k] - t) % mod;
          a[k] = (a[k] + t) % mod;
        }
    }
    if (rev) {
      long long inv = power(n, mod - 2);
      for (int i = 0; i < n; i++) a[i] = a[i] * inv % mod;
      reverse(a + 1, a + n);
    }
  }
  void test() {
    init(8);
    static long long a[maxn], b[maxn];
    a[0] = 1, a[1] = 2, a[2] = 1;
    b[0] = 1, b[1] = 1;
    trans(a, 0);
    trans(b, 0);
    for (int i = 0; i < n; i++) a[i] = a[i] * b[i] % mod;
    trans(a, 1);
    for (int i = 0; i <= 5; i++) printf("%lld ", (a[i] % mod + mod) % mod);
  }
} t;
char s[maxn];
long long f[maxn], g[maxn];
bool chk[maxn];
int stk[maxn], tp;
int main() {
  init();
  int T = readint();
  while (T--) {
    int n = readint();
    readstr(s + 1);
    t.init(n * 2 + 2);
    memset(f, 0, t.n * 8);
    memset(g, 0, t.n * 8);
    for (int i = 1; i <= n; i++)
      if (s[i] == 'V')
        f[i] = 1;
      else if (s[i] == 'K')
        g[n + 1 - i] = 1;
    t.trans(f, 0);
    t.trans(g, 0);
    for (int i = 0; i < t.n; i++) f[i] = f[i] * g[i] % mod;
    t.trans(f, 1);
    for (int i = 0; i <= n; i++) chk[i] = !f[n + 1 - i] && !f[n + 1 + i];
    tp = 0;
    for (int i = 1; i < n; i++) {
      for (int j = i; j <= n; j += i) chk[i] &= chk[j];
      if (chk[i]) stk[++tp] = i;
    }
    stk[++tp] = n;
    printf("%d\n", tp);
    for (int i = 1; i <= tp; i++) printf("%d%c", stk[i], " \n"[i == tp]);
  }
}
