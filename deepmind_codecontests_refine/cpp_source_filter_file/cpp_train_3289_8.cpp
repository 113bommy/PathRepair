#include <bits/stdc++.h>
using namespace std;
const int MAXN = 5 * 100000;
vector<int> g[MAXN + 1], e[MAXN + 1];
int col[MAXN + 1], cur = 1, used[MAXN + 1];
void dfs(int v, int p) {
  int num = 1;
  vector<int> del;
  for (auto x : g[v]) {
    del.push_back(col[x]);
    used[col[x]] = 1;
  }
  for (auto x : g[v]) {
    if (col[x]) continue;
    while (used[num]) num++;
    used[num] = 1;
    del.push_back(num);
    col[x] = num;
  }
  for (auto x : del) used[x] = 0;
  for (auto x : e[v]) {
    if (x == p) continue;
    dfs(x, v);
  }
}
int main() {
  int n, m;
  scanf("%d%d", &n, &m);
  int pos = 0;
  for (int i = 1; i <= n; i++) {
    int sz;
    scanf("%d", &sz);
    for (int j = 0; j < sz; j++) {
      int x;
      scanf("%d", &x);
      g[i].push_back(x);
    }
    if (g[i].size() > g[pos].size()) pos = i;
    sort(g[i].begin(), g[i].end());
  }
  for (int i = 0; i < n - 1; i++) {
    int a, b;
    scanf("%d%d", &a, &b);
    e[a].push_back(b);
    e[b].push_back(a);
  }
  for (auto x : g[pos]) col[x] = cur++, used[cur] = 1;
  dfs(pos, -1);
  cout << *max_element(col + 1, col + 1 + m) << "\n";
  for (int i = 1; i <= m; i++) {
    if (!col[i]) col[i] = 1;
    printf("%d ", col[i]);
  }
  printf("\n");
  return 0;
}
