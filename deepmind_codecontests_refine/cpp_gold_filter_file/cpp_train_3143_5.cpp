#include <bits/stdc++.h>
#pragma GCC optimize(2)
using namespace std;
template <typename T>
void read(T &x) {
  x = 0;
  char op = getchar();
  int F = 1;
  while (!isdigit(op)) {
    if (op == '-') F *= -1;
    op = getchar();
  }
  while (isdigit(op)) {
    x = (x << 1) + (x << 3) + op - '0';
    op = getchar();
  }
  x *= F;
}
template <typename T, typename... Args>
void read(T &x, Args &...args) {
  read(x);
  read(args...);
}
const int N = 100005;
const int inf = 1e9;
vector<int> G[N];
void add(int u, int v) { G[u].push_back(v); }
int used[N], fa[N], dep[N];
vector<int> all;
int in_cycle[N];
void dfs(int u, int p) {
  used[u] = 1, fa[u] = p;
  for (auto v : G[u]) {
    if (v == p) continue;
    if (used[v]) {
      if (dep[v] > dep[u]) continue;
      int now = u;
      while (true) {
        all.push_back(now);
        in_cycle[now] = 1;
        if (now == v) break;
        now = fa[now];
      }
    } else {
      dep[v] = dep[u] + 1;
      dfs(v, u);
    }
  }
}
void print_circle() {
  cout << "print_circle\n";
  printf("size %d\n", all.size());
  for (auto v : all) {
    cout << v << ' ';
  }
  cout << '\n';
}
int frob;
int sz[N], dp[N], sum_dp[N];
int sum_sz[N];
void dfs2(int u, int p) {
  sz[u] = 1, dp[u] = 0;
  for (auto v : G[u]) {
    if (v == p || v == frob) continue;
    dfs2(v, u);
    sz[u] += sz[v];
    dp[u] += dp[v];
  }
  dp[u] += sz[u];
}
vector<int> allv;
void dfs3(int u, int p) {
  allv.push_back(u);
  for (auto v : G[u]) {
    if (v == p || v == frob) continue;
    dep[v] = dep[u] + 1;
    dfs3(v, u);
  }
}
void print_allv() {
  printf("Print allv\n");
  for (auto v : allv) {
    cout << v << ' ';
  }
  cout << '\n';
}
int res[N], n;
int best[2][N];
int main() {
  read(n);
  for (int i = 1; i <= n; i++) {
    int u, v;
    read(u, v);
    add(u, v);
    add(v, u);
  }
  dfs(0, -1);
  int tot = 0;
  for (auto u : all) {
    frob = u;
    for (auto v : G[u]) {
      if (in_cycle[v]) continue;
      dfs2(v, u);
      sum_dp[u] += dp[v];
    }
    tot += sum_dp[u];
  }
  for (int i = 0; i < all.size(); i++) {
    sum_sz[i] = 1;
    for (auto v : G[all[i]]) {
      if (in_cycle[v]) continue;
      sum_sz[i] += sz[v];
    }
  }
  for (auto u : all) {
    frob = u;
    int add = -inf;
    for (auto v : G[u]) {
      if (in_cycle[v]) continue;
      int Size = n - sz[v];
      allv.clear();
      dep[v] = 2;
      dfs3(v, u);
      int sub = -dp[v];
      for (auto root : allv) {
        dfs2(root, u);
        add = max(add, dp[root] + dep[root] * Size + sub);
      }
    }
    if (add != -inf) {
      res[u] = sum_dp[u] + add;
    } else
      res[u] = n;
  }
  int q1 = 0, q2 = 1;
  for (int i = 0; i < all.size(); i++) {
    int &tmp = all[i];
    best[q1][i] = tot - sum_dp[tmp] + res[tmp];
  }
  for (int j = all.size(); j < (all.size() << 1); j++) {
    sum_sz[j] = sum_sz[j - all.size()];
  }
  for (int j = 1; j < (all.size() << 1); j++) {
    sum_sz[j] += sum_sz[j - 1];
  }
  for (int i = 0; i < all.size() - 1; i++) {
    memset(best[q2], 0, sizeof(best[q2]));
    for (int j = 0; j < all.size(); j++) {
      int tot = sum_sz[i + j];
      if (j > 0) tot -= sum_sz[j - 1];
      best[q2][j] = max(best[q2][j], best[q1][j] + (n - tot));
      int pre = j - 1;
      if (j == 0) pre += all.size();
      best[q2][pre] = max(best[q2][pre], best[q1][j] + (n - tot));
    }
    q1 ^= 1, q2 ^= 1;
  }
  int ans = 0;
  for (int i = 0; i < all.size(); i++) {
    ans = max(ans, best[q1][i]);
  }
  printf("%d\n", ans);
  return 0;
}
