#include <bits/stdc++.h>
using namespace std;
inline int read() {
  int x = 0, w = 1;
  char c = getchar();
  while (c < '0' || c > '9') {
    if (c == '-') w = -1;
    c = getchar();
  }
  while (c <= '9' && c >= '0') {
    x = (x << 1) + (x << 3) + c - '0';
    c = getchar();
  }
  return w == 1 ? x : -x;
}
int n, ans[200005];
struct node {
  int x, y, id;
} a[200005];
int main() {
  n = read();
  for (int i = 1; i <= n; i++) a[i].x = read(), a[i].y = read(), a[i].id = i;
  while (1) {
    long long x = 0, y = 0;
    for (int i = 0; i <= n; i++) {
      if ((x + a[i].x) * (x + a[i].x) + (y + a[i].y) * (y + a[i].y) <=
          (x - a[i].x) * (x - a[i].x) + (y - a[i].y) * (y - a[i].y)) {
        ans[a[i].id] = 1;
        x += a[i].x;
        y += a[i].y;
      } else
        ans[a[i].id] = -1, x = a[i].x, y -= a[i].y;
    }
    if (x * x + y * y <= 1.5e6 * 1.5e6) break;
    random_shuffle(a + 1, a + n + 1);
  }
  for (int i = 1; i <= n; i++) printf("%d ", ans[i]);
  return 0;
}
