#include <bits/stdc++.h>
const int blo = 1e3;
int n, x[1100000], y[1100000], p[1100000], w[1100000];
inline bool cmp(int a, int b) {
  if (w[a] == w[b]) {
    if (w[a] & 1)
      return y[a] < y[b];
    else
      return y[a] > y[b];
  }
  return w[a] < w[b];
}
int main() {
  scanf("%d", &n);
  for (int i = 1; i <= n; i++) {
    scanf("%d%d", &x[i], &y[i]);
    w[i] = x[i] / blo;
    p[i] = i;
  }
  std::sort(p + 1, p + n + 1, cmp);
  for (int i = 1; i <= n; i++) printf("%d ", p[i]);
  return 0;
}
