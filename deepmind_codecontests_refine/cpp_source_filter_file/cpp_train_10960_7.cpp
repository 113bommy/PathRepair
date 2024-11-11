#include <bits/stdc++.h>
using namespace std;
long long res;
int n, m, p, col[500100], dsu[500100], sz[500100];
bool tag[500100];
struct dat {
  int u, v, su, sv;
  bool tu, tv;
  dat(int a, int b, int c, int d, bool e, bool f) {
    u = a, v = b, su = c, sv = d, tu = e, tv = f;
  }
};
struct node {
  int x, y;
  node(int X = 0, int Y = 0) { x = X, y = Y; }
  long long id() const {
    if (col[x] == col[y]) return col[x];
    return 1ll * min(col[x], col[y]) * p + max(col[x], col[y]);
  }
  friend bool operator<(const node &u, const node &v) {
    return u.id() < v.id();
  }
} e[500100];
stack<dat> s;
int findanc(int x) { return dsu[x] == x ? x : findanc(dsu[x]); }
bool findcol(int x) {
  return dsu[x] == x ? tag[x] : (tag[x] ^ findcol(dsu[x]));
}
bool merge(int x, int y) {
  bool u = findcol(x), v = findcol(y);
  x = findanc(x), y = findanc(y);
  if (x == y) return u != v;
  s.push(dat(x, y, sz[x], sz[y], tag[x], tag[y]));
  if (sz[x] < sz[y]) swap(x, y);
  tag[y] ^= tag[x], sz[x] += sz[y], dsu[y] = x;
  if (u == v) tag[y] ^= 1;
  return true;
}
bool self[500100];
void backdata() {
  dat x = s.top();
  s.pop();
  dsu[x.u] = x.u, dsu[x.v] = x.v;
  tag[x.u] = x.tu, tag[x.v] = x.tv;
  sz[x.u] = x.su, sz[x.v] = x.sv;
}
int main() {
  scanf("%d%d%d", &n, &m, &p);
  for (int i = 1; i <= n; i++) dsu[i] = i, sz[i] = 1, scanf("%d", &col[i]);
  for (int i = 1, x, y; i <= m; i++) scanf("%d%d", &x, &y), e[i] = node(x, y);
  for (int i = 1; i <= p; i++) self[i] = true;
  sort(e + 1, e + m + 1);
  for (int i = 1; i <= m;) {
    if (col[e[i].x] == col[e[i].y])
      self[col[e[i].x]] &= merge(e[i].x, e[i].y), i++;
    else {
      int j = i;
      while (j <= m && e[j].id() == e[i].id()) j++;
      if (self[col[e[i].x]] && self[col[e[i].y]]) {
        int sz = s.size();
        for (int k = i; k < j; k++)
          if (!merge(e[k].x, e[k].y)) {
            res--;
            break;
          }
        while (s.size() > sz) backdata();
      }
      i = j;
    }
  }
  int tot = 0;
  for (int i = 1; i <= n; i++)
    if (self[i]) tot++;
  res += 1ll * tot * (tot - 1) / 2;
  printf("%lld\n", res);
  return 0;
}
