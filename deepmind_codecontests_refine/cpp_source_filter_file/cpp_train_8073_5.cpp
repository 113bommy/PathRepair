#include <bits/stdc++.h>
using namespace std;
const int N = 1e5 + 100;
int L, n, p, t;
int l[N];
int r[N];
int f[N];
int g[N];
void update(int i, int pre, int left, int right) {
  int tmp = pre + (right - left) / p;
  if (tmp > f[i]) {
    f[i] = tmp;
    g[i] = left + (right - left) / p * p;
  } else if (tmp == f[i]) {
    g[i] = min(g[i], left + (right - left) / p * p);
  }
}
int main() {
  int i, j;
  scanf("%d%d%d%d", &L, &n, &p, &t);
  for (i = 1; i <= n; i++) {
    scanf("%d%d", &l[i], &r[i]);
  }
  int ans = 0;
  g[0] = -t;
  for (i = 1, j = 0; i <= n; i++) {
    for (; g[j] + t <= r[i]; j++) {
      if (g[j] + t <= l[i]) {
        update(i, f[j], l[i], r[i]);
      } else {
        update(i, f[j], g[j] + t, r[i]);
      }
    }
    j--;
    ans = max(ans, f[i]);
    if (f[i] < f[i - 1]) {
      f[i] = f[i - 1];
      g[i] = g[i - 1];
    } else if (f[i] == f[i - 1]) {
      g[i] = g[i - 1];
    }
  }
  printf("%d\n", ans);
  return 0;
}
