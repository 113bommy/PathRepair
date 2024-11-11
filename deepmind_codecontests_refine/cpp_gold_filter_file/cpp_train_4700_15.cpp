#include <bits/stdc++.h>
using namespace std;
const int maxn = 1000010;
struct SegementTree {
  int mx, lz;
};
SegementTree tr[maxn * 4];
int L[maxn], a[maxn];
void pushup(int x) { tr[x].mx = max(tr[(x << 1)].mx, tr[((x << 1) | 1)].mx); }
void maintain(int x, int val) {
  tr[x].mx += val;
  tr[x].lz += val;
}
void pushdown(int x) {
  if (tr[x].lz) {
    maintain((x << 1), tr[x].lz);
    maintain(((x << 1) | 1), tr[x].lz);
    tr[x].lz = 0;
  }
}
void build(int x, int l, int r) {
  if (l == r) {
    tr[x].mx = 0;
    tr[x].lz = 0;
    return;
  }
  int mid = (l + r) >> 1;
  build((x << 1), l, mid);
  build(((x << 1) | 1), mid + 1, r);
  pushup(x);
}
void update(int x, int l, int r, int ql, int qr, int val) {
  if (l >= ql && r <= qr) {
    maintain(x, val);
    return;
  }
  int mid = (l + r) >> 1;
  pushdown(x);
  if (ql <= mid) update((x << 1), l, mid, ql, qr, val);
  if (qr > mid) update(((x << 1) | 1), mid + 1, r, ql, qr, val);
  pushup(x);
}
int query(int x, int l, int r, int ql, int qr) {
  if (l >= ql && r <= qr) {
    return tr[x].mx;
  }
  int mid = (l + r) >> 1, ans = 0;
  pushdown(x);
  if (ql <= mid) ans = max(ans, query((x << 1), l, mid, ql, qr));
  if (qr > mid) ans = max(ans, query(((x << 1) | 1), mid + 1, r, ql, qr));
  return ans;
}
int main() {
  int n, m;
  scanf("%d%d", &n, &m);
  for (int i = 1; i <= n; i++) scanf("%d", &a[i]);
  a[0] = 0x3f3f3f3f;
  for (int i = 1; i <= n; i++) {
    L[i] = i - 1;
    while (a[i] > a[L[i]]) {
      L[i] = L[L[i]];
    }
  }
  build(1, 1, n);
  for (int i = 1; i < m; i++) update(1, 1, n, L[i] + 1, i, 1);
  for (int i = 1, j = m; j <= n; i++, j++) {
    update(1, 1, n, L[j] + 1, j, 1);
    printf("%d ", query(1, 1, n, i, j));
  }
}
