#include <bits/stdc++.h>
using namespace std;
void fileio() {}
vector<long long int>* adj;
vector<long long int> par;
vector<long long int> val;
vector<long long int> down;
vector<long long int> tot;
long long int dfs(long long int v, long long int p) {
  down[v] = val[v];
  for (long long int a : adj[v]) {
    if (a != p) {
      par[a] = v;
      long long int temp = dfs(a, v);
      if (temp > 0) down[v] += temp;
    }
  }
  return down[v];
}
void dfs2(long long int v) {
  long long int p = par[v];
  if (v != 0) {
    if (down[v] > 0) {
      tot[v] = max(tot[p], down[v]);
    } else {
      tot[v] = max(val[v] + tot[p], val[v]);
    }
  }
  for (long long int a : adj[v]) {
    if (a != p) dfs2(a);
  }
}
void solve() {
  long long int n;
  cin >> n;
  adj = new vector<long long int>[n];
  par.assign(n, 0);
  val.assign(n, 0);
  down.assign(n, 0);
  tot.assign(n, 0);
  for (long long int i = 0; i <= n - 1; i++) {
    cin >> val[i];
    if (val[i] == 0) val[i] = -1;
  }
  for (long long int i = 0; i <= n - 2; i++) {
    long long int a, b;
    cin >> a >> b;
    adj[a - 1].push_back(b - 1);
    adj[b - 1].push_back(a - 1);
  }
  tot[0] = dfs(0, -1);
  dfs2(0);
  for (long long int i = 0; i <= n - 1; i++) cout << tot[i] << " ";
}
int32_t main() {
  fileio();
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  { solve(); }
  return 0;
}
