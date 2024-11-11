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
const int MAXN = 1e5;
const int MAXM = 2e3;
const int MAXPOS = 2e5;
int n, m, a[MAXN + 5], b[MAXM + 5], sum[MAXPOS + 5];
int l[MAXN + 5], r[MAXN + 5], f[MAXN + 5], g[MAXN + 5];
int main() {
  scanf("%d%d", &n, &m);
  for (int i = 1; i <= n; i++) scanf("%d", &a[i]);
  sort(a + 1, a + n + 1);
  for (int i = 1; i <= m; i++) scanf("%d", &b[i]), sum[b[i]]++;
  sort(b + 1, b + m + 1);
  for (int i = 1; i <= MAXPOS; i++) sum[i] += sum[i - 1];
  a[0] = -MAXPOS;
  a[n + 1] = MAXPOS + MAXPOS;
  for (int i = 1; i <= n; i++) l[i] = (a[i - 1] + 1 == a[i]) ? l[i - 1] : i;
  for (int i = n; i; i--) r[i] = (a[i + 1] - 1 == a[i]) ? r[i + 1] : i;
  for (int i = 1; i <= n; i++) {
    f[i] = max(f[i], f[i - 1] + sum[a[i]] - sum[a[i] - 1]);
    g[i] = max(g[i], g[i - 1] + sum[a[i]] - sum[a[i] - 1]);
    for (int j = 1; j <= m && b[j] < a[i]; j++)
      if (a[i] - b[j] < i) {
        chkmax(g[i], f[l[i - a[i] + b[j]] - 1] + sum[a[i]] - sum[b[j] - 1]);
      }
    chkmax(f[i], g[i]);
    for (int j = m; j && b[j] >= a[i]; j--)
      if (b[j] - a[i] <= n - i) {
        chkmax(f[r[i + b[j] - a[i]]], g[i] + sum[b[j]] - sum[a[i]]);
      }
  }
  printf("%d\n", f[n]);
  return 0;
}
