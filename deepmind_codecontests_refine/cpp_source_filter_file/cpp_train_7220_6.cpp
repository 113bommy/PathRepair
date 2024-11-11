#include <bits/stdc++.h>
using namespace std;
vector<int> adj[3010];
vector<int> tome[3010];
int isc[3010];
int chs;
int filisc(int x, int pr) {
  if (x == chs) {
    isc[x] = 1;
    return 1;
  }
  int i, z = 0;
  for (i = 0; i < adj[x].size(); i++) {
    if (adj[x][i] == pr) continue;
    z = max(z, filisc(adj[x][i], x));
  }
  isc[x] = z;
  return z;
}
int c = 0;
void bld(int x, int pr) {
  int i;
  for (i = 0; i < adj[x].size(); i++) {
    if (adj[x][i] == pr) continue;
    if (isc[adj[x][i]] != tome[x][i]) c++;
    bld(adj[x][i], x);
  }
}
int mx = 0;
void dfs(int x, int pr, int bc, int mm) {
  mm = min(mm, -bc);
  mx = max(mx, bc + mm);
  int i;
  for (i = 0; i < adj[x].size(); i++) {
    if (adj[x][i] == pr) continue;
    if (tome[x][i])
      dfs(adj[x][i], x, bc + 1, mm);
    else
      dfs(adj[x][i], x, bc - 1, mm);
  }
}
int main() {
  int i, n, x, y;
  scanf("%d", &n);
  for (i = 0; i < n - 1; i++) {
    scanf("%d%d", &x, &y);
    x--, y--;
    adj[x].push_back(y);
    adj[y].push_back(x);
    tome[x].push_back(0);
    tome[y].push_back(1);
  }
  int mn = 100000;
  for (i = 0; i < n; i++) {
    mx = 0;
    memset(isc, 0, sizeof isc);
    chs = i, c = 0;
    filisc(0, -1);
    bld(0, -1);
    dfs(i, -1, 0, 10000000);
    mn = min(mn, c - mx);
  }
  printf("%d\n", mn);
}
