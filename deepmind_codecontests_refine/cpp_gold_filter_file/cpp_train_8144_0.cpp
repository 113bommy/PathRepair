#include <bits/stdc++.h>
using namespace std;
const int N = 1100000;
int n, a[N], b[N];
struct node {
  int to;
  int u, v;
  node() {}
  node(int x, int y, int z) : to(x), u(y), v(z) {}
};
int fir[N];
vector<node> e[N];
vector<int> rev[N], print;
vector<bool> vis[N];
void dfs(int from) {
  for (int &i = fir[from]; i < e[from].size(); ++i)
    if (!vis[from][i]) {
      int to = e[from][i].to, u = e[from][i].u, v = e[from][i].v;
      vis[from][i] = vis[to][rev[from][i]] = true;
      dfs(to);
      print.push_back(v), print.push_back(u);
    }
}
void solve(int x) {
  int S = 1 << x;
  for (int i = 1; i <= n; ++i) a[i] %= S, b[i] %= S;
  for (int i = 0; i < S; ++i) e[i].clear(), rev[i].clear(), vis[i].clear();
  for (int i = 1; i <= n; ++i) {
    if (a[i] == b[i]) {
      e[a[i]].push_back(node(a[i], 2 * i - 1, 2 * i));
      e[a[i]].push_back(node(a[i], 2 * i, 2 * i - 1));
      rev[a[i]].push_back(e[a[i]].size() - 1);
      rev[a[i]].push_back(e[a[i]].size() - 2);
    } else {
      e[a[i]].push_back(node(b[i], 2 * i - 1, 2 * i));
      e[b[i]].push_back(node(a[i], 2 * i, 2 * i - 1));
      rev[a[i]].push_back(e[b[i]].size() - 1);
      rev[b[i]].push_back(e[a[i]].size() - 1);
    }
    vis[a[i]].push_back(false);
    vis[b[i]].push_back(false);
  }
  for (int i = 0; i < S; ++i)
    if (e[i].size() % 2 != 0) return;
  print.clear();
  memset(fir, 0, sizeof(fir));
  dfs(a[1]);
  if (print.size() != 2 * n) return;
  printf("%d\n", x);
  for (int i = 2 * n - 1; i >= 0; --i) printf("%d ", print[i]);
  exit(0);
}
int main() {
  scanf("%d", &n);
  for (int i = 1; i <= n; ++i) {
    scanf("%d%d", &a[i], &b[i]);
  }
  for (int k = 20; k >= 0; --k) {
    solve(k);
  }
  return 0;
}
