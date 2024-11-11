#include <bits/stdc++.h>
int n;
int sz[(300010)], to[(300010)][26], _sz[(300010)], _to[(300010)][26];
bool saved[(300010)];
std::vector<int> rollback;
int ans[(300010)];
int merge(int u, int v) {
  if (!u) return v;
  if (!v) return u;
  if (sz[u] < sz[v]) {
    std::swap(u, v);
  }
  if (!saved[u]) {
    saved[u] = 1;
    _sz[u] = sz[u];
    memcpy(_to[u], to[u], sizeof to[u]);
    rollback.push_back(u);
  }
  for (int k = 0; k < 26; ++k) {
    int &su = to[u][k];
    int sv = to[v][k];
    if (su || sv) {
      sz[u] -= sz[su];
      su = merge(su, sv);
      sz[u] += sz[su];
    }
  }
  return u;
}
void dfs(int u, int depth) {
  sz[u] = 1;
  for (int k = 0; k < 26; ++k) {
    int v = to[u][k];
    if (v) {
      dfs(v, depth + 1);
      sz[u] += sz[v];
    }
  }
  int w = 0;
  for (int k = 0; k < 26; ++k) {
    int v = to[u][k];
    if (v) {
      w = merge(w, v);
    }
  }
  ans[depth] = w ? (sz[u] - sz[w]) : 0;
  for (auto v : rollback) {
    if (saved[v]) {
      saved[v] = 0;
      sz[v] = _sz[v];
      memcpy(to[v], _to[v], sizeof _to[v]);
    }
  }
  rollback.clear();
}
int main() {
  scanf("%d", &n);
  for (int i = 1; i < n; ++i) {
    int u, v;
    char t;
    scanf("%d%d %c", &u, &v, &t);
    to[u][t - 'a'] = v;
  }
  dfs(1, 1);
  int ans1 = INT_MAX, ans2 = 0;
  for (int i = 1; i <= n; ++i) {
    if (ans1 > n - ans[i]) {
      ans1 = n - ans[i];
      ans2 = i;
    }
  }
  printf("%d\n%d\n", ans1, ans2);
  return 0;
}
