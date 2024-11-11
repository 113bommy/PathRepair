#include <bits/stdc++.h>
using namespace std;
int n, LSH, lsh[100005 * 2];
struct data {
  int a, b, h;
} p[100005];
long long maxn[100005 * 8], f[100005], ans;
int find(int x) {
  int l = 1, r = LSH, mid, ans;
  while (l <= r) {
    mid = (l + r) >> 1;
    if (lsh[mid] >= x)
      ans = mid, r = mid - 1;
    else
      l = mid + 1;
  }
  return ans;
}
int cmp(data a, data b) { return a.b < b.b || (a.b == b.b && a.a < b.a); }
void update(int now) { maxn[now] = max(maxn[now << 1], maxn[now << 1 | 1]); }
void change(int now, int l, int r, int x, long long v) {
  int mid = (l + r) >> 1;
  if (l == r) {
    maxn[now] = max(maxn[now], v);
    return;
  }
  if (x <= mid)
    change(now << 1, l, mid, x, v);
  else
    change(now << 1 | 1, mid + 1, r, x, v);
  update(now);
}
long long query(int now, int l, int r, int lr, int rr) {
  int mid = (l + r) >> 1;
  long long ans = 0;
  if (lr <= l && r <= rr) return maxn[now];
  if (lr <= mid) ans = max(ans, query(now << 1, l, mid, lr, rr));
  if (mid + 1 <= rr) ans = max(ans, query(now << 1 | 1, mid + 1, r, lr, rr));
  return ans;
}
int main() {
  scanf("%d", &n);
  for (int i = 1; i <= n; ++i) {
    scanf("%d%d%d", &p[i].a, &p[i].b, &p[i].h);
    lsh[++LSH] = p[i].a, lsh[++LSH] = p[i].b;
  }
  sort(lsh + 1, lsh + LSH + 1);
  LSH = unique(lsh + 1, lsh + LSH + 1) - lsh - 1;
  for (int i = 1; i <= n; ++i) p[i].a = find(p[i].a), p[i].b = find(p[i].b);
  sort(p + 1, p + n + 1, cmp);
  f[1] = (long long)p[1].h;
  change(1, 1, LSH, p[1].b, f[1]);
  for (int i = 2; i <= n; ++i) {
    f[i] = query(1, 1, LSH, p[i].a + 1, p[i].b);
    f[i] += (long long)p[i].h;
    change(1, 1, LSH, p[i].b, f[i]);
  }
  ans = 0LL;
  for (int i = 1; i <= n; ++i) ans = max(ans, f[i]);
  printf("%I64d\n", ans);
}
