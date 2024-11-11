#include <bits/stdc++.h>
using namespace std;
int n, m, p, len, q, ans = 2000000001, x, y, t, cnt, a[100000], b[100000],
                     nex[100000], wen[100000], hea[100000], boo[100000],
                     bo[100000], dfn[100000], low[100000], val[100000];
void add(int x, int y, int z) {
  ++len;
  nex[len] = hea[x];
  wen[len] = y;
  val[len] = z;
  hea[x] = len;
}
int dfs(int x) {
  if (x == q) return 1;
  dfn[x] = 1;
  for (int i = hea[x]; i; i = nex[i])
    if (bo[i] == 0 && dfn[wen[i]] == 0) {
      if (dfs(wen[i])) {
        ++a[0];
        a[a[0]] = i;
        return 1;
      }
    }
  return 0;
}
void tarjan(int x, int y) {
  dfn[x] = low[x] = ++cnt;
  int booo = 1;
  for (int i = hea[x]; i; i = nex[i])
    if (bo[i] == 0) {
      if (booo && wen[i] == y) {
        booo = 0;
        continue;
      }
      if (!dfn[wen[i]]) {
        tarjan(wen[i], x);
        low[x] = min(low[x], low[wen[i]]);
        if (low[wen[i]] > dfn[x]) boo[i] = boo[i * 3 - i / 2 * 4 - 1] = 1;
      } else
        low[x] = min(low[x], dfn[wen[i]]);
    }
}
int main() {
  scanf("%d%d", &n, &m);
  scanf("%d%d", &p, &q);
  for (int i = 1; i <= m; i++) {
    int x, y, z;
    scanf("%d%d%d", &x, &y, &z);
    add(x, y, z);
    add(y, x, z);
  }
  if (!dfs(p)) {
    printf("0\n0");
    return 0;
  }
  for (int i = 0; i <= a[0]; i++) b[i] = a[i];
  for (int i = 1; i <= b[0]; i++) {
    bo[b[i]] = bo[b[i] * 3 - b[i] / 2 * 4 - 1] = 1;
    a[0] = 0;
    for (int j = 1; j <= n; j++) dfn[j] = 0;
    if (!dfs(p)) {
      if (ans > val[b[i]]) {
        ans = val[b[i]];
        t = 1;
        x = b[i];
      }
    } else {
      cnt = 0;
      for (int j = 1; j <= n; j++) dfn[j] = low[j] = 0;
      for (int j = 1; j <= m; j++) boo[j] = 0;
      tarjan(p, 0);
      for (int j = 1; j <= a[0]; j++)
        if (boo[a[j]]) {
          if (ans > val[b[i]] + val[a[j]]) {
            ans = val[b[i]] + val[a[j]];
            t = 2;
            x = b[i];
            y = a[j];
          }
        }
    }
    bo[b[i]] = bo[b[i] * 3 - b[i] / 2 * 4 - 1] = 0;
  }
  if (ans > 2000000000)
    puts("-1");
  else {
    printf("%d\n%d\n", ans, t);
    if (t >= 1) printf("%d", (x + 1) / 2);
    if (t == 2) printf(" %d", (y + 1) / 2);
  }
}
