#include <bits/stdc++.h>
using namespace std;
const long long size = 1e5;
int n, q, sz = 1, tree[4 * size];
pair<int, int> dat[100005];
int gcd(int a, int b) {
  if (b == 0) return a;
  return gcd(b, a % b);
}
void init(int s) {
  while (sz < s) {
    sz *= 2;
  }
  for (int i = 0; i < 2 * sz - 1; ++i) {
    tree[i] = 0;
  }
}
void upd(int pos, int a) {
  tree[pos += sz - 1] = a;
  while (pos > 0) {
    pos = (pos - 1) / 2;
    tree[pos] = gcd(tree[pos * 2 + 1], tree[pos * 2 + 2]);
  }
}
int ask(int l, int r, int cl, int cr, int cur) {
  if (cr <= l || cl >= r) return 1e9;
  if (cl >= l && cr <= r)
    return tree[cur];
  else
    return gcd(ask(l, r, cl, (cl + cr) / 2, cur * 2 + 1),
               ask(l, r, (cl + cr) / 2, cr, cur * 2 + 2));
}
int main() {
  ios_base::sync_with_stdio(0);
  ;
  cin >> n;
  init(n);
  for (int i = 0; i < n; ++i) {
    int s;
    cin >> s;
    dat[i] = {s, i};
    upd(i, s);
  }
  sort(dat, dat + n);
  cin >> q;
  for (int i = 0; i < q; ++i) {
    int l, r, gcd, from, to;
    pair<int, int> tmp;
    cin >> l >> r;
    gcd = ask(l - 1, r, 0, sz, 0);
    tmp = {gcd, l - 1};
    from = lower_bound(dat, dat + n, tmp) - dat;
    tmp = {gcd, r};
    to = lower_bound(dat, dat + n, tmp) - dat;
    cout << r - l + 1 - to + from << endl;
  }
}
