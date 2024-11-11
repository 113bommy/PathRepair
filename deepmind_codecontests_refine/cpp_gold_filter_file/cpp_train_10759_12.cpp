#include <bits/stdc++.h>
using namespace std;
const int maxn = 20, inf = 0x7ffffff;
int n, m, d[maxn][maxn], ans, fa[maxn], du[maxn], S[maxn], top, f[1 << 15];
bool flag = true;
struct node {
  int x, y;
} e[2010];
int find(int x) {
  if (x == fa[x]) return x;
  return fa[x] = find(fa[x]);
}
int main() {
  scanf("%d%d", &n, &m);
  for (int i = 1; i <= n; i++) fa[i] = i;
  for (int i = 1; i <= n; i++)
    for (int j = 1; j <= n; j++)
      if (i != j) d[i][j] = inf;
  for (int i = 1; i <= m; i++) {
    int x, y, z;
    scanf("%d%d%d", &x, &y, &z);
    e[i].x = x;
    e[i].y = y;
    du[x]++;
    du[y]++;
    int fx = find(x), fy = find(y);
    if (fx != fy) fa[fx] = fy;
    ans += z;
    if (x != y) d[x][y] = d[y][x] = min(d[x][y], z);
  }
  for (int k = 1; k <= n; k++)
    for (int i = 1; i <= n; i++)
      for (int j = 1; j <= n; j++) d[i][j] = min(d[i][j], d[i][k] + d[k][j]);
  int temp = find(1);
  for (int i = 1; i <= m; i++) {
    int fx = find(e[i].x), fy = find(e[i].y);
    if (fx != temp && fy != temp) {
      flag = false;
      break;
    }
  }
  if (!flag)
    puts("-1");
  else {
    for (int i = 1; i <= n; i++)
      if (du[i] % 2 == 1) S[++top] = i;
    int limit = (1 << top) - 1;
    for (int i = 1; i <= limit; i++) f[i] = inf;
    for (int sta = 0; sta <= limit; sta++)
      if (f[sta] != inf)
        for (int i = 1; i <= top; i++)
          if (!(sta >> (i - 1) & 1))
            for (int j = 1; j <= top; j++)
              if (!(sta >> (j - 1) & 1) && i != j && d[S[i]][S[j]] != inf)
                f[sta | (1 << (i - 1)) | (1 << (j - 1))] =
                    min(f[sta | (1 << (i - 1)) | (1 << (j - 1))],
                        f[sta] + d[S[i]][S[j]]);
    printf("%d\n", ans + f[limit]);
  }
  return 0;
}
