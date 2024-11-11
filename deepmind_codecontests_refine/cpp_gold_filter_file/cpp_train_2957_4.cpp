#include <bits/stdc++.h>
using namespace std;
const int MAXN = 1e5 + 5;
const int MAXM = 1e5 + 5;
int n, m;
set<pair<int, int> > has_edge;
int v[MAXN];
bool randSolve() {
  random_shuffle(v, v + n);
  for (int i = 0; i < m; ++i)
    if (has_edge.count(pair<int, int>(v[i], v[(i + 1) % n]))) return false;
  for (int i = 0; i < m; ++i) printf("%d %d\n", v[i], v[(i + 1) % n]);
  return true;
}
void solve() {
  for (int i = 0; i < n; ++i) v[i] = i + 1;
  for (int i = 0; i < 1000; ++i) {
    if (randSolve()) return;
  }
  puts("-1");
}
int main() {
  scanf("%d%d", &n, &m);
  for (int i = 0; i < m; ++i) {
    int u, v;
    scanf("%d%d", &u, &v);
    has_edge.insert(pair<int, int>(u, v));
    has_edge.insert(pair<int, int>(v, u));
  }
  solve();
  return 0;
}
