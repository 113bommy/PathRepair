#include <bits/stdc++.h>
using namespace std;
inline int read() {
  int ans = 0, f = 1;
  char c = getchar();
  for (; !isdigit(c); c = getchar())
    if (c == '-') f = -1;
  for (; isdigit(c); c = getchar()) ans = (ans << 3) + (ans << 1) + (c ^ 48);
  return ans * f;
}
inline int cmin(int &a, int b) { return a = min(a, b); }
inline int cmax(int &a, int b) { return a = max(a, b); }
struct data {
  int id, l, r;
  bool operator<(const data &rhs) const {
    return l == rhs.l ? r < rhs.r : l < rhs.l;
  }
} a[200005];
int n;
int ans[200005];
int pos[200005];
struct node {
  int id, l;
  bool operator<(const node &rhs) const { return l < rhs.l; }
} t[800005];
inline void push_up(int p) { t[p] = min(t[(p << 1)], t[(p << 1 | 1)]); }
void build(int p, int l, int r) {
  if (l == r) {
    t[p] = node{pos[l], a[pos[l]].l};
    return;
  }
  int mid = l + r >> 1;
  build((p << 1), l, mid);
  build((p << 1 | 1), mid + 1, r);
  push_up(p);
}
int query(int p, int l, int r, int ql, int qr) {
  if (ql <= l && r <= qr) return t[p].id;
  int mid = l + r >> 1;
  int ret = 0, val = 1e9;
  if (ql <= mid) {
    int tmp = query((p << 1), l, mid, ql, qr);
    if (a[tmp].l < val) val = a[tmp].l, ret = tmp;
  }
  if (qr > mid) {
    int tmp = query((p << 1 | 1), mid + 1, r, ql, qr);
    if (a[tmp].l < val) val = a[tmp].l, ret = tmp;
  }
  return ret;
}
int flag = 0, x, y;
multiset<node> s;
int main() {
  n = read();
  for (int i = 1; i <= n; i++) a[i].id = i, a[i].l = read(), a[i].r = read();
  sort(a + 1, a + n + 1);
  for (int i = 1, j = 1; i <= n; i++) {
    while (j <= n && a[j].l <= i) {
      s.insert({j, a[j].r});
      j++;
    }
    auto x = s.lower_bound({0, i});
    ans[a[x->id].id] = i;
    pos[i] = x->id;
    s.erase(x);
  }
  build(1, 1, n);
  for (int i = 1; i < n; i++) {
    if (a[pos[i]].r == i) continue;
    int j = query(1, 1, n, i + 1, a[pos[i]].r);
    if (a[j].l <= i && a[j].l) {
      flag = 1, x = i, y = j;
      break;
    }
  }
  if (!flag) {
    cout << "YES" << endl;
    for (int i = 1; i <= n; i++) cout << ans[i] << ' ';
    cout << endl;
  } else {
    cout << "NO" << endl;
    for (int i = 1; i <= n; i++) cout << ans[i] << ' ';
    cout << endl;
    swap(ans[a[pos[x]].id], ans[a[y].id]);
    for (int i = 1; i <= n; i++) cout << ans[i] << ' ';
    cout << endl;
  }
  return 0;
}
