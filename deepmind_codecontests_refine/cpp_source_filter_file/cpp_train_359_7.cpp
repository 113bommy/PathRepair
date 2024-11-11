#include <bits/stdc++.h>
using namespace std;
int ok[200005], n, q[200005], s[200005];
struct data {
  int id, a, b;
} c[200005];
bool cmp(data a, data b) {
  if (a.a == b.a) return a.b > b.b;
  return a.a > b.a;
}
int Judge(data a, data b, data c) {
  long long k = 1LL * (b.a - a.a) * (c.a - b.a);
  k = 1;
  if (1LL * (a.b - b.b) * a.a * c.b * (c.a - a.a) * k >
      1LL * k * (b.b - c.b) * c.a * a.b * (b.a - a.a))
    return 1;
  return 0;
}
int interisminus(data a, data b) {
  int x = 1, y = 1;
  if (a.b < b.b) x = -1;
  if (a.b == b.b) x = 0;
  if (b.a < a.a) y = -1;
  if (x * y != 1) return 1;
  return 0;
}
int main() {
  scanf("%d", &n);
  for (int i = 1; i <= n; i++) scanf("%d%d", &c[i].a, &c[i].b), c[i].id = i;
  sort(c + 1, c + 1 + n, cmp);
  int r = 0;
  c[0].a = -1;
  for (int i = 1; i <= n; i++) {
    if (c[i].a == c[i - 1].a) continue;
    while (r > 1 && Judge(c[i], c[q[r]], c[q[r - 1]])) r--;
    q[++r] = i;
  }
  for (int i = 1; i <= r; i++) ok[c[q[i]].id] = 1;
  for (int i = r; i > 1; i--) {
    if (c[q[i]].b <= c[q[i - 1]].b)
      ok[c[q[i]].id] = 0;
    else
      break;
  }
  for (int i = 2; i <= n; i++)
    if (c[i].a == c[i - 1].a && c[i].b == c[i - 1].b && ok[c[i - 1].id])
      ok[c[i].id] = 1;
  for (int i = 1; i <= n; i++)
    if (ok[i]) printf("%d ", i);
  printf("\n");
  return 0;
}
