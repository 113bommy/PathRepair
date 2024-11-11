#include <bits/stdc++.h>
using namespace std;
int chh;
const int N = 100005;
int T, n, m;
int p[N], h[N], a[N], b[N];
vector<int> g[N];
bool dfs(int x, int fa) {
  int v, c, d;
  a[x] = 0, b[x] = 0;
  for (__typeof__((g[x]).begin()) it = (g[x]).begin(); it != (g[x]).end();
       it++) {
    v = *it;
    if (v == fa) continue;
    if (!dfs(v, x)) return 0;
    p[x] += p[v];
    a[x] += a[v], b[x] += b[v];
  }
  if (p[x] < a[x] + b[x]) return 0;
  if (p[x] < h[x]) return 0;
  if ((p[x] + h[x]) % 2) return 0;
  c = (p[x] + h[x]) / 2;
  d = p[x] - c;
  if (c < a[x]) return 0;
  a[x] = c, b[x] = d;
  return 1;
}
int main() {
  int x, y;
  scanf("%d", &T);
  while (T--) {
    scanf("%d %d", &n, &m);
    for (int i = 0; i < (n); i++) g[i + 1].clear();
    for (int i = 0; i < (n); i++) scanf("%d", &p[i + 1]);
    for (int i = 0; i < (n); i++) scanf("%d", &h[i + 1]);
    for (int i = 0; i < (n - 1); i++) {
      scanf("%d %d", &x, &y);
      g[x].push_back(y);
      g[y].push_back(x);
    }
    puts(dfs(1, -1) ? "YES" : "NO");
  }
  return 0;
}
