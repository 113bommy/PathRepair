#include <bits/stdc++.h>
using namespace std;
const int maxx = 600010;
const double pi = acos(-1.0);
const double eps = 1e-15;
vector<int> g[maxx];
int t, n, m, u, v;
int res = 0, root = 0;
long long ans = 0, total = 0, sum = 0, cnt = 0;
long long a[maxx], b[maxx], bj[maxx], vis[maxx];
long long dp[maxx][4];
struct node {
  long long a, b, c;
} s[maxx];
void dfs(int x, int father) {
  int u = 0;
  for (int i = 0; i < g[x].size(); i++) {
    int to = g[x][i];
    if (to == father) continue;
    u = 1;
    dfs(to, x);
  }
  if (!u) root = x;
}
void dfs1(int x, int father) {
  if (ans) return;
  bj[++res] = x;
  int uu = 0;
  for (int i = 0; i < g[x].size(); i++) {
    int to = g[x][i];
    if (to == father) continue;
    uu++;
    dfs1(to, x);
  }
  if (uu > 1) {
    ans = 1;
    return;
  }
}
void dfs2(int x, int father, int op) {
  cnt++;
  if (cnt % 3 == 1) {
    if (op == 1) sum += s[x].c;
    if (op == 2) sum += s[x].c;
    if (op == 3) sum += s[x].b;
    if (op == 4) sum += s[x].b;
    if (op == 5) sum += s[x].a;
    if (op == 6) sum += s[x].a;
  }
  if (cnt % 3 == 2) {
    if (op == 1) sum += s[x].a;
    if (op == 2) sum += s[x].b;
    if (op == 3) sum += s[x].a;
    if (op == 4) sum += s[x].c;
    if (op == 5) sum += s[x].b;
    if (op == 6) sum += s[x].c;
  }
  if (cnt % 3 == 0) {
    if (op == 1) sum += s[x].b;
    if (op == 2) sum += s[x].a;
    if (op == 3) sum += s[x].c;
    if (op == 4) sum += s[x].a;
    if (op == 5) sum += s[x].c;
    if (op == 6) sum += s[x].b;
  }
  for (int i = 0; i < g[x].size(); i++) {
    int to = g[x][i];
    if (to == father) continue;
    dfs2(to, x, op);
  }
}
int main() {
  scanf("%d", &n);
  for (int i = 1; i <= n; i++) scanf("%lld", &s[i].a);
  for (int i = 1; i <= n; i++) scanf("%lld", &s[i].b);
  for (int i = 1; i <= n; i++) scanf("%lld", &s[i].c);
  for (int i = 1; i < n; i++)
    scanf("%d%d", &u, &v), g[u].push_back(v), g[v].push_back(u);
  dfs(1, 1);
  dfs1(root, root);
  if (ans)
    printf("-1");
  else {
    ans = 1e8;
    sum = cnt = 0;
    if (g[g[root][0]][0] == root)
      u = g[g[root][0]][1];
    else
      u = g[g[root][0]][0];
    sum += s[root].a + s[g[root][0]].b;
    dfs2(u, g[root][0], 1);
    if (sum < ans) ans = sum, total = 1;
    sum = cnt = 0;
    if (g[g[root][0]][0] == root)
      u = g[g[root][0]][1];
    else
      u = g[g[root][0]][0];
    sum += s[root].b + s[g[root][0]].a;
    dfs2(u, g[root][0], 2);
    if (sum < ans) ans = sum, total = 2;
    sum = cnt = 0;
    if (g[g[root][0]][0] == root)
      u = g[g[root][0]][1];
    else
      u = g[g[root][0]][0];
    sum += s[root].a + s[g[root][0]].c;
    dfs2(u, g[root][0], 3);
    if (sum < ans) ans = sum, total = 3;
    sum = cnt = 0;
    if (g[g[root][0]][0] == root)
      u = g[g[root][0]][1];
    else
      u = g[g[root][0]][0];
    sum += s[root].c + s[g[root][0]].a;
    dfs2(u, g[root][0], 4);
    if (sum < ans) ans = sum, total = 4;
    sum = cnt = 0;
    if (g[g[root][0]][0] == root)
      u = g[g[root][0]][1];
    else
      u = g[g[root][0]][0];
    sum += s[root].b + s[g[root][0]].c;
    dfs2(u, g[root][0], 5);
    if (sum < ans) ans = sum, total = 5;
    sum = cnt = 0;
    if (g[g[root][0]][0] == root)
      u = g[g[root][0]][1];
    else
      u = g[g[root][0]][0];
    sum += s[root].c + s[g[root][0]].b;
    dfs2(u, g[root][0], 6);
    if (sum < ans) ans = sum, total = 6;
    printf("%lld\n", ans);
    if (total == 1) {
      a[1] = 1, a[2] = 2, a[0] = 3;
      for (int i = 1; i <= n; i++) b[bj[i]] = a[i % 3];
    }
    if (total == 2) {
      a[1] = 2, a[2] = 1, a[0] = 3;
      for (int i = 1; i <= n; i++) b[bj[i]] = a[i % 3];
    }
    if (total == 3) {
      a[1] = 1, a[2] = 3, a[0] = 2;
      for (int i = 1; i <= n; i++) b[bj[i]] = a[i % 3];
    }
    if (total == 4) {
      a[1] = 3, a[2] = 1, a[0] = 2;
      for (int i = 1; i <= n; i++) b[bj[i]] = a[i % 3];
    }
    if (total == 5) {
      a[1] = 2, a[2] = 3, a[0] = 1;
      for (int i = 1; i <= n; i++) b[bj[i]] = a[i % 3];
    }
    if (total == 6) {
      a[1] = 3, a[2] = 2, a[0] = 1;
      for (int i = 1; i <= n; i++) b[bj[i]] = a[i % 3];
    }
    for (int i = 1; i <= n; i++) printf("%lld ", b[i]);
  }
  return 0;
}
