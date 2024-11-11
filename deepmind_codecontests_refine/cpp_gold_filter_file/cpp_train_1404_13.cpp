#include <bits/stdc++.h>
struct xx {
  int w, s;
} a[105];
int cmp(const void *a, const void *b) {
  xx *c = (xx *)a;
  xx *d = (xx *)b;
  if ((*c).w != (*d).w) return (*c).w - (*d).w;
  return (*c).s - (*d).s;
}
int n, k, tot, ans, b[105];
int main() {
  scanf("%d%d", &n, &k);
  for (int i = 0; i < n; i++) {
    scanf("%d", &a[i].w);
    a[i].s = i;
  }
  qsort(a, n, sizeof(a[0]), cmp);
  a[n].w = 1;
  if (a[0].w > k)
    printf("0");
  else {
    for (int i = 0; i < n; i++) {
      tot += a[i].w;
      if (tot > k) break;
      b[++ans] = a[i].s + 1;
    }
    printf("%d\n", ans);
    for (int i = 1; i <= ans; i++) printf("%d ", b[i]);
  }
  return 0;
}
