#include <bits/stdc++.h>
using namespace std;
struct node {
  long long a, b;
} Q[200010];
bool cmp(node x, node y) { return x.b < y.b; }
int main() {
  int n, t;
  long double p = 0, q = 0;
  scanf("%d%d", &n, &t);
  for (int i = 1; i <= n; i++) scanf("%lld", &Q[i].a);
  for (int i = 1; i <= n; i++) scanf("%lld", &Q[i].b);
  for (int i = 1; i <= n; i++) {
    p += Q[i].a * Q[i].b, q += Q[i].a;
  }
  sort(Q + 1, Q + n + 1, cmp);
  if (Q[1].b > t || Q[n].b < t) {
    printf("0\n");
    return 0;
  }
  if (p * 1.0 / q < t) {
    for (int i = 1; i <= n; i++) {
      long double tp = p - Q[i].a * Q[i].b, tq = q - Q[i].a;
      if (tp * 1.0 / tq >= t) {
        long double x = (p - t * q) * 1.0 / (Q[i].b - t);
        p -= x * Q[i].b, q -= x;
        break;
      } else
        p = tp, q = tq;
    }
  } else if (p * 1.0 / q > t) {
    for (int i = n; i >= 1; i--) {
      long double tp = p - Q[i].a * Q[i].b, tq = q - Q[i].a;
      if (tp * 1.0 / tq <= t) {
        long double x = (p - t * q) * 1.0 / (Q[i].b - t);
        p -= x * Q[i].b, q -= x;
        break;
      } else
        p = tp, q = tq;
    }
  }
  printf("%.8Lf\n", q);
  return 0;
}
