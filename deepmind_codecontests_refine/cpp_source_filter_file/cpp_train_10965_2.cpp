#include <bits/stdc++.h>
using namespace std;
int n, k, q, x[100005], y[100005], h[100005], a[100005], b[100005], as, bs,
    v[100005 + 100005], f[100005], o[100005 + 100005], p, bit[100005];
int ql[100005], qh[100005], ts, st[1 << 18], A[100005], F[100005];
int main() {
  scanf("%d %d", &n, &k);
  for (int i = (1); i <= (n); i++) {
    scanf("%d", &x[i]);
    a[as++] = x[i];
  }
  for (int i = (1); i <= (n); i++) {
    scanf("%d", &y[i]);
    b[bs++] = y[i];
  }
  sort(a, a + as);
  sort(b, b + bs);
  as = unique(a, a + as) - a;
  bs = unique(b, b + bs) - b;
  for (int i = (1); i <= (n); i++) {
    int t = lower_bound(a, a + as, x[i]) - a;
    v[++p] = i;
    o[p] = f[t];
    f[t] = p;
  }
  for (int i = (0); i < (as); i++) {
    for (int z = (0); z < (2); z++)
      for (int j = (f[i]); j; j = o[j]) {
        int t = v[j];
        if (z) {
          int l = lower_bound(b, b + bs, y[t] - k) - b;
          int g = upper_bound(b, b + bs, y[t] + k) - b;
          for (int x = g; x; x -= x & -x) h[t] += bit[x];
          for (int x = l; x; x -= x & -x) h[t] -= bit[x];
        } else {
          int g = lower_bound(b, b + bs, y[t]) - b + 1;
          for (int x = g; x <= bs + 1; x += x & -x) bit[x]++;
        }
      }
  }
  scanf("%d", &q);
  for (int i = (0); i < (as); i++) f[i] = 0;
  p = 0;
  for (int i = (0); i < (q); i++) {
    int r, b, c;
    scanf("%d %d", &r, &b);
    c = max(x[r], x[b]);
    ql[i] = max(y[r], y[b]) - k;
    qh[i] = min(y[r], y[b]) + k;
    c = lower_bound(a, a + as, c) - a;
    v[++p] = i;
    o[p] = f[c];
    f[c] = p;
  }
  for (int i = (1); i <= (n); i++) {
    int t = lower_bound(a, a + as, x[i]) - a;
    v[++p] = i;
    o[p] = F[t];
    F[t] = p;
  }
  for (ts = 1; ts < bs + 2; ts <<= 1)
    ;
  for (int i = (as - 1); i >= (0); i--) {
    for (int j = (F[i]); j; j = o[j]) {
      int t = lower_bound(b, b + bs, y[v[j]]) - b + ts + 1;
      st[t] = max(st[j], h[v[j]]);
      for (t >>= 1; t; t >>= 1) st[t] = max(st[t << 1], st[(t << 1) + 1]);
    }
    for (int j = (f[i]); j; j = o[j]) {
      int l = lower_bound(b, b + bs, ql[v[j]]) - b;
      int h = upper_bound(b, b + bs, qh[v[j]]) - b - 1;
      if (l > h) {
        A[v[j]] = -1;
        continue;
      }
      for (l += ts, h += ts + 2; l ^ h ^ 1; l >>= 1, h >>= 1) {
        if (~l & 1) A[v[j]] = max(A[v[j]], st[l ^ 1]);
        if (h & 1) A[v[j]] = max(A[v[j]], st[h ^ 1]);
      }
      if (!A[v[j]]) A[v[j]]--;
    }
  }
  for (int i = (0); i < (q); i++) printf("%d\n", A[i]);
}
