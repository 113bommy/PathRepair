#include <bits/stdc++.h>
using namespace std;
int tree[(int)9e5], lazy[(int)9e5];
void applyLazy(int pos, int lo, int hi) {
  lazy[pos * 2] += lazy[pos];
  lazy[pos * 2 + 1] += lazy[pos];
  tree[pos] += lazy[pos] * (hi - lo + 1);
  lazy[pos] = 0;
}
void upd(int lo, int hi, int num, int pos = 1, int currLo = 0,
         int currHi = (int)1e5 + 5) {
  applyLazy(pos, currLo, currHi);
  if (currHi < lo || currLo > hi) return;
  if (currHi <= hi && currLo >= lo) {
    lazy[pos] += num;
    applyLazy(pos, currLo, currHi);
    return;
  }
  int mid = (currLo + currHi) / 2;
  upd(lo, hi, num, pos * 2, currLo, mid);
  upd(lo, hi, num, pos * 2 + 1, mid + 1, currHi);
  tree[pos] = tree[pos * 2] + tree[pos * 2 + 1];
}
int query(int lo, int hi, int pos = 1, int currLo = 0,
          int currHi = (int)1e5 + 5) {
  if (currHi < lo || currLo > hi) return 0;
  if (currHi <= hi && currLo >= lo) {
    applyLazy(pos, currLo, currHi);
    return tree[pos];
  }
  applyLazy(pos, currLo, currHi);
  int mid = (currHi + currLo) / 2;
  return query(lo, hi, pos * 2, currLo, mid) +
         query(lo, hi, pos * 2 + 1, mid + 1, currHi);
}
int main() {
  int n, q;
  cin >> n >> q;
  int lo = 0, hi = n - 1;
  bool flip = 0;
  upd(0, n - 1, 1);
  for (int x = 0; x < q; x++) {
    int t;
    cin >> t;
    if (t == 1) {
      int p;
      cin >> p;
      if (flip) p = hi - lo + 1 - p;
      if (p <= (lo + hi) / 2) {
        for (int x = 1; p - x >= 0; x++) {
          upd(lo + p + x - 1, lo + p + x - 1, query(lo + p - x, lo + p - x));
          upd(lo + p - x, lo + p - x, 0);
        }
        lo += p;
        flip = 0;
      } else {
        for (int x = 1; p + lo + x - 1 <= hi; x++) {
          upd(p + lo - x, p + lo - x, query(p + lo + x - 1, p + lo + x - 1));
          upd(p + lo + x - 1, p + lo + x - 1, 0);
        }
        hi = lo + p - 1;
        flip = 1;
      }
    } else {
      int a, b;
      cin >> a >> b;
      b--;
      if (flip) {
        int tmpA = a;
        a = hi - b;
        b = hi - tmpA;
      } else {
        a += lo;
        b += lo;
      }
      cout << query(a, b) << endl;
    }
  }
}
