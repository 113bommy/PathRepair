#include <bits/stdc++.h>
using namespace std;
const int maxn = 1e5 + 10;
int n, m, k;
vector<int> vec[maxn];
vector<int> path;
int vis[maxn];
int dep[maxn];
int son[maxn];
bool dfs(int u, int fa) {
  vis[u] = vis[fa] + 1;
  for (auto& v : vec[u]) {
    if (v == fa) continue;
    if (vis[v]) {
      if (vis[u] < vis[v]) continue;
      if (vis[u] - vis[v] + 1 > k) continue;
      vector<int> ans;
      while (path.back() != v) {
        ans.emplace_back(path.back());
        path.pop_back();
      }
      ans.emplace_back(v);
      int lens = ans.size();
      printf("2\n%d\n", lens);
      for (int i = 0; i < lens; i++)
        printf("%d%c", ans[i], i == lens - 1 ? '\n' : ' ');
      return true;
    } else {
      path.emplace_back(v);
      if (dfs(v, u)) return true;
      path.pop_back();
    }
  }
  return false;
}
bool dfs2(int u, int fa) {
  vis[u] = 1;
  for (auto& v : vec[u]) {
    if (v == fa) continue;
    if (vis[v]) {
      vector<int> ans;
      while (path.back() != v) {
        ans.emplace_back(path.back());
        path.pop_back();
      }
      ans.emplace_back(v);
      int lens = ans.size();
      ans.pop_back();
      --lens;
      int num = (k + 1) / 2;
      printf("1\n%d", ans[0]);
      for (int i = 2; num; i += 2) {
        printf(" %d", ans[i]);
        --num;
      }
      printf("\n");
      return true;
    } else {
      path.emplace_back(v);
      if (dfs2(v, u)) return true;
      path.pop_back();
    }
  }
  return false;
}
void sg() {
  path.emplace_back(1);
  if (dfs(1, 0)) return;
  fill(vis + 1, vis + 1 + n, 0);
  dfs2(1, 0);
}
void dfs1(int u, int fa) {
  dep[u] = dep[fa] + 1;
  for (auto& v : vec[u]) {
    if (v == fa) continue;
    dfs1(v, u);
    if (dep[v] > dep[son[u]]) son[u] = v;
  }
  return;
}
vector<int> v1;
vector<int> v2;
void st() {
  dfs1(1, 0);
  for (int i = 1; i <= n; i++) {
    if (dep[i] & 1)
      v1.emplace_back(i);
    else
      v2.emplace_back(i);
  }
  if (v1.size() < v2.size()) swap(v1, v2);
  int num = (k + 1) / 2;
  printf("1\n%d", v1[0]);
  --num;
  for (int i = 1; num; i++) {
    printf(" %d", v1[i]);
    --num;
  }
  printf("\n");
  return;
}
int main() {
  scanf("%d%d%d", &n, &m, &k);
  for (int i = 1; i <= m; i++) {
    int u, v;
    scanf("%d%d", &u, &v);
    vec[u].emplace_back(v);
    vec[v].emplace_back(u);
  }
  if (m > n - 1)
    sg();
  else
    st();
  return 0;
}
