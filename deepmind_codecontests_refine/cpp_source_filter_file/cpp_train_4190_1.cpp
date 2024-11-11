#include <bits/stdc++.h>
using namespace std;
const long long INF = 0x3f3f3f3f3f3f3f3fLL;
const int inf = 0x3f3f3f3f;
const int maxn = 2e5 + 10;
const int mod = 1e9 + 7;
const double eps = 1e-6;
int di[8][2] = {{-1, 0},  {1, 0},  {0, -1}, {0, 1},
                {-1, -1}, {-1, 1}, {1, -1}, {1, 1}};
inline long long rd() {
  long long x = 0, f = 1;
  char ch = getchar();
  while (ch < '0' || ch > '9') {
    if (ch == '-') f = -1;
    ch = getchar();
  }
  while (ch >= '0' && ch <= '9') {
    x = (x << 3) + (x << 1) + (ch ^ 48);
    ch = getchar();
  }
  return x * f;
}
int n, m, k;
int a[maxn];
vector<int> ve[maxn];
int f[maxn][22], deep[maxn];
void bfs(int root) {
  f[root][0] = 0;
  deep[root] = 1;
  queue<int> qu;
  qu.push(root);
  while (qu.size()) {
    int x = qu.front();
    qu.pop();
    for (int y : ve[x]) {
      if (deep[y]) continue;
      deep[y] = deep[x] + 1;
      f[y][0] = x;
      for (int j = 1; j <= 20; j++) f[y][j] = f[f[y][j - 1]][j - 1];
      qu.push(y);
    }
  }
}
int lca(int x, int y) {
  if (deep[x] > deep[y]) swap(x, y);
  for (int i = 20; i >= 0; i--)
    if (deep[f[y][i]] >= deep[x]) y = f[y][i];
  if (x == y) return x;
  for (int i = 20; i >= 0; i--) {
    if (f[x][i] != f[y][i]) {
      x = f[x][i];
      y = f[y][i];
    }
  }
  return f[x][0];
}
bool cmp(const int &a, const int &b) { return deep[a] > deep[b]; }
int main() {
  n = rd(), m = rd();
  for (int i = 1; i < n; i++) {
    int u = rd(), v = rd();
    ve[u].push_back(v);
    ve[v].push_back(u);
  }
  bfs(1);
  while (m--) {
    k = rd();
    for (int i = 1; i <= k; i++) a[i] = rd();
    sort(a + 1, a + 1 + n, cmp);
    int now = a[1];
    int flag = 1;
    for (int i = 2; i <= n; i++) {
      now = lca(now, a[i]);
      if (deep[a[i]] - deep[now] > 1) {
        flag = 0;
        break;
      }
    }
    if (n == 2) flag = 1;
    puts(flag ? "YES" : "NO");
  }
}
