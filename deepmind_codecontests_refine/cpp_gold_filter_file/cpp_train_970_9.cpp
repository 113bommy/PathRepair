#include <bits/stdc++.h>
using namespace std;
vector<long long int> parent(1000001);
map<long long int, long long int> urank;
void create(long long int x) {
  parent[x] = x;
  urank[x] = 0;
}
long long int find(long long int x) {
  if (parent[x] != x) {
    parent[x] = find(parent[x]);
  }
  return parent[x];
}
void merge(long long int x, long long int y) {
  long long int xroot = find(x);
  long long int yroot = find(y);
  if (urank[xroot] <= urank[yroot]) {
    parent[xroot] = yroot;
    urank[yroot] = urank[yroot] + urank[xroot];
  } else {
    parent[yroot] = xroot;
    urank[xroot] = urank[xroot] + urank[yroot];
  }
}
void solve() {
  long long int n, m1, m2;
  cin >> n >> m1;
  for (long long int i = 1; i < n + 1; i++) create(i);
  for (long long int i = 0; i < m1; i++) {
    long long int a, b;
    cin >> a >> b;
    if (find(a) != find(b)) merge(a, b);
  }
  map<long long int, long long int> m;
  for (long long int i = 1; i < n + 1; i++) {
    m[find(i)]++;
  }
  cin >> m2;
  for (long long int i = 0; i < m2; i++) {
    long long int a, b;
    cin >> a >> b;
    long long int root1 = find(a);
    long long int root2 = find(b);
    if (root1 == root2) m.erase(root1);
  }
  map<long long int, long long int>::iterator it;
  long long int max = 0;
  for (it = m.begin(); it != m.end(); it++) {
    if (it->second > max) max = it->second;
  }
  cout << max;
}
signed main() {
  std::ios::sync_with_stdio(false);
  int T = 1;
  while (T--) {
    solve();
  }
  return 0;
}
