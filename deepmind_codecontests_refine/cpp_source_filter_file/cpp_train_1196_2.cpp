#include <bits/stdc++.h>
std::vector<int> G[100033];
bool del[100033];
int legs[100033];
void dfs(int a, int par = 0) {
  if (G[a].size() <= 2) {
    del[a] = 1;
    for (int i = (0), __ = (G[a].size()); i < __; ++i)
      if (G[a][i] != par) dfs(G[a][i], a);
  }
}
int n;
int a, b;
int cnt;
int main() {
  scanf("%d", &n);
  for (int i = (0), __ = (n - 1); i < __; ++i) {
    scanf("%d%d", &a, &b);
    G[a].push_back(b);
    G[b].push_back(a);
  }
  for (int a = (1), __ = (n); a <= __; ++a)
    if (G[a].size() == 1) dfs(a);
  for (int a = (1), __ = (n); a <= __; ++a)
    for (int j = (0), __ = (G[a].size()); j < __; ++j)
      if (del[G[a][j]]) {
        legs[a] = std::min(legs[a] + 1, 2);
      }
  for (int a = (1), __ = (n); a <= __; ++a)
    if (!del[a]) {
      cnt = 0;
      for (int j = (0), __ = (G[a].size()); j < __; ++j)
        if (!del[G[a][j]] && G[G[a][j]].size() - legs[G[a][j]] > 1) {
          ++cnt;
        }
      if (cnt == 2) {
        puts("No");
        return 0;
      }
    }
  puts("Yes");
  return 0;
}
