#include <bits/stdc++.h>
#pragma GCC optimize("Ofast")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx")
using namespace std;
struct node {
  long long pref = 0;
  long long suf = 0;
  long long dp = 0;
  node() {}
};
long long sz = 1 << 3;
vector<node> tree(2 * sz - 1, node());
vector<long long> a(sz);
void change(long long id, long long l, long long r, long long i, long long x) {
  if (r - l == 1) {
    a[i] = x;
    tree[id].pref = 1;
    tree[id].suf = 1;
    tree[id].dp = 1;
    return;
  }
  long long mid = (l + r) / 2;
  if (i < mid)
    change(id * 2 + 1, l, mid, i, x);
  else
    change(id * 2 + 2, mid, r, i, x);
  long long suf = tree[id * 2 + 1].suf;
  long long pref = tree[id * 2 + 2].pref;
  if (a[mid - 1] <= a[mid])
    tree[id].dp = tree[id * 2 + 1].dp - suf * (suf + 1) / 2 +
                  tree[id * 2 + 2].dp - pref * (pref + 1) / 2 +
                  (suf + pref) * (suf + pref + 1) / 2;
  else {
    tree[id].dp = tree[id * 2 + 1].dp + tree[id * 2 + 2].dp;
  }
  if (tree[id * 2 + 1].pref == mid - l and a[mid - 1] <= a[mid])
    tree[id].pref = mid - l + pref;
  else
    tree[id].pref = tree[id * 2 + 1].pref;
  if (tree[id * 2 + 2].suf == r - mid and a[mid] >= a[mid - 1])
    tree[id].suf = r - mid + suf;
  else
    tree[id].suf = tree[id * 2 + 2].suf;
}
node getsum(long long id, long long l, long long r, long long lq,
            long long rq) {
  if (l >= rq or r <= lq) return node();
  if (lq <= l and r <= rq) return tree[id];
  long long mid = (l + r) / 2;
  node x = getsum(id * 2 + 1, l, mid, lq, rq);
  node y = getsum(id * 2 + 2, mid, r, lq, rq);
  if (x.dp == 0) return y;
  if (y.dp == 0) return x;
  node c = node();
  long long suf = x.suf;
  long long pref = y.pref;
  if (a[mid - 1] <= a[mid]) {
    c.dp = x.dp - suf * (suf + 1) / 2 + y.dp - pref * (pref + 1) / 2 +
           (suf + pref) * (suf + pref + 1) / 2;
  } else {
    c.dp = x.dp + y.dp;
  }
  if (x.pref == mid - max(lq, l) and a[mid - 1] <= a[mid])
    c.pref = mid - max(lq, l) + pref;
  else
    c.pref = x.pref;
  if (y.suf == min(r, rq) - mid and a[mid] >= a[mid - 1])
    c.suf = min(r, rq) - mid + suf;
  else
    c.suf = y.suf;
  return c;
}
int main() {
  {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
  };
  long long n, q;
  cin >> n >> q;
  for (long long i = 0; i < n; i++) cin >> a[i];
  for (long long i = 0; i < n; i++) change(0, 0, sz, i, a[i]);
  for (long long i = 0; i < q; i++) {
    long long t;
    cin >> t;
    if (t == 1) {
      long long x, y;
      cin >> x >> y;
      x--;
      change(0, 0, sz, x, y);
    } else {
      long long lq, rq;
      cin >> lq >> rq;
      lq--;
      rq--;
      cout << getsum(0, 0, sz, lq, rq + 1).dp << "\n";
    }
  }
}
