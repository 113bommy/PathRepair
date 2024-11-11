#include <bits/stdc++.h>
using namespace std;
const int Imx = 2147483647;
const long long Lbig = 2e18;
const int mod = 1e9 + 7;
struct fastio {
  char s[100000];
  int it, len;
  fastio() { it = len = 0; }
  inline char get() {
    if (it < len) return s[it++];
    it = 0;
    len = fread(s, 1, 100000, stdin);
    if (len == 0)
      return EOF;
    else
      return s[it++];
  }
  bool notend() {
    char c = get();
    while (c == ' ' || c == '\n') c = get();
    if (it > 0) it--;
    return c != EOF;
  }
} _buff;
inline long long getnum() {
  long long r = 0;
  bool ng = 0;
  char c;
  c = _buff.get();
  while (c != '-' && (c < '0' || c > '9')) c = _buff.get();
  if (c == '-') ng = 1, c = _buff.get();
  while (c >= '0' && c <= '9') r = r * 10 + c - '0', c = _buff.get();
  return ng ? -r : r;
}
template <class T>
inline void putnum(T x) {
  if (x < 0) putchar('-'), x = -x;
  register short a[20] = {}, sz = 0;
  while (x) a[sz++] = x % 10, x /= 10;
  if (sz == 0) putchar('0');
  for (int i = sz - 1; i >= 0; i--) putchar('0' + a[i]);
}
inline char getreal() {
  char c = _buff.get();
  while (c <= 32) c = _buff.get();
  return c;
}
long long qpow(long long x, long long k) {
  return k == 0 ? 1
                : 1ll * qpow(1ll * x * x % mod, k >> 1) * (k & 1 ? x : 1) % mod;
}
const int maxn = 2000111;
int n;
char s[maxn], t[1000111];
int tot, go[maxn][26], len[maxn], par[maxn], slink[maxn], diff[maxn];
int gpl[maxn], dp[maxn];
int append(int n, int p, char c) {
  int ic = c - 'a';
  while (s[n - len[p] - 1] != c) p = par[p];
  if (!go[p][ic]) {
    int q = ++tot;
    len[q] = len[p] + 2;
    int t = par[p];
    while (s[n - len[t] - 1] != c) t = par[t];
    par[q] = go[t][ic];
    go[p][ic] = q;
    diff[q] = len[q] - len[par[q]];
    slink[q] = diff[q] == diff[par[q]] ? slink[par[q]] : par[q];
  }
  return go[p][ic];
}
void upd(int &x, int v) { x = x + v >= mod ? x + v - mod : x + v; }
int main() {
  par[0] = tot = 1;
  len[1] = -1;
  scanf("%s", s + 1);
  n = strlen(s + 1);
  for (int i = 1; i <= n; i++) t[i] = s[n - i + 1];
  for (int i = n; i >= 1; i--) s[(i << 1) - 1] = s[i];
  for (int i = 1; i <= n; i++) s[(i << 1)] = t[i];
  int st = 0;
  dp[0] = 1;
  for (int i = 1; i <= n; i++) {
    dp[i] = 0;
    st = append(i, st, s[i]);
    for (int p = st; p; p = slink[p]) {
      int lst = i - len[slink[p]] - diff[p];
      gpl[p] = dp[lst];
      if (diff[par[p]] == diff[p]) upd(gpl[p], gpl[par[p]]);
      if (!(i & 1)) upd(dp[i], gpl[p]);
    }
  }
  cout << dp[n] << endl;
  return 0;
}
