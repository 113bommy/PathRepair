#include <bits/stdc++.h>
using namespace std;
int n, m;
struct node {
  int x, y;
} ans[100000];
int bian[1000000], fa[10000], tot;
int getfa(int i) {
  if (i == fa[i]) return fa[i];
  return fa[i] = getfa(fa[i]);
}
int main() {
  scanf("%d%d", &n, &m);
  for (int i = 1; i <= n; i++) fa[i] = i;
  for (int i = 1; i <= m; i++) {
    int x, y;
    scanf("%d%d", &x, &y);
    bian[x]++;
    bian[y]++;
    fa[getfa(x)] = getfa(y);
  }
  for (int i = 1; i <= n; i++)
    if (bian[i] > 2) {
      printf("NO");
      return 0;
    }
  for (int i = 1; i <= n; i++)
    for (int j = i; j <= n; j++)
      if (bian[i] < 2 && bian[j] < 2 && getfa(i) != getfa(j)) {
        ans[++tot] = node{i, j};
        bian[i]++;
        bian[j]++;
        fa[getfa(i)] = getfa(j);
      }
  if (tot + m < n) {
    tot++;
    for (int i = 1; i <= n; i++)
      if (bian[i] < 2) {
        bian[i]++;
        if (ans[tot].x)
          ans[tot].y = i;
        else
          ans[tot].x = i;
      }
  }
  for (int i = 1; i <= n; i++)
    if (getfa(i) != getfa(1)) {
      printf("NO");
      return 0;
    }
  printf("YES\n");
  printf("%d\n", tot);
  for (int i = 1; i <= tot; i++) printf("%d %d\n", ans[i].x, ans[i].y);
}
