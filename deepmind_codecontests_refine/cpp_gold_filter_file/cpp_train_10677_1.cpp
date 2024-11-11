#include <bits/stdc++.h>
using namespace std;
inline long long read() {
  long long x = 0, f = 1;
  char ch = getchar();
  while (ch < '0' || ch > '9') {
    if (ch == '-') f = -1;
    ch = getchar();
  }
  while (ch >= '0' && ch <= '9') {
    x = x * 10 + ch - '0';
    ch = getchar();
  }
  return x * f;
}
inline void wrote(long long x) {
  if (x < 0) putchar('-'), x = -x;
  if (x >= 10) wrote(x / 10);
  putchar(x % 10 + '0');
}
inline void writeln(long long x) {
  wrote(x);
  puts("");
}
const long long N = 3010;
struct data {
  long long x, y;
} a[N];
long long win[N][N], n, m;
bool operator<(data a, data b) { return a.x > b.x; }
char get(long long x) { return x == 2 ? 'W' : (x == 1 ? 'D' : 'L'); }
void solve(long long x) {
  sort(a + x, a + n + 1);
  long long ned = a[x].x;
  for (long long i = n; i >= x + 1; --i) {
    if (ned > 1)
      ned -= 2, win[a[x].y][a[i].y] = 2, win[a[i].y][a[x].y] = 0;
    else if (ned)
      a[i].x--, ned--, win[a[i].y][a[x].y] = win[a[x].y][a[i].y] = 1;
    else
      a[i].x -= 2, win[a[x].y][a[i].y] = 0, win[a[i].y][a[x].y] = 2;
  }
  a[x].x = ned;
}
int main() {
  n = read();
  m = read();
  for (long long i = 1; i <= m; ++i) a[i].x = read(), a[i].y = i;
  long long tmp = 0, mx = 0;
  for (long long i = 1; i <= m; ++i) {
    tmp += a[i].x;
    mx += 2 * (n - i);
    if (tmp > mx) return puts("no"), 0;
  }
  for (long long i = m + 1; i <= n; ++i) {
    mx += 2 * (n - i);
    a[i].x = min(a[i - 1].x, mx - tmp);
    tmp += a[i].x;
    a[i].y = i;
  }
  if (tmp != mx) return puts("no"), 0;
  for (long long i = 1; i <= n; ++i) solve(i);
  puts("yes");
  for (long long i = 1; i <= n; ++i) {
    for (long long j = 1; j <= n; ++j) putchar(i == j ? 'X' : get(win[i][j]));
    puts("");
  }
}
