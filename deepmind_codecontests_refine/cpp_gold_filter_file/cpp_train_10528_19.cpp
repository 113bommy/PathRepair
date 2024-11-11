#include <bits/stdc++.h>
using namespace std;
struct Edge {
  int to;
  int nex;
} e[1000005];
bool vis[300005];
int head[300005], tot;
int d[300005], fa[300005];
vector<int> v[300005], ans[300005], leaf;
bool cmp(int x, int y) { return d[x] > d[y]; }
void add(int x, int y) {
  e[tot].to = y;
  e[tot].nex = head[x];
  head[x] = tot++;
}
void dfs(int x) {
  vis[x] = 1;
  bool f = 1;
  for (int i = head[x]; i != -1; i = e[i].nex) {
    int y = e[i].to;
    if (vis[y]) continue;
    d[y] = d[x] + 1;
    fa[y] = x;
    dfs(y);
    f = 0;
  }
  if (f) leaf.push_back(x);
}
int main() {
  memset(head, -1, sizeof head);
  int n, m, k, x, y;
  scanf("%d%d%d", &n, &m, &k);
  for (int i = 1; i <= m; i++) {
    scanf("%d%d", &x, &y);
    add(x, y);
    add(y, x);
    v[x].push_back(y);
    v[y].push_back(x);
  }
  d[1] = 1;
  dfs(1);
  int mx = *max_element(d + 1, d + n + 1);
  if (mx >= n / k) {
    puts("PATH");
    for (int i = 1; i <= n; i++) {
      if (d[i] == mx) {
        int st = i;
        while (st != 1) ans[0].push_back(st), st = fa[st];
        ans[0].push_back(st);
        break;
      }
    }
    printf("%d\n", (int)ans[0].size());
    for (auto x : ans[0]) printf("%d ", x);
    puts("");
  } else {
    for (int i = 0; i < k; i++) {
      int x = leaf[i];
      sort(v[x].begin(), v[x].end(), cmp);
      if (v[x][0] != fa[x]) {
        puts("@@");
      }
      int y = v[x][1], z = v[x][2];
      if ((d[x] - d[y] + 1) % 3 != 0) {
        int st = x;
        while (st != y) ans[i].push_back(st), st = fa[st];
        ans[i].push_back(st);
      } else if ((d[x] - d[z] + 1) % 3 != 0) {
        int st = x;
        while (st != z) ans[i].push_back(st), st = fa[st];
        ans[i].push_back(st);
      } else {
        int st = y;
        while (st != z) ans[i].push_back(st), st = fa[st];
        ans[i].push_back(st);
      }
    }
    puts("CYCLES");
    for (int i = 0; i < k; i++) {
      printf("%d\n", (int)ans[i].size());
      for (auto x : ans[i]) printf("%d ", x);
      puts("");
    }
  }
}
