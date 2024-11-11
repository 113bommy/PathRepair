#include <bits/stdc++.h>
using namespace std;
const int MAXN = 1000 + 5;
int n, adj[MAXN][MAXN], to0, fr0;
bool mark[MAXN];
void dfs(int v) {
  mark[v] = true;
  fr0++;
  for (int i = 0; i < n; i++) {
    if (adj[v][i] > 0 && !mark[i]) dfs(i);
  }
  return;
}
void dfs2(int v) {
  mark[v] = true;
  to0++;
  for (int i = 0; i < n; i++) {
    if (adj[i][v] > 0 && !mark[i]) dfs2(i);
  }
  return;
}
int main() {
  ios_base::sync_with_stdio(false);
  cin >> n;
  for (int i = 0; i < n; i++)
    for (int j = 0; j < n; j++) cin >> adj[i][j];
  dfs(0);
  for (int i = 0; i < n; i++) mark[i] = false;
  dfs2(0);
  if (fr0 == n && to0 == n)
    cout << "YES" << endl;
  else
    cout << "NO" << endl;
  return 0;
}
