#include <bits/stdc++.h>
const double PI = 2.0 * acos(0);
using namespace std;
struct T {
  int a, b;
} ar[40000];
int R[] = {0, 0, 1, -1}, C[] = {1, -1, 0, 0};
int main() {
  int i, j, k, l, t, cs = 1, r = 1, s, m, n, a, b, c, d, e, f, g, h, u, v;
  scanf("%d", &n);
  for (i = 0; i < n; i++) {
    scanf("%d %d", &ar[i].a, &ar[i].b);
  }
  int ans = 0;
  for (i = 0; i < n - 2; i++) {
    a = ar[i + 1].a - ar[i].a;
    b = ar[i + 1].b - ar[i].b;
    c = ar[i + 2].a - ar[i + 1].a;
    d = ar[i + 2].b - ar[i + 1].b;
    if (a != 0) a /= abs(a);
    if (b != 0) b /= abs(b);
    if (c != 0) c /= abs(c);
    if (d != 0) d /= abs(d);
    for (j = 0; j < 4; j++) {
      if (a == R[j] && b == C[j]) u = j;
    }
    for (j = 0; j < 4; j++) {
      if (c == R[j] && d == C[j]) v = j;
    }
    if (u == 0 && v == 3) ans++;
    if (u == 1 && v == 2) ans++;
    if (u == 2 && v == 0) ans++;
    if (u == 3 && v == 1) ans++;
  }
  printf("%d\n", ans);
  return 0;
}
