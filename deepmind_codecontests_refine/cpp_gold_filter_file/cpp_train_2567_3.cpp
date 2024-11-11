#include <bits/stdc++.h>
using namespace std;
const long long N = 400000;
long long a1;
long long visited[N] = {0};
long long vis1[N] = {0};
vector<long long> adj[N];
long long node[N] = {0};
void dfs(long long r) {
  visited[r] = 1;
  node[r] = 1;
  for (long long u : adj[r]) {
    if (visited[u] == 0) {
      dfs(u);
      node[r] = node[r] + node[u];
    }
  }
}
void dfs1(long long r, long long x) {
  vis1[r] = 1;
  for (long long u : adj[r]) {
    if (vis1[u] == 0) {
      vis1[u] = 1;
      if (u == x) a1 = r;
      dfs1(u, x);
    }
  }
}
int main() {
  long long n, x, y;
  cin >> n >> x >> y;
  for (long long i = 1; i < n; i++) {
    long long x, y;
    cin >> x >> y;
    adj[x].push_back(y);
    adj[y].push_back(x);
  }
  dfs(x);
  dfs1(y, x);
  cout << ((n * (n - 1))) - (node[y] * (n - (node[a1])));
}
