#include <bits/stdc++.h>
using namespace std;
inline int read() {
  char ch;
  int f = 1, x;
  while (ch = getchar(), !isdigit(ch))
    if (ch == '-') f = -1;
  x = (ch ^ 48);
  while (ch = getchar(), isdigit(ch)) x = (x << 3) + (x << 1) + (ch ^ 48);
  return x * f;
}
inline void write(int x) {
  if (x < 0) {
    putchar('-');
    write(-x);
    return;
  }
  if (x > 9) write(x / 10);
  putchar(x % 10 ^ 48);
}
inline void writ(int x, char p = '\n') {
  write(x);
  putchar(p);
}
int n, m, g[110][110];
int main() {
  n = min(read(), 50), m = read();
  for (int i = (1); i <= (m); ++i) {
    int u = read(), v = read();
    if (u <= n && v <= n) g[u][v] = g[v][u] = 1;
  }
  int ans[5];
  for (ans[0] = 1; ans[0] <= n; ++ans[0])
    for (ans[1] = ans[0] + 1; ans[1] <= n; ++ans[1])
      for (ans[2] = ans[1] + 1; ans[2] <= n; ++ans[2])
        for (ans[3] = ans[2] + 1; ans[3] <= n; ++ans[3])
          for (ans[4] = ans[3] + 1; ans[4] <= n; ++ans[4]) {
            int cnt = 0;
            for (int i = (0); i <= (4); ++i)
              for (int j = (i + 1); j <= (4); ++j) cnt += g[ans[i]][ans[j]];
            if (cnt == 0 || cnt == 10) {
              for (int i = (0); i <= (3); ++i) writ(ans[i], ' ');
              writ(ans[4]);
              return 0;
            }
          }
  puts("-1");
  return 0;
}
