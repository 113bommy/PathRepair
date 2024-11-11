#include <bits/stdc++.h>
int gcd2(int a, int b) {
  if (a > b) return gcd2(b, a);
  if (b % a == 0) return a;
  return gcd2(b % a, a);
}
struct s {
  int v;
  int in;
};
int sortv(const void *v1, const void *v2) {
  struct s *s1 = (struct s *)v1;
  struct s *s2 = (struct s *)v2;
  return s1->v - s2->v;
}
int sorti(const void *v1, const void *v2) {
  struct s *s1 = (struct s *)v1;
  struct s *s2 = (struct s *)v2;
  return s1->in - s2->in;
}
struct s o[300000];
using namespace std;
int t, w, j, i, m, n, k;
int main() {
  scanf("%d", &n);
  for (i = 0; i < n; i++) {
    scanf("%I64d", &o[i].v);
    o[i].in = i;
  }
  w = sizeof(struct s);
  qsort(o, n, w, sortv);
  for (i = 0; i < n - 1; i++) {
    if (o[i].v == o[i + 1].v) {
      o[i + 1].v += 1;
    }
    if (o[i].v > o[i + 1].v) {
      o[i + 1].v = o[i].v + 1;
    }
  }
  qsort(o, n, w, sorti);
  for (i = 0; i < n; i++) {
    printf("%I64d ", o[i].v);
  }
  return 0;
}
