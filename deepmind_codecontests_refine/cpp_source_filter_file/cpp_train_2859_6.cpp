#include <bits/stdc++.h>
using namespace std;
const int N = 2010;
int n, m, Q, u[N][N], f[N][N], ans[N];
int L[N], R[N];
char mp[N][N];
struct node {
  int fa[N];
  int find(int x) { return fa[x] == x ? x : fa[x] = find(fa[x]); }
} l[N], r[N];
struct query {
  int x, y;
} q[N];
void del(int x, int y) {
  l[x].fa[y] = l[x].find(y - 1);
  r[x].fa[y] = r[x].find(y + 1);
}
int main() {
  cin >> n >> m >> Q;
  for (int i = 1; i <= n; i++) {
    scanf("%s", mp[i] + 1);
    for (int j = 1; j <= m + 1; j++) {
      l[i].fa[j] = r[i].fa[j] = j;
      u[i][j] = i;
    }
  }
  for (int i = 1; i <= Q; i++)
    scanf("%d%d", &q[i].x, &q[i].y), mp[q[i].x][q[i].y] = 'X';
  for (int i = 1; i <= n; i++)
    for (int j = 1; j <= m; j++)
      if (mp[i][j] == '.') del(i, j);
  int sz = 0;
  for (int i = 1; i <= n; i++)
    for (int j = 1; j <= m; j++)
      if (mp[i][j] == '.') {
        u[i][j] = u[i - 1][j];
        f[i][j] = min(f[i - 1][j - 1] + 1, min(i - u[i][j], j - l[i].find(j)));
        sz = max(sz, f[i][j]);
      }
  for (int cas = Q; cas; --cas) {
    ans[cas] = sz;
    del(q[cas].x, q[cas].y);
    for (int i = 1; i <= n; i++) {
      L[i] = q[cas].y - l[i].find(q[cas].y);
      R[i] = r[i].find(q[cas].y) - q[cas].y;
    }
    for (int i = q[cas].x; i >= 1; i--) {
      L[i] = min(L[i], L[i + 1]);
      R[i] = min(R[i], R[i + 1]);
    }
    for (int i = q[cas].x + 1; i <= n; i++) {
      L[i] = min(L[i], L[i - 1]);
      R[i] = min(R[i], R[i - 1]);
    }
    for (int i = 1; i <= q[cas].x; i++) {
      while (i + sz <= n &&
             min(R[i], R[i + sz]) + min(L[i], L[i + sz]) - 1 > sz)
        ++sz;
    }
  }
  for (int i = 1; i <= Q; i++) printf("%d\n", ans[i]);
  return 0;
}
