#include <bits/stdc++.h>
using namespace std;
const int N = 1e6 + 5;
int n, m, k, tot, gs, fa[N], size[N], x[N], y[N], id[N], tim[N];
struct node {
  int x, y;
} zhan[N];
vector<node> g[N * 4];
vector<int> q[N * 4];
inline int read() {
  int ret = 0, f = 0;
  char c = getchar();
  while (!isdigit(c)) {
    if (c == '-') f = 1;
    c = getchar();
  }
  while (isdigit(c)) {
    ret = ret * 10 + c - 48;
    c = getchar();
  }
  if (f) return -ret;
  return ret;
}
void change(int nod, int l, int r, int L, int R, int x, int y) {
  if (l == L && r == R) {
    g[nod].push_back((node){x, y});
    return;
  }
  int mid = (l + r) / 2;
  if (R <= mid)
    change(nod * 2, l, mid, L, R, x, y);
  else if (L > mid)
    change(nod * 2 + 1, mid + 1, r, L, R, x, y);
  else {
    change(nod * 2, l, mid, L, mid, x, y);
    change(nod * 2 + 1, mid + 1, r, mid + 1, R, x, y);
  }
}
void change2(int nod, int l, int r, int x, int y) {
  if (l == r) {
    q[nod].push_back(y);
    return;
  }
  int mid = (l + r) / 2;
  if (x <= mid)
    change2(nod * 2, l, mid, x, y);
  else
    change2(nod * 2 + 1, mid + 1, r, x, y);
}
int find(int x) {
  if (fa[x] == x) return x;
  return find(fa[x]);
}
void merge(int x, int y) {
  x = find(x), y = find(y);
  if (x == y) return;
  if (size[x] > size[y]) swap(x, y);
  fa[x] = y;
  size[y] += size[x];
  zhan[++tot] = (node){x, y};
}
void Del(int x, int y) {
  size[y] -= size[x];
  fa[x] = x;
}
void solve(int nod, int l, int r) {
  int st = tot;
  for (int i = 0; i < g[nod].size(); i++) {
    node u = g[nod][i];
    merge(u.x, u.y);
  }
  int mid = (l + r) / 2;
  if (l < r) solve(nod * 2, l, mid);
  if (l < r) solve(nod * 2 + 1, mid + 1, r);
  for (int i = 0; i < q[nod].size(); i++) {
    int x = q[nod][i];
    printf("%lld\n", size[find(x)]);
  }
  while (tot > st) {
    Del(zhan[tot].x, zhan[tot].y);
    tot--;
  }
}
signed main() {
  n = read();
  m = read();
  k = read();
  for (int i = 1; i <= n; i++) {
    fa[i] = i;
    size[i] = 1;
  }
  int t = 1;
  for (int i = 1; i <= m; i++) {
    int opt = read();
    if (opt == 1) {
      gs++;
      x[gs] = read(), y[gs] = read();
      tim[gs] = t;
      id[gs] = i;
    } else if (opt == 2) {
      int x = read();
      gs++;
      tim[gs] = t;
      id[gs] = i;
      change2(1, 1, m, i, x);
    } else if (opt == 3) {
      t++;
      gs++;
      tim[gs] = t;
      id[gs] = i;
    }
  }
  for (int i = 1, j = 1; i <= gs; i++) {
    while (j + 1 <= gs && tim[j + 1] - tim[i] < k) j++;
    change(1, 1, m, id[i], id[j], x[i], y[i]);
  }
  solve(1, 1, m);
  return 0;
}
