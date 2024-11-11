#include <bits/stdc++.h>
using namespace std;
int read() {
  int x = 0, f = 1;
  char ch = getchar();
  while (ch - '0' < 0 || ch - '0' > 9) {
    if (ch == '-') f = -1;
    ch = getchar();
  }
  while (ch - '0' >= 0 && ch - '0' <= 9) {
    x = x * 10 + ch - '0';
    ch = getchar();
  }
  return x * f;
}
int Q, cnt;
double f[500010][45];
int fa[500010], son[500010];
double quick_pow(double x, int p) {
  double an = 1, po = x;
  while (p) {
    if (p & 1) an *= po;
    po *= po;
    p >>= 1;
  }
  return an;
}
int main() {
  int bl = 33;
  cnt = 1;
  for (int i = 0; i <= bl; i++) f[1][i] = 1;
  Q = read();
  while (Q--) {
    int op = read(), x = read();
    if (op == 1) {
      cnt++;
      fa[cnt] = x;
      son[x]++;
      double las = f[x][0];
      f[x][0] = quick_pow(0.5, son[x]);
      for (int i = 0; i <= bl; i++) f[cnt][i] = 1;
      for (int i = 1; i <= bl; i++) {
        int u = fa[x];
        if (!u) break;
        double tmp = f[u][i];
        f[u][i] /= (0.5 + 0.5 * las);
        f[u][i] *= (f[x][i - 1] * 0.5 + 0.5);
        las = tmp;
        x = u;
      }
    } else {
      double ans = 0;
      for (int i = 1; i <= bl; i++) ans += (double)i * (f[x][i] - f[x][i - 1]);
      printf("%.8lf\n", ans);
    }
  }
  return 0;
}
