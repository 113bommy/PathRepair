#include <bits/stdc++.h>
using namespace std;
const int maxn = 1e5 + 5;
const int maxm = 1e5 + 5;
const int INF = 0x3f3f3f3f;
const long long LINF = 3e17 + 1;
const int mod = 1e9 + 7;
int n, r, m, h;
inline int read() {
  register int x = 0, f = 1;
  char ch = getchar();
  while (!isdigit(ch)) {
    if (ch == '-') f = -1;
    ch = getchar();
  }
  while (isdigit(ch)) {
    x = (x << 3) + (x << 1) + ch - '0';
    ch = getchar();
  }
  return (f == 1) ? x : -x;
}
struct node {
  int x, y;
  bool operator<(const node& rhs) const { return x < rhs.x; }
} a[maxn << 1];
struct Qr {
  int x1, y1, x2, y2;
  int id;
  bool operator<(const Qr& rhs) const { return x2 < rhs.x2; }
} qry[maxn << 1];
int tr[maxn << 4];
bool ans[maxn];
void update(int o, int l, int r, int pos, int val) {
  if (l == r) {
    tr[o] = val;
    return;
  }
  int mid = (l + r) >> 1;
  if (pos <= mid)
    update((o << 1), l, mid, pos, val);
  else
    update((o << 1 | 1), mid + 1, r, pos, val);
  tr[o] = min(tr[(o << 1)], tr[(o << 1 | 1)]);
}
int query(int o, int l, int r, int ql, int qr) {
  if (ql <= l && r <= qr) {
    return tr[o];
  }
  int mid = (l + r) >> 1;
  int res = INF;
  if (ql <= mid) res = min(res, query((o << 1), l, mid, ql, qr));
  if (mid < qr) res = min(res, query((o << 1 | 1), mid + 1, r, ql, qr));
  return res;
}
int main() {
  ;
  ios::sync_with_stdio(0);
  cin.tie(0);
  ;
  int k, q;
  cin >> n >> m >> k >> q;
  for (int i = 1; i <= k; i++) cin >> a[i].x >> a[i].y;
  for (int i = 1; i <= q; i++) {
    cin >> qry[i].x1 >> qry[i].y1 >> qry[i].x2 >> qry[i].y2;
    qry[i].id = i;
  }
  sort(a + 1, a + k + 1, [](node aa, node bb) { return aa.x < bb.x; });
  sort(qry + 1, qry + 1 + q, [](Qr aa, Qr bb) { return aa.x2 < bb.x2; });
  int cnt = 1;
  int tt;
  for (int i = 1; i <= q; i++) {
    while (a[cnt].x <= qry[i].x2 && cnt <= k) {
      update(1, 1, m, a[cnt].y, a[cnt].x);
      cnt++;
    }
    tt = query(1, 1, m, qry[i].y1, qry[i].y2);
    if (tt >= qry[i].x1) ans[qry[i].id] = 1;
  }
  sort(a + 1, a + k + 1, [](node aa, node bb) { return aa.y < bb.y; });
  sort(qry + 1, qry + 1 + q, [](Qr aa, Qr bb) { return aa.y2 < bb.y2; });
  memset(tr, 0, sizeof(tr));
  cnt = 1;
  for (int i = 1; i <= q; i++) {
    while (a[cnt].y <= qry[i].y2 && cnt <= k) {
      update(1, 1, n, a[cnt].x, a[cnt].y);
      cnt++;
    }
    tt = query(1, 1, n, qry[i].x1, qry[i].x2);
    if (tt >= qry[i].y1) ans[qry[i].id] = 1;
  }
  for (int i = 1; i <= q; i++) {
    if (ans[i])
      cout << "YES" << endl;
    else
      cout << "NO" << endl;
  }
  return 0;
}
