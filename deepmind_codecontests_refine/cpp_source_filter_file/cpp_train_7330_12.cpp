#include <bits/stdc++.h>
using namespace std;
template <class T>
T sqr(T x) {
  return x * x;
}
const int N = 300010;
struct sa {
  int l, x, r;
};
struct sg {
  int l, r, d;
  sg() {}
  sg(int l, int r, int d) : l(l), r(r), d(d) {}
};
struct sf {
  int x, d, id;
};
vector<sg> g[N + 10];
sa a[N];
sf f[N * 4];
int n, L, R, ans;
void ins(int p, int l, int r, int b, int e, int d) {
  if (l == b && r == e) {
    if (f[p].id == 0) f[p].id = l;
    f[p].d += d;
    return;
  }
  int mid = (l + r) / 2;
  f[p * 2].d += f[p].d;
  f[p * 2 + 1].d += f[p].d;
  f[p].d = 0;
  if (e <= mid)
    ins(p * 2, l, mid, b, e, d);
  else if (b >= mid + 1)
    ins(p * 2 + 1, mid + 1, r, b, e, d);
  else {
    ins(p * 2, l, mid, b, mid, d);
    ins(p * 2 + 1, mid + 1, r, mid + 1, e, d);
  }
  if (f[p * 2].x + f[p * 2].d > f[p * 2 + 1].x + f[p * 2 + 1].d) {
    f[p].x = f[p * 2].x + f[p * 2].d;
    f[p].id = f[p * 2].id;
  } else {
    f[p].x = f[p * 2 + 1].x + f[p * 2 + 1].d;
    f[p].id = f[p * 2 + 1].id;
  }
}
int main() {
  int i, j;
  scanf("%d", &n);
  for (i = 1; i <= n; i++) {
    scanf("%d%d%d", &a[i].l, &a[i].x, &a[i].r);
    g[a[i].l].push_back(sg(a[i].x, a[i].r, 1));
    g[a[i].x + 1].push_back(sg(a[i].x, a[i].r, -1));
  }
  for (i = 1; i <= N; i++) {
    for (j = 0; j < g[i].size(); j++)
      ins(1, 1, N, g[i][j].l, g[i][j].r, g[i][j].d);
    if (f[1].x + f[1].d > ans) {
      ans = f[1].x + f[1].d;
      L = i;
      R = f[1].id;
    }
  }
  printf("%d\n", ans);
  for (i = 1; i <= n; i++)
    if (a[i].l <= L && a[i].x >= L && a[i].x <= R && a[i].r >= R)
      printf("%d ", i);
  puts("");
}
