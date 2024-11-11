#include <bits/stdc++.h>
using namespace std;
const int N = 1e5 + 10;
const long long mod = 1e9 + 7;
const long long inf = 1e18 + 10;
long long a[N], mn[4 * N], mx[4 * N], dif[4 * N], lzt[4 * N], lzy[4 * N], n;
long long cal(long long x) {
  long long y = 1;
  while (y < x) y *= 42LL;
  return y - x;
}
void build(int l = 0, int r = n, int id = 1) {
  if (r - l == 1) {
    mn[id] = mx[id] = a[l];
    dif[id] = cal(a[l]);
    return;
  }
  int mid = (l + r) >> 1;
  build(l, mid, (id << 1));
  build(mid, r, (id << 1 | 1));
  mn[id] = min(mn[(id << 1)], mn[(id << 1 | 1)]);
  mx[id] = max(mx[(id << 1)], mx[(id << 1 | 1)]);
  dif[id] = min(dif[(id << 1)], dif[(id << 1 | 1)]);
}
void shift(int id) {
  long long x = lzt[id], y = lzy[id];
  if (x == 1) {
    mn[(id << 1)] = mn[(id << 1 | 1)] = mx[(id << 1)] = mx[(id << 1 | 1)] = y;
    dif[(id << 1)] = dif[(id << 1 | 1)] = cal(y);
    lzt[(id << 1)] = lzt[(id << 1 | 1)] = 1;
    lzy[(id << 1)] = lzy[(id << 1 | 1)] = y;
  } else {
    mn[(id << 1)] += y;
    mn[(id << 1 | 1)] += y;
    mx[(id << 1)] += y;
    mx[(id << 1 | 1)] += y;
    lzy[(id << 1)] += y;
    lzy[(id << 1 | 1)] += y;
    if (mn[id] == mx[id])
      dif[(id << 1)] = dif[(id << 1 | 1)] = cal(mn[id]);
    else
      dif[(id << 1)] -= y, dif[(id << 1 | 1)] -= y;
  }
  lzt[id] = lzy[id] = 0;
}
void upd(int l, int r, long long x, int s = 0, int e = n, int id = 1) {
  if (e <= l || r <= s) return;
  if (l <= s && e <= r) {
    mn[id] = mx[id] = x;
    dif[id] = cal(x);
    lzt[id] = 1;
    lzy[id] = x;
    return;
  }
  shift(id);
  int mid = (s + e) >> 1;
  upd(l, r, x, s, mid, (id << 1));
  upd(l, r, x, mid, e, (id << 1 | 1));
  mn[id] = min(mn[(id << 1)], mn[(id << 1 | 1)]);
  mx[id] = max(mx[(id << 1)], mx[(id << 1 | 1)]);
  dif[id] = min(dif[(id << 1)], dif[(id << 1 | 1)]);
}
void add(int l, int r, long long x, int s = 0, int e = n, int id = 1) {
  if (e <= l || r <= s) return;
  if (l <= s && e <= r && (mn[id] == mx[id] || x <= dif[id])) {
    mn[id] += x;
    mx[id] += x;
    lzy[id] += x;
    if (mn[id] == mx[id])
      dif[id] = cal(mn[id]);
    else
      dif[id] -= x;
    return;
  }
  shift(id);
  int mid = (s + e) >> 1;
  add(l, r, x, s, mid, (id << 1));
  add(l, r, x, mid, e, (id << 1 | 1));
  mn[id] = min(mn[(id << 1)], mn[(id << 1 | 1)]);
  mx[id] = max(mx[(id << 1)], mx[(id << 1 | 1)]);
  dif[id] = min(dif[(id << 1)], dif[(id << 1 | 1)]);
}
long long get(int p, int l = 0, int r = n, int id = 1) {
  if (r - l == 1) return mn[id];
  shift(id);
  int mid = (l + r) >> 1;
  if (p < mid) return get(p, l, mid, (id << 1));
  return get(p, mid, r, (id << 1 | 1));
}
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  int q;
  cin >> n >> q;
  for (int i = 0; i < n; i++) cin >> a[i];
  build();
  while (q--) {
    int typ;
    cin >> typ;
    if (typ == 1) {
      int p;
      cin >> p;
      p--;
      cout << get(p) << '\n';
    } else if (typ == 2) {
      int l, r, x;
      cin >> l >> r >> x;
      l--;
      upd(l, r, x);
    } else {
      int l, r, x;
      cin >> l >> r >> x;
      l--;
      add(l, r, x);
      while (dif[1] == 0) add(l, r, x);
    }
    assert(0 < dif[1]);
  }
  return 0;
}
