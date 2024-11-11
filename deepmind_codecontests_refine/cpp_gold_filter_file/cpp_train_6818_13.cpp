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
template <typename T>
void print(T x, char c) {
  if (!x) putc('0');
  if (x < 0) putc('-'), x = ~x + 1;
  recursive_print(x);
  putc(c);
}
void print_final() { fwrite(wbuf, 1, p3 - wbuf, stdout); }
}  // namespace fastio
const int MAXN = 1e5;
const int INF = 0x3f3f3f3f;
int n, m, a[MAXN + 5], b[MAXN + 5], dp[MAXN + 5], mn[MAXN + 5], pre[MAXN + 5],
    ps[MAXN + 5];
int main() {
  scanf("%d", &n);
  for (int i = 1; i <= n + 1; i++) mn[i] = INF + 1;
  for (int i = 1; i <= n; i++) scanf("%d", &a[i]);
  a[++n] = INF;
  scanf("%d", &m);
  for (int i = 1; i <= m; i++) scanf("%d", &b[i]);
  sort(b + 1, b + m + 1);
  for (int i = 1; i <= n; i++) {
    if (~a[i]) {
      int t = lower_bound(mn + 1, mn + n + 1, a[i]) - mn;
      dp[i] = t;
      pre[i] = ps[t - 1];
      mn[t] = a[i];
      ps[t] = i;
    } else {
      for (int j = m, k = n; j; j--) {
        while (mn[k] >= b[j]) k--;
        mn[k + 1] = b[j];
        ps[k + 1] = i;
      }
    }
  }
  int x = n, val = a[n], is = 0, clen = dp[n] + 1;
  while (clen--) {
    if (!is) {
      if (!~a[pre[x]]) {
        is = 1;
        for (int j = m; j; j--)
          if (~b[j] && b[j] < a[x]) {
            a[pre[x]] = b[j];
            b[j] = -1;
            break;
          }
      }
      x = pre[x];
    } else {
      bool flg = 0;
      for (int j = x - 1; ~j; j--)
        if (~a[j] && a[j] < a[x] && dp[j] + 1 == clen) {
          x = j;
          is = 0;
          flg = 1;
          break;
        }
      if (!flg) {
        int val = 0, pos = 0;
        for (int j = 1; j <= m; j++)
          if (~b[j] && b[j] < a[x]) val = b[j], pos = j;
        b[pos] = -1;
        is = 1;
        for (int j = x - 1; j; j--)
          if (!~a[j]) {
            a[j] = val;
            x = j;
            break;
          }
      }
    }
  }
  for (int i = 1; i <= n; i++)
    if (!~a[i]) {
      for (int j = 1; j <= m; j++)
        if (~b[j]) {
          a[i] = b[j], b[j] = -1;
          break;
        }
    }
  for (int i = 1; i < n; i++) printf("%d ", a[i]);
  return 0;
}
