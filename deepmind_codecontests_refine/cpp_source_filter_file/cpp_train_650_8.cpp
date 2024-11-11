#include <bits/stdc++.h>
namespace IO {
template <typename T>
inline void read(T &x) {
  x = 0;
  int f = 1;
  char ch = getchar();
  while (ch > '9' || ch < '0') {
    if (ch == '-') f = -1;
    ch = getchar();
  }
  while (ch >= '0' && ch <= '9')
    x = (x << 3) + (x << 1) + ch - '0', ch = getchar();
  x *= f;
  return;
}
template <typename T>
inline void write(T x = 0) {
  T wr[51];
  wr[0] = 0;
  if (x < 0) putchar('-'), x = -x;
  if (!x) putchar(48);
  while (x) wr[++wr[0]] = x % 10, x /= 10;
  while (wr[0]) putchar(48 + wr[wr[0]--]);
  return;
}
}  // namespace IO
using IO::read;
using IO::write;
using namespace std;
const int N = 4e5 + 11;
int n, m, top, now, k;
int op[N], a[N], b[N], fa[N], sz[N], sa[N], sb[N], cur[N], ti[N];
vector<pair<int, int> > v[N];
void modify(int x, int y, int a, int b, int k, int l, int r) {
  if (x <= l && r <= y) {
    v[k].push_back(pair<int, int>(a, b));
    return;
  }
  int mid = (l + r) >> 1;
  if (x <= mid) modify(x, y, a, b, k << 1, l, mid);
  if (mid < y) modify(x, y, a, b, k << 1 | 1, mid + 1, r);
}
int find(int x) { return fa[x] == x ? x : find(fa[x]); }
void merge(int x, int y) {
  x = find(x), y = find(y);
  if (x == y) return;
  if (sz[x] < sz[y]) swap(x, y);
  sa[++top] = x, sb[top] = y;
  sz[x] += sz[y];
  fa[y] = x;
}
void del(int tim) {
  int x, y;
  while (top > tim) {
    x = sa[top], y = sb[top];
    fa[y] = y, sz[x] -= sz[y];
    --top;
  }
}
void dfs(int k, int l, int r) {
  int t = top;
  for (auto s : v[k]) merge(s.first, s.second);
  if (l == r) {
    if (op[l] == 2) printf("%d\n", sz[find(a[l])]);
    del(t);
    return;
  }
  int mid = (l + r) >> 1;
  dfs(k << 1, l, mid), dfs(k << 1 | 1, mid + 1, r);
  del(t);
}
int main() {
  read(n);
  read(m);
  read(k);
  for (int i = 1; i <= n; ++i) fa[i] = i, sz[i] = 1;
  for (int i = 1; i <= m; ++i) {
    read(op[i]);
    if (op[i] == 1)
      read(a[i]), read(b[i]), cur[i] = now;
    else if (op[i] == 2)
      read(a[i]), cur[i] = now;
    else
      ti[++now] = i, cur[i] = now;
  }
  for (int i = 1; i <= m; ++i)
    if (op[i] == 1) {
      if (cur[i] + k > now)
        modify(i, m, a[i], b[i], 1, 1, m);
      else
        modify(i, ti[cur[i] + k], a[i], b[i], 1, 1, m);
    }
  dfs(1, 1, m);
  return 0;
}
