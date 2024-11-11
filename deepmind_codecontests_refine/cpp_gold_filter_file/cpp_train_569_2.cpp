#include <bits/stdc++.h>
using namespace std;
constexpr int N = 1.1e5;
int n;
struct D {
  int x, h, id;
  bool operator<(const D& o) const { return x < o.x; }
} a[N];
int ans[N], f[N];
struct SD {
  int mf = 0;
  SD *lc = nullptr, *rc = nullptr;
} root;
void ins(SD* a, int l, int r, int w, int x) {
  if (l == r) {
    a->mf = x;
    return;
  }
  int mi = (l + r) / 2;
  if (w <= mi) {
    SD*& lc = a->lc;
    if (!lc) lc = new SD();
    ins(lc, l, mi, w, x);
  } else {
    SD*& rc = a->rc;
    if (!rc) rc = new SD();
    ins(rc, mi + 1, r, w, x);
  }
  a->mf = max(a->lc ? a->lc->mf : -1, a->rc ? a->rc->mf : -1);
}
int rmq(SD* a, int l, int r, int p, int q) {
  if (!a) return -1;
  if (p <= l && r <= q) return a->mf;
  if (q < l || r < p) return -1;
  int mi = (l + r) / 2;
  return max(rmq(a->lc, l, mi, p, q), rmq(a->rc, mi + 1, r, p, q));
}
int main() {
  ios_base::sync_with_stdio(false);
  cin >> n;
  for (int i = 0; i < n; ++i) {
    cin >> a[i].x >> a[i].h;
    a[i].id = i;
  }
  sort(a, a + n);
  f[n] = n;
  a[n].x = 1e9;
  for (int i = n - 1; i >= 0; --i) {
    int l = i, r = n;
    int mx = a[i].x + a[i].h - 1;
    while (l < r) {
      int mi = (l + r + 1) / 2;
      if (a[mi].x > mx)
        r = mi - 1;
      else
        l = mi;
    }
    f[i] = max(r, rmq(&root, 0, n, i + 1, r));
    ins(&root, 0, n, i, f[i]);
    ans[a[i].id] = f[i] - i + 1;
  }
  for (int i = 0; i < n; ++i) {
    cout << ans[i] << (i + 1 == n ? "\n" : " ");
  }
  return 0;
}
