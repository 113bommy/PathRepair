#include <bits/stdc++.h>
using namespace std;
const int N = 5e5 + 10;
int B[N], I[N], R[N];
int F[N];
void modify(int p[], int h[], int n) {
  for (int i = 1; i <= n; i++) h[i] = p[i];
  sort(h + 1, h + 1 + n);
  int cnt = unique(h + 1, h + 1 + n) - (h + 1);
  for (int i = 1; i <= n; i++) {
    p[i] = lower_bound(h + 1, h + 1 + cnt, p[i]) - h;
  }
}
struct node {
  int bb, ii, rr;
  friend bool operator<(const node n1, const node n2) {
    if (n1.bb != n2.bb) return n1.bb < n2.bb;
    if (n1.ii != n2.ii) return n1.ii > n2.ii;
    if (n1.rr != n2.rr) return n1.rr < n2.rr;
  }
} a[N];
int maxn[N * 4];
void build(int l, int r, int u) {
  if (l == r) {
    maxn[u] = 0;
    return;
  }
  int mid = (l + r) / 2;
  build(l, mid, u * 2);
  build(mid + 1, r, u * 2 + 1);
  maxn[u] = max(maxn[u * 2], maxn[u * 2 + 1]);
}
int query(int l, int r, int u, int x, int y) {
  if (l == x && r == y) return maxn[u];
  int mid = (l + r) / 2;
  if (y <= mid)
    return query(l, mid, u * 2, x, y);
  else if (x > mid)
    return query(mid + 1, r, u * 2 + 1, x, y);
  else
    return max(query(l, mid, u * 2, x, mid),
               query(mid + 1, r, u * 2 + 1, mid + 1, y));
}
void update(int l, int r, int u, int x, int id) {
  if (l == x && l == r) {
    maxn[u] = max(maxn[u], a[id].rr);
    return;
  }
  int mid = (l + r) / 2;
  if (x <= mid)
    update(l, mid, u * 2, x, id);
  else
    update(mid + 1, r, u * 2 + 1, x, id);
  maxn[u] = max(maxn[u * 2], maxn[u * 2 + 1]);
}
int main() {
  int n;
  scanf("%d", &n);
  for (int i = 1; i <= n; i++) scanf("%d", &B[i]);
  for (int i = 1; i <= n; i++) scanf("%d", &I[i]);
  for (int i = 1; i <= n; i++) scanf("%d", &R[i]);
  modify(B, F, n);
  modify(I, F, n);
  modify(R, F, n);
  for (int i = 1; i <= n; i++) {
    a[i].bb = B[i];
    a[i].ii = I[i];
    a[i].rr = R[i];
  }
  sort(a + 1, a + 1 + n);
  build(1, 1, n);
  int ans = 0;
  for (int i = n; i >= 1; i--) {
    if (a[i].ii < n && query(1, n, 1, a[i].ii + 1, n) > a[i].rr) {
      ans++;
      continue;
    }
    update(1, n, 1, a[i].ii, i);
  }
  printf("%d\n", ans);
  return 0;
}
