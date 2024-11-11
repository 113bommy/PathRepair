#include <bits/stdc++.h>
#pragma GCC optimize(2)
using namespace std;
const int inf = 0x3f3f3f3f;
const int finf = -0x3f3f3f3f - 1;
const int mod = 1e9 + 7;
const int maxn = 1e5 + 5;
int n, k, m;
int lg2[maxn], a[maxn];
int mn[maxn][20];
void init() {
  lg2[1] = 0;
  for (int i = 2; i < maxn; i++) {
    lg2[i] = lg2[i - 1];
    if (!(i & (i - 1))) lg2[i]++;
  }
  for (int i = 1; i <= n; i++) mn[i][0] = a[i];
  for (int j = 1; j <= lg2[n]; j++) {
    for (int i = 1; i + (1 << j) - 1 <= n; i++) {
      mn[i][j] = min(mn[i][j - 1], mn[i + (1 << (j - 1))][j - 1]);
    }
  }
}
int query(int l, int r) {
  if (l > r) return min(query(l, n), query(1, r));
  int k = lg2[r - l + 1];
  return min(mn[l][k], mn[r - (1 << k) + 1][k]);
}
int ls[maxn * 50], rs[maxn * 50], tr[maxn * 50], cnt, rt;
int lazy[maxn * 50];
int getmn(int l, int r) {
  if (r - l + 1 >= n) return query(1, n);
  l = (l - 1) % n + 1;
  r = (r - 1) % n + 1;
  return query(l, r);
}
int create(int l, int r) {
  ++cnt;
  ls[cnt] = rs[cnt] = 0;
  lazy[cnt] = -1;
  tr[cnt] = getmn(l, r);
  return cnt;
}
void pushdown(int x) {
  if (lazy[x] == -1) return;
  if (!ls[x]) ls[x] = create(1, 1);
  if (!rs[x]) rs[x] = create(1, 1);
  tr[ls[x]] = tr[rs[x]] = lazy[x];
  lazy[ls[x]] = lazy[rs[x]] = lazy[x];
  lazy[x] = -1;
}
void modify(int ql, int qr, int v, int l, int r, int &x) {
  if (!x) x = create(l, r);
  if (ql <= l && r <= qr) {
    tr[x] = lazy[x] = v;
    return;
  }
  pushdown(x);
  int mid = (l + r) / 2;
  if (ql <= mid) modify(ql, qr, v, l, mid, ls[x]);
  if (qr > mid) modify(ql, qr, v, mid + 1, r, rs[x]);
  tr[x] = inf;
  if (ls[x])
    tr[x] = min(tr[x], tr[ls[x]]);
  else
    tr[x] = min(tr[x], getmn(l, mid));
  if (rs[x])
    tr[x] = min(tr[x], tr[rs[x]]);
  else
    tr[x] = min(tr[x], getmn(mid + 1, r));
}
int ask(int ql, int qr, int l, int r, int &x) {
  if (!x) x = create(l, r);
  if (ql <= l && r <= qr) return tr[x];
  pushdown(x);
  int mid = (l + r) / 2;
  int lans = inf, rans = inf;
  if (ql <= mid) lans = ask(ql, qr, l, mid, ls[x]);
  if (qr > mid) rans = ask(ql, qr, mid + 1, r, rs[x]);
  return min(lans, rans);
}
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  cin >> n >> k;
  for (int i = 1; i <= n; i++) cin >> a[i];
  init();
  cin >> m;
  while (m--) {
    int op, l, r, x;
    cin >> op >> l >> r;
    if (op == 1) {
      cin >> x;
      modify(l, r, x, 1, n * k, rt);
    } else {
      cout << ask(l, r, 1, n * k, rt) << endl;
    }
  }
  return 0;
}
