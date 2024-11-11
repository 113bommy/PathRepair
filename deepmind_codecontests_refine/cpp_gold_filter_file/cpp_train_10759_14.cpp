#include <bits/stdc++.h>
using namespace std;
int g[17][17];
int h[17], f[1 << 17], d[17];
void floyd(int n) {
  for (int k = 0; k < n; k++) {
    for (int i = 0; i < n; i++) {
      for (int j = 0; j < n; j++) {
        g[i][j] = min(g[i][j], g[i][k] + g[k][j]);
      }
    }
  }
}
int first(int mask) {
  int r = 0;
  for (; !(mask & 1); r++, mask >>= 1)
    ;
  return r;
}
bool test(int mask, int b) { return (mask & (1 << b)); }
int main() {
  for (int n, m; scanf("%d%d", &n, &m) != EOF;) {
    memset(g, 0x3f, sizeof(g));
    memset(f, 0x3f, sizeof(f));
    memset(d, 0, sizeof(d));
    int answer = 0, cnt = 0;
    for (int i = 0; i < n; i++) g[i][i] = 0;
    for (int i = 1, x, y, w; i <= m; i++) {
      scanf("%d%d%d", &x, &y, &w);
      x--, y--;
      answer += w;
      g[x][y] = g[y][x] = min(g[x][y], w);
      d[x]++, d[y]++;
    }
    floyd(n);
    bool flag = false;
    for (int i = 0; i < n; i++) {
      if (g[0][i] == 0x3f3f3f3f && d[i]) {
        flag = true;
        break;
      }
      if (d[i] % 2) h[cnt++] = i;
    }
    if (flag) {
      printf("-1\n");
      continue;
    }
    int S = 1 << cnt;
    f[0] = 0;
    for (int i = 1; i < S; i++) {
      int sp = first(i);
      for (int j = sp + 1; j < cnt; j++) {
        if (!test(i, j)) continue;
        int mask = i ^ (1 << sp) ^ (1 << j);
        f[i] = min(f[i], f[mask] + g[h[sp]][h[j]]);
      }
    }
    if (cnt != 0) answer += f[S - 1];
    printf("%d\n", answer);
  }
  return 0;
}
