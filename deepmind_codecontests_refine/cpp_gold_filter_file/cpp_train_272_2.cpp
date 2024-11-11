#include <bits/stdc++.h>
using namespace std;
struct s {
  int to, next;
} edge[2 * 200005];
int head[200005];
int tot;
void add(int x, int y) {
  edge[tot].to = y;
  edge[tot].next = head[x];
  head[x] = tot++;
}
int f[200005][3], id[200005][3], ff[200005 * 2], cnt;
bool dfs(int x, int sum) {
  if (f[x][sum ^ 1] == 1) return false;
  f[x][sum ^ 1] = 1;
  ff[cnt++] = x;
  if (head[x] == -1 && f[x][1]) return true;
  for (int i = head[x]; i != -1; i = edge[i].next) {
    int z = edge[i].to;
    if (dfs(z, sum ^ 1)) return true;
  }
  cnt--;
  return false;
}
int vis[200005];
bool check(int x) {
  vis[x] = 1;
  bool flag = false;
  for (int i = head[x]; i != -1; i = edge[i].next) {
    int z = edge[i].to;
    if (vis[z] == 1)
      flag = true;
    else if (vis[z] == 0)
      flag = check(z);
    if (flag) return true;
  }
  vis[x] = 2;
  return false;
}
int main() {
  int n, m;
  scanf("%d %d", &n, &m);
  memset(head, -1, sizeof(head));
  tot = 0;
  int x, k;
  for (int i = 1; i <= n; ++i) {
    scanf("%d", &k);
    for (int j = 1; j <= k; ++j) {
      scanf("%d", &x);
      add(i, x);
    }
  }
  scanf("%d", &x);
  cnt = 0;
  if (dfs(x, 1)) {
    printf("Win\n");
    for (int i = 0; i <= cnt - 1; ++i)
      printf("%d%c", ff[i], i == cnt - 1 ? '\n' : ' ');
  } else if (check(x))
    printf("Draw\n");
  else
    printf("Lose\n");
}
