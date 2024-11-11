#include <bits/stdc++.h>
using namespace std;
const long long N = 3005;
long long n, a[N], b[N], f[N][N], pre[N];
inline long long read() {
  long long ret = 0, ff = 1;
  char ch = getchar();
  while (!isdigit(ch)) {
    if (ch == '-') ff = -1;
    ch = getchar();
  }
  while (isdigit(ch)) {
    ret = ret * 10 + (ch ^ 48);
    ch = getchar();
  }
  return ret * ff;
}
void write(long long x) {
  if (x < 0) {
    x = -x, putchar('-');
  }
  if (x > 9) write(x / 10);
  putchar(x % 10 + 48);
}
void writeln(long long x) { write(x), puts(""); }
void writesp(long long x) { write(x), putchar(' '); }
signed main() {
  n = read();
  for (long long i = 1; i <= n; i++) a[i] = b[i] = read() - i;
  sort(b + 1, b + n + 1);
  for (long long i = 1; i <= n; i++) f[1][i] = abs(a[1] - b[i]);
  pre[0] = 1e9;
  for (long long i = 1; i <= n; i++) pre[i] = min(pre[i - 1], f[1][i]);
  for (long long i = 2; i <= n; i++) {
    for (long long j = 1; j <= n; j++) f[i][j] = pre[j] + abs(a[i] - b[j]);
    for (long long j = 1; j <= n; j++) pre[j] = min(pre[j - 1], f[i][j]);
  }
  long long ans = 1e15;
  for (long long i = 1; i <= n; i++) ans = min(ans, f[n][i]);
  write(ans);
  return 0;
}
