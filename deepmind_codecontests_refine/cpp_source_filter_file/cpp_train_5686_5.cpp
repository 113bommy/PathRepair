#include <bits/stdc++.h>
using namespace std;
int re() {
  int s = 0, w = 1;
  char ch = getchar();
  while (ch < '0' || ch > '9') {
    if (ch == '-') w = -1;
    ch = getchar();
  }
  while (ch >= '0' && ch <= '9') s = s * 10 + ch - '0', ch = getchar();
  return s * w;
}
int n, x = -1, y = -1;
struct node {
  int l, r;
} a[200100];
bool cmp(node a, node b) { return a.r < b.r; }
int main() {
  n = re();
  for (int i = 1; i <= n; i++) a[i].l = re(), a[i].r = re();
  sort(a + 1, a + 1 + n, cmp);
  for (int i = 1; i <= n; i++) {
    if (x > y) swap(x, y);
    if (a[i].l > x) {
      x = a[i].r;
    } else if (a[i].l > y) {
      y = a[i].r;
    } else {
      puts("NO");
      return 0;
    }
  }
  puts("YES");
}
