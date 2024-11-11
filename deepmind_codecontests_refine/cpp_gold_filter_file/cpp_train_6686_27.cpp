#include <bits/stdc++.h>
using namespace std;
long long read() {
  long long q = 0, w = 1;
  char ch = getchar();
  while (ch > '9' || ch < '0') {
    if (ch == '-') w = -1;
    ch = getchar();
  }
  while (ch >= '0' && ch <= '9') {
    q = q * 10 + (ch - '0');
    ch = getchar();
  }
  return q * w;
}
void write(long long x) {
  if (x < 0) {
    putchar('-');
    x = (-x);
  }
  if (x > 9) write(x / 10);
  putchar('0' + x % 10);
}
void writeln(long long x) {
  write(x);
  puts("");
}
void writecs(long long x) {
  write(x);
  putchar(' ');
}
namespace G {
const long long N = 2e4 + 95;
struct Node {
  long long l, r, dat;
} s[N << 2];
long long a[N];
void Build(long long p, long long l, long long r) {
  s[p].l = l;
  s[p].r = r;
  if (l == r) {
    s[p].dat = a[l];
    return;
  }
  long long mid = (l + r) >> 1;
  Build(p * 2, l, mid);
  Build(p * 2 + 1, mid + 1, r);
  s[p].dat = max(s[p * 2].dat, s[p * 2 + 1].dat);
  return;
}
long long Query(long long p, long long l, long long r) {
  if (l <= s[p].l && s[p].r <= r) return s[p].dat;
  if (r < s[p].l || s[p].r < l) return -0x7FFFFFFF;
  return max(Query(p * 2, l, r), Query(p * 2 + 1, l, r));
}
}  // namespace G
const long long N = 50 + 95;
const long long M = 2e4 + 95;
const long long H = 1e5 + 95;
long long n, m, k, a[N][M];
long long sum[N][M], f[N][M];
long long g[N][M];
pair<long long, long long> b[H];
long long head, tail, tag;
void Clear() {
  head = 1;
  tail = 0;
  tag = 0;
  return;
}
int main() {
  n = read();
  m = read();
  k = read();
  for (long long i = 1; i <= n; i++)
    for (long long j = 1; j <= m; j++) a[i][j] = read();
  for (long long i = 1; i <= (n + 1); i++)
    for (long long j = 1; j <= m; j++)
      sum[i][j] = (sum[i - 1][j] + sum[i][j - 1] - sum[i - 1][j - 1] + a[i][j]);
  for (long long i = 1; i <= (n + 1); i++)
    for (long long j = 1; j <= m; j++) g[i][j] = (g[i][j - 1] + a[i][j]);
  for (long long i = 1; i <= (m - k + 1); i++)
    f[1][i] = (sum[2][i + k - 1] - sum[2][i - 1]);
  for (long long i = 2; i <= n; i++) {
    for (long long j = 1; j <= (m - k + 1); j++) G::a[j] = f[i - 1][j];
    G::Build(1, 1, (m - k + 1));
    for (long long j = 1; j <= (m - k + 1); j++) {
      long long cost = (g[i][j + k - 1] - g[i][j - 1] + g[i + 1][j + k - 1] -
                        g[i + 1][j - 1]);
      if ((j - k) >= 1) f[i][j] = max(f[i][j], G::Query(1, 1, j - k) + cost);
      if ((j + k) <= (m - k + 1))
        f[i][j] = max(f[i][j], G::Query(1, j + k, m - k + 1) + cost);
    }
    Clear();
    for (long long j = 1; j <= (m - k + 1); j++) {
      long long tmp = (f[i - 1][j] + g[i + 1][j + k - 1] - g[i + 1][j - 1]);
      if (j != 1)
        tag += (a[i][j + k - 1] + a[i + 1][j + k - 1] - a[i + 1][j - 1]);
      while (head <= tail && (b[tail].second + tag) <= tmp) tail--;
      b[++tail] = make_pair(j, tmp - tag);
      while (head <= tail && b[head].first < (j - k + 1)) head++;
      f[i][j] = max(f[i][j], b[head].second + tag);
    }
    Clear();
    for (long long j = (m - k + 1); j >= 1; j--) {
      long long tmp = (f[i - 1][j] + g[i + 1][j + k - 1] - g[i + 1][j - 1]);
      if (j != (m - k + 1)) tag += (a[i][j] + a[i + 1][j] - a[i + 1][j + k]);
      while (head <= tail && (b[tail].second + tag) <= tmp) tail--;
      b[++tail] = make_pair(j, tmp - tag);
      while (head <= tail && (j + k - 1) < b[head].first) head++;
      f[i][j] = max(f[i][j], b[head].second + tag);
    }
  }
  long long ans = 0;
  for (long long i = 1; i <= (m - k + 1); i++) ans = max(ans, f[n][i]);
  writeln(ans);
  return 0;
}
