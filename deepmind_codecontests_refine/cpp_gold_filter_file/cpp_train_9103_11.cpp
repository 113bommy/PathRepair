#include <bits/stdc++.h>
using namespace std;
const int N = 1000010;
struct op {
  int x, y;
  op() {}
  op(int x, int y) : x(x), y(y) {}
};
op st1[N], st2[N];
int tp1, tp2;
int a[N], b[N], c1[N], c2[N], p[N];
int main() {
  int n, i, j, x;
  scanf("%d", &n);
  for (i = 1; i <= n; i++) scanf("%d", &a[i]);
  for (i = 1; i <= n; i++) scanf("%d", &b[i]);
  for (i = 1; i <= n; i++) {
    for (j = 30; j >= 0; j--) {
      if (1 << j & a[i]) {
        if (c1[j]) {
          st1[++tp1] = op(i, c1[j]);
          a[i] ^= a[c1[j]];
        } else {
          c1[j] = i;
          break;
        }
      }
    }
  }
  for (i = 1; i <= n; i++) {
    for (j = 30; j >= 0; j--) {
      if (1 << j & b[i]) {
        if (c2[j]) {
          st2[++tp2] = op(i, c2[j]);
          b[i] ^= b[c2[j]];
        } else {
          c2[j] = i;
          break;
        }
      }
    }
  }
  for (i = 30; i >= 0; i--) {
    if (c2[i] && !c1[i]) {
      printf("-1");
      return 0;
    }
    if (c1[i] && !c2[i]) {
      st1[++tp1] = op(c1[i], c1[i]);
      c1[i] = 0;
    }
    if (c1[i] && c2[i]) {
      x = a[c1[i]] ^ b[c2[i]];
      for (j = 30; j >= 0; j--) {
        if (1 << j & x) {
          if (c1[j]) {
            st1[++tp1] = op(c1[i], c1[j]);
            x ^= a[c1[j]];
          } else {
            printf("-1");
            return 0;
          }
        }
      }
      a[c1[i]] = b[c2[i]];
    }
  }
  for (i = 1; i <= n; i++) p[i] = -1;
  for (i = 30; i >= 0; i--) {
    if (c1[i]) p[c1[i]] = i;
  }
  for (i = 30; i >= 0; i--) {
    if (c1[i] != c2[i]) {
      if (p[c2[i]] != -1) c1[p[c2[i]]] = c1[i];
      swap(p[c1[i]], p[c2[i]]);
      st1[++tp1] = op(c2[i], c1[i]);
      st1[++tp1] = op(c1[i], c2[i]);
      st1[++tp1] = op(c2[i], c1[i]);
    }
  }
  printf("%d\n", tp1 + tp2);
  for (i = 1; i <= tp1; i++) {
    printf("%d %d\n", st1[i].x, st1[i].y);
  }
  for (i = tp2; i; i--) {
    printf("%d %d\n", st2[i].x, st2[i].y);
  }
}
