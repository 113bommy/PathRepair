#include <bits/stdc++.h>
using namespace std;
const int maxn = 200000 + 10;
int n, x[maxn];
bool mark[maxn];
vector<int> adj[maxn], drt[maxn];
void dfs1(int v) {
  mark[v] = true;
  for (int i = 0; i < adj[v].size(); i++) {
    int y = adj[v][i];
    if (!mark[y]) {
      dfs1(y);
      x[v] += x[y];
      if (drt[v][i] == -1) x[v]++;
    }
  }
}
void dfs2(int v) {
  mark[v] = true;
  for (int i = 0; i < adj[v].size(); i++) {
    int y = adj[v][i];
    if (!mark[y]) {
      x[y] = x[v];
      if (drt[v][i] == 1)
        x[y]++;
      else
        x[y]--;
      dfs2(y);
    }
  }
}
int main() {
  cin >> n;
  for (int i = 1; i < n; i++) {
    int a, b;
    cin >> a >> b;
    adj[a].push_back(b);
    drt[a].push_back(1);
    adj[b].push_back(a);
    drt[b].push_back(-1);
  }
  dfs1(1);
  memset(mark, 0, sizeof mark);
  dfs2(1);
  int mn = 100000;
  for (int i = 1; i <= n; i++) {
    mn = min(mn, x[i]);
  }
  cout << mn << endl;
  for (int i = 1; i <= n; i++) {
    if (x[i] == mn) cout << i << " ";
  }
  cout << endl;
  return 0;
}
