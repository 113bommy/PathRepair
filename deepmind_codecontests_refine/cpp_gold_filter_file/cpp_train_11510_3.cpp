#include <bits/stdc++.h>
using namespace std;
const int maxn = 1000100;
int pre[maxn], C[4 * maxn], net[maxn], a[maxn], t[maxn];
struct node {
  int L, R, id;
} Q[maxn];
bool cmp(node u, node v) {
  if (u.R != v.R) return u.R < v.R;
  return u.L < v.L;
}
int ans[maxn], n;
int L, R, v;
void pushup(int rt) { C[rt] = C[rt << 1] ^ C[rt << 1 | 1]; }
void update(int l, int r, int rt) {
  if (l == r) {
    C[rt] ^= v;
    return;
  }
  int mid = l + r >> 1;
  if (L <= mid) update(l, mid, rt << 1);
  if (R > mid) update(mid + 1, r, rt << 1 | 1);
  pushup(rt);
}
int query(int l, int r, int rt) {
  if (L <= l && R >= r) return C[rt];
  int mid = l + r >> 1, ans = 0;
  if (L <= mid) ans ^= query(l, mid, rt << 1);
  if (R > mid) ans ^= query(mid + 1, r, rt << 1 | 1);
  return ans;
}
int main() {
  scanf("%d", &n);
  memset(net, -1, sizeof(net));
  for (int i = 1; i <= n; i++)
    scanf("%d", &a[i]), t[i] = a[i], pre[i] = pre[i - 1] ^ a[i];
  sort(t + 1, t + n + 1);
  int m = unique(t + 1, t + n + 1) - t - 1, q;
  scanf("%d", &q);
  for (int i = 1; i <= q; i++) scanf("%d%d", &L, &R), Q[i] = (node){L, R, i};
  sort(Q + 1, Q + q + 1, cmp);
  int k = 1;
  for (int i = 1; i <= n; i++) {
    int num = lower_bound(t + 1, t + m + 1, a[i]) - t;
    v = a[i];
    if (net[num] == -1)
      L = R = i, update(1, n, 1);
    else
      R = L = net[num], update(1, n, 1), L = R = i, update(1, n, 1);
    net[num] = i;
    while (k <= q && Q[k].R == i)
      L = Q[k].L, R = Q[k].R,
      ans[Q[k].id] = query(1, n, 1) ^ pre[Q[k].R] ^ pre[Q[k].L - 1], k++;
  }
  for (int i = 1; i <= q; i++) printf("%d\n", ans[i]);
  return 0;
}
