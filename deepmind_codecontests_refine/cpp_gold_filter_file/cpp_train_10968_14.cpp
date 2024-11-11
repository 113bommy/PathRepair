#include <bits/stdc++.h>
using namespace std;
const long long int maxn = 2e5 + 5, M = 313, bghs = 1e9 + 7, inf = 1e18;
long long int n, m, cnt = 0, dist1[maxn], dist2[maxn];
long long int mark[maxn];
vector<long long int> adj[maxn];
long long int yu[maxn], yv[maxn], yw[maxn];
long long int yalv[maxn], yalu[maxn];
void esoadd(long long int i, long long int c, long long int j) {
  yu[cnt] = i;
  yv[cnt] = j;
  yw[cnt] = c;
  cnt++;
}
long long int dfs(long long int root) {
  mark[root] = (root == n - 1 ? 1 : -1);
  for (auto y : adj[root]) {
    if (!mark[y]) dfs(y);
    if (mark[y] == 1) mark[root] = 1;
  }
  return mark[root];
}
bool esolve() {
  for (long long int rep = 0; rep < n; rep++) {
    for (long long int i = 0; i < cnt; i++) {
      dist1[yv[i]] = min(dist1[yv[i]], dist1[yu[i]] + yw[i]);
    }
  }
  for (long long int i = 0; i < n; i++) dist2[i] = dist1[i];
  for (long long int rep = 0; rep < n; rep++) {
    for (long long int i = 0; i < cnt; i++) {
      dist1[yv[i]] = min(dist1[yv[i]], dist1[yu[i]] + yw[i]);
    }
  }
  for (long long int i = 0; i < n; i++)
    if (dist2[i] != dist1[i]) return 0;
  return 1;
}
void chap() {
  cout << "Yes\n";
  for (long long int i = 0; i < m; i++) {
    if (mark[yalu[i]] != 1 || mark[yalv[i]] != 1)
      cout << "1\n";
    else
      cout << dist1[yalv[i]] - dist1[yalu[i]] << '\n';
  }
}
int main() {
  ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
  cin >> n >> m;
  for (long long int i = 0; i < m; i++) {
    long long int u, v;
    cin >> u >> v;
    u--;
    v--;
    yalu[i] = u;
    yalv[i] = v;
    adj[u].push_back(v);
  }
  dfs(0);
  for (long long int i = 0; i < m; i++) {
    if (mark[yalu[i]] != 1 || mark[yalv[i]] != 1) continue;
    esoadd(yalv[i], -1, yalu[i]);
    esoadd(yalu[i], 2, yalv[i]);
  }
  if (!esolve()) {
    cout << "No\n";
    return 0;
  }
  chap();
}
