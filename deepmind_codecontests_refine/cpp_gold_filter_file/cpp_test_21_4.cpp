#include <bits/stdc++.h>
using namespace std;
template <typename T1, typename T2>
void chkmin(T1 &x, T2 y) {
  if (x > y) x = y;
}
template <typename T1, typename T2>
void chkmax(T1 &x, T2 y) {
  if (x < y) x = y;
}
const int MOD = 1e9 + 7;
const int INF = 0x3f3f3f3f;
const long long INFll = 0x3f3f3f3f3f3f3f3fll;
const double EPS = 1e-6;
namespace fastio {
char rbuf[1 << 23], *p1 = rbuf, *p2 = rbuf, wbuf[1 << 23], *p3 = wbuf;
inline char getc() {
  return p1 == p2 &&
                 (p2 = (p1 = rbuf) + fread(rbuf, 1, 1 << 23, stdin), p1 == p2)
             ? -1
             : *p1++;
}
inline void putc(char x) { (*p3++ = x); }
template <typename T>
void read(T &x) {
  x = 0;
  char c = getchar();
  T neg = 0;
  while (!isdigit(c)) neg |= (c == '-'), c = getchar();
  while (isdigit(c)) x = (x << 3) + (x << 1) + (c ^ 48), c = getchar();
  if (neg) x = -x;
}
template <typename T>
void recursive_print(T x) {
  if (!x) return;
  recursive_print(x / 10);
  putc(x % 10 + '0');
}
template <typename T>
void print(T x) {
  if (!x) putc('0');
  if (x < 0) putc('-'), x = -x;
  recursive_print(x);
}
template <typename T>
void print(T x, char c) {
  print(x);
  putc(c);
}
void print_final() { fwrite(wbuf, 1, p3 - wbuf, stdout); }
}  // namespace fastio
template <typename Tv, int limN, int limM>
struct link_list {
  int hd[limN + 5], nxt[limM + 5], item_n = 0;
  Tv val[limM + 5];
  void clear() {
    memset(hd, 0, sizeof(hd));
    item_n = 0;
  }
  void ins(int x, Tv y) {
    val[++item_n] = y;
    nxt[item_n] = hd[x];
    hd[x] = item_n;
  }
};
const int MAXN = 100;
int n, k, m, mod, fac[MAXN + 5], c[MAXN + 5][MAXN + 5];
int dp[MAXN + 5][MAXN + 5][MAXN + 5];
int calc(int n, int m, int k) {
  if (!n) return (!k) ? 1 : 0;
  if (!m) return (!k) ? fac[n] : 0;
  if (m == 1) return (k == 1) ? fac[n] : 0;
  if (~dp[n][m][k]) return dp[n][m][k];
  if (m + k - 1 > n) return (!k) ? fac[n] : 0;
  dp[n][m][k] = 0;
  for (int i = 1; i <= n; i++)
    for (int j = 0; j <= min(k, i - 1); j++)
      dp[n][m][k] = (dp[n][m][k] + 1ll * calc(i - 1, m - 1, j) *
                                       calc(n - i, m - 1, k - j) % mod *
                                       c[n - 1][i - 1]) %
                    mod;
  return dp[n][m][k];
}
int main() {
  scanf("%d%d%d%d", &n, &m, &k, &mod);
  for (int i = 0; i <= n; i++) {
    c[i][0] = 1;
    for (int j = 1; j <= i; j++)
      c[i][j] = (c[i - 1][j] + c[i - 1][j - 1]) % mod;
  }
  for (int i = (fac[0] = 1); i <= n; i++) fac[i] = 1ll * fac[i - 1] * i % mod;
  memset(dp, -1, sizeof(dp));
  printf("%d\n", calc(n, m, k));
  return 0;
}
