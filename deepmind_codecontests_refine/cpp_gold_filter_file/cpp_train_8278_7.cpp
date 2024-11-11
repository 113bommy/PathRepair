#include <bits/stdc++.h>
struct D {
  int a, b;
};
D d[100010];
int n;
int cmp(const void* a, const void* b) {
  D* aa = (D*)a;
  D* bb = (D*)b;
  return (aa->b / aa->a) - (bb->b) / (bb->a);
}
int tn(int x) {
  if (x == n) {
    return 2100000000;
  }
  return (d[x].b) / (d[x].a);
}
int main() {
  int kk;
  scanf("%d%d", &n, &kk);
  long long int k = kk;
  for (int i = 0; i < n; i++) {
    scanf("%d", &d[i].a);
  }
  for (int i = 0; i < n; i++) {
    scanf("%d", &d[i].b);
  }
  qsort(d, n, sizeof(D), cmp);
  d[n].a = 2100000000;
  d[n].b = 2010000000;
  int ans = 0;
  int c = 0;
  int p = 0;
  if (k == 0) {
    printf("%d\n", tn(0));
    return 0;
  }
  while (k > 0) {
    long long int tc = (tn(p) - ans) * c;
    if (k >= tc) {
      k -= tc;
      ans = tn(p);
    } else {
      ans += k / c;
      break;
    }
    int odc = c;
    int cc = d[p].a - (d[p].b % d[p].a);
    c += d[p].a;
    p++;
    while (tn(p) == tn(p - 1)) {
      cc += d[p].a - (d[p].b % d[p].a);
      c += d[p].a;
      p++;
    }
    if (k >= (cc + odc)) {
      k -= cc;
      k -= odc;
      ans++;
    } else
      break;
    if (p == n) {
      ans += (k / c);
      break;
    }
  }
  printf("%d\n", ans);
  return 0;
}
