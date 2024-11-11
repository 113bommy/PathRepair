#include <bits/stdc++.h>
#pragma comment(linker, "/STACK:102400000,102400000")
using namespace std;
int n, m, ege;
int d[3005][3005], pre[3005 * 2], head[3005], en[3005 * 2], v[3005 * 2];
queue<int> qu;
bool vis[3005];
void add(int a, int b, int c) {
  ege++;
  pre[ege] = head[a];
  head[a] = ege;
  en[ege] = b;
  v[ege] = c;
}
void bfs(int x) {
  d[x][x] = 0;
  memset(vis, 0, sizeof(vis));
  while (!qu.empty()) qu.pop();
  vis[x] = 1;
  qu.push(x);
  while (!qu.empty()) {
    int k = qu.front();
    qu.pop();
    int p = head[k];
    while (p != -1) {
      if (!vis[en[p]])
        d[x][en[p]] = d[x][k] + v[p], qu.push(en[p]), vis[en[p]] = 1;
      p = pre[p];
    }
  }
}
void init() {
  memset(d, -1, sizeof(d));
  memset(head, -1, sizeof(head));
  ege = 0;
}
int main() {
  scanf("%d%d", &n, &m);
  init();
  int a, b;
  for (int i = 1; i <= m; i++) {
    scanf("%d%d", &a, &b);
    add(a, b, 1);
    add(b, a, 1);
  }
  for (int i = 1; i <= n; i++) bfs(i);
  int s1, s2, t1, t2, l1, l2;
  scanf("%d%d%d", &s1, &t1, &l1);
  scanf("%d%d%d", &s2, &t2, &l2);
  if (d[s1][t1] > l1 || d[s2][t2] > l2) {
    printf("-1\n");
    return 0;
  }
  int ans = d[s1][t1] + d[s2][t2];
  for (int i = 1; i <= n; i++)
    for (int j = 1; j <= n; j++) {
      if (i == j) continue;
      if (d[s1][i] + d[i][j] + d[j][t1] <= l1) {
        if (d[s2][i] + d[i][j] + d[j][t2] <= l2)
          ans = min(ans, d[s1][i] + d[j][t1] + d[i][j] + d[s2][i] + d[j][t2]);
        if (d[s2][j] + d[i][j] + d[i][t2] <= l2)
          ans = min(ans, d[s1][i] + d[j][t1] + d[i][j] + d[s2][j] + d[i][t2]);
      }
    }
  printf("%d\n", m - ans);
}
