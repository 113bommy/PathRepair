#include <bits/stdc++.h>
using namespace std;
const int maxn = 1e5 + 20, inf = 3e5 + 5;
int ans[maxn], H[maxn], sz[maxn], n;
vector<int> adj[maxn];
bool mark[maxn];
void dfsdata(int u, int p = -1) {
  sz[u] = 1;
  for (int i : adj[u]) {
    if (!mark[i] && i != p) {
      H[i] = H[u] + 1;
      dfsdata(i, u);
      sz[u] += sz[i];
    }
  }
}
int findCentroid(int u, int szlg, int par = -1) {
  for (int i : adj[u]) {
    if (!mark[i] && i != par && sz[u] * 2 > szlg) {
      return findCentroid(i, szlg, u);
    }
  }
  return u;
}
void centroid(int u, int h) {
  H[u] = 0;
  dfsdata(u);
  u = findCentroid(u, sz[u]);
  H[u] = 0;
  dfsdata(u);
  mark[u] = 1;
  ans[u] = 65 + h;
  for (int i : adj[u]) {
    if (!mark[i]) {
      centroid(u, h + 1);
    }
  }
}
int main() {
  cin >> n;
  for (int i = 0; i < n - 1; i++) {
    int x, y;
    cin >> x >> y;
    adj[x].push_back(y);
    adj[y].push_back(x);
  }
  centroid(1, 0);
  for (int i = 1; i <= n; i++) {
    cout << char(ans[i]) << " ";
  }
  return 0;
}
