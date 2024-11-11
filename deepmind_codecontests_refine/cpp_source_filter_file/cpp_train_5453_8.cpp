#include <bits/stdc++.h>
using namespace std;
const int N = 100005;
int n;
int fir[N], to[N], nxt[N], ecnt;
void add_edge(int u, int v) {
  to[++ecnt] = v;
  nxt[ecnt] = fir[u];
  fir[u] = ecnt;
}
int dep[N];
void dfs(int node, int fa) {
  dep[node] = dep[fa] + 1;
  for (int e = fir[node]; e; e = nxt[e]) {
    if (to[e] == fa) continue;
    dfs(to[e], node);
  }
}
int main() {
  cin >> n;
  for (int i = 1; i < n; i++) {
    int a, b;
    cin >> a >> b;
    add_edge(a, b);
    add_edge(b, a);
  }
  dfs(1, 0);
  double ans = 0;
  for (int i = 1; i <= n; i++) ans += 1.0 / dep[i];
  cout << fixed << setprecision(6) << ans;
}
