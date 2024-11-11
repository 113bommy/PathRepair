#include <bits/stdc++.h>
const int N = 100005;
int n, d[N], id[N], x[2 * N];
int main() {
  scanf("%d", &n);
  for (int i = 0; i < n; ++i) {
    scanf("%d", d + i);
    id[i] = i;
  }
  std::sort(id, id + n, [](int a, int b) { return d[a] > d[b] ? a : b; });
  for (int i = 0; i < n; ++i) {
    x[i] = 2 * id[i] + 1;
    if (i) printf("%d %d\n", 2 * id[i - 1] + 1, 2 * id[i] + 1);
  }
  int cur = n - 1;
  for (int i = 0; i < n; ++i) {
    printf("%d %d\n", 2 * id[i] + 2, x[d[id[i]] + i - 1]);
    if (d[id[i]] + i > cur) {
      x[++cur] = 2 * id[i] + 2;
    }
  }
  return 0;
}
