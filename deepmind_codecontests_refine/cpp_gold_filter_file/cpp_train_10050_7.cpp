#include <bits/stdc++.h>
using namespace std;
const long long INF = 1e18;
const int N = 1e5 + 50;
int n, k;
long long w[N], g[N], A[N], B[N];
int sta[N];
long long Sm[N];
namespace SGT {
const int N = ::N << 2;
long long a[N], mx[N], t[N];
void up(int x) {
  mx[x] = max(mx[x << 1], mx[x << 1 | 1]) + t[x];
  a[x] = max(a[x << 1], a[x << 1 | 1]);
}
void build(int x, int l, int r) {
  if (l == r) return a[x] = mx[x] = B[l], void();
  build(x << 1, l, ((l + r) >> 1));
  build(x << 1 | 1, ((l + r) >> 1) + 1, r);
  up(x);
}
void mdf(int x, int l, int r, int L, int R, long long v) {
  if (L <= l && r <= R) return t[x] += v, mx[x] += v, void();
  if (L <= ((l + r) >> 1)) mdf(x << 1, l, ((l + r) >> 1), L, R, v);
  if (R > ((l + r) >> 1)) mdf(x << 1 | 1, ((l + r) >> 1) + 1, r, L, R, v);
  up(x);
}
long long qry(int x, int l, int r, int L, int R) {
  if (L <= l && r <= R) return a[x];
  long long ans = -INF;
  if (L <= ((l + r) >> 1)) ans = max(ans, qry(x << 1, l, ((l + r) >> 1), L, R));
  if (R > ((l + r) >> 1))
    ans = max(ans, qry(x << 1 | 1, ((l + r) >> 1) + 1, r, L, R));
  return ans;
}
long long qmx(int x, int l, int r, int L, int R) {
  if (L <= l && r <= R) return mx[x];
  long long ans = -INF;
  if (L <= ((l + r) >> 1)) ans = max(ans, qmx(x << 1, l, ((l + r) >> 1), L, R));
  if (R > ((l + r) >> 1))
    ans = max(ans, qmx(x << 1 | 1, ((l + r) >> 1) + 1, r, L, R));
  return ans + t[x];
}
}  // namespace SGT
int main() {
  scanf("%d%d", &n, &k);
  for (int i = 1; i < n; i++) scanf("%lld", &w[i]), w[i] += w[i - 1];
  for (int i = 1; i <= n; i++) scanf("%lld", &g[i]), g[i] += g[i - 1];
  for (int i = 1; i <= n; i++)
    A[i] = g[i - 1] - w[i - 1], B[i] = g[i] - w[i - 1];
  int ans = 0, top = 0;
  SGT::build(1, 1, n);
  for (int i = n, u, v; i >= 1; i--) {
    while (top && A[i] <= A[sta[top]]) {
      u = sta[top], v = sta[top - 1];
      if (v) SGT::mdf(1, 1, n, v - 1, n, -A[u] + A[v]);
      --top;
    }
    sta[++top] = i;
    u = i, v = sta[top - 1];
    if (v) SGT::mdf(1, 1, n, v - 1, n, A[u] - A[v]);
    int l = 1, r = top;
    while (l < r) {
      int mid = (l + r) >> 1;
      if (A[sta[top]] - A[sta[mid]] <= k)
        r = mid;
      else
        l = mid + 1;
    }
    int rp = l == 1 ? n : sta[l - 1] - 1;
    l = i - 1, r = rp - 1;
    while (l < r) {
      int mid = (l + r + 1) >> 1;
      if (SGT::qmx(1, 1, n, i, mid) <= SGT::qry(1, 1, n, mid + 1, rp) + k)
        l = mid;
      else
        r = mid - 1;
    }
    ans = max(ans, l - i + 2);
  }
  cout << ans;
  return 0;
}
