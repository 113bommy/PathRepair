#include <bits/stdc++.h>
using namespace std;
const int M = 100005;
int read() {
  int x = 0, flag = 1;
  char c;
  while ((c = getchar()) < '0' || c > '9')
    if (c == '-') flag = -1;
  while (c >= '0' && c <= '9')
    x = (x << 3) + (x << 1) + (c ^ 48), c = getchar();
  return x * flag;
}
int n, m, k, len, bit[3 * M], b[5 * M];
long long ans;
struct node {
  int x, r, f;
  bool operator<(const node &b) const { return r > b.r; }
} a[M];
struct data {
  int tp, x, y, w;
  bool operator<(const data &b) const { return x < b.x; }
} p[5 * M];
int lowbit(int x) { return x & (-x); }
void upd(int x, int f) {
  for (int i = x; i <= len; i += lowbit(i)) bit[i] += f;
}
int ask(int x) {
  int r = 0;
  for (int i = x; i >= 1; i -= lowbit(i)) r += bit[i];
  return r;
}
void cdq(int l, int r) {
  if (l == r) return;
  int mid = (l + r) >> 1, j = l;
  cdq(l, mid);
  cdq(mid + 1, r);
  sort(p + l, p + mid + 1);
  sort(p + mid + 1, p + r + 1);
  for (int i = mid + 1; i <= r; i++) {
    while (j <= mid && p[i].x >= p[j].x) {
      if (p[j].tp == 0) upd(p[j].y, 1);
      j++;
    }
    if (p[i].tp == 1) ans += p[i].w * ask(p[i].y);
  }
  for (j--; j >= l; j--)
    if (p[j].tp == 0) upd(p[j].y, -1);
}
int main() {
  n = read();
  k = read();
  for (int i = 1; i <= n; i++) {
    int x = read(), r = read(), f = read();
    a[i] = node{x, r, f};
  }
  sort(a + 1, a + 1 + n);
  for (int i = 1; i <= n; i++) {
    int x = a[i].x, r = a[i].r, f = a[i].f;
    int x1 = x - r, x2 = x + r, y1 = f - k, y2 = f + k;
    p[++m] = data{1, x1 - 1, y1 - 1, 1};
    p[++m] = data{1, x1 - 1, y2, -1};
    p[++m] = data{1, x2, y1 - 1, -1};
    p[++m] = data{1, x2, y2, 1};
    p[++m] = data{0, x, f, 0};
  }
  for (int i = 1; i <= m; i++) b[i] = p[i].y;
  sort(b + 1, b + 1 + m);
  len = unique(b + 1, b + 1 + m) - b - 1;
  for (int i = 1; i <= m; i++)
    p[i].y = lower_bound(b + 1, b + 1 + len, p[i].y) - b;
  cdq(1, m);
  printf("%lld\n", ans);
}
