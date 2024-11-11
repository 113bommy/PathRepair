#include <bits/stdc++.h>
using namespace std;
const int mn = 210;
int n, m, a[mn];
int main() {
  scanf("%d%d", &n, &m);
  int i, j, k;
  for (i = 1; i <= n; ++i) scanf("%d", a + i);
  if (m <= 0) {
    puts("No");
    return 0;
  }
  if (n <= 1) {
    if (m != a[1])
      puts("No");
    else {
      printf("Yes\n1 1");
      for (i = 1; i <= a[1] - 1; ++i) printf(" 1 1");
      printf("\n");
    }
    return 0;
  }
  if (m == 1) {
    k = 0;
    for (i = 1; i <= n; ++i)
      if (a[i] == 1) k = 1;
    if (!k)
      puts("No");
    else {
      --a[k];
      puts("Yes");
      printf("%d", k);
      for (i = 1; i <= n; ++i)
        for (j = 1; j <= a[i]; ++j) printf(" %d %d", i, i);
      printf(" %d\n", k);
    }
    return 0;
  }
  m = -m;
  for (i = 1; i <= n; ++i) m += a[i];
  if (m < 0)
    puts("No");
  else {
    puts("Yes");
    --a[1], --a[2];
    printf("1");
    for (i = 2; i <= n; ++i) {
      if (!m) break;
      k = min(m, a[i]);
      m -= k, a[i] -= k;
      for (j = 1; j <= k; ++j) printf(" %d %d", i, i);
    }
    printf(" 1 2");
    k = min(m, a[1]);
    a[1] -= k;
    for (i = 1; i <= k; ++i) printf(" 1 1");
    printf(" 2");
    for (i = 1; i <= n; ++i)
      for (j = 1; j <= a[i]; ++j) printf(" %d %d", i, i);
  }
  return 0;
}
