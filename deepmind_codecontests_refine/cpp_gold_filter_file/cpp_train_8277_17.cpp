#include <bits/stdc++.h>
using namespace std;
int _min(int x, int y) { return x < y ? x : y; }
int _max(int x, int y) { return x > y ? x : y; }
int read() {
  int s = 0, f = 1;
  char ch = getchar();
  while (ch < '0' || ch > '9') {
    if (ch == '-') f = -1;
    ch = getchar();
  }
  while (ch >= '0' && ch <= '9') s = s * 10 + ch - '0', ch = getchar();
  return s * f;
}
double f[510000][61];
int fa[510000], son[510000];
double pow_mod(double a, int k) {
  double ans = 1.0;
  while (k) {
    if (k & 1) ans *= a;
    a *= a;
    k /= 2;
  }
  return ans;
}
int main() {
  int n = 1;
  for (int i = 0; i <= 60; i++) f[n][i] = 1.0;
  int Q = read();
  for (int i = 1; i <= Q; i++) {
    int opt = read(), x = read();
    if (opt == 1) {
      n++;
      fa[n] = x;
      son[x]++;
      for (int i = 0; i <= 60; i++) f[n][i] = 1.0;
      double last = f[x][0];
      f[x][0] = pow_mod(0.5, son[x]);
      for (int i = 1; i <= 60; i++) {
        if (x == 1) break;
        int u = fa[x];
        double hh = f[u][i];
        f[u][i] /= (0.5 + 0.5 * last);
        f[u][i] *= (0.5 + 0.5 * f[x][i - 1]);
        x = u;
        last = hh;
      }
    } else {
      double ans = 0.0;
      for (int i = 1; i <= 60; i++) ans += (double)i * (f[x][i] - f[x][i - 1]);
      printf("%.10lf\n", ans);
    }
  }
  return 0;
}
