#include <bits/stdc++.h>
using namespace std;
const int N = 2e5 + 5, inf = 1e9 + 15;
int c[N], g[N][2], h[N][2];
bool least[N];
vector<int> t[N];
void init(int u = 0, int p = -1, int pv = inf) {
  if (c[u] < pv) {
    least[u] = 1;
    pv = c[u];
  }
  for (int v : t[u]) {
    if (v == p) continue;
    init(v, u, c[u]);
  }
}
long long ans = 0;
void dfs(int u = 0, int p = -1) {
  for (int v : t[u]) {
    if (v == p) continue;
    dfs(v, u);
    h[u][0] += h[v][0];
    h[u][1] += h[v][1];
  }
  if (least[u]) {
    long long m = min(h[u][0], h[u][1]);
    ans += 2LL * m * c[u];
    h[u][0] -= m;
    h[u][1] -= m;
  }
}
int main() {
  cin.tie(0);
  cout.tie(0);
  ios_base::sync_with_stdio(0);
  int n;
  cin >> n;
  for (int i = 0; i < n; ++i) {
    int a, b, ci;
    cin >> c[i] >> b >> ci;
    if (b != ci) {
      ++h[i][b];
    }
  }
  for (int i = 0; i < n - 1; ++i) {
    int x, y;
    cin >> x >> y;
    --x, --y;
    t[x].push_back(y);
    t[y].push_back(x);
  }
  init();
  dfs();
  if (h[0][0] || h[0][1]) {
    cout << -1 << '\n';
  } else {
    cout << ans << '\n';
  }
}
