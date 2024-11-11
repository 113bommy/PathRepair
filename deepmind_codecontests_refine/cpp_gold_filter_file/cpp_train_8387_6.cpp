#include <bits/stdc++.h>
using namespace std;
struct qwq {
  int nxt, to;
};
qwq edge[2000010];
int n, cnt, root, sum, a;
int fa[1000010], head[1000010], s[1000010], val[1000010], ans[3];
void addedge(int f, int t) {
  edge[++cnt].nxt = head[f];
  edge[cnt].to = t;
  head[f] = cnt;
}
void dfs(int now) {
  s[now] = val[now];
  for (int i = head[now]; i; i = edge[i].nxt) {
    int to = edge[i].to;
    if (to == fa[now]) continue;
    dfs(to);
    s[now] += s[to];
  }
  if (s[now] == sum / 3) {
    s[now] = 0;
    ans[++a] = now;
  }
}
int main() {
  scanf("%d", &n);
  for (int i = 1; i <= n; i++) {
    scanf("%d%d", &fa[i], &val[i]);
    addedge(i, fa[i]);
    addedge(fa[i], i);
    if (fa[i] == 0) root = i;
    sum += val[i];
  }
  if (sum % 3) {
    printf("-1");
  } else {
    dfs(root);
    if (a >= 3) {
      printf("%d %d", ans[1], ans[2]);
    } else
      printf("-1");
  }
  return ~~(0 - 0);
}
