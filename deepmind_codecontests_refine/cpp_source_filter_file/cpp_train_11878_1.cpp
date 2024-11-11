#include <bits/stdc++.h>
using namespace std;
const int MOD = 1e9 + 7;
const int INF = 1e9;
const int N = 1e6 + 5;
int id[N], sta[N], type[N];
vector<int> v[N], son[N];
int dfs(int u) {
  switch (type[u]) {
    case 0:
      return sta[u];
    case 1:
      return sta[u] = dfs(son[u][0]) & dfs(son[u][1]);
    case 2:
      return sta[u] = dfs(son[u][0]) | dfs(son[u][1]);
    case 3:
      return sta[u] = dfs(son[u][0]) ^ dfs(son[u][1]);
    case 4:
      return sta[u] = !dfs(son[u][0]);
  }
}
int cnt;
int solve(int u) {
  int i1 = 0, i2 = 0;
  switch (type[u]) {
    case 0:
      v[cnt].push_back(id[u]);
      return cnt++;
    case 1:
      if (sta[son[u][1]]) i1 = solve(son[u][0]);
      if (sta[son[u][0]]) i2 = solve(son[u][1]);
      break;
    case 2:
      if (sta[son[u][1]] == 0) i1 = solve(son[u][0]);
      if (sta[son[u][0]] == 0) i2 = solve(son[u][1]);
      break;
    case 3:
      i1 = solve(son[u][0]);
      i2 = solve(son[u][1]);
      break;
    case 4:
      return solve(son[u][0]);
  }
  if (!i1 && !i2) return 0;
  if (v[i1].size() < v[i2].size()) swap(i1, i2);
  for (int e : v[i2]) v[i1].push_back(e);
  return i1;
}
int ans[N];
int main() {
  int n;
  scanf("%d", &n);
  char op[10];
  int tot = 0;
  for (int i = 1; i <= n; i++) {
    scanf("%s", op);
    if (op[0] == 'I') {
      type[i] = 0;
      id[i] = ++tot;
      scanf("%d", &sta[i]);
    } else if (op[0] == 'A') {
      type[i] = 1;
      son[i].resize(2);
      scanf("%d%d", &son[i][0], &son[i][1]);
    } else if (op[0] == 'O') {
      type[i] = 2;
      son[i].resize(2);
      scanf("%d%d", &son[i][0], &son[i][1]);
    } else if (op[0] == 'X') {
      type[i] = 3;
      son[i].resize(2);
      scanf("%d%d", &son[i][0], &son[i][1]);
    } else {
      type[i] = 4;
      son[i].resize(1);
      scanf("%d", &son[i][0]);
    }
  }
  int x = dfs(1);
  int p = solve(1);
  for (int i = 1; i <= tot; i++) ans[i] = x;
  for (int e : v[p]) ans[e] ^= 1;
  for (int i = 1; i <= tot; i++) printf("%d", ans[i]);
  return 0;
}
