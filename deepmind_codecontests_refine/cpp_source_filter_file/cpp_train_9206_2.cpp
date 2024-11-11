#include <bits/stdc++.h>
typedef struct val {
  long int val, ind;
} va;
int cmp(const void *a, const void *b) {
  va ka = *(va *)a;
  va kb = *(va *)b;
  if (ka.val > kb.val)
    return -1;
  else
    return 1;
}
int a[2009][2009];
int main() {
  va v[2009], ba[2009];
  long int n, m, t1, t2, i, j, ans = 0;
  scanf("%ld %ld", &n, &m);
  for (i = 0; i < n; i++) {
    scanf("%ld", &v[i].val);
    v[i].ind = i + 1;
    ba[i] = v[i];
  }
  for (i = 0; i < m; i++) {
    scanf("%ld %ld", &t1, &t2);
    a[t1][t2] = 1;
    a[t2][t1] = 1;
  }
  qsort(v, n, sizeof(va), cmp);
  for (i = 0; i < n; i++)
    for (j = 1; j <= m; j++)
      if (a[v[i].ind][j]) {
        a[v[i].ind][j] = 0;
        a[j][v[i].ind] = 0;
        ans += ba[j - 1].val;
      }
  printf("%ld\n", ans);
  return 0;
}
