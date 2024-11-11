#include <bits/stdc++.h>
using namespace std;
inline long long read() {
  long long x = 0;
  char ch = getchar(), w = 1;
  while (ch < '0' || ch > '9') {
    if (ch == '-') w = -1;
    ch = getchar();
  }
  while (ch >= '0' && ch <= '9') {
    x = x * 10 + ch - '0';
    ch = getchar();
  }
  return x * w;
}
void write(long long x) {
  if (x < 0) putchar('-'), x = -x;
  if (x > 9) write(x / 10);
  putchar(x % 10 + '0');
}
inline void writeln(long long x) {
  write(x);
  puts("");
}
const int N = 510000;
const int MAX_H = 30;
int n = 1;
int fa[N], st[N], top;
double f[N][34];
bool de;
void show() {
  for (int i = 1; i <= n; ++i) {
    for (int j = 0; j <= n; ++j) printf("%lf ", f[i][j]);
    puts("");
  }
}
int main() {
  int Q = read(), op, x;
  for (int i = 0; i <= MAX_H; ++i) f[1][i] = 1;
  while (Q--) {
    op = read(), x = read();
    if (x == 4) de = 1;
    if (op == 1) {
      ++n;
      fa[n] = x;
      for (int i = 0; i <= MAX_H; ++i) f[n][i] = 1;
      int y = n;
      top = 0;
      int ct = 0;
      while (y) {
        if (ct > MAX_H) break;
        st[++top] = y;
        y = fa[y];
        ++ct;
      }
      for (int i = top; i > 1; --i)
        for (int j = 1; j <= MAX_H; ++j)
          f[st[i]][j] /= (f[st[i - 1]][j - 1] * 0.5 + 0.5);
      f[x][0] *= 0.5;
      for (int i = 2; i <= top; ++i)
        for (int j = 1; j <= MAX_H; ++j)
          f[st[i]][j] *= (f[st[i - 1]][j - 1] * 0.5 + 0.5);
    } else {
      double ans = 0;
      for (int i = 1; i <= MAX_H; ++i) ans += (f[x][i] - f[x][i - 1]) * i;
      printf("%.7lf\n", ans);
    }
  }
  return 0;
}
