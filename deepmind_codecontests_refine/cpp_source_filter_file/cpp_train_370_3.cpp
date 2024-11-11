#include <bits/stdc++.h>
#pragma GCC optimize("O2")
#pragma G++ optimize("O2")
using namespace std;
const int N = 111111;
const int M = 666666;
const int MOD = 1e9 + 7;
const int intINF = 1e9;
const long long llINF = 2e18;
const double pi = acos(-1.0);
const int dx[4] = {-1, 1, 0, 0};
const int dy[4] = {0, 0, -1, 1};
const double eps = 1e-10;
int read() {
  int v = 0, f = 1;
  char c = getchar();
  while (c < 48 || 57 < c) {
    if (c == '-') f = -1;
    c = getchar();
  }
  while (48 <= c && c <= 57) v = (v << 3) + v + v + c - 48, c = getchar();
  return v * f;
}
long long readll() {
  long long v = 0, f = 1;
  char c = getchar();
  while (c < 48 || 57 < c) {
    if (c == '-') f = -1;
    c = getchar();
  }
  while (48 <= c && c <= 57) v = (v << 3) + v + v + c - 48, c = getchar();
  return v * f;
}
unsigned long long readull() {
  long long v = 0, f = 1;
  char c = getchar();
  while (c < 48 || 57 < c) {
    if (c == '-') f = -1;
    c = getchar();
  }
  while (48 <= c && c <= 57) v = (v << 3) + v + v + c - 48, c = getchar();
  return v * f;
}
vector<pair<int, int> > V[N];
int a[N], n, m, q;
void predo() {}
void init() {
  n = read(), m = read();
  for (int i = (int)1; i <= (int)m; i++) {
    int x = read(), y = read();
    a[y] = x;
  }
  q = read();
  for (int i = (int)1; i <= (int)q; i++) {
    int x = read(), y = read();
    V[y].push_back(make_pair(x, i));
  }
}
struct node {
  int mx, mx2, tag1, tag2;
} t[N << 2];
void addtag(int p, int s1, int s2) {
  if (t[p].mx >= s1) {
    t[p].mx = s2;
    if (!t[p].tag1) t[p].tag1 = s1;
    t[p].tag2 = s2;
  }
}
void pushdown(int p) {
  if (t[p].tag1) {
    addtag(p << 1, t[p].tag1, t[p].tag2);
    addtag(p << 1 | 1, t[p].tag1, t[p].tag2);
    t[p].tag1 = t[p].tag2 = 0;
  }
}
void fix(int p, int x) {
  if (x > t[p].mx) {
    t[p].mx2 = t[p].mx;
    t[p].mx = x;
  } else if (x < t[p].mx && x > t[p].mx2)
    t[p].mx2 = x;
}
void pushup(int p) {
  t[p].mx = -intINF;
  fix(p, t[p << 1].mx);
  fix(p, t[p << 1].mx2);
  fix(p, t[p << 1 | 1].mx);
  fix(p, t[p << 1 | 1].mx2);
}
void update(int l, int r, int x, int y, int s1, int s2, int p) {
  if (t[p].mx < s1) return;
  if (x <= l && r <= y && t[p].mx2 < s1) {
    addtag(p, s1, s2);
    return;
  }
  pushdown(p);
  int mid = (l + r) >> 1;
  if (x <= mid) update(l, mid, x, y, s1, s2, p << 1);
  if (y > mid) update(mid + 1, r, x, y, s1, s2, p << 1 | 1);
  pushup(p);
}
int query(int l, int r, int x, int p) {
  if (l == r) return t[p].mx;
  pushdown(p);
  int mid = (l + r) >> 1;
  if (x <= mid) return query(l, mid, x, p << 1);
  return query(mid + 1, r, x, p << 1 | 1);
}
void build(int l, int r, int p) {
  if (l == r) {
    t[p].mx = l;
    t[p].mx2 = -intINF;
    return;
  }
  int mid = (l + r) >> 1;
  build(l, mid, p << 1);
  build(mid + 1, r, p << 1 | 1);
  pushup(p);
}
int ans[N];
void solve() {
  build(1, n, 1);
  for (int i = (int)1; i <= (int)n; i++) {
    if (a[i]) {
      update(1, n, 1, i, a[i], i, 1);
    }
    for (auto t : V[i]) {
      ans[t.second] = query(1, n, t.first, 1);
    }
  }
  for (int i = (int)1; i <= (int)q; i++) printf("%d\n", ans[i]);
}
int main() {
  predo();
  int cas = 1;
  while (cas--) {
    init();
    solve();
  }
  return 0;
}
