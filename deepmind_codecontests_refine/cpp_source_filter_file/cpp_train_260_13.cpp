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
inline void debug(int x) { fprintf(stderr, "ycx has aked ioi %d times\n", x); }
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
  while (!isdigit(c)) neg |= !(c ^ '-'), c = getchar();
  while (isdigit(c)) x = (x << 3) + (x << 1) + (c ^ 48), c = getchar();
  if (neg) x = (~x) + 1;
}
template <typename T>
void recursive_print(T x) {
  if (!x) return;
  recursive_print(x / 10);
  putc(x % 10 ^ 48);
}
template <typename T>
void print(T x) {
  if (!x) putc('0');
  if (x < 0) putc('-'), x = ~x + 1;
  recursive_print(x);
}
void print_final() { fwrite(wbuf, 1, p3 - wbuf, stdout); }
}  // namespace fastio
const int MAXN = 20;
const int MAXM = 1e5;
const int MAXP = 1 << 20;
const int INF = 0x3f3f3f3f;
int n, m, a[MAXN + 5][MAXM + 5];
long long cnt[MAXP + 5], mn[MAXP + 5], ans[MAXP + 5];
void FWTxor(long long *a, int len, int type) {
  for (int i = 2; i <= len; i <<= 1)
    for (int j = 0; j < len; j += i)
      for (int k = 0; k < (i >> 1); k++) {
        int X = a[j + k], Y = a[(i >> 1) + j + k];
        if (type == 1)
          a[j + k] = X + Y, a[(i >> 1) + j + k] = X - Y;
        else
          a[j + k] = (X + Y) / 2, a[(i >> 1) + j + k] = (X - Y) / 2;
      }
}
int main() {
  scanf("%d%d", &n, &m);
  for (int i = 1; i <= n; i++)
    for (int j = 1; j <= m; j++) scanf("%1d", &a[i][j]);
  for (int j = 1; j <= m; j++) {
    int msk = 0;
    for (int i = 1; i <= n; i++) msk |= (a[i][j] << i - 1);
    cnt[msk]++;
  }
  for (int i = 0; i < (1 << n); i++)
    mn[i] = min(__builtin_popcount(i), n - __builtin_popcount(i));
  FWTxor(cnt, 1 << n, 1);
  FWTxor(mn, 1 << n, 1);
  for (int i = 0; i < (1 << n); i++) ans[i] = 1ll * cnt[i] * mn[i];
  FWTxor(ans, 1 << n, -1);
  int ret = INF;
  for (int i = 0; i < (1 << n); i++) chkmin(ret, (int)ans[i]);
  printf("%d\n", ret);
  return 0;
}
