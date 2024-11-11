#include <bits/stdc++.h>
using namespace std;
const int inf = 2147483647;
const int N = 1e5 + 1;
int _max(int x, int y) { return x > y ? x : y; }
int _min(int x, int y) { return x < y ? x : y; }
inline int read() {
  int x = 0, f = 1;
  char ch = getchar();
  while (ch < '0' || ch > '9') {
    if (ch == '-') f = -1;
    ch = getchar();
  }
  while (ch >= '0' && ch <= '9')
    x = (x << 3) + (x << 1) + (ch ^ 48), ch = getchar();
  return x * f;
}
void put(int x) {
  if (x < 0) putchar('-'), x = -x;
  if (x >= 10) put(x / 10);
  putchar(x % 10 + '0');
}
struct node {
  int x, p;
} a[N];
int m1[N], m2[N];
bool cmp(node a, node b) { return a.x < b.x; }
int main() {
  int n = read(), mn = 1e9, mx = -1e9;
  for (int i = 1; i <= n; i++) {
    a[i].x = read(), a[i].p = i;
    mn = _min(mn, a[i].x), mx = _max(mx, a[i].x);
  }
  for (int i = 1; i <= n; i++) {
    m1[a[i].p] = _max(a[i].x - mn, mx - a[i].x);
    int c1 = 2e9, c2 = 2e9;
    if (i > 1) c1 = _min(c1, a[i].x - a[i - 1].x);
    if (i < n) c2 = _min(c2, a[i + 1].x - a[i].x);
    m2[a[i].p] = _min(c1, c2);
  }
  for (int i = 1; i <= n; i++) printf("%d %d\n", m2[i], m1[i]);
  return 0;
}
