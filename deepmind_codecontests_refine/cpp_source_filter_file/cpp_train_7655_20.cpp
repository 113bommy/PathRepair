#include <bits/stdc++.h>
using namespace std;
const int MAXN = 100010;
int n;
int fa[MAXN][21];
int dep[MAXN];
int LCA(int x, int y) {
  if (dep[x] < dep[y]) swap(x, y);
  for (int i = 20; i >= 0; i--) {
    if (dep[x] - (1 << i) >= dep[y]) {
      x = fa[x][i];
    }
  }
  if (x == y) return x;
  for (int i = 20; i >= 0; i--) {
    if (fa[x][i] != fa[y][i]) {
      x = fa[x][i];
      y = fa[y][i];
    }
  }
  return fa[x][0];
}
int main() {
  scanf("%d", &n);
  int L, R;
  L = R = 1;
  int mx = 0;
  int p;
  for (int i = 2; i <= n; i++) {
    scanf("%d", &p);
    fa[i][0] = p;
    dep[i] = dep[p] + 1;
    for (int j = 1; j <= 20; j++) {
      fa[i][j] = fa[fa[i][j - 1]][j - 1];
    }
    int z = LCA(i, L);
    int ans1 = dep[i] + dep[L] - 2 * dep[z];
    z = LCA(i, R);
    int ans2 = dep[i] + dep[R] - 2 * dep[z];
    if (ans1 > ans2 && ans1 > mx) {
      mx = ans1;
      R = i;
    }
    if (ans2 >= ans1 && ans2 > mx) {
      L = i;
      mx = ans2;
    }
    if (i == n)
      printf("%d\n", mx);
    else
      printf("%d ", mx);
  }
}
