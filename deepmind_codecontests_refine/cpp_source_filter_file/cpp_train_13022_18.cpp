#include <bits/stdc++.h>
int main() {
  int i, j, n, m, f, l, c = 0;
  scanf("%i%i", &n, &m);
  int a_m[101] = {0};
  struct obj {
    int a[2];
  };
  struct obj o[n];
  for (i = 0; i < n; ++i) {
    scanf("%i%i", &o[i].a[0], &o[i].a[1]);
  }
  for (i = 0; i < n; ++i) {
    f = o[i].a[0];
    l = o[i].a[1];
    for (j = f; j <= l; ++j) {
      a_m[j]++;
    }
  }
  for (i = 1; i < m; ++i) {
    if (a_m[i] == 0) {
      ++c;
    }
  }
  if (c == 0)
    printf("%i", c);
  else
    printf("%i\n", c);
  for (i = 1; i < m; ++i) {
    if (a_m[i] == 0) {
      printf("%i ", i);
    }
  }
}
