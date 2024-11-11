#include <bits/stdc++.h>
const int MAXN = 5e5 + 10;
int n;
std::vector<int> g[MAXN];
char s[MAXN];
int col[MAXN];
void dfs(int u, int fa, int c) {
  col[u] = c;
  for (int v : g[u]) {
    if (v == fa) continue;
    dfs(v, u, c ^ 1);
  }
}
bool solve() {
  dfs(1, 0, 0);
  int p[2];
  p[0] = p[1] = 0;
  for (int i = 1; i <= n; i++) {
    if (s[i] == 'W') {
      for (int j : g[i]) {
        if (g[i].size() - 1 + g[j].size() - 1 >= 2) {
          return 1;
        }
        if (s[j] == 'W' && g[i].size() - 1 + g[j].size() - 1 >= 1) {
          return 1;
        }
      }
      if (p[col[i]]) return 1;
      p[col[i]]++;
    } else {
      int cnt = 0;
      for (int j : g[i]) {
        if (g[i].size() - 2 + g[j].size() - 1 >= 2) {
          cnt++;
        }
      }
      if (cnt >= 2) return 1;
    }
    if (g[i].size() == 3) {
      if (p[col[i] ^ 1]) return 1;
      p[col[i] ^ 1]++;
    }
    int x = 0;
    for (int j : g[i]) {
      if (s[j] == 'W') x++;
    }
    if (x >= 2) return 1;
  }
  return 0;
}
int main() {
  int t;
  scanf("%d", &t);
  while (t--) {
    scanf("%d", &n);
    for (int i = 1; i <= n; i++) g[i].clear();
    for (int i = 1; i < n; i++) {
      int u, v;
      scanf("%d%d", &u, &v);
      g[u].push_back(v);
      g[v].push_back(u);
    }
    scanf("%s", s + 1);
    puts(solve() ? "White" : "Draw");
  }
}
