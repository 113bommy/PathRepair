#include <bits/stdc++.h>
using namespace std;
int n, len, a[1000000], nex[1000000], wen[1000000], hea[1000000], f[1000000][4],
    ans;
void add(int x, int y) {
  ++len;
  nex[len] = hea[x];
  wen[len] = y;
  hea[x] = len;
}
void dfs(int x, int y) {
  int min1 = 0, min2 = 0;
  f[x][1] = f[x][2] = 0;
  f[x][a[x] ^ 3] = 1000000;
  for (int i = hea[x]; i; i = nex[i])
    if (wen[i] != y) {
      dfs(wen[i], x);
      min1 = max(min1, f[x][1] + min(f[wen[i]][1], f[wen[i]][2] + 1));
      min2 = max(min2, f[x][2] + min(f[wen[i]][2], f[wen[i]][1] + 1));
      f[x][1] = max(f[x][1], min(f[wen[i]][1], f[wen[i]][2] + 1));
      f[x][2] = max(f[x][2], min(f[wen[i]][2], f[wen[i]][1] + 1));
    }
  ans = max(ans, min(a[x] != 1 ? min2 : 10000000, a[x] != 2 ? min1 : 0));
}
int main() {
  int t;
  scanf("%d", &t);
  do {
    --t;
    len = 0;
    scanf("%d", &n);
    for (int i = 1; i <= n; i++) hea[i] = 0;
    for (int i = 1; i <= n; i++) scanf("%d", &a[i]);
    for (int i = 1; i < n; i++) {
      int x, y;
      scanf("%d%d", &x, &y);
      add(x, y);
      add(y, x);
    }
    dfs(1, 0);
    printf("%d\n", (ans + 1) / 2 + 1);
    ans = 0;
  } while (t);
  return 0;
}
