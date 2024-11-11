#include <bits/stdc++.h>
using namespace std;
const int N = 1e5 + 5;
const int mod = 1e9 + 7;
const int inf = 1e8 + 7;
class splay_treap {
 public:
  int b, c, l, mn;
} st[4 * N];
class splay_trick {
 public:
  int a, b, c;
  bool operator<(splay_trick x) const { return a > x.a; }
} seen[N];
int n, i, bas, son, ans;
int x[N], y[N], z[N];
vector<int> v;
void push(int root, int bas, int son) {
  if (st[root].l) {
    st[(root + root)].l = st[(root + root + 1)].l = st[root].l;
    st[(root + root)].c = st[(root + root + 1)].c = st[root].l;
    st[(root + root)].mn = st[(root + root)].c + st[(root + root)].b;
    st[(root + root + 1)].mn =
        st[(root + root + 1)].c + st[(root + root + 1)].b;
    st[root].l = 0;
  }
}
void update2(int root, int bas, int son, int x, int y, int v) {
  if (bas > y or son < x) return;
  if (x <= bas and son <= y) {
    st[root].l = st[root].c = v;
    st[root].mn = st[root].c + st[root].b;
    return;
  }
  push(root, bas, son);
  update2((root + root), bas, ((bas + son) / 2), x, y, v);
  update2((root + root + 1), ((bas + son) / 2) + 1, son, x, y, v);
  st[root].c = max(st[(root + root)].c, st[(root + root + 1)].c);
  st[root].mn = min(st[(root + root)].mn, st[(root + root + 1)].mn);
}
void update(int root, int bas, int son, int x) {
  if (bas > x or son < x) return;
  if (bas == son) {
    st[root].b = x;
    st[root].mn = st[root].b + st[root].c;
    return;
  }
  push(root, bas, son);
  update((root + root), bas, ((bas + son) / 2), x);
  update((root + root + 1), ((bas + son) / 2) + 1, son, x);
  st[root].b = min(st[(root + root)].b, st[(root + root + 1)].b);
  st[root].mn = min(st[(root + root)].mn, st[(root + root + 1)].mn);
}
int query(int root, int bas, int son, int x) {
  if (bas > x or son < x) return 0;
  if (bas == son) return st[root].c;
  push(root, bas, son);
  return query((root + root), bas, ((bas + son) / 2), x) +
         query((root + root + 1), ((bas + son) / 2) + 1, son, x);
}
void init(int root, int bas, int son) {
  st[root].mn = st[root].b = inf;
  st[root].l = st[root].c = 0;
  if (bas == son) return;
  init((root + root), bas, ((bas + son) / 2));
  init((root + root + 1), ((bas + son) / 2) + 1, son);
}
int main() {
  scanf("%d", &n);
  for (i = 1; i <= n; i++) {
    scanf("%d", x + i);
    v.push_back(x[i]);
  }
  for (i = 1; i <= n; i++) {
    scanf("%d", y + i);
    v.push_back(y[i]);
  }
  for (i = 1; i <= n; i++) {
    scanf("%d", z + i);
    v.push_back(z[i]);
  }
  sort(v.begin(), v.end());
  v.resize(unique(v.begin(), v.end()) - v.begin());
  int s = v.size();
  for (i = 0; i < N; i++) seen[i].a = seen[i].b = seen[i].c = inf;
  for (i = 1; i <= n; i++) {
    x[i] = lower_bound(v.begin(), v.end(), x[i]) - v.begin() + 1;
    if (seen[x[i]].a == inf) seen[x[i]].a = i;
  }
  for (i = 1; i <= n; i++) {
    y[i] = lower_bound(v.begin(), v.end(), y[i]) - v.begin() + 1;
    if (seen[y[i]].b == inf) seen[y[i]].b = i;
  }
  for (i = 1; i <= n; i++) {
    z[i] = lower_bound(v.begin(), v.end(), z[i]) - v.begin() + 1;
    if (seen[z[i]].c == inf) seen[z[i]].c = i;
  }
  sort(seen + 1, seen + s + 1);
  init(1, 1, n);
  seen[s + 1].a = 0;
  ans = seen[1].a;
  for (i = 1; i <= s; i++) {
    if (seen[i].b != inf) update(1, 1, n, seen[i].b);
    bas = 1;
    son = min(n, seen[i].b - 1);
    while (bas < son) {
      int ort = bas + son >> 1;
      if (query(1, 1, n, ort) > seen[i].c)
        bas = ort + 1;
      else
        son = ort;
    }
    if (query(1, 1, n, bas) <= seen[i].c)
      update2(1, 1, n, bas, min(n, seen[i].b - 1), seen[i].c);
    ans = min(ans, st[1].mn + seen[i + 1].a);
    ans = min(ans, st[1].c + seen[i + 1].a);
  }
  cout << ans << endl;
}
