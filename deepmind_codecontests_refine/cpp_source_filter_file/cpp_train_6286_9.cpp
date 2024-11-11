#include <bits/stdc++.h>
using namespace std;
void affiche(int t[], int n) {
  for (int i = 0; i < n; i++) cout << t[i] << " ";
  cout << '\n';
}
void afficheV(vector<int> t) {
  for (int i = 0; i < t.size(); i++) cout << t[i] << " ";
  cout << '\n';
}
int const MAXN = 1e4 + 7;
struct UnionFind {
  int root[404], size[404];
  int forest;
  int find_set(int u) {
    if (root[u] == 0) return u;
    return root[u] = find_set(root[u]);
  }
  void union_set(int u, int v) {
    if (size[u] == 0) size[u] = 1;
    if (size[v] == 0) size[v] = 1;
    u = find_set(u);
    v = find_set(v);
    if (u != v) {
      if (size[v] > size[u]) swap(u, v);
      root[v] = u;
      size[u] += size[v];
      forest++;
    }
  }
} L[MAXN], R[MAXN], ans;
int main() {
  ios_base::sync_with_stdio(0), cin.tie(0);
  int n, m;
  cin >> n >> m;
  int u[m + 7], v[m + 7];
  for (int i = 1; i < m + 1; i++) {
    cin >> u[i] >> v[i];
    L[i] = L[i - 1];
    L[i].union_set(v[i], u[i]);
  }
  for (int i = m; i >= 1; i--) {
    R[i] = R[i + 1];
    R[i].union_set(v[i], u[i]);
  }
  int q;
  cin >> q;
  while (q--) {
    int l, r;
    cin >> l >> r;
    ans = L[--l];
    for (int i = 1; i < n + 1; i++) {
      if (R[r + 1].root[i]) ans.union_set(i, R[r + 1].root[i]);
    }
    cout << n - ans.forest << '\n';
  }
}
