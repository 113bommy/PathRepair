#include <bits/stdc++.h>
using namespace std;
const int maxn = 1010;
vector<pair<int, int>> ve[maxn];
struct edge {
  int u, v, w;
} e[maxn], ans[maxn * 10];
vector<int> leaf[maxn];
int in[maxn], tot;
int p[maxn], n;
void dfs(int u) {
  if (in[u] == 1) {
    leaf[u].push_back(u);
    return;
  }
  for (auto& tmp : ve[u]) {
    int v = tmp.first;
    if (v == p[u]) continue;
    p[v] = u;
    dfs(v);
    leaf[u].push_back(leaf[v][0]);
  }
}
void pre() {
  for (int i = 1; i <= n; i++)
    if (in[i] > 2) {
      dfs(i);
      break;
    }
  for (int i = 1; i <= n; i++) {
    if (ve[i].size() > 2 && leaf[i].size() <= 2) {
      int u = p[i];
      for (auto& v : leaf[u]) {
        if (v != leaf[i][0] && v != leaf[i][1]) {
          leaf[i].push_back(v);
          break;
        }
      }
    }
  }
}
void add(int u, int v, int w) {
  int l1 = leaf[v][0], l2 = leaf[v][1];
  if (l1 == u) l1 = leaf[v][2];
  if (l2 == u) l2 = leaf[v][2];
  ans[tot].u = u;
  ans[tot].v = l1;
  ans[tot++].w = w / 2;
  ans[tot].u = u;
  ans[tot].v = l2;
  ans[tot++].w = w / 2;
  ans[tot].u = l2;
  ans[tot].v = l1;
  ans[tot++].w = -w / 2;
}
void solve() {
  tot = 0;
  for (int i = 1; i < n; i++) {
    int u = e[i].u, v = e[i].v, w = e[i].w;
    if (v == p[u]) swap(u, v);
    if (in[u] == 1)
      add(u, v, w);
    else if (in[v] == 1)
      add(v, u, w);
    else {
      int t = leaf[v][0];
      add(t, u, w);
      add(t, v, -w);
    }
  }
  printf("%d\n", tot);
  for (int i = 0; i < tot; i++) {
    printf("%d %d %d\n", ans[i].u, ans[i].v, ans[i].w);
  }
}
void test() {
  for (int i = 1; i <= n; i++) {
    printf("leafnum[%d]:%d\n", i, leaf[i].size());
    for (auto& tmp : leaf[i]) {
      printf("%d ", tmp);
    }
    printf("\n");
  }
}
int main() {
  while (~scanf("%d", &n)) {
    int u, v, w;
    for (int i = 0; i <= n; i++) {
      ve[i].clear();
      leaf[i].clear();
      in[i] = 0;
      p[i] = 0;
    }
    for (int i = 1; i < n; i++) {
      scanf("%d%d%d", &u, &v, &w);
      e[i].u = u;
      e[i].v = v;
      e[i].w = w;
      ve[u].push_back(make_pair(v, w));
      ve[v].push_back(make_pair(u, w));
      in[u]++;
      in[v]++;
    }
    bool flag = 1;
    for (int i = 1; i <= n; i++)
      if (in[i] == 2) {
        flag = 0;
        break;
      }
    if (!flag) {
      printf("NO\n");
      continue;
    }
    printf("YES\n");
    if (n == 2) {
      printf("1\n");
      printf("%d %d %d\n", e[0].u, e[0].v, e[0].w);
      continue;
    }
    pre();
    solve();
  }
}
