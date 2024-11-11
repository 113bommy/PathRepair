#include <bits/stdc++.h>
using namespace std;
const int N = 310000;
int q[N], n, fry, frx, top, nxt[N];
long double k[N];
bool ans[N];
struct dian {
  int id, x, y;
} d[N];
bool operator<(const dian &a, const dian &b) {
  return a.x > b.x || (a.x == b.x && a.y > b.y);
}
long double K(dian i, dian j) {
  return (long double)i.x * j.x * (j.y - i.y) /
         ((long double)i.y * j.y * (j.x - i.x));
}
int main() {
  scanf("%d", &n);
  for (int i = 1; i <= n; i++) {
    d[i].id = i;
    scanf("%d%d", &d[i].x, &d[i].y);
    if (fry < d[i].y || (d[i].y == fry && frx < d[i].x)) {
      fry = d[i].y;
      frx = d[i].x;
    }
  }
  sort(d + 1, d + 1 + n);
  q[++top] = 1;
  for (int i = 2; i <= n && frx <= d[i].x; i++) {
    if (d[q[top]].x == d[i].x) {
      if (d[q[top]].y == d[i].y) {
        nxt[d[i].id] = nxt[d[q[top]].id];
        nxt[d[q[top]].id] = d[i].id;
      }
      continue;
    }
    while (top > 1 && k[top] > K(d[q[top]], d[i])) top--;
    q[++top] = i;
    k[top] = K(d[q[top - 1]], d[i]);
  }
  for (; top; top--) {
    for (int i = d[q[top]].id; i; i = nxt[i]) ans[i] = 1;
  }
  for (int i = 1; i <= n; i++)
    if (ans[i]) printf("%d ", i);
  printf("\n");
  return 0;
}
