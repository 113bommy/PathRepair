#include <bits/stdc++.h>
using namespace std;
unordered_map<int, int> mp;
int cnt[200005];
int a[200005];
int num[200005];
int l, r, t;
int tot = 0;
int lz[200005];
int ans[200005];
int A, B;
int be[200005];
struct Query {
  int l, r, id, t;
  Query() {}
  Query(int _l, int _r, int _id, int _t) { l = _l, r = _r, id = _id, t = _t; }
  bool operator<(const Query &rhs) const {
    return be[l] == be[rhs.l] ? (be[r] == be[rhs.r] ? t < rhs.t : r < rhs.r)
                              : l < rhs.l;
  }
} q[200005];
struct Change {
  int x, y, lz;
  Change() {}
  Change(int _x, int _y, int _lz) { x = _x, y = _y, lz = _lz; }
} p[200005];
int getid(int x) {
  if (!mp.count(x)) mp[x] = ++tot;
  return mp[x];
}
void add(int x, int k) {
  if (num[x]) cnt[num[x]]--;
  num[x] += k;
  if (num[x]) cnt[num[x]]++;
}
void change(int x, int k) {
  if (l <= x && r >= x) {
    add(a[x], -1);
    add(k, 1);
  }
  a[x] = k;
}
int getres() {
  for (int i = 1;; i++) {
    if (cnt[i] == 0) return i;
  }
}
int main() {
  int n, m;
  cin >> n >> m;
  int len = pow(n, 0.6666);
  for (int i = 1; i <= n; i++) {
    int x;
    scanf("%d", &x);
    lz[i] = a[i] = getid(x);
    be[i] = (i - 1) / len + 1;
  }
  for (int i = 1; i <= m; i++) {
    int op, x, y;
    scanf("%d%d%d", &op, &x, &y);
    if (op == 1) {
      q[++A] = Query(x, y, A, B);
    } else {
      y = getid(y);
      p[++B] = Change(x, y, lz[x]);
      lz[x] = y;
    }
  }
  sort(q + 1, q + 1 + A);
  l = 1, r = 0, t = 0;
  for (int i = 1; i <= A; i++) {
    while (t < q[i].t) change(p[t + 1].x, p[t + 1].y), t++;
    while (t > q[i].t) change(p[t].x, p[t].lz), t--;
    while (l < q[i].l) add(a[l], -1), l++;
    while (l > q[i].l) add(a[l - 1], 1), l--;
    while (r < q[i].r) add(a[r + 1], 1), r++;
    while (r > q[i].r) add(a[r], -1), r--;
    ans[q[i].id] = getres();
  }
  for (int i = 1; i <= A; i++) {
    cout << ans[i] << endl;
  }
}
