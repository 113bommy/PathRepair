#include <bits/stdc++.h>
using namespace std;
vector<int> E[200000];
vector<int> E2[200000];
vector<int> adj[200000];
int cmp[200000];
int n, m;
void dfs(int v, int c) {
  if (cmp[v] != -1) return;
  cmp[v] = c;
  for (int i = 0; i < E[v].size(); i++) {
    dfs(E[v][i], c);
  }
}
int per[200000];
int ok;
void dfs2(int v, int cor) {
  if (per[v] == cor) return;
  if (per[v] != -1) {
    ok = 0;
    return;
  }
  per[v] = cor;
  for (int i = 0; i < adj[v].size(); i++) {
    int viz = adj[v][i];
    dfs2(viz, cor ^ 1);
  }
}
int main() {
  memset(cmp, -1, sizeof cmp);
  cin >> n >> m;
  for (int i = 0; i < m; i++) {
    int a, b, c;
    scanf("%d %d %d", &a, &b, &c);
    a--, b--;
    if (c)
      E[a].push_back(b), E[b].push_back(a);
    else
      E2[a].push_back(b), E2[b].push_back(a);
  }
  int at = 0;
  for (int i = 0; i < n; i++)
    if (cmp[i] == -1) dfs(i, at++);
  for (int i = 0; i < n; i++)
    for (int j = 0; j < E2[i].size(); j++) {
      int viz = E2[i][j];
      if (cmp[i] == cmp[viz]) {
        cout << 0 << endl;
        return 0;
      }
      adj[cmp[i]].push_back(cmp[viz]);
    }
  ok = 0;
  memset(per, -1, sizeof per);
  int cnt = 0;
  for (int i = 0; i < at; i++)
    if (per[i] == -1) {
      dfs2(i, 0);
      cnt++;
    }
  if (ok) {
    cout << 0 << endl;
    return 0;
  }
  long long ans = 1;
  for (int i = 0; i < cnt - 1; i++) {
    ans *= 2;
    ans %= 1000000007;
  }
  cout << ans << endl;
  return 0;
}
