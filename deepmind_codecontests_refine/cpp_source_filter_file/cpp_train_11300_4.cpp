#include <bits/stdc++.h>
using namespace std;
int inf = 0x3f3f3f3f;
const int N = int(1e5) + 10;
int visit[N];
vector<int> v[N];
int n, m;
int ans;
bool ok;
void dfs(int u, int prv, int h) {
  visit[u] = h;
  ans = max(ans, h);
  for (int i = 0; i < v[u].size(); i++) {
    int adj = v[u][i];
    if (adj == prv) continue;
    if (visit[adj] == 0) {
      dfs(adj, u, h + 1);
    }
  }
}
int main() {
  scanf("%d %d", &n, &m);
  for (int i = 0; i < m; i++) {
    int x, y;
    scanf("%d %d", &x, &y);
    v[x].push_back(y);
    v[y].push_back(x);
  }
  int s = 1;
  int maxi = -1;
  dfs(1, 1, 0);
  for (int i = 1; i < n; i++) {
    if (visit[i] > maxi) {
      maxi = visit[i];
      s = i;
    }
  }
  memset(visit, 0, sizeof visit);
  dfs(s, s, 0);
  printf("%d\n", ans);
  return 0;
}
