#include <bits/stdc++.h>
using namespace std;
const int N = (int)3e5 + 50;
int n, m, q;
int v[N];
int rv[N], sw[N];
int shad[N];
struct Tree {
  long long dat[N * 4];
  void init_dat(int x, int l, int r) {
    if (l == r) {
      dat[x] = v[l];
      return;
    }
    int mid = (l + r) / 2;
    init_dat(2 * x + 1, l, mid);
    init_dat(2 * x + 2, mid + 1, r);
    dat[x] = dat[2 * x + 1] + dat[2 * x + 2];
  }
  void update(int bt, int pos, int x, int l, int r, int val) {
    int mid = (l + r) / 2;
    if (l == r) {
      dat[x] = val;
      return;
    }
    if (rv[bt]) {
      bt = l + r - pos;
    }
    if (sw[bt - 1]) {
      if (pos <= mid)
        pos += (1 << (bt - 1));
      else
        pos -= (1 << (bt - 1));
    }
    if (pos <= mid)
      update(bt - 1, pos, 2 * x + 1, l, mid, val);
    else
      update(bt - 1, pos, 2 * x + 2, mid + 1, r, val);
    dat[x] = dat[2 * x + 1] + dat[2 * x + 2];
  }
  long long ask(int bt, int a, int b, int x, int l, int r) {
    assert(l <= a && b <= r);
    if (a <= l && r <= b) return dat[x];
    if (rv[bt]) {
      int na = l + r - b;
      int nb = l + r - a;
      a = na, b = nb;
    }
    long long res = 0;
    int mid = (l + r) / 2;
    int blen = (1 << (bt - 1));
    if (min(b, mid) >= a) {
      res += sw[bt - 1] ? ask(bt - 1, a + blen, min(b, mid) + blen, 2 * x + 2,
                              mid + 1, r)
                        : ask(bt - 1, a, min(b, mid), 2 * x + 1, l, mid);
    }
    if (max(a, mid + 1) <= b) {
      res +=
          sw[bt - 1]
              ? ask(bt - 1, max(a, mid + 1) - blen, b - blen, 2 * x + 1, l, mid)
              : ask(bt - 1, max(a, mid + 1), b, 2 * x + 2, mid + 1, r);
    }
    return res;
  }
} tree;
int main() {
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  cin >> m >> q;
  n = (1 << m);
  for (int i = 0; i < (n); ++i) cin >> v[i], shad[i] = v[i];
  tree.init_dat(0, 0, n - 1);
  while (q--) {
    int tp;
    cin >> tp;
    if (tp == 1) {
      int pos, val;
      cin >> pos >> val;
      pos--;
      tree.update(m, pos, 0, 0, n - 1, val);
    } else if (tp == 2) {
      int k;
      cin >> k;
      rv[k] ^= 1;
    } else if (tp == 3) {
      int k;
      cin >> k;
      sw[k] ^= 1;
    } else {
      int l, r;
      cin >> l >> r;
      l--, r--;
      cout << tree.ask(m, l, r, 0, 0, n - 1) << '\n';
    }
  }
}
