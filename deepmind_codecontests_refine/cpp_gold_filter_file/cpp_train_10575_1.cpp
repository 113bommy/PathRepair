#include <bits/stdc++.h>
using namespace std;
struct node {
  int to, val;
  node(int a, int b) : to(a), val(b) {}
};
vector<node> edge[300000 + 5];
int mark[300000 + 5], Next[300000 * 2 + 5][26], size[300000 + 5],
    dep[300000 + 5], ans[300000 + 5];
int n, cnt;
int Merge(int x, int y) {
  if (x == 0 || y == 0) return x | y;
  int i, z = ++cnt;
  size[z] = 1;
  for (i = 0; i <= 25; i++) {
    Next[z][i] = Merge(Next[x][i], Next[y][i]);
    size[z] += size[Next[z][i]];
  }
  return z;
}
void dfs(int now) {
  mark[now] = 1;
  int i, l = edge[now].size();
  size[now] = 1;
  for (i = 0; i <= l - 1; i++) {
    int v = edge[now][i].to, c = edge[now][i].val;
    if (mark[v]) continue;
    Next[now][c] = v;
    dep[v] = dep[now] + 1;
    dfs(v);
    size[now] += size[v];
  }
  ans[dep[now]] += size[now];
  int tmp = 0;
  cnt = n;
  for (i = 0; i <= 25; i++) tmp = Merge(tmp, Next[now][i]);
  ans[dep[now]] -= max(size[tmp], 1);
  return;
}
int main() {
  int i, u, v;
  char c[2];
  scanf("%d", &n);
  for (i = 1; i <= n - 1; i++)
    scanf("%d%d%s", &u, &v, &c), edge[u].push_back(node(v, c[0] - 'a')),
        edge[v].push_back(node(u, c[0] - 'a'));
  dep[1] = 1;
  dfs(1);
  int ansi = 0;
  for (i = 1; i <= n; i++)
    if (ans[i] > ans[ansi]) ansi = i;
  printf("%d\n%d\n", n - ans[ansi], ansi);
  return 0;
}
