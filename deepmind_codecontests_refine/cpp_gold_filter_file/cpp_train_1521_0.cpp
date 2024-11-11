#include <bits/stdc++.h>
using namespace std;
struct Circle {
  long long x, y, r;
  Circle(long long _ = 0, long long __ = 0, long long ___ = 0)
      : x(_), y(__), r(___) {}
};
const double PI = acos(-1.0);
const int MAXN = 1005;
Circle yuan[MAXN];
int fa[MAXN];
int dis[MAXN];
int n;
int getFa(int idx) {
  if (fa[idx] == idx) return idx;
  int now = dis[idx];
  int root = getFa(fa[idx]);
  dis[idx] = now + dis[fa[idx]];
  return fa[idx] = root;
}
const double eps = 1e-6;
bool in(int i, int j) {
  long long xi = yuan[i].x;
  long long yi = yuan[i].y;
  long long xj = yuan[j].x;
  long long yj = yuan[j].y;
  return sqrt((xi - xj) * (xi - xj) + (yi - yj) * (yi - yj)) -
             (yuan[i].r + yuan[j].r) <
         -eps;
}
int main() {
  scanf("%d", &n);
  for (int i = 0; i < n; i++)
    scanf("%I64d%I64d%I64d", &yuan[i].x, &yuan[i].y, &yuan[i].r);
  sort(yuan, yuan + n, [](Circle c1, Circle c2) { return c1.r < c2.r; });
  for (int i = 0; i < n; i++) {
    fa[i] = i;
    dis[i] = 0;
  }
  for (int i = 0; i < n; i++) {
    for (int j = n - 1; j > i; j--) {
      if (in(i, j)) {
        fa[i] = j;
        dis[i] = 1;
      }
    }
  }
  long long sumR2 = 0;
  for (int i = 0; i < n; i++) {
    getFa(i);
    int sign = (dis[i] == 0 || dis[i] == 1 || dis[i] % 2) ? 1 : -1;
    sumR2 += yuan[i].r * yuan[i].r * sign;
  }
  printf("%.9f\n", sumR2 * PI);
  return 0;
}
