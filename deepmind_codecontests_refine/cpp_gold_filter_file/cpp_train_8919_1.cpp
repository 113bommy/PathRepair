#include <bits/stdc++.h>
int n, m, p;
int a[3000000];
long long ans;
int main() {
  scanf("%d %d", &n, &m);
  p = 1 << n;
  for (int i = 0; i < p; ++i) {
    scanf("%d", &a[i]);
    ans += a[i];
  }
  printf("%.9lf\n", double(ans) / p);
  int u, v;
  for (int i = 0; i < m; ++i) {
    scanf("%d %d", &u, &v);
    ans += v - a[u];
    a[u] = v;
    printf("%.9lf\n", double(ans) / p);
  }
  return 0;
}
