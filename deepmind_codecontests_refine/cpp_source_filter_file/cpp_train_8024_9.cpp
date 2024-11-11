#include <bits/stdc++.h>
using namespace std;
void guan() {
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
}
const int maxn = 200020;
const unsigned long long mod = 1e9 + 7;
const double pi = acos(-1.0);
const unsigned long long maxx = 1LL << 61;
const double eps = 1e-7;
int n, m, x;
inline int read() { return (cin >> n >> m >> x) ? 1 : 0; }
int a[maxn];
typedef struct Node {
  int l, r;
  unsigned long long sum;
  vector<pair<int, int> > pre, suf;
} node;
node t[maxn * 2];
inline void up(node& a, node& b, node& c) {
  a.l = b.l, a.r = c.r, a.sum = b.sum + c.sum;
  a.pre = b.pre, a.suf = c.suf;
  for (int i = 0; i < c.pre.size(); ++i) {
    int ta = a.pre[a.pre.size() - 1].first, tb = c.pre[i].first;
    if ((ta | tb) != ta) {
      a.pre.push_back(pair<int, int>(ta | tb, c.pre[i].second + b.r - b.l + 1));
    }
  }
  for (int i = 0; i < b.suf.size(); ++i) {
    int ta = a.suf[a.suf.size() - 1].first, tb = b.suf[i].first;
    if ((ta | tb) != ta) {
      a.suf.push_back(pair<int, int>(ta | tb, b.suf[i].second + c.r - c.l + 1));
    }
  }
  int i, j;
  int r = b.r - b.l + 1, l = c.r - c.l + 1;
  for (i = b.suf.size() - 1, j = 0; i >= 0 && j < c.pre.size(); --i) {
    for (; j < c.pre.size(); ++j) {
      if ((b.suf[i].first | c.pre[j].first) >= x) {
        a.sum += (r - b.suf[i].second + 1) * (l - c.pre[j].second + 1);
        break;
      }
    }
    r = b.suf[i].second - 1;
  }
}
void build(int l, int r, int rt) {
  t[rt].l = l, t[rt].r = r, t[rt].sum = 0;
  int mid = (l + r) / 2;
  if (l == r) {
    t[rt].pre.push_back(pair<int, int>(a[l], 1));
    t[rt].suf.push_back(pair<int, int>(a[l], 1));
    if (a[l] >= x) t[rt].sum += 1;
    return;
  }
  build(l, mid, rt << 1);
  build(mid + 1, r, rt << 1 | 1);
  up(t[rt], t[(rt << 1)], t[(rt << 1 | 1)]);
}
int change(int L, int R, int val, int l, int r, int rt) {
  if (L == l && R == r) {
    t[rt].suf[0].first = val;
    t[rt].pre[0].first = val;
    if (val >= x)
      t[rt].sum = 1;
    else
      t[rt].sum = 0;
    return 1;
  }
  int mid = (l + r) / 2;
  if (R <= mid) {
    change(L, R, val, l, mid, rt << 1);
  } else if (mid < L) {
    change(L, R, val, mid + 1, r, rt << 1 | 1);
  } else {
    change(L, mid, val, l, mid, rt << 1);
    change(mid + 1, R, val, mid + 1, r, rt << 1 | 1);
  }
  up(t[rt], t[(rt << 1)], t[(rt << 1 | 1)]);
  return 1;
}
node query(int L, int R, int l, int r, int rt) {
  if (L == l && R == r) {
    return t[rt];
  }
  int mid = (l + r) / 2;
  node temp;
  if (R <= mid) {
    temp = query(L, R, l, mid, rt << 1);
  } else if (mid < L) {
    temp = query(L, R, mid + 1, r, rt << 1 | 1);
  } else {
    node lnode = query(L, mid, l, mid, rt << 1);
    node rnode = query(mid + 1, R, mid + 1, r, rt << 1 | 1);
    up(temp, lnode, rnode);
  }
  return temp;
}
void solve() {
  int cnum = n;
  for (int i = 1; i <= n; i++) cin >> a[i];
  build(1, cnum, 1);
  for (int i = 1; i <= m; i++) {
    int ty, u, v;
    cin >> ty >> u >> v;
    unsigned long long ans = 0;
    if (ty == 1) {
      change(u, u, v, 1, cnum, 1);
    } else {
      cout << query(u, v, 1, cnum, 1).sum << endl;
    }
  }
}
int main() {
  guan();
  int t = 1;
  while (t--) {
    while (read()) solve();
  }
  return 0;
}
