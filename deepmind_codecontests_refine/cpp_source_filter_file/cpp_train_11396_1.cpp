#include <bits/stdc++.h>
using namespace std;
const int MAXN = 1e5 + 10, STAN = (1 << 30) - 1;
struct QJ {
  int l, r, q;
} q[MAXN];
int n, m;
struct Seg {
  int water[MAXN * 4], sh[MAXN * 4];
  bool fir[MAXN * 4];
  Seg() {
    memset(water, 0, sizeof(water));
    memset(fir, 0, sizeof(fir));
  }
  int _st, _ed, _x, _t;
  void _insert(int num, int l, int r) {
    if (_st <= l && r <= _ed) {
      water[num] ^= _x;
      return;
    }
    int mid = (l + r) >> 1;
    if (_st <= mid) _insert(num << 1, l, mid);
    if (_ed >= mid + 1) _insert(num << 1 | 1, mid + 1, r);
  }
  int _swim(int num, int l, int r, int now) {
    int x;
    now ^= water[num];
    if (l == r) {
      if (!fir[num]) {
        sh[num] = now;
        fir[num] = true;
      } else
        sh[num] &= now;
      return now;
    }
    int mid = (l + r) >> 1;
    if (_t <= mid)
      now = _swim(num << 1, l, mid, now);
    else
      now = _swim(num << 1 | 1, mid + 1, r, now);
    if (!fir[num]) {
      sh[num] = now;
      fir[num] = true;
    } else
      sh[num] &= now;
    return now;
  }
  int _check(int num, int l, int r) {
    if (l == r) return sh[num];
    if (_st <= l && r <= _ed) return sh[num];
    int mid = (l + r) >> 1;
    int ans = STAN;
    if (_st <= mid) ans &= _check(num << 1, l, mid);
    if (_ed >= mid + 1) ans &= _check(num << 1 | 1, mid + 1, r);
    return ans;
  }
  inline void Insert(int l, int r, int q) {
    _st = l, _ed = r, _x = q;
    _insert(1, 1, n);
  }
  inline int Swim(int t) {
    _t = t;
    return _swim(1, 1, n, 0);
  }
  inline bool Check(int l, int r, int q) {
    _st = l;
    _ed = r;
    return _check(1, 1, n) == q;
  }
} T;
int a[MAXN];
int main() {
  scanf("%d%d", &n, &m);
  for (int i = 1; i <= m; i++) {
    scanf("%d%d%d", &q[i].l, &q[i].r, &q[i].q);
    T.Insert(q[i].l, q[i].r, q[i].q);
  }
  for (int i = 1; i <= n; i++) a[i] = T.Swim(i);
  for (int i = 1; i <= m; i++)
    if (!T.Check(q[i].l, q[i].r, q[i].q)) {
      printf("NO\n");
      return 0;
    }
  printf("YES\n");
  for (int i = 1; i <= n; i++) printf("%d ", a[i]);
  printf("\n");
  return 0;
}
