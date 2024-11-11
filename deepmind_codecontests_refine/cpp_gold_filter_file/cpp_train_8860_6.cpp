#include <bits/stdc++.h>
const int N = 100005;
int d[N];
int main() {
  int n, s, k = 0;
  scanf("%d%d", &n, &s);
  for (int i = 1; i < n; ++i) {
    int u, v;
    scanf("%d%d", &u, &v);
    ++d[u], ++d[v];
  }
  for (int i = 1; i <= n; ++i) k += (d[i] == 1);
  printf("%lf", 2.0 * s / k);
}
