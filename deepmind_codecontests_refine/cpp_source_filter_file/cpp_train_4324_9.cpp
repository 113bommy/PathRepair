#include <bits/stdc++.h>
using namespace std;
const int MAXN = 2e5 + 10;
const int INF = 1e9 + 7;
bool used[MAXN];
vector<pair<int, int>> G[MAXN];
vector<int> roads[MAXN];
int dfs(int v, int day) {
  used[v] = 1;
  int ans = G[v].size();
  int firstday = day;
  int toadd = -1;
  for (int i = 0; i < G[v].size(); ++i)
    if (!used[G[v][i].first]) {
      day += toadd;
      if (day < 0) {
        day = firstday + 1;
        toadd = 1;
      }
      roads[day].push_back(G[v][i].second);
      ans = max(ans, dfs(G[v][i].first, day));
    }
  return ans;
}
int main() {
  int n;
  scanf("%d", &n);
  for (int i = 1; i < n; ++i) {
    int u, v;
    scanf("%d%d", &u, &v);
    G[u].push_back(make_pair(v, i));
    G[v].push_back(make_pair(u, i));
  }
  int t = dfs(1, 0);
  printf("%d", t);
  for (int i = 0; i < t; ++i) {
    printf("\n%d ", roads[i].size());
    for (int j = 0; j < roads[i].size(); ++j) printf("%d ", roads[i][j]);
  }
  return 0;
}
