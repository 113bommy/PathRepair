#include <bits/stdc++.h>
using namespace std;
int N, Q, last[500005], ncnt, roots[500005];
struct node {
  int l, r;
  pair<int, int> te;
  node() : l(0), r(0), te(make_pair(0, 0)) {}
};
node ns[500005 * 20];
void up(int o) {
  int l = ns[o].l, r = ns[o].r;
  int lt = ns[l].te.first, rt = ns[r].te.first;
  if (lt && rt)
    ns[o].te = min(ns[l].te, ns[r].te);
  else if (lt)
    ns[o].te = ns[l].te;
  else
    ns[o].te = ns[r].te;
}
int build(int l, int r) {
  int cur = ncnt++;
  if (l == r) return cur;
  int mid = (l + r) / 2;
  ns[cur].l = build(l, mid);
  ns[cur].r = build(mid + 1, r);
  return cur;
}
int update(int o, int l, int r, int x, pair<int, int> te) {
  if (x < l || r < x) return o;
  int cur = ncnt++;
  if (l == r) {
    ns[cur].te = te;
    return cur;
  } else {
    int mid = (l + r) / 2;
    ns[cur].l = update(ns[o].l, l, mid, x, te);
    ns[cur].r = update(ns[o].r, mid + 1, r, x, te);
    up(cur);
    return cur;
  }
}
void update_noncopy(int o, int l, int r, int x, pair<int, int> te) {
  if (x < l || r < x) return;
  if (l == r)
    ns[o].te = te;
  else {
    int mid = (l + r) / 2;
    update_noncopy(ns[o].l, l, mid, x, te);
    update_noncopy(ns[o].r, mid + 1, r, x, te);
    up(o);
  }
}
pair<int, int> query(int o, int l, int r, int L, int R) {
  if (R < l || r < L) return make_pair(2147483647, 0);
  if (L <= l && r <= R) return ns[o].te;
  int mid = (l + r) / 2;
  return min(query(ns[o].l, l, mid, L, R), query(ns[o].r, mid + 1, r, L, R));
}
int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  cin >> N;
  roots[0] = build(1, N);
  int tmp;
  for (int i = 1; i <= N; i++) {
    cin >> tmp;
    if (last[tmp] == 0) {
      roots[i] = update(roots[i - 1], 1, N, i, make_pair(-1, tmp));
      last[tmp] = i;
    } else {
      int pos = last[tmp];
      roots[i] = update(roots[i - 1], 1, N, pos, make_pair(pos, tmp));
      update_noncopy(roots[i], 1, N, i, make_pair(pos, tmp));
      last[tmp] = i;
    }
  }
  cin >> Q;
  int L, R;
  for (int i = 1; i <= Q; i++) {
    cin >> L >> R;
    pair<int, int> res = query(roots[R], 1, N, L, R);
    if (res.first == 0 || res.first >= L)
      cout << 0 << '\n';
    else
      cout << res.second << '\n';
  }
  return 0;
}
