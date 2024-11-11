#include <bits/stdc++.h>
using namespace std;
struct edge {
  int u, v, d, id;
};
edge e[100010 * 2];
vector<pair<int, int> > a[100010];
int fa[100010];
long long ans[100010];
int nc[100010], son[100010], id[100010];
bool vis[100010];
int n;
bool cmp(const edge &x, const edge &y) { return x.d < y.d; }
void input() {
  for (int i = 0; i < n - 1; i++) {
    scanf("%d%d%d", &e[i].u, &e[i].v, &e[i].d);
    e[i].id = i;
  }
  sort(e, e + n - 1, cmp);
}
void dfs(int x, int p, int tot) {
  vis[x] = true;
  son[x] = nc[x];
  for (int i = 0; i < a[x].size(); i++) {
    int v = a[x][i].first, iden = a[x][i].second;
    if (v != p) {
      if (tot) {
        ans[iden] = (long long)(tot - son[v]) * son[v];
      }
      dfs(v, x, tot);
      if (!tot) son[x] += son[v];
    }
  }
}
int find(int x) {
  int fx = x, tm;
  while (fa[fx] != fx) fx = fa[fx];
  while (fa[x] != fx) {
    tm = fa[x];
    fa[x] = fx;
    x = tm;
  }
  return fx;
}
void solve() {
  memset(ans, 0, sizeof(ans));
  for (int i = 1; i <= n; i++) fa[i] = i, nc[i] = 1;
  int len;
  for (int i = 0; i < n - 1; i += len) {
    for (len = 1; i + len < n && e[i].d == e[i + len - 1].d; len++)
      ;
    len--;
    if (len == 1) {
      int fx = find(e[i].u);
      int fy = find(e[i].v);
      fa[fy] = fx;
      ans[e[i].id] = (long long)nc[fx] * nc[fy];
      nc[fx] += nc[fy];
    } else {
      for (int j = i; j < i + len; j++) {
        int x = find(e[j].u), y = find(e[j].v);
        a[x].resize(0);
        a[y].resize(0);
        vis[x] = vis[y] = false;
      }
      for (int j = i; j < i + len; j++) {
        int x = find(e[j].u), y = find(e[j].v);
        a[x].push_back(make_pair(y, e[j].id));
        a[y].push_back(make_pair(x, e[j].id));
      }
      for (int j = i; j < i + len; j++) {
        int fx = find(e[j].u);
        if (!vis[fx]) {
          dfs(fx, -1, 0);
          dfs(fx, -1, son[fx]);
        }
      }
      for (int j = i; j < i + len; j++) {
        int fx = find(e[j].u), fy = find(e[j].v);
        fa[fy] = fx;
        nc[fx] += nc[fy];
      }
    }
  }
}
bool cmpid(const int x, const int y) {
  return ans[x] > ans[y] || (ans[x] == ans[y] && x < y);
}
void output() {
  for (int i = 0; i < n - 1; i++) id[i] = i;
  sort(id, id + n - 1, cmpid);
  vector<int> most;
  most.push_back(id[0]);
  for (int i = 1; i < n - 1; i++)
    if (ans[id[i]] == ans[id[0]]) most.push_back(id[i]);
  cout << ans[id[0]] * 2 << " " << most.size() << endl;
  for (int i = 0; i < most.size(); i++)
    if (i == 0)
      cout << most[i] + 1;
    else
      cout << " " << most[i] + 1;
  cout << endl;
}
int main() {
  while (scanf("%d", &n) != EOF) {
    input();
    solve();
    output();
  }
  return 0;
}
