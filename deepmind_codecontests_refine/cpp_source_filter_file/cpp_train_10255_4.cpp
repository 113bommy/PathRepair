#include <bits/stdc++.h>
using namespace std;
int a[2000050];
int b[2000050];
int c[2000050];
struct node {
  int x, y;
  node() {}
  node(int xx, int yy) { x = xx, y = yy; }
} q[2000050];
int main() {
  int n;
  scanf("%d", &n);
  for (int i = 1; i <= n; ++i) scanf("%d", &a[i]);
  for (int i = 1; i <= n; ++i) {
    scanf("%d", &b[i]);
    c[b[i]] = i;
  }
  for (int i = 1; i <= n; ++i) a[i] = c[a[i]];
  int tail = 0;
  int ans = 0;
  for (int i = n; i > 0; --i) {
    int p = -1;
    for (int j = n; j > 0; --j)
      if (a[j] == i) {
        p = j;
        break;
      }
    if (p == i) continue;
    int now = p + 1;
    while (p != i) {
      while (now < n && a[now] >= now) now++;
      q[tail++] = node(p, now);
      swap(a[p], a[now]);
      ans += now - p;
      p = now;
      now++;
    }
  }
  printf("%d\n", ans);
  printf("%d\n", tail);
  for (int i = 0; i < tail; ++i) {
    printf("%d %d\n", q[i].x, q[i].y);
  }
}
