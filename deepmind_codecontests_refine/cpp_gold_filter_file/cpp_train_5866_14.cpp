#include <bits/stdc++.h>
using namespace std;
int read() {
  char ch = '!';
  int res = 0, f = 0;
  while (!isdigit(ch)) {
    ch = getchar();
    if (ch == '-') f = 1;
  }
  while (isdigit(ch)) res = res * 10 + ch - '0', ch = getchar();
  return f ? -res : res;
}
int n, m, now[303];
double p[3003][303], f[303][3003], sum[303], tmp[3003], ans;
void upd(int x) {
  ++now[x];
  memcpy(tmp, f[x], sizeof(double) * (n + 1));
  if (now[x] == 0)
    f[x][0] = 1;
  else
    f[x][0] = 0;
  for (int i = 1; i <= n; ++i)
    f[x][i] = f[x][i - 1] * (1 - p[i][x]) + tmp[i - 1] * p[i][x];
  sum[x] += f[x][n];
}
int main() {
  n = read(), m = read();
  for (int i = 1; i <= n; ++i)
    for (int j = 1; j <= m; ++j) {
      int x = read();
      p[i][j] = x / (double)1000;
    }
  for (int i = 1; i <= m; ++i) now[i] = -1, upd(i);
  for (int i = 1; i <= n; ++i) {
    int id = 0;
    double mn = 1e9;
    for (int j = 1; j <= m; ++j)
      if (sum[j] < mn) mn = sum[j], id = j;
    ans += 1 - sum[id], upd(id);
  }
  printf("%.10lf", ans);
  return 0;
}
