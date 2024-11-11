#include <bits/stdc++.h>
using std::sort;
using std::vector;
int boss[3000];
int w[3000];
int c[3000];
struct Edge {
  int u, v, w;
} E[3000];
bool ecmp(Edge x, Edge y) { return x.w < y.w; }
int find(int x) {
  if (boss[x] != x) boss[x] = find(boss[x]);
  return boss[x];
}
int main() {
  int n;
  scanf("%d", &n);
  for (int i = 0; i < n - 1; ++i) {
    int tu, tv, tw;
    scanf("%d%d%d", &tu, &tv, &tw);
    Edge tmp = (Edge){tu - 1, tv - 1, tw};
    E[i] = tmp;
  }
  sort(E, E + n - 1, ecmp);
  int ans = E[0].w;
  for (int i = 0; i < n; ++i) boss[i] = i;
  int sum = 0;
  for (int i = 0; i < n; ++i) {
    scanf("%d", &w[i]);
    sum += w[i];
    c[i] = 1;
  }
  for (int i = 0; i < n - 1; ++i) {
    int bu = find(E[i].u);
    int bv = find(E[i].v);
    boss[bv] = bu;
    w[bu] += w[bv];
    c[bu] += c[bv];
    if (c[bu] > sum - w[bu])
      break;
    else
      ans = E[i + 1].w;
  }
  printf("%d\n", ans);
  return 0;
}
