#include <bits/stdc++.h>
using namespace std;
const int MAX_N = 111111;
int g[MAX_N << 1], nxt[MAX_N << 1], c[MAX_N], nm;
int n, m, p;
int d[MAX_N];
void dfs(int x, int fa, int dep) {
  d[x] = dep;
  for (int k = c[x]; ~k; k = nxt[k]) {
    int j = g[k];
    if (j != fa) dfs(j, x, dep + 1);
  }
}
void addedge(int x, int y) {
  g[nm] = y;
  nxt[nm] = c[x];
  c[x] = nm;
  nm++;
}
int main() {
  memset(c, -1, sizeof c);
  int p2;
  scanf("%d%d%d", &n, &m, &p2);
  long long p = p2;
  m = min(m, n - 1);
  for (int i = (1); i <= (n - 1); ++i) {
    int x, y;
    scanf("%d%d", &x, &y);
    addedge(x, y);
    addedge(y, x);
  }
  dfs(1, -1, 0);
  sort(d + 1, d + 1 + n);
  int f = 2, ans = 0;
  for (int i = (3); i <= (n); ++i) {
    if (d[i] != d[i - 1]) p -= i - f;
    while (p < 0) p += d[i] - d[f++];
    ans = max(ans, i - f + 1);
  }
  cout << min(ans, m) << endl;
}
