#include <bits/stdc++.h>
using namespace std;
int parent[100], rnk[100] = {0};
int find(int a) {
  if (parent[a] == a) return a;
  return parent[a] = find(parent[a]);
}
void merge(int a, int b) {
  int u = find(a);
  int v = find(b);
  if (u != v) {
    if (rnk[u] < rnk[v]) swap(u, v);
    if (rnk[u] == rnk[v]) rnk[u]++;
    parent[v] = u;
  }
}
void solve() {
  int i, n;
  cin >> n;
  int a[n], f[n];
  for (i = 0; i < n; i++) cin >> a[i], a[i]--;
  for (i = 0; i < n; i++) cin >> f[i];
  for (i = 0; i < n; i++) parent[i] = i;
  for (i = 0; i < n; i++) {
    if (i + f[i] < n) merge(i, i + f[i]);
    if (i - f[i] >= 0) merge(i, i - f[i]);
  }
  for (i = 0; i < n; i++) {
    int u = find(i);
    int v = find(a[i]);
    if (u != v) {
      cout << "NO" << '\n';
      return;
    }
  }
  cout << "YES" << '\n';
}
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  ;
  solve();
  return 0;
}
