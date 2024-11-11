#include <bits/stdc++.h>
using namespace std;
const int N = 25 * (1e4);
long long h[2][N], n, m, par[2][N], depth, endvert[2], k;
vector<int> adj[N], leaves, backedge[N];
bool mark[2][N];
void DFS(int v, int t, int parent) {
  mark[t][v] = 1;
  bool leaf = 1;
  if (h[t][endvert[t]] < h[t][v]) endvert[t] = v;
  for (int i = 0; i < adj[v].size(); i++) {
    int u = adj[v][i];
    if (mark[t][u]) {
      if (u != parent && !t) backedge[v].push_back(u);
      continue;
    }
    h[t][u] = h[t][v] + 1;
    par[t][u] = v;
    leaf = 0;
    DFS(u, t, v);
  }
  if (leaf && !t) leaves.push_back(v);
}
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  cin >> n >> m >> k;
  for (int i = 0; i < m; i++) {
    int x, y;
    cin >> x >> y;
    adj[x].push_back(y);
    adj[y].push_back(x);
  }
  DFS(1, 0, 0);
  DFS(endvert[0], 1, 0);
  if (h[1][endvert[1]] >= (n + k - 1) / k) {
    cout << "PATH" << endl << h[1][endvert[1]] + 1 << endl;
    int v = endvert[1];
    while (v > 0) {
      cout << v << " ";
      v = par[1][v];
    }
    return 0;
  }
  cout << "CYCLES" << endl;
  for (int i = 0; i < k; i++) {
    int v = leaves[i];
    int u = backedge[v][0], w = backedge[v][1];
    if (h[0][u] < h[0][w]) swap(u, w);
    if ((h[0][v] - h[0][u] + 1) % 3 == 0 && (h[0][v] - h[0][w] + 1) % 3 == 0) {
      cout << h[0][u] - h[0][w] + 1 << endl << v << " ";
      int crntv = u;
      while (crntv != par[0][w]) {
        cout << crntv << " ";
        crntv = par[0][crntv];
      }
      cout << endl;
      continue;
    }
    if ((h[0][v] - h[0][u] + 1) % 3 != 0) {
      cout << h[0][v] - h[0][u] + 1 << endl;
      int crntv = v;
      while (crntv != par[0][u]) {
        cout << crntv << " ";
        crntv = par[0][crntv];
      }
      cout << endl;
      continue;
    }
    if ((h[0][v] - h[0][w] + 1) % 3 != 0) {
      cout << h[0][v] - h[0][w] + 1 << endl;
      int crntv = v;
      while (crntv != par[0][w]) {
        cout << crntv << " ";
        crntv = par[0][crntv];
      }
      cout << endl;
      continue;
    }
  }
}
