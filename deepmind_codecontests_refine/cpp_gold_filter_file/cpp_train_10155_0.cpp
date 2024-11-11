#include <bits/stdc++.h>
using namespace std;
const int maxn = 3e5 + 5;
int p[maxn], n, q, t, C[maxn], sz[maxn];
vector<int> T[maxn];
void dfs(int v) {
  sz[v] = 1;
  int hv = 0;
  for (int i = 0; i < T[v].size(); i++) {
    int u = T[v][i];
    dfs(u);
    sz[v] += sz[u];
    if (sz[T[v][hv]] < sz[u]) hv = i;
  }
  if (sz[v] == 1) return;
  if (2 * sz[T[v][hv]] > sz[v]) {
    C[v] = C[T[v][hv]];
    while (2 * (sz[v] - sz[C[v]]) > sz[v]) C[v] = p[C[v]];
  }
}
int main() {
  for (int i = 0; i < maxn; i++) sz[i] = 0, C[i] = i;
  cin >> n >> q;
  for (int i = 2; i <= n; i++) cin >> p[i], T[p[i]].push_back(i);
  dfs(1);
  while (q--) cin >> t, cout << C[t] << endl;
}
