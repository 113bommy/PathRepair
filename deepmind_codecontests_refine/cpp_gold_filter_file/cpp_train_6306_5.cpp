#include <bits/stdc++.h>
using namespace std;
const int N = 1e5 + 5, F = 1e4 + 15;
long long ans;
int n, r[N], cnt, c[F], x[N], f[N], p[N];
struct node {
  int op, x, y, w;
  bool operator<(const node a) const { return (x ^ a.x) ? x < a.x : op < a.op; }
} q[N * 5], t[N * 5];
int read() {
  int x = 0, f = 1;
  char s;
  while ((s = getchar()) < '0' || s > '9')
    if (s == '-') f = -1;
  while (s >= '0' && s <= '9') {
    x = (x << 1) + (x << 3) + (s ^ 48);
    s = getchar();
  }
  return x * f;
}
bool cmp(const int a, const int b) { return r[a] > r[b]; }
int lowbit(const int x) { return x & -x; }
void add(int x, const int k) {
  while (x <= F - 5) c[x] += k, x += lowbit(x);
}
int ask(int x) {
  int r = 0;
  while (x) r += c[x], x -= lowbit(x);
  return r;
}
void Clear(int x) {
  while (x <= F - 5) c[x] = 0, x += lowbit(x);
}
void cdq(const int L, const int R) {
  if (L >= R) return;
  int mid = L + R >> 1;
  cdq(L, mid);
  cdq(mid + 1, R);
  int i = L, j = mid + 1, k = L;
  while (i <= mid && j <= R)
    if (q[i] < q[j]) {
      if (q[i].op == 0) add(q[i].y, 1);
      t[k++] = q[i++];
    } else {
      if (q[j].op == 1) ans += ask(q[j].y) * q[j].w;
      t[k++] = q[j++];
    }
  while (i <= mid) t[k++] = q[i++];
  while (j <= R) {
    if (q[j].op == 1) ans += ask(q[j].y) * q[j].w;
    t[k++] = q[j++];
  }
  for (i = L; i <= R; ++i) {
    if (q[i].op == 0) Clear(q[i].y);
    q[i] = t[i];
  }
}
int main() {
  int k;
  n = read(), k = read();
  for (int i = 1; i <= n; ++i)
    x[i] = read(), r[i] = read(), f[i] = read(), p[i] = i;
  sort(p + 1, p + n + 1, cmp);
  for (int i = 1; i <= n; ++i) {
    int s = p[i];
    int x1 = x[s] - r[s], x2 = x[s] + r[s], y1 = max(f[s] - k, 1),
        y2 = f[s] + k;
    q[++cnt] = (node){1, x1 - 1, y1 - 1, 1};
    q[++cnt] = (node){1, x1 - 1, y2, -1};
    q[++cnt] = (node){1, x2, y1 - 1, -1};
    q[++cnt] = (node){1, x2, y2, 1};
    q[++cnt] = (node){0, x[s], f[s], 0};
  }
  cdq(1, cnt);
  printf("%lld\n", ans);
  return 0;
}
