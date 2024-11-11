#include <bits/stdc++.h>
using namespace std;
const int N = 100010;
const int inf = ~0U >> 1;
const int mod = 1e9 + 7;
int m, n;
vector<int> e[N];
int dep[N], p[N][20];
long long sum[N], son[N], summ[N];
void dfs(int x, int father, int depth) {
  dep[x] = depth;
  p[x][0] = father;
  son[x] = 1;
  for (int i = 0; i < e[x].size(); ++i) {
    int y = e[x][i];
    if (father == y) continue;
    dfs(y, x, depth + 1);
    son[x] += son[y];
    sum[x] += sum[y] + son[y];
  }
}
void dfs2(int x, int father, long long up) {
  summ[x] = sum[x] + up;
  for (int i = 0; i < e[x].size(); ++i) {
    int y = e[x][i];
    if (father == y) continue;
    dfs2(y, x, summ[x] - (sum[y] + son[y]) + (n - son[y]));
  }
}
int LCA(int x, int y) {
  int delta = dep[x] - dep[y];
  for (int i = 19; i >= 0; --i)
    if (delta >> i & 1) x = p[x][i];
  if (x == y) return x;
  for (int i = 19; i >= 0; --i)
    if (p[x][i] != p[y][i]) {
      x = p[x][i], y = p[y][i];
    }
  return p[x][0];
}
int get_father(int x, int delta) {
  for (int i = 19; i >= 0; --i)
    if (delta >> i & 1) x = p[x][i];
  return x;
}
int main() {
  scanf("%d %d", &n, &m);
  for (int i = 1, x, y; i < n; ++i) {
    scanf("%d %d", &x, &y);
    e[x].push_back(y);
    e[y].push_back(x);
  }
  dfs(1, 0, 1);
  dfs2(1, 0, 0);
  for (int j = 1; j < 20; ++j)
    for (int i = 1; i <= n; ++i) p[i][j] = p[p[i][j - 1]][j - 1];
  for (int i = 0, x, y; i < m; ++i) {
    scanf("%d %d", &x, &y);
    if (dep[x] < dep[y]) swap(x, y);
    int lca = LCA(x, y);
    long long path_cnt, dis, total;
    if (lca == y) {
      int z = get_father(x, dep[x] - dep[y] - 1);
      long long son_y = n - son[z];
      long long sum_y = summ[y] - (sum[z] + son[z]);
      path_cnt = son[x] * son_y;
      dis = dep[x] - dep[y];
      total = sum[x] * son_y + sum_y * son[x] + (dis + 1) * path_cnt;
    } else {
      path_cnt = son[x] * son[y];
      dis = dep[x] + dep[y] - 2 * dep[lca];
      total = sum[x] * son[y] + sum[y] * son[x] + (dis + 1) * path_cnt;
    }
    printf("%.8f\n", 1.0 * total / path_cnt);
  }
  return 0;
}
