#include <bits/stdc++.h>
using namespace std;
long long n, m;
vector<vector<long long>> adj, adjInv;
vector<long long> scc;
long long sccID;
vector<bool> visited;
void dfs1(long long curr, stack<long long> &seen) {
  visited[curr] = true;
  for (long long x : adj[curr]) {
    if (!visited[x]) {
      dfs1(x, seen);
    }
  }
  seen.push(curr);
}
void dfs2(long long curr) {
  visited[curr] = true;
  scc[curr] = sccID;
  for (long long x : adjInv[curr]) {
    if (!visited[x]) {
      dfs2(x);
    }
  }
}
void calcSCC() {
  visited.clear();
  visited.resize(n + 1, false);
  stack<long long> seen;
  for (long long i = 1; i <= n; ++i) {
    if (!visited[i]) {
      dfs1(i, seen);
    }
  }
  visited.clear();
  visited.resize(n + 1, false);
  sccID = 0;
  while (!seen.empty()) {
    while (!seen.empty() && visited[seen.top()]) seen.pop();
    if (!seen.empty()) {
      dfs2(seen.top());
      sccID++;
    }
  }
}
void solve() {
  cin >> n >> m;
  n *= 2;
  adj.clear();
  adj.resize(n + 1);
  adjInv.clear();
  adjInv.resize(n + 1);
  scc.clear();
  scc.resize(n + 1);
  vector<pair<long long, long long>> edges;
  while (m--) {
    long long u, v;
    cin >> u >> v;
    v += n / 2;
    if (u == v - n / 2) {
      adj[v].push_back(u);
      edges.push_back({v, u});
      adjInv[u].push_back(v);
    } else {
      edges.push_back({u, v});
      adj[u].push_back(v);
      adjInv[v].push_back(u);
    }
  }
  calcSCC();
  if (sccID == 1) {
    cout << "No\n";
    return;
  }
  if (n == 2) {
    cout << "No\n";
    return;
  }
  vector<long long> indegree(n + 1, 0);
  for (auto &e : edges) {
    long long u = scc[e.first];
    long long v = scc[e.second];
    if (u == v) continue;
    ++indegree[v];
  }
  vector<bool> inA(n / 2 + 1, false);
  for (long long i = n / 2 + 1; i <= n; ++i) {
    if (indegree[scc[i]] == 0) {
      for (long long j = n / 2 + 1; j <= n; ++j) {
        if (scc[j] == scc[i]) {
          inA[j - n / 2] = true;
        }
      }
      break;
    }
  }
  vector<bool> asdf(n / 2 + 1, false);
  vector<long long> temp;
  for (long long i = 1; i <= n / 2; ++i) {
    if (inA[i]) {
      asdf[i] = true;
      temp.push_back(i);
    }
  }
  cout << "Yes\n";
  cout << n / 2 - temp.size() << ' ';
  cout << temp.size() << '\n';
  for (long long i = 1; i <= n / 2; ++i) {
    if (!asdf[i]) cout << i << ' ';
  }
  cout << '\n';
  for (long long pos : temp) cout << pos << ' ';
  cout << '\n';
}
signed main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  long long t;
  cin >> t;
  while (t--) {
    solve();
  }
}
