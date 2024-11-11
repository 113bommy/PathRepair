#include <bits/stdc++.h>
using namespace std;
struct rec {
  int sum[2], sl[2], sr[2], s[2], recl[2], recr[2], recll[2], recrr[2];
} tr[210000 * 4];
int a[210000], lab[210000], ql[100], qr[100], n;
rec merge(rec a, rec b) {
  rec c;
  for (int k = 0; k <= 1; k++) {
    c.sum[k] = a.sum[k] + b.sum[k];
    if (a.sl[k] > a.sum[k] + b.sl[k])
      c.sl[k] = a.sl[k], c.recl[k] = a.recl[k];
    else
      c.sl[k] = a.sum[k] + b.sl[k], c.recl[k] = b.recl[k];
    if (b.sr[k] > b.sum[k] + a.sr[k])
      c.sr[k] = b.sr[k], c.recr[k] = b.recr[k];
    else
      c.sr[k] = b.sum[k] + a.sr[k], c.recr[k] = a.recr[k];
    if (a.s[k] > b.s[k] && a.s[k] > a.sr[k] + b.sl[k])
      c.s[k] = a.s[k], c.recll[k] = a.recll[k], c.recrr[k] = a.recrr[k];
    else if (b.s[k] > a.sr[k] + b.sl[k])
      c.s[k] = b.s[k], c.recll[k] = b.recll[k], c.recrr[k] = b.recrr[k];
    else
      c.s[k] = a.sr[k] + b.sl[k], c.recll[k] = a.recr[k],
      c.recrr[k] = b.recl[k];
  }
  return c;
}
void down(int u, int l, int r) {
  if (!lab[u]) return;
  swap(tr[u].sum[0], tr[u].sum[1]);
  swap(tr[u].sl[0], tr[u].sl[1]);
  swap(tr[u].sr[0], tr[u].sr[1]);
  swap(tr[u].s[0], tr[u].s[1]);
  swap(tr[u].recl[0], tr[u].recl[1]);
  swap(tr[u].recr[0], tr[u].recr[1]);
  swap(tr[u].recll[0], tr[u].recll[1]);
  swap(tr[u].recrr[0], tr[u].recrr[1]);
  if (l != r) lab[u * 2] ^= 1, lab[u * 2 + 1] ^= 1;
  lab[u] = 0;
}
void debug(int u, int l, int r) {
  printf("%d %d %d %d %d %d\n", l, r, tr[u].sl[0], tr[u].sr[0], tr[u].s[0],
         tr[u].sum[0]);
}
void build(int u, int l, int r) {
  if (l == r) {
    tr[u].sum[0] = tr[u].sl[0] = tr[u].sr[0] = tr[u].s[0] = a[l];
    tr[u].sum[1] = tr[u].sl[1] = tr[u].sr[1] = tr[u].s[1] = -a[l];
    tr[u].recl[0] = tr[u].recl[1] = tr[u].recr[0] = tr[u].recr[1] = l;
    tr[u].recll[0] = tr[u].recll[1] = tr[u].recrr[0] = tr[u].recrr[1] = l;
    return;
  }
  int mid = (l + r) / 2;
  build(u * 2, l, mid);
  build(u * 2 + 1, mid + 1, r);
  tr[u] = merge(tr[u * 2], tr[u * 2 + 1]);
}
void change(int u, int l, int r, int x) {
  down(u, l, r);
  if (l == r) {
    tr[u].sum[0] = tr[u].sl[0] = tr[u].sr[0] = tr[u].s[0] = a[l];
    tr[u].sum[1] = tr[u].sl[1] = tr[u].sr[1] = tr[u].s[1] = -a[l];
    tr[u].recl[0] = tr[u].recl[1] = tr[u].recr[0] = tr[u].recr[1] = l;
    tr[u].recll[0] = tr[u].recll[1] = tr[u].recrr[0] = tr[u].recrr[1] = l;
    return;
  }
  int mid = (l + r) / 2;
  if (x <= mid)
    change(u * 2, l, mid, x);
  else
    change(u * 2 + 1, mid + 1, r, x);
  down(u * 2, l, mid);
  down(u * 2 + 1, mid + 1, r);
  tr[u] = merge(tr[u * 2], tr[u * 2 + 1]);
}
rec query(int u, int l, int r, int x, int y) {
  down(u, l, r);
  if (x <= l && y >= r) return tr[u];
  int mid = (l + r) / 2;
  if (y <= mid) return query(u * 2, l, mid, x, y);
  if (x > mid) return query(u * 2 + 1, mid + 1, r, x, y);
  return merge(query(u * 2, l, mid, x, y), query(u * 2 + 1, mid + 1, r, x, y));
}
void rev(int u, int l, int r, int x, int y) {
  down(u, l, r);
  if (x > r || y < l) return;
  if (x <= l && y >= r) {
    lab[u] = 1;
    down(u, l, r);
    return;
  }
  int mid = (l + r) / 2;
  rev(u * 2, l, mid, x, y);
  rev(u * 2 + 1, mid + 1, r, x, y);
  down(u * 2, l, mid);
  down(u * 2 + 1, mid + 1, r);
  tr[u] = merge(tr[u * 2], tr[u * 2 + 1]);
}
int main() {
  scanf("%d", &n);
  for (int i = 1; i <= n; i++) scanf("%d", &a[i]);
  build(1, 1, n);
  int T;
  scanf("%d", &T);
  while (T--) {
    int kk;
    scanf("%d", &kk);
    if (!kk) {
      int x, y;
      scanf("%d%d", &x, &y);
      a[x] = y;
      change(1, 1, n, x);
    } else {
      int l, r, k, Ans = 0, tot = 0, num = 0;
      scanf("%d%d%d", &l, &r, &k);
      while (k--) {
        rec ans = query(1, 1, n, l, r);
        if (ans.sl[0] > ans.sr[0] && ans.sl[0] > ans.s[0]) {
          tot += ans.sl[0];
          rev(1, 1, n, l, ans.recl[0]);
          ql[++num] = l;
          qr[num] = ans.recl[0];
        } else if (ans.sr[0] > ans.s[0]) {
          tot += ans.sr[0];
          rev(1, 1, n, ans.recr[0], r);
          ql[++num] = ans.recr[0];
          qr[num] = r;
        } else {
          tot += ans.s[0];
          rev(1, 1, n, ans.recll[0], ans.recrr[0]);
          ql[++num] = ans.recll[0];
          qr[num] = ans.recrr[0];
        }
        Ans = max(Ans, tot);
      }
      while (num) rev(1, 1, n, ql[num], qr[num]), num--;
      printf("%d\n", Ans);
    }
  }
  return 0;
}
