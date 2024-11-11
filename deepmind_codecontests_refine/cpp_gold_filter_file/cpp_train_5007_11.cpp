#include <bits/stdc++.h>
using namespace std;
bool used[1000010], del[1000010];
vector<int> a[1000010], b[1000010];
int n, m;
void dfs(int x) {
  for (int i = x; i <= n; i++)
    if (del[i] == 0) {
      del[i] = 1;
      for (int j = 0; j < a[i].size(); j++) del[a[i][j]] = 1;
      dfs(i + 1);
      used[i] = 1;
      for (int j = 0; j < b[i].size(); j++)
        if (used[b[i][j]] == 1) {
          used[i] = 0;
          break;
        }
      return;
    }
}
int main() {
  scanf("%d%d", &n, &m);
  int u, v;
  for (int i = 1; i <= m; i++) {
    scanf("%d%d", &u, &v);
    a[u].push_back(v);
    b[v].push_back(u);
  }
  dfs(1);
  int cnt = 0;
  for (int i = 1; i <= n; i++)
    if (used[i] == 1) cnt++;
  printf("%d\n", cnt);
  for (int i = 1; i <= n; i++)
    if (used[i] == 1) printf("%d ", i);
}
