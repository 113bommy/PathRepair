#include <bits/stdc++.h>
using namespace std;
const int N = 1e6 + 10;
struct node {
  int num4, num7, dec, inc;
  node() { num4 = num7 = dec = inc = 0; }
} seg[N << 2];
string s;
int lazy[N << 2], n, m;
void merge(node &a, node b, node c) {
  a.num4 = b.num4 + c.num4;
  a.num7 = b.num7 + c.num7;
  a.inc = max(b.num4 + c.inc, b.inc + c.num7);
  a.dec = max(b.num7 + c.dec, b.dec + c.num4);
}
void build(int id = 1, int b = 0, int e = n) {
  if (e - b == 1) {
    seg[id].dec = seg[id].inc = 1;
    if (s[b] == '4') {
      seg[id].num4 = 1;
    } else {
      seg[id].num7 = 1;
    }
    return;
  }
  int mid = (b + e) >> 1, lc = id * 2, rc = lc + 1;
  build(lc, b, mid);
  build(rc, mid, e);
  merge(seg[id], seg[lc], seg[rc]);
}
void shift(int id, int b, int e) {
  if (lazy[id]) {
    lazy[id] = 0;
    lazy[id * 2] ^= 1;
    lazy[id * 2 + 1] ^= 1;
    swap(seg[id].num4, seg[id].num7);
    swap(seg[id].inc, seg[id].dec);
  }
}
void modify(int l, int r, int id = 1, int b = 0, int e = n) {
  if (b >= r || l >= e) return;
  int mid = (b + e) >> 1, lc = id * 2, rc = lc + 1;
  if (l <= b && e <= r) {
    swap(seg[id].num4, seg[id].num7);
    swap(seg[id].inc, seg[id].dec);
    lazy[lc] ^= 1, lazy[rc] ^= 1;
    return;
  }
  shift(lc, b, mid), shift(rc, mid, e);
  modify(l, r, lc, b, mid);
  modify(l, r, rc, mid, e);
  merge(seg[id], seg[lc], seg[rc]);
}
int main() {
  ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
  cin >> n >> m >> s;
  build();
  while (m--) {
    string t;
    cin >> t;
    if (t == "count") {
      cout << seg[1].inc << "\n";
    } else {
      int l, r;
      cin >> l >> r;
      l--;
      modify(l, r);
    }
  }
}
