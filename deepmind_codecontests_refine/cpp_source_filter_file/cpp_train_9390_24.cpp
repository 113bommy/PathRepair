#include <bits/stdc++.h>
using namespace std;
const int MaxM = 1e5;
struct node {
  int u, v, pos;
  double w;
} e[MaxM + 1], e1[MaxM + 1];
int n, m, k, t;
int f[5001];
int ans[MaxM + 1];
int find(int x) {
  if (x != f[x]) f[x] = find(f[x]);
  return f[x];
}
bool cmp(const node &a, const node &b) { return a.w < b.w; }
int check(double x) {
  int cnt = 0;
  t = 0;
  for (int i = 1; i <= m; i++) {
    e1[i] = e[i];
    e1[i].w += e[i].u == 1 ? x : 0;
  }
  for (int i = 1; i <= n; i++) f[i] = i;
  sort(e1 + 1, e1 + m + 1, cmp);
  for (int i = 1; i <= m; i++) {
    int x = find(e1[i].u), y = find(e1[i].v);
    if (x != y) {
      f[y] = x;
      if (e1[i].u == 1) cnt++;
      ans[++t] = e1[i].pos;
    }
  }
  return cnt;
}
int main() {
  scanf("%d %d %d", &n, &m, &k);
  for (int i = 1; i <= m; i++) {
    scanf("%d %d %lf", &e[i].u, &e[i].v, &e[i].w);
    if (e[i].u > e[i].v) swap(e[i].u, e[i].v);
    e[i].pos = i;
  }
  double l = -1e6, r = 1e6, mid;
  int cnt;
  while (l + 0.1 < r) {
    mid = (l + r) / 2;
    cnt = check(mid);
    if (cnt == k) break;
    if (cnt < k)
      r = mid;
    else
      l = mid;
  }
  if (cnt == k) {
    printf("%d\n", t);
    for (int i = 1; i <= t; i++) printf("%d ", ans[i]);
  } else
    printf("-1\n");
  return 0;
}
