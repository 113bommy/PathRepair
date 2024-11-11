#include <bits/stdc++.h>
using namespace std;
const int maxn = 600500;
struct data {
  int x, c;
};
vector<data> g[maxn];
int c[maxn][26], sz[maxn], dep[maxn], ans[maxn];
char ch[10];
int n, tot, mx;
int merge(int a, int b) {
  if (!a || !b) return a | b;
  int x = ++tot;
  sz[x] = 1;
  for (int i = 0; i <= 25; i++) {
    c[x][i] = merge(c[a][i], c[b][i]);
    sz[x] += sz[c[x][i]];
  }
  return x;
}
void dfs(int u, int fa) {
  sz[u] = 1;
  mx = max(mx, dep[u]);
  for (auto v : g[u]) {
    if (v.x == fa) continue;
    dep[v.x] = dep[u] + 1;
    c[u][v.c] = v.x;
    dfs(v.x, u);
    sz[u] += sz[v.x];
  }
  ans[dep[u]] += sz[u];
  int p = 0;
  tot = n;
  for (int i = 0; i <= 25; i++) p = merge(p, c[u][i]);
  ans[dep[u]] -= max(1, sz[p]);
}
int main() {
  scanf("%d", &n);
  for (int i = 2; i <= n; i++) {
    int x, y;
    scanf("%d%d%s", &x, &y, ch);
    g[x].push_back((data){y, ch[0] - 'a'});
    g[y].push_back((data){x, ch[0] - 'a'});
  }
  dep[1] = 1;
  dfs(1, 0);
  int out0 = 0, out1 = 0;
  for (int i = 1; i <= mx; i++)
    if (out0 < ans[i]) out0 = ans[i], out1 = i;
  cout << n - out0 << endl;
  cout << out1 << endl;
  return 0;
}
