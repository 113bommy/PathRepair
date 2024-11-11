#include <bits/stdc++.h>
using namespace std;
long long n, m, d;
long long marked[100007];
vector<int> adj[100007];
long long maxdistdown[100007];
long long maxdistup[100007];
int dfs(int v, int parent) {
  maxdistdown[v] = marked[v] ? 0 : -1;
  for (int i = 0; i < adj[v].size(); ++i) {
    int to = adj[v][i];
    if (to != parent) {
      long long d = dfs(to, v);
      if (d > -1) maxdistdown[v] = max(maxdistdown[v], d + 1);
    }
  }
  return maxdistdown[v];
}
void dfs2(int v, int parent) {
  long long mx1 = -1, mx2 = -2;
  for (int i = 0; i < adj[v].size(); ++i) {
    int to = adj[v][i];
    if (to != parent) {
      if (maxdistdown[to] > mx1) {
        mx2 = mx1;
        mx1 = maxdistdown[to];
      } else if (maxdistdown[to] > mx2) {
        mx2 = maxdistdown[to];
      }
    }
  }
  for (int i = 0; i < adj[v].size(); ++i) {
    int to = adj[v][i];
    if (to != parent) {
      long long siblingdist = maxdistdown[to] == mx1 ? mx2 : mx1;
      if (siblingdist != -1) siblingdist += 2;
      maxdistup[to] = siblingdist;
      if (maxdistup[v] != -1)
        maxdistup[to] = max(maxdistup[to], maxdistup[v] + 1);
      if (marked[to]) maxdistup[to] = max(maxdistup[to], 0LL);
      dfs2(to, v);
    }
  }
}
int main(int argc, char const *argv[]) {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cin >> n >> m >> d;
  for (int i = 0; i < m; ++i) {
    int x;
    cin >> x;
    marked[x - 1] = 1;
  }
  for (int i = 0; i < n - 1; ++i) {
    int x, y;
    cin >> x >> y;
    --x, --y;
    adj[x].push_back(y);
    adj[y].push_back(x);
  }
  dfs(0, -1);
  maxdistup[0] = marked[0] ? 0 : -1;
  dfs2(0, -1);
  int res = 0;
  for (int i = 0; i < n; ++i) {
    if (maxdistup[i] <= d and maxdistdown[i] <= d) ++res;
  }
  cout << res << endl;
  return 0;
}
