#include <bits/stdc++.h>
using namespace std;
const long long mod = 100000000 + 9;
int parent[100001], size[100001];
void make_set(int v) {
  parent[v] = v;
  size[v] = 1;
}
int find_set(int v) {
  if (v == parent[v]) return v;
  return parent[v] = find_set(parent[v]);
}
void union_sets(int a, int b) {
  a = find_set(a);
  b = find_set(b);
  if (a != b) {
    if (size[a] < size[b]) swap(a, b);
    parent[b] = a;
    size[a] += size[b];
  }
}
int main() {
  int n, m, i, x, y;
  cin >> n >> m;
  for (i = 0; i < n; i++) make_set(i);
  long long ans = 1;
  for (i = 0; i < m; i++) {
    cin >> x >> y;
    if (find_set(x) == find_set(y))
      ans *= 2;
    else {
      union_sets(x, y);
    }
    ans %= mod;
    cout << ans - 1 << endl;
  }
  return 0;
}
