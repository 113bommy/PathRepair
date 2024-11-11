#include <bits/stdc++.h>
using namespace std;
struct Node {
  double a;
  double b;
  double c;
} s[25];
bool cmp(Node x, Node y) { return x.c < y.c; }
int main() {
  int n, i, j;
  double a[25], b[25], c[25], v;
  while (scanf("%d %lf", &n, &v) != EOF) {
    for (i = 1; i <= n; i++) scanf("%lf", &s[i].a);
    for (i = 1; i <= n; i++) {
      scanf("%lf", &s[i].b);
      s[i].c = s[i].b / s[i].a;
    }
    sort(s + 1, s + n + 1, cmp);
    double ans = 0;
    for (i = 1; i <= n; i++) ans = ans + s[1].c * s[i].a;
    if (ans > v) ans = v;
    printf("%lf\n", ans);
  }
  return 0;
}
