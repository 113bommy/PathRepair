#include <bits/stdc++.h>
using std::bitset;
using std::sort;
int n, m;
bitset<160> a[160], b[160], T[160];
struct Edge {
  int from, to, w;
  bool operator<(Edge x) const { return w < x.w; }
} edge[160];
void times(bitset<160> *a, bitset<160> *b) {
  bitset<160> res[160];
  for (int i = 1; i <= n; i++)
    for (int j = 1; j <= n; j++)
      if (a[i][j]) res[i] |= b[j];
  for (int i = 1; i <= n; i++) a[i] = res[i];
}
void quickpow(bitset<160> *a, int b) {
  bitset<160> res[160];
  for (int i = 1; i <= n; i++) res[i][i] = 1;
  while (b) {
    if (b & 1) times(res, a);
    times(a, a);
    b >>= 1;
  }
  for (int i = 1; i <= n; i++) a[i] = res[i];
}
int main() {
  scanf("%d%d", &n, &m);
  for (int i = 1; i <= m; i++)
    scanf("%d%d%d", &edge[i].from, &edge[i].to, &edge[i].w);
  sort(edge + 1, edge + m + 1);
  for (int i = 1; i <= n; i++) a[i][i] = 1;
  int now = 0;
  if (edge[1].w > 0) return puts("Impossible"), 0;
  for (int i = 1; i < m; i++) {
    T[edge[i].from][edge[i].to] = 1;
    if (edge[i].w == edge[i + 1].w) continue;
    for (int j = 1; j <= n + 1 && now < edge[i + 1].w; j++, now++) {
      times(a, T);
      if (a[1][n] == 1) return printf("%d\n", now), 0;
    }
    for (int j = 1; j <= n; j++) b[j] = T[j];
    quickpow(b, edge[i + 1].w - now);
    times(a, b);
    now = edge[i + 1].w;
  }
  T[edge[m].from][edge[m].to] = 1;
  for (int j = 1; j <= n + 1; j++, now++) {
    times(a, T);
    if (a[1][n] == 1) return printf("%d\n", now + 1), 0;
  }
  return puts("Impossible"), 0;
}
