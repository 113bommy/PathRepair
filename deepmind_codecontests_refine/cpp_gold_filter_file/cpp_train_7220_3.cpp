#include <bits/stdc++.h>
using namespace std;
int ans = 10000;
int g1[3005];
vector<vector<pair<int, int> > > v1(3004);
int dfs(int u, int p) {
  int ct = 0;
  for (int i = 0; i < v1[u].size(); i++) {
    if (v1[u][i].first == p) continue;
    ct += v1[u][i].second;
    ct += dfs(v1[u][i].first, u);
  }
  return ct;
}
void mydfs(int u, int p, int s, int edg, int st) {
  ans = min(ans, g1[s] - edg + st);
  for (int i = 0; i < v1[u].size(); i++) {
    if (v1[u][i].first == p) continue;
    int nst = st;
    if (!v1[u][i].second) nst = min(st + 1, edg);
    mydfs(v1[u][i].first, u, s, edg + v1[u][i].second, nst);
  }
}
int main() {
  int n, mn, ct, i, j, y1, x, y;
  scanf("%d", &n);
  if (n < 3) {
    puts("0");
    return 0;
  }
  for (i = 0; i < n - 1; i++) {
    scanf("%d", &x), scanf("%d", &y);
    x--, y--;
    v1[x].push_back(make_pair(y, 0));
    v1[y].push_back(make_pair(x, 1));
  }
  for (i = 0; i < n; i++) {
    g1[i] = dfs(i, -1);
  }
  for (i = 0; i < n; i++) {
    mydfs(i, -1, i, 0, 0);
  }
  cout << ans << endl;
  return 0;
}
