#include <bits/stdc++.h>
using namespace std;
long long modpow(long long a, long long b, long long m = 1000000007) {
  a %= m;
  long long res = 1;
  while (b) {
    if (b & 1) res = res * a % m;
    a = a * a % m;
    b >>= 1;
  }
  return res;
}
long long bpow(long long a, long long b) {
  long long res = 1;
  while (b) {
    if (b & 1) res = res * a;
    a = a * a;
    b >>= 1;
  }
  return res;
}
long long modinv(long long a) { return modpow(a, 1000000007 - 2, 1000000007); }
void graph(vector<vector<long long> > &adj, long long m) {
  long long x, y;
  for (long long i = 0; i < m; i++) {
    cin >> x >> y;
    adj[x - 1].push_back(y - 1);
    adj[y - 1].push_back(x - 1);
  }
}
vector<long long> parent, euler, visited, first;
void dfs(vector<vector<long long> > &adj, long long node) {
  visited[node] = true;
  first[node] = euler.size();
  euler.push_back(node);
  for (auto to : adj[node]) {
    if (!visited[to]) {
      parent[to] = node;
      dfs(adj, to);
      euler.push_back(node);
    }
  }
}
const int mxN = 2e5 + 5;
int pr[mxN], d[mxN];
bool vis[mxN];
void solve() {
  int n;
  cin >> n;
  if (n == 3) {
    cout << "1 1\n";
    return;
  }
  vector<vector<long long> > adj(n);
  for (long long i = 0; i < n - 1; i++) {
    long long x, y;
    cin >> x >> y;
    x--, y--;
    adj[x].push_back(y);
    adj[y].push_back(x);
    d[x]++;
    d[y]++;
  }
  int minus = 0;
  int index;
  for (long long i = 0; i < n; i++) {
    if (d[i] == 1) {
      index = i;
      if (d[adj[i][0]] > 2 && vis[adj[i][0]]) {
        minus++;
      }
      vis[adj[i][0]] = true;
    }
  }
  int fmin, fmax;
  fmax = (n - 1) - minus;
  first.resize(n);
  parent.resize(n);
  euler.reserve(n * 2);
  visited.assign(n, false);
  int root = index;
  parent[root] = -1;
  dfs(adj, root);
  long long value = first[root] % 2;
  int count = 0;
  ;
  for (long long i = 0; i < n; i++) {
    if (d[i] == 1) {
      count += (first[i] % 2 != value);
    }
  }
  if (count == 0) {
    fmin = 1;
  } else {
    fmin = 3;
  }
  cout << fmin << " " << fmax << "\n";
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  int t = 1;
  while (t--) {
    solve();
  }
}
