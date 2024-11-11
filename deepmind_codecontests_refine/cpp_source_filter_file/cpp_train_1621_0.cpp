#include <bits/stdc++.h>
using namespace std;
inline long long read() {
  char ch = getchar();
  long long x = 0;
  int op = 1;
  for (; !isdigit(ch); ch = getchar())
    if (ch == '-') op = -1;
  for (; isdigit(ch); ch = getchar()) x = x * 10 + ch - '0';
  return x * op;
}
inline void write(long long a) {
  if (a < 0) putchar('-'), a = -a;
  if (a >= 10) write(a / 10);
  putchar('0' + a % 10);
}
const int N = 5005, M = 10005;
const int inf = 1e9;
int n, m, now;
int a[N], sum[N], f[N], g[N], b[N], pre[N][M];
int main() {
  n = read();
  m = read();
  for (int i = 1; i <= n; i++) sum[i] = sum[i - 1] + (a[i] = read());
  memset(f, 0x3f, sizeof f);
  f[0] = 0;
  for (int i = 1; i <= n; i++) {
    now = min(now + a[i] / 10, M);
    for (int j = 0; j <= now; j++) {
      g[j] = f[j];
      f[j] = inf;
    }
    for (int j = 0; j <= now; j++)
      if (g[j] <= sum[i - 1]) {
        int t = m - (sum[i - 1] - g[j]) + j;
        for (int k = 0; k <= a[i] / 2 && k <= t; k++) {
          int r = (a[i] - k) / 10;
          if (g[j] + a[i] - k < f[j + r]) {
            f[j + r] = g[j] + a[i] - k;
            pre[i][j + r] = k;
          }
        }
      }
  }
  int ans = 0;
  for (int i = 1; i <= now; i++)
    if (f[i] < f[ans]) ans = i;
  write(f[ans]);
  puts("");
  for (int i = n; i >= 1; i--) {
    b[i] = pre[i][ans];
    ans -= (a[i] - pre[i][ans]) / 10;
  }
  for (int i = 1; i <= n; i++) write(b[i]), putchar(' ');
  return 0;
}
