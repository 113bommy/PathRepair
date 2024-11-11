#include <bits/stdc++.h>
using namespace std;
const int MM = 310000;
const int LE = 100000;
int da[MM], db[MM], V[LE];
int seg[LE * 4], lazy[LE * 4], vv[LE];
void build(int id = 1, int l = 0, int r = LE) {
  if (l == r - 1) {
    seg[id] = vv[l];
    return;
  }
  int mid = (l + r) / 2;
  build(id * 2, l, mid);
  build(id * 2 + 1, mid, r);
  seg[id] = max(seg[id * 2], seg[id * 2 + 1]);
}
void upd(int id = 1, int l = 0, int r = LE, int x = 1) {
  lazy[id] += x;
  seg[id] += x;
}
void shift(int id, int l, int r) {
  int mid = (l + r) / 2;
  upd(id * 2, l, mid, lazy[id]);
  upd(id * 2 + 1, mid, r, lazy[id]);
  lazy[id] = 0;
}
void update(int x, int y, int v, int id = 1, int l = 0, int r = LE) {
  if (x >= r || y <= l) return;
  if (l >= x && r <= y) {
    upd(id, l, r, v);
    return;
  }
  shift(id, l, r);
  int mid = (l + r) / 2;
  update(x, y, v, id * 2, l, mid);
  update(x, y, v, id * 2 + 1, mid, r);
  seg[id] = max(seg[id * 2], seg[id * 2 + 1]);
}
int get(int id = 1, int l = 0, int r = LE) {
  if (l == r - 1) return l;
  if (seg[id] <= 0) return -1;
  shift(id, l, r);
  int mid = (l + r) / 2;
  if (seg[id * 2 + 1] > 0)
    return get(id * 2 + 1, mid, r);
  else
    return get(id * 2, l, mid);
}
int main() {
  std::ios::sync_with_stdio(false);
  std::cin.tie(0);
  int n, m;
  cin >> n >> m;
  for (int i = 0; i < n; i++) cin >> da[i], vv[da[i]]++;
  for (int i = 0; i < m; i++) cin >> db[i], vv[db[i]]--;
  for (int i = LE - 1; i >= 0; i--) vv[i] += vv[i + 1];
  build();
  int q;
  cin >> q;
  while (q-- != 0) {
    int a, b, c;
    cin >> a >> b >> c;
    b--;
    if (a == 1) {
      update(0, da[b] + 1, -1);
      da[b] = c;
      update(0, da[b] + 1, 1);
    } else {
      update(0, db[b] + 1, 1);
      db[b] = c;
      update(0, db[b] + 1, -1);
    }
    cout << get() << endl;
  }
}
