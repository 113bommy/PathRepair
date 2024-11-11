#include <bits/stdc++.h>
using namespace std;
int n, m, k;
vector<int> g[250010];
int dep[250010], fa[250010];
int isleaf[250010];
void dfs(int now, int f) {
  fa[now] = f;
  dep[now] = dep[f] + 1;
  isleaf[now] = 1;
  for (int i = 0; i < g[now].size(); i++) {
    if (dep[g[now][i]]) continue;
    dfs(g[now][i], now);
    isleaf[now] = 0;
  }
}
int main() {
  scanf("%d%d%d", &n, &m, &k);
  int from, to;
  int limit = (n + k - 1) / k;
  for (int i = 1; i <= m; i++) {
    scanf("%d%d", &from, &to);
    g[from].push_back(to);
    g[to].push_back(from);
  }
  dfs(1, 0);
  for (int i = 1; i <= n; i++) {
    if (dep[i] >= limit) {
      int now = i;
      vector<int> line;
      while (now) {
        line.push_back(now);
        now = fa[now];
      }
      puts("PATH");
      cout << line.size() << endl;
      for (int i = 0; i < line.size(); i++) {
        cout << line[i] << " ";
      }
      puts("");
      return 0;
    }
  }
  puts("CYCLES");
  vector<int> leaf;
  for (int i = 1; i <= n; i++) {
    if (isleaf[i]) leaf.push_back(i);
  }
  vector<int> ans[200010];
  for (int i = 0; i < k; i++) {
    int flag = 0;
    int now = leaf[i];
    for (int j = 0; j < g[now].size(); j++) {
      if (dep[now] - dep[g[now][j]] > 1) {
        if (dep[now] - dep[g[now][j]] % 3 != 0) {
          flag = 1;
          int tmp = now;
          while (tmp != g[now][j]) {
            ans[i + 1].push_back(tmp);
            tmp = fa[tmp];
          }
          ans[i + 1].push_back(g[now][j]);
          break;
        }
      }
    }
    if (!flag) {
      int fa1 = 0, fa2 = 0;
      for (int j = 0; j < g[now].size(); j++) {
        if (dep[now] - dep[g[now][i]] > 1) {
          if (!fa1)
            fa1 = g[now][i];
          else if (!fa2)
            fa2 = g[now][i];
          else
            break;
        }
      }
      if (dep[fa1] > dep[fa2]) swap(fa1, fa2);
      int tmp = fa2;
      while (tmp != fa1) {
        ans[i + 1].push_back(tmp);
        tmp = fa[tmp];
      }
      ans[i + 1].push_back(fa1);
      ans[i + 1].push_back(now);
    }
  }
  for (int i = 1; i <= k; i++) {
    cout << ans[i].size() << endl;
    for (int j = 0; j < ans[i].size(); j++) {
      cout << ans[i][j] << " ";
    }
    puts("");
  }
}
