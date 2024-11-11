#include <bits/stdc++.h>
using namespace std;
struct node {
  int o;
  int c;
  int t;
};
string s;
node segtree[5 * 1000000 + 20];
void build(int l, int r, int idx) {
  if (l == r) {
    if (s[l] == '(') {
      segtree[idx].o = 1;
    } else
      segtree[idx].c = 1;
    return;
  }
  build(l, (l + r) / 2, 2 * idx);
  build((l + r) / 2 + 1, r, 2 * idx + 1);
  int temp = min(segtree[2 * idx].o, segtree[2 * idx + 1].c);
  segtree[idx].t = segtree[2 * idx].t + segtree[2 * idx + 1].t + temp;
  segtree[idx].o = segtree[2 * idx].o + segtree[2 * idx + 1].o - temp;
  segtree[idx].c = segtree[2 * idx].c + segtree[2 * idx + 1].c - temp;
}
pair<int, pair<int, int>> query(int l, int r, int x, int y, int idx) {
  if (l > y || r < x) {
    pair<int, pair<int, int>> p = (make_pair(0, make_pair(0, 0)));
    return p;
  }
  if (x <= l && r <= y) {
    pair<int, pair<int, int>> p;
    p = (make_pair(segtree[idx].t, make_pair(segtree[idx].o, segtree[idx].c)));
    return p;
  }
  pair<int, pair<int, int>> p, q, ret;
  int mid = (l + r) / 2;
  p = query(l, mid, x, y, 2 * idx), q = query(mid + 1, r, x, y, 2 * idx + 1);
  int temp = min(p.second.first, q.second.second);
  int s, d, f;
  s = p.first + q.first + temp;
  d = p.second.first + q.second.first - temp;
  f = q.second.second + p.second.second - temp;
  ret = make_pair(s, make_pair(d, f));
  return ret;
}
int main() {
  int m;
  cin >> s >> m;
  int n = (int)s.length();
  build(0, n - 1, 1);
  for (int i = 0; i < m; i++) {
    int l, r;
    cin >> l >> r;
    l--, r--;
    pair<int, pair<int, int>> p = query(0, n - 1, l, r, 1);
    cout << p.first << endl;
  }
  return 0;
}
