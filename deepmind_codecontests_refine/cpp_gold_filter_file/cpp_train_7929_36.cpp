#include <bits/stdc++.h>
const int N = 2e4 + 10;
int n, m;
int a[N], b[N], used[2 * N];
int main() {
  scanf("%d", &n);
  for (int i = 1; i <= n; ++i) scanf("%d", &a[i]), used[a[i]] = 1;
  scanf("%d", &m);
  for (int i = 1; i <= m; ++i) scanf("%d", &b[i]), used[b[i]] = 1;
  for (int i = 1; i <= n; ++i)
    for (int j = 1; j <= m; ++j)
      if (not used[a[i] + b[j]]) {
        printf("%d %d\n", a[i], b[j]);
        return 0;
      }
  return 0;
}
