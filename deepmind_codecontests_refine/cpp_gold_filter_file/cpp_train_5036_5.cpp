#include <bits/stdc++.h>
using namespace std;
const int INF = 0x3f3f3f3f;
const long long LINF = 0x3f3f3f3f3f3f3f3fll;
const int MAXN = 2e5 + 10;
int curflow[MAXN];
int dir[MAXN];
int first[MAXN];
bool foi[MAXN];
vector<pair<int, int> > adj[MAXN];
vector<int> ind[MAXN];
int sum[MAXN];
int n, m;
void dfs(int v) {
  foi[v] = 1;
  for (int a = 0; a < adj[v].size(); ++a) {
    int nxt = adj[v][a].first;
    int i = ind[v][a];
    if (foi[nxt]) continue;
    dir[i] = (first[i] == v ? 0 : 1);
    curflow[nxt] += adj[v][a].second;
    if (nxt != n && 2 * curflow[nxt] == sum[nxt]) dfs(nxt);
  }
}
int main() {
  scanf("%d%d", &n, &m);
  for (int a = 0; a < m; ++a) {
    int u, v, c;
    scanf("%d%d%d", &u, &v, &c);
    adj[u].push_back(pair<int, int>(v, c));
    adj[v].push_back(pair<int, int>(u, c));
    ind[u].push_back(a);
    ind[v].push_back(a);
    first[a] = u;
    sum[u] += c;
    sum[v] += c;
  }
  dfs(1);
  for (int a = 0; a < m; ++a) printf("%d\n", dir[a]);
  return 0;
}
