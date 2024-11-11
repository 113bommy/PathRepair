#include <bits/stdc++.h>
void pr1(int *a, int n) {
  for (int i = 1; i <= n; ++i) printf("%d ", a[i]);
  puts("");
}
void pr0(int *a, int n) {
  for (int i = 0; i <= n; ++i) printf("%d ", a[i]);
  puts("");
}
using namespace std;
template <typename T>
void read(T &x) {
  x = 0;
  int f = 1;
  char c = getchar();
  for (; !isdigit(c); c = getchar())
    if (c == '-') f = -1;
  for (; isdigit(c); c = getchar()) x = x * 10 + c - 48;
  x *= f;
}
vector<pair<int, int> > xdt[1200010];
long long ans[300010];
void md(int x, int l, int r, int ll, int rr, pair<int, int> ins) {
  if (ll <= l && r <= rr)
    xdt[x].push_back(ins);
  else {
    int mid = (l + r) / 2;
    if (ll <= mid) md(x * 2, l, mid, ll, rr, ins);
    if (rr > mid) md(x * 2 + 1, mid + 1, r, ll, rr, ins);
  }
}
int fa[600010], d[600010], szx[600010], szy[600010];
const int m = 300000;
int gtf(int x) {
  while (fa[x] != x) x = fa[x];
  return x;
}
int cx[600010], cy[600010], fg[600010], cn = 0;
long long nans = 0;
void mg(pair<int, int> &a) {
  int x = gtf(a.first), y = gtf(a.second);
  if (x != y) {
    ++cn;
    if (d[x] < d[y]) swap(x, y);
    cx[cn] = x;
    cy[cn] = y;
    fg[cn] = 0;
    if (d[x] == d[y]) fg[cn] = 1, ++d[x];
    fa[y] = x;
    nans -= 1ll * szx[x] * szy[x];
    nans -= 1ll * szx[y] * szy[y];
    szx[x] += szx[y];
    szy[x] += szy[y];
    nans += 1ll * szx[x] * szy[x];
  }
}
void pop() {
  int x = cx[cn], y = cy[cn];
  fa[y] = y;
  d[x] -= fg[cn];
  nans -= 1ll * szx[x] * szy[x];
  szx[x] -= szx[y];
  szy[x] -= szy[y];
  nans += 1ll * szx[x] * szy[x];
  nans += 1ll * szx[y] * szy[y];
  --cn;
}
void wk(int x, int l, int r) {
  int si = xdt[x].size(), scn = cn;
  for (int i = 0; i < si; ++i) mg(xdt[x][i]);
  if (l == r)
    ans[l] = nans;
  else {
    int mid = (l + r) / 2;
    wk(x * 2, l, mid);
    wk(x * 2 + 1, mid + 1, r);
  }
  while (cn != scn) pop();
}
map<pair<int, int>, int> mp;
int q;
int main() {
  read(q);
  for (int i = 1; i <= m; ++i) fa[i] = i, szx[i] = 1, d[i] = 1;
  for (int i = m; i <= m + m; ++i) fa[i] = i, szy[i] = 1, d[i] = 1;
  for (int i = 1; i <= q; ++i) {
    int x, y;
    read(x);
    read(y);
    y += m;
    pair<int, int> pr = make_pair(x, y);
    if (!mp[pr])
      mp[pr] = i;
    else
      md(1, 1, q, mp[pr], i - 1, pr), mp.erase(pr);
  }
  for (map<pair<int, int>, int>::iterator it = mp.begin(); it != mp.end(); ++it)
    md(1, 1, q, it->second, q, it->first);
  wk(1, 1, q);
  for (int i = 1; i <= q; ++i) printf("%lld ", ans[i]);
  return 0;
}
