#include <bits/stdc++.h>
using namespace std;
const int MAXN = 3005;
int N;
vector<int> adj[MAXN];
vector<int> len[MAXN];
int X[MAXN];
bool vis[MAXN];
int total = 0, nodecnt = 0, xcnt = 0;
void dfs(int node, int val) {
  vis[node] = true;
  nodecnt++;
  xcnt += X[node];
  for (int i = 0; i < adj[node].size(); i++) {
    int next = adj[node][i];
    if (!vis[next] && len[node][i] < val) dfs(next, val);
  }
}
bool check(int val) {
  memset(vis, false, sizeof(vis));
  for (int i = 0; i < N; i++)
    if (!vis[i]) {
      nodecnt = 0, xcnt = 0;
      dfs(i, val);
      if (nodecnt > total - xcnt) return false;
    }
  return true;
}
int main() {
  cin >> N;
  for (int i = 0; i < N - 1; i++) {
    int a, b, c;
    cin >> a >> b >> c;
    a--, b--;
    adj[a].push_back(b);
    adj[b].push_back(a);
    len[a].push_back(c);
    len[b].push_back(c);
  }
  for (int i = 0; i < N; i++) {
    cin >> X[i];
    total += X[i];
  }
  int lo = 0, hi = 10000;
  while (lo < hi) {
    int mid = lo + (hi - lo + 1) / 2;
    if (check(mid))
      lo = mid;
    else
      hi = mid - 1;
  }
  cout << lo << "\n";
  return 0;
}
