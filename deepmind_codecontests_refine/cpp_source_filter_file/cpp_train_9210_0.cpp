#include <bits/stdc++.h>
using namespace std;
const long long INF = 2e17;
long long seg[200000 * 4 + 100];
long long lazy[200000 * 4 + 100];
void shift(int id, int b, int e) {
  lazy[id * 2] += lazy[id];
  lazy[(id * 2) + 1] += lazy[id];
  seg[id * 2] += lazy[id];
  seg[(id * 2) + 1] += lazy[id];
  lazy[id] = 0;
}
void upd(int b, int e, int r, int l, int val, int id = 1) {
  if (l <= b || r >= e) return;
  if (r <= b && l >= e) {
    seg[id] += val;
    lazy[id] += val;
    return;
  }
  shift(id, b, e);
  int m = (e + b) / 2;
  upd(b, m, r, l, val, id * 2);
  upd(m, e, r, l, val, (id * 2) + 1);
  seg[id] = min(seg[id * 2], seg[(id * 2) + 1]);
}
long long get(int b, int e, int r, int l, int id = 1) {
  if (l <= b || r >= e) return INF;
  if (r <= b && l >= e) return seg[id];
  shift(id, b, e);
  int m = (e + b) / 2;
  return min(get(b, m, r, l, id * 2), get(m, e, r, l, (id * 2) + 1));
}
int main() {
  int n;
  cin >> n;
  for (int i = 0; i < n; i++) {
    int t;
    cin >> t;
    upd(0, n, i, i + 1, t);
  }
  int m;
  cin >> m;
  while (m--) {
    int r, l, val;
    scanf("%d %d", &r, &l);
    bool typ = (getchar() == ' ');
    if (!typ) {
      if (r > l)
        cout << min(get(0, n, 0, l + 1), get(0, n, r, n)) << '\n';
      else
        cout << get(0, n, r, l) << '\n';
      continue;
    }
    cin >> val;
    if (r > l) {
      upd(0, n, 0, l + 1, val);
      upd(0, n, r, n, val);
    } else
      upd(0, n, r, l + 1, val);
  }
}
