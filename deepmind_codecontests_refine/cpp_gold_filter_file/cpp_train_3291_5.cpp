#include <bits/stdc++.h>
using namespace std;
int f[63][32][2010], du[110], d[110], ans[110][110], p[110];
int n, top;
bool cmp(int a, int b) { return (du[a] < du[b]); }
void proc(int x, int y, int sum) {
  if (!x && !y) return;
  int now = f[x][y][sum] >> 1;
  int sign = f[x][y][sum] & 1;
  du[++top] = now;
  if (sign)
    proc(x - 1, y, sum - now);
  else
    proc(x - 1, y - 1, sum - now);
}
void PROC() {
  reverse(du + 1, du + top + 1);
  for (int i = 1; i <= top; i++) p[i] = i;
  for (int i = 1; i <= top; i++) {
    sort(p + i, p + top + 1, cmp);
    int u = p[i];
    int res = du[u];
    for (int j = i + 1; j <= i + res; j++) {
      ans[u][p[j]] = 1;
    }
    for (int j = i + res + 1; j <= top; j++) {
      ans[p[j]][u] = 1;
      du[p[j]]--;
    }
  }
  printf("%d\n", top);
  for (int i = 1; i <= top; i++) {
    for (int j = 1; j <= top; j++) printf("%d", ans[i][j]);
    putchar('\n');
  }
}
int main() {
  memset(f, -1, sizeof(f));
  scanf("%d", &n);
  for (int i = 1; i <= n; i++) scanf("%d", &d[i]);
  sort(d + 1, d + n + 1);
  f[0][0][0] = 0;
  for (int k = 1; k <= 62; k++) {
    for (int y = 1; y <= n && y <= k; y++) {
      int x = k;
      int val = d[y];
      if (x > 62) continue;
      for (int sum = k * (k - 1) / 2; sum <= 2000; sum++) {
        if (x > 0 && y > 0 && sum >= val && f[x - 1][y - 1][sum - val] != -1)
          f[x][y][sum] = val * 2;
        if (x > 0 && sum >= val && f[x - 1][y][sum - val] != -1)
          f[x][y][sum] = val * 2 + 1;
      }
    }
  }
  for (int k = n; k <= 62; k++) {
    if (f[k][n][k * (k - 1) / 2] != -1) {
      proc(k, n, (k) * (k - 1) / 2);
      PROC();
      return 0;
    }
  }
  printf("=(\n");
  return 0;
}
