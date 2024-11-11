#include <bits/stdc++.h>
using namespace std;
const int maxn = 2e5 + 7;
class num {
 public:
  int val, index;
  bool operator>(const num &b) const {
    return val == b.val ? index < b.index : val > b.val;
  }
} a[maxn];
int b[maxn];
class node {
 public:
  int l, r, val;
} p[maxn << 5];
int pn = 0;
int root[maxn];
int init(const int &l, const int &r) {
  int pos = pn++;
  if (l == r) return pos;
  int mid = (l + r) >> 1;
  p[pos].l = init(l, mid);
  p[pos].r = init(mid + 1, r);
  return pn;
}
int insert(const int &l, const int &r, const int &n, const num &x) {
  int pos = pn++;
  p[pos] = p[n];
  p[pos].val++;
  if (l == r) return pos;
  int mid = (l + r) >> 1;
  if (x.index <= mid) {
    p[pos].l = insert(l, mid, p[pos].l, x);
  } else {
    p[pos].r = insert(mid + 1, r, p[pos].r, x);
  }
  return pos;
}
int ask(const int &l, const int &r, const int &n, const int &pos) {
  if (l == r) return l;
  int mid = (l + r) >> 1;
  if (p[p[n].l].val <= pos)
    return ask(l, mid, p[n].l, pos);
  else
    return ask(mid + 1, r, p[n].r, pos - p[p[n].l].val);
}
int main() {
  int n, m;
  cin >> n;
  for (int i = 1; i <= n; i++) {
    cin >> b[i];
    a[i].val = b[i];
    a[i].index = i;
  }
  sort(a + 1, a + n + 1, greater<num>());
  root[0] = init(1, n);
  for (int i = 1; i <= n; i++) {
    root[i] = insert(1, n, root[i - 1], a[i]);
  }
  cin >> m;
  for (int i = 0; i < m; i++) {
    int k, pos;
    cin >> k >> pos;
    cout << b[ask(1, n, root[k], pos)] << endl;
  }
}
