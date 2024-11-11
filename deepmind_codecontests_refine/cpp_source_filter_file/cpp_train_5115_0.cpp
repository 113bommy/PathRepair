#include <bits/stdc++.h>
using namespace std;
vector<bool> visited(100005);
vector<bool> visited2(100005);
vector<long long> adj[100005];
long long col[100005];
int r, sum;
void dfs(long long v) {
  visited[v] = true;
  long long m = 1e18;
  long long y = 0;
  for (long long u : adj[v]) {
    if (!visited[u]) {
      if (col[u] == -1) {
        col[u] = col[v];
      } else {
        m = min(m, col[u]);
      }
      if (col[u] < col[v]) {
        r = -1;
      }
      dfs(u);
    }
  }
  if (m != 1e18) {
    col[v] = max(col[v], m);
  }
}
void dfs2(long long v) {
  visited2[v] = true;
  for (long long u : adj[v]) {
    if (!visited2[u]) {
      sum += col[u] - col[v];
      dfs2(u);
    }
  }
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  long long n, i = 0, j = 0, k = 0, l = 0, m = 0, a = 0, b = 0, x = 0, y = 0,
               z = 0, c, p;
  cin >> n;
  for (i = 2; i <= n; i++) {
    cin >> x;
    adj[i].push_back(x);
    adj[x].push_back(i);
  }
  for (i = 1; i <= n; i++) {
    cin >> col[i];
  }
  dfs(1);
  if (r == -1) {
    cout << r;
    return 0;
  }
  sum += col[1];
  dfs2(1);
  cout << sum;
  return 0;
}
