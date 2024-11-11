#include <bits/stdc++.h>
using namespace std;
int n, q, x, y, lo[200050];
long long ans;
struct dick {
  long long l, w;
} a[200050], b[200050];
struct data {
  long long l, r, s;
} tr1[4 * 200050], tr2[4 * 200050];
void build(int la, int l1, int r1) {
  tr1[la].l = l1;
  tr1[la].r = r1;
  tr2[la].l = l1;
  tr2[la].r = r1;
  if (l1 == r1) {
    tr1[la].s = a[l1].w;
    lo[l1] = la;
    tr2[la].s = b[l1].w * b[l1].l;
    return;
  }
  build(2 * la, l1, (l1 + r1) / 2);
  build(2 * la + 1, (l1 + r1) / 2 + 1, r1);
  tr1[la].s = tr1[2 * la].s + tr1[2 * la + 1].s;
  tr2[la].s = tr2[2 * la].s + tr2[2 * la + 1].s;
  tr2[la].s %= 1000000007;
}
void ch(int lab) {
  long long mid = lo[lab], mid1 = y - a[lab].w,
            mid2 = (y - b[lab].w) * b[lab].l % 1000000007;
  a[lab].w = b[lab].w = y;
  while (mid) {
    tr1[mid].s += mid1;
    tr2[mid].s += mid2;
    tr2[mid].s %= 1000000007;
    mid >>= 1;
  }
}
long long q1(int la, int l1, int r1) {
  if (l1 <= tr1[la].l && r1 >= tr1[la].r) return tr1[la].s;
  long long dick = 0;
  if (l1 <= tr1[2 * la].r) dick += q1(2 * la, l1, r1);
  if (r1 >= tr1[2 * la + 1].l) dick += q1(2 * la + 1, l1, r1);
  return dick;
}
long long q2(int la, int l1, int r1) {
  if (l1 <= tr2[la].l && r1 >= tr2[la].r) return tr2[la].s % 1000000007;
  long long dick = 0;
  if (l1 <= tr2[2 * la].r) dick += q2(2 * la, l1, r1) % 1000000007;
  if (r1 >= tr2[2 * la + 1].l) dick += q2(2 * la + 1, l1, r1) % 1000000007;
  return dick % 1000000007;
}
long long caul(int l, int r, int k) {
  long long sl = 0, sr = 0;
  if (k > l) sl = (q1(1, l, k - 1) % 1000000007) * b[k].l - q2(1, l, k - 1);
  if (k < r) sr = q2(1, k + 1, r) - (q1(1, k + 1, r) % 1000000007) * b[k].l;
  return ((sl + sr) % 1000000007 + 1000000007) % 1000000007;
}
void deal(int l, int r, long long ll, long long lr, int lm) {
  long long mid = (l + r) / 2, mid1 = 0;
  if (l == r) {
    printf("%lld\n", caul(x, y, l));
    return;
  }
  if (lm == -1) ll = q1(1, x, mid);
  lr = q1(1, mid + 1, y);
  if (lm != -1) {
    if (lm < mid) {
      mid1 = q1(1, lm + 1, mid);
      ll += mid1, lr -= mid1;
    }
    if (lm > mid) {
      mid1 = q1(1, mid + 1, lm);
      ll -= mid1, lr += mid1;
    }
  }
  if (ll < lr)
    deal(mid + 1, r, ll, lr, mid);
  else
    deal(l, mid, ll, lr, mid);
}
int main() {
  scanf("%d%d", &n, &q);
  for (int i = 1; i <= n; i++) scanf("%lld", &a[i].l), b[i].l = a[i].l - i;
  for (int i = 1; i <= n; i++) scanf("%lld", &a[i].w), b[i].w = a[i].w;
  build(1, 1, n);
  for (int i = 1; i <= q; i++) {
    scanf("%d%d", &x, &y);
    if (x < 0)
      ch(-x);
    else
      deal(x, y, 0, 0, -1);
  }
}
