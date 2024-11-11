#include <bits/stdc++.h>
int c[60];
struct oper {
  int x1, y1;
  int x2, y2;
} op[3000];
struct position {
  int a;
  int x, y;
} p[3000], q[3000];
int cmp(const void *a, const void *b) {
  struct position *c = (struct position *)a;
  struct position *d = (struct position *)b;
  return c->a - d->a;
}
int main() {
  int n, m, k, i, j, tmp, len;
  while (scanf("%d", &n) != EOF) {
    for (i = 1; i <= n; i++) scanf("%d", &c[i]);
    k = 0;
    for (i = 1; i <= n; i++)
      for (j = 1; j <= c[i]; j++) {
        scanf("%d", &p[k].a);
        p[k].x = i;
        p[k++].y = j;
      }
    len = k;
    for (i = 0; i < len; i++) {
      q[i].a = p[i].a;
      q[i].x = p[i].x;
      q[i].y = p[i].y;
    }
    m = 0;
    qsort(q, len, sizeof(q[0]), cmp);
    for (i = 0; i < len; i++) {
      if (p[i].a != q[i].a) {
        for (j = i + 1; j < len; j++) {
          if (p[j].a == q[i].a) {
            tmp = p[j].a;
            p[j].a = p[i].a;
            p[i].a = tmp;
            op[m].x1 = p[i].x;
            op[m].y1 = p[i].y;
            op[m].x2 = p[j].x;
            op[m].y2 = p[j].y;
            m++;
            break;
          }
        }
      }
    }
    printf("%d\n", m);
    for (i = 0; i < m; i++)
      printf("%d %d %d %d\n", op[i].x1, op[i].y1, op[i].x2, op[i].y2);
  }
  return 0;
}
