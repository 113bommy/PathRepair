#include <bits/stdc++.h>
using namespace std;
const int N = 3005;
int n, x[N], f[N], sz[N], v[N];
inline int getf(int v) { return f[v] == v ? v : f[v] = getf(f[v]); }
struct Edge {
  int u, v, w;
} e[N];
int main() {
  ios::sync_with_stdio(false);
  cin >> n;
  for (int i = 1; i < n; i++) cin >> e[i].u >> e[i].v >> e[i].w;
  sort(e + 1, e + n, [](Edge a, Edge b) { return a.w < b.w; });
  int sum = 0;
  for (int i = 1; i <= n; i++) cin >> x[i], sum += x[i];
  for (int i = 1; i <= n; i++) f[i] = i, sz[i] = 1, v[i] = x[i];
  for (int i = 1; i < n; i++) {
    int fx = getf(e[i].u), fy = getf(e[i].v);
    f[fx] = fy;
    sz[fy] += fx;
    v[fy] += fx;
    if (sz[fy] > sum - v[fy]) {
      cout << e[i].w << endl;
      return 0;
    }
  }
  cout << e[n - 1].w << endl;
  return 0;
}
