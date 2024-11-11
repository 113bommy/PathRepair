#include <bits/stdc++.h>
int main() {
  int n, m;
  scanf("%d%d", &n, &m);
  std::vector<int> p(m, 0);
  for (int i = 0; i < m; ++i) {
    puts("1");
    fflush(stdout);
    int t;
    scanf("%d", &t);
    if (t == -2) {
      return 0;
    }
    if (t == 0) {
      return 0;
    }
    if (t == 1) {
      p[i] = 1;
    } else {
      p[i] = -1;
    }
  }
  int l = 1, r = n, mid, t, it = 0;
  while (l <= r) {
    mid = (l + r) >> 1;
    assert((it + 1 + m) <= 60);
    printf("%d\n", mid);
    fflush(stdout);
    scanf("%d", &t);
    if (t == -2) {
      return 0;
    }
    t *= p[it++];
    if (t == 0) {
      return 0;
    }
    if (t == 1) {
      l = mid + 1;
    } else {
      r = mid - 1;
    }
  }
  return 0;
}
