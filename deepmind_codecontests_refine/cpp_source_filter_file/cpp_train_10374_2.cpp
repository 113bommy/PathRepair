#include <bits/stdc++.h>
int h[100007];
int q[100007];
int od[100007];
int out[100007];
int n;
int good[100007];
int comp(const void *a, const void *b) {
  const int *ia = (const int *)a;
  const int *ib = (const int *)b;
  int x = *ia, y = *ib;
  if (x != y) return (q[x] - q[y]);
  return (y - x);
}
void init() {
  int i, o, p, j, k;
  scanf("%d", &n);
  for (i = n - 1; i >= 0; --i) {
    scanf("%d", &q[i]);
    od[i] = i;
  }
  qsort(od, n, sizeof(int), comp);
}
void up(int k) {
  int t = k / 2;
  if (t <= 0) return;
  if (h[t] < h[k]) return;
  int p = h[t];
  h[t] = h[k];
  h[k] = p;
  up(t);
}
void work() {
  int i, o, p, j, k;
  for (i = 0; i < n; ++i) {
    k = od[i];
    if (h[0] > 0 && k - h[1] > 0)
      good[k] = k - h[1] - 1;
    else
      good[k] = -1;
    if (q[od[i + 1]] != q[od[i]]) {
      h[++h[0]] = k;
      up(h[0]);
    }
  }
  for (i = n - 1; i > 0; --i) printf("%d ", good[i]);
  printf("%d\n", good[0]);
}
int main() {
  init();
  work();
  return 0;
}
