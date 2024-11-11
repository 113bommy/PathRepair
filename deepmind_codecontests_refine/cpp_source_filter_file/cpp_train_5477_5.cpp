#include <bits/stdc++.h>
using namespace std;
const int N = 200005;
vector<int> vec[N];
int sz[N], ok[N], n;
int q[N], fa[N];
int ans[N][3], top;
vector<int> e[N];
void dfs(int x, int fa) {
  sz[x] = 1;
  int mx = 0;
  for (auto i : e[x])
    if (i != fa) dfs(i, x), sz[x] += sz[i], mx = max(mx, sz[i]);
  if (sz[x] * 2 >= n && mx * 2 <= n) ok[x] = 1;
}
void dfs2(int x, int y) {
  fa[x] = y;
  for (auto i : e[x])
    if (i != y) dfs2(i, x);
  q[++*q] = x;
}
void ins(int x, int y, int z) {
  ++top;
  ans[top][0] = x;
  ans[top][1] = y;
  ans[top][2] = z;
}
int main() {
  scanf("%d", &n);
  for (int i = (int)(1); i <= (int)(n - 1); i++) {
    int x, y;
    scanf("%d%d", &x, &y);
    e[x].push_back(y);
    e[y].push_back(x);
  }
  dfs(1, 0);
  for (int i = (int)(1); i <= (int)(n); i++)
    if (ok[i])
      for (auto j : e[i])
        if (!ok[j]) {
          *q = 0;
          dfs2(j, i);
          ins(i, j, q[1]);
          for (int k = (int)(1); k <= (int)((*q) - 1); k++)
            if (fa[q[k]] != q[k + 1]) ins(q[k], fa[q[k]], q[k + 1]);
          for (int k = (int)((*q) - 1); k >= (int)(2); k--)
            ins(q[k - 1], q[k], q[*q]);
          ins(i, q[1], q[*q]);
        }
  printf("%d\n", top);
  for (int i = (int)(1); i <= (int)(top); i++)
    for (int j = (int)(0); j <= (int)(2); j++)
      printf("%d%c", ans[i][j], j == 2 ? '\n' : ' ');
}
