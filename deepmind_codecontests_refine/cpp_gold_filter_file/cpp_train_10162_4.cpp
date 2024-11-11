#include <bits/stdc++.h>
using namespace std;
int A[1000010], B[1000010], par[1000010], C[1000010], vis[1000010];
int dep[1000010];
vector<int> adj[1000010], cd[1000010];
map<int, int> M[1000010];
vector<int> cyc;
vector<int> basis;
void dfs(int v, int p, int d) {
  par[v] = p;
  vis[v] = 1;
  dep[v] = d;
  for (int i = 0; i < adj[v].size(); i++) {
    if (adj[v][i] == p or vis[adj[v][i]]) continue;
    dfs(adj[v][i], v, d ^ M[v][adj[v][i]]);
  }
}
void gauss() {
  for (int i = 29; i >= 0; i--) {
    int t = 0;
    for (int j = 0; j < cyc.size(); j++) {
      if (cyc[j] & (1 << i)) {
        if (!t) {
          t = cyc[j];
          cyc[j] = 0;
        } else {
          cyc[j] ^= t;
        }
      }
    }
    if (t) basis.push_back(t);
  }
}
int query(int q) {
  for (int i = 0; i < basis.size(); i++) {
    if ((basis[i] ^ q) < q) q ^= basis[i];
  }
  return q;
}
int main() {
  int n, m;
  cin >> n >> m;
  for (int i = 1; i <= m; i++) {
    cin >> A[i] >> B[i] >> C[i];
    adj[A[i]].push_back(B[i]);
    adj[B[i]].push_back(A[i]);
    M[A[i]][B[i]] = M[B[i]][A[i]] = C[i];
  }
  dfs(1, 0, 0);
  for (int i = 1; i <= m; i++) {
    if (A[i] == par[B[i]] or B[i] == par[A[i]]) continue;
    cyc.push_back(dep[B[i]] ^ dep[A[i]] ^ C[i]);
  }
  gauss();
  cout << query(dep[1] ^ dep[n]) << endl;
}
