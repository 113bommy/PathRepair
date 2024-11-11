#include <bits/stdc++.h>
using namespace std;
const int N = 1007;
vector<int> v[N], q[N];
bool fl[N << 1];
int n, m, k, tg, ca, cb, w[N], g[N], f[N][N], f1[N], f2[N], f3[N], f4[N];
struct edg {
  int u, t, w;
} e[N];
inline void update() {
  for (int i = 1; i <= m; i++) f[e[i].u][e[i].w] = f[e[i].t][e[i].w] = 0;
  for (int i = 1; i <= m; i++) f[e[i].u][e[i].w]++, f[e[i].t][e[i].w]++;
  for (int i = 1; i <= n; i++) {
    f1[i] = m + 1, f2[i] = 0, f3[i] = 0, f4[i] = 0;
    for (int j = 1; j <= k; j++) {
      if (f[i][j] < f1[i]) f1[i] = f[i][j], f2[i] = j;
      if (!f1[i]) break;
    }
  }
  for (int i = 1; i <= m; i++) {
    if (f[e[i].u][e[i].w] > f3[e[i].u])
      f3[e[i].u] = f[e[i].u][e[i].w], f4[e[i].u] = e[i].w;
    if (f[e[i].t][e[i].w] > f3[e[i].t])
      f3[e[i].t] = f[e[i].t][e[i].w], f4[e[i].t] = e[i].w;
  }
}
inline bool check() {
  for (int i = 1; i <= n; i++)
    if (f3[i] - f1[i] > 2) return false;
  return true;
}
inline void dfs(int u) {
  for (int i = 0; i < v[u].size(); i++) {
    if (fl[q[u][i]]) continue;
    fl[q[u][i]] = 1, e[q[u][i]].w = (tg & 1) ? ca : cb, tg ^= 1, g[u]--,
    g[v[u][i]]--, dfs(v[u][i]);
  }
}
int main() {
  cin >> n >> m >> k;
  int a, b;
  srand(time(0));
  for (int i = 1; i <= n; i++) cin >> w[i];
  for (int i = 1; i <= m; i++)
    cin >> a >> b, e[i].u = a, e[i].t = b, e[i].w = rand() % k + 1;
  update();
  while (!check()) {
    memset(g, 0, sizeof(g)), memset(fl, 0, sizeof(fl));
    for (int i = 0; i <= n; i++) v[i].resize(0), q[i].resize(0);
    for (int i = 1; i <= n; i++)
      if (f3[i] - f1[i] > 2) {
        a = f2[i], b = f4[i];
        break;
      }
    for (int i = 1; i <= m; i++)
      if (e[i].w == a || e[i].w == b) {
        g[e[i].u]++, g[e[i].t]++;
        q[e[i].u].push_back(i), q[e[i].t].push_back(i);
        v[e[i].u].push_back(e[i].t), v[e[i].t].push_back(e[i].u);
      }
    for (int i = 1; i <= n; i++)
      if (g[i] & 1)
        v[0].push_back(i), v[i].push_back(0), g[0]++, q[i].push_back(m + i),
            q[0].push_back(m + i);
    ca = a, cb = b;
    for (int i = 0; i <= n; i++)
      if (g[i]) dfs(i);
    update();
  }
  for (int i = 1; i <= m; i++) cout << e[i].w << endl;
}
