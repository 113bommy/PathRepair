#include <bits/stdc++.h>
using namespace std;
const int N = 110;
int n, cnt, du[N], G[N], a[N], b[N], id1[N], id2[N], rk1[N], rk2[N], id[N];
struct edge {
  int t, nx;
} E[N * N];
inline bool cmp1(const int &x, const int &y) {
  return a[x] < a[y] || (a[x] == a[y] && x > y);
}
inline bool cmp2(const int &x, const int &y) {
  return b[x] < b[y] || (b[x] == b[y] && x < y);
}
inline void addedge(int x, int y) {
  E[++cnt].t = y;
  E[cnt].nx = G[x];
  G[x] = cnt;
  du[y]++;
}
int Q[N], l, r;
inline int cg1(int x, int y) {
  return ((a[x] <= a[y] && b[x] > a[y]) || (a[x] > a[y] && b[x] <= a[y])) +
         ((a[y] < b[x] && b[y] >= b[x]) || (a[y] >= b[x] && b[y] < b[x]));
}
inline int cg2(int x, int y) {
  return ((a[x] < a[y] && b[x] >= a[y]) || (a[x] >= a[y] && b[x] < a[y])) +
         ((a[y] <= b[x] && b[y] > b[x]) || (a[y] > b[x] && b[y] <= b[x]));
}
int main() {
  scanf("%d", &n);
  for (int i = 1; i <= n; i++)
    scanf("%d%d", &a[i], &b[i]), b[i] += a[i], id1[i] = id2[i] = i;
  sort(id1 + 1, id1 + 1 + n, cmp1);
  sort(id2 + 1, id2 + 1 + n, cmp2);
  for (int i = 1; i <= n; i++) rk1[id1[i]] = i, rk2[id2[i]] = i;
  for (int i = 1; i <= n; i++) {
    for (int j = i + 1; j <= n; j++) {
      if (cg1(i, j) > cg2(j, i)) addedge(i, j);
      if (cg2(j, i) > cg1(i, j)) addedge(j, i);
    }
  }
  l = 1;
  for (int i = 1; i <= n; i++)
    if (!du[i]) Q[++r] = i;
  while (l <= r) {
    int x = Q[l++];
    for (int i = G[x]; i; i = E[i].nx)
      if (!--du[E[i].t]) Q[++r] = E[i].t;
  }
  int ans = 0;
  for (int i = 1; i <= n; i++) {
    int x = Q[i], y = rk1[x];
    a[x] = b[x];
    while (y < n && cmp1(id1[y + 1], x))
      ans++, swap(rk1[x], rk1[id1[y + 1]]), swap(id1[y], id1[y + 1]), y++;
    while (y > 1 && cmp1(x, id1[y - 1]))
      ans++, swap(rk1[x], rk1[id1[y - 1]]), swap(id1[y], id1[y - 1]), y--;
  }
  printf("%d\n", ans);
  return 0;
}
