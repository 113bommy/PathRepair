#include <bits/stdc++.h>
#pragma GCC optimize("Ofast")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")
using namespace std;
int n, m, r1, r2, t1[2000005][2], t2[2000005][2], d1[500005], a1[500005],
    d2[500005], a2[500005];
int i1[500005], o1[500005], i2[500005], o2[500005], st, s1[500005], s2[500005],
    L, R;
int f1[500005], f2[500005];
bool b1[2000005], b2[200005];
vector<int> v[500005], e[500005], ve[500005];
int mx(int x, int y) { return x > y ? x : y; }
void dfs(int x, int y) {
  d1[x] = d1[y] + 1;
  i1[x] = ++st;
  s1[st] = x;
  for (int i = 0; i < v[x].size(); ++i) {
    int z = v[x][i];
    if (z != y) {
      a1[z] = a1[x] ^ e[x][i];
      f1[ve[x][i]] = z;
      dfs(z, x);
    }
  }
  o1[x] = st;
}
void bld1(int k, int l, int r) {
  if (l == r) {
    t1[k][a1[s1[l]]] = d1[s1[l]];
    return;
  }
  int m = (l + r) >> 1, lc = k << 1, rc = lc ^ 1;
  bld1(lc, l, m), bld1(rc, m + 1, r);
  t1[k][0] = mx(t1[lc][0], t1[rc][0]);
  t1[k][1] = mx(t1[lc][1], t1[rc][1]);
}
void bld2(int k, int l, int r) {
  if (l == r) {
    t2[k][a2[s2[l]]] = d2[s2[l]];
    return;
  }
  int m = (l + r) >> 1, lc = k << 1, rc = lc ^ 1;
  bld2(lc, l, m), bld2(rc, m + 1, r);
  t2[k][0] = mx(t2[lc][0], t2[rc][0]);
  t2[k][1] = mx(t2[lc][1], t2[rc][1]);
}
void mk1(int k, int l, int r) {
  if (l >= L && r <= R) {
    b1[k] ^= 1;
    swap(t1[k][0], t1[k][1]);
    return;
  }
  int m = (l + r) >> 1, lc = k << 1, rc = lc ^ 1;
  if (b1[k]) {
    b1[lc] ^= 1;
    swap(t1[lc][0], t1[lc][1]);
    b1[rc] ^= 1;
    swap(t1[rc][0], t1[rc][1]);
    b1[k] = 0;
  }
  if (L <= m) mk1(lc, l, m);
  if (R > m) mk1(rc, m + 1, r);
  t1[k][0] = mx(t1[lc][0], t1[rc][0]);
  t1[k][1] = mx(t1[lc][1], t1[rc][1]);
}
void mk2(int k, int l, int r) {
  if (l >= L && r <= R) {
    b2[k] ^= 1;
    swap(t2[k][0], t2[k][1]);
    return;
  }
  int m = (l + r) >> 1, lc = k << 1, rc = lc ^ 1;
  if (b2[k]) {
    b2[lc] ^= 1;
    swap(t2[lc][0], t2[lc][1]);
    b2[rc] ^= 1;
    swap(t2[rc][0], t2[rc][1]);
    b2[k] = 0;
  }
  if (L <= m) mk2(lc, l, m);
  if (R > m) mk2(rc, m + 1, r);
  t2[k][0] = mx(t2[lc][0], t2[rc][0]);
  t2[k][1] = mx(t2[lc][1], t2[rc][1]);
}
int main() {
  scanf("%d", &n);
  for (int i = 1; i < n; ++i) {
    int x, y, z;
    scanf("%d%d%d", &x, &y, &z);
    v[x].push_back(y), v[y].push_back(x);
    e[x].push_back(z), e[y].push_back(z);
    ve[x].push_back(i), ve[y].push_back(i);
  }
  dfs(1, 0);
  r2 = 1;
  for (int i = 1; i <= n; ++i)
    if (d1[i] > d1[r2]) r2 = i;
  a1[r2] = 0;
  st = 0;
  dfs(r2, 0);
  for (int i = 1; i <= n; ++i)
    if (d1[i] > d1[r1]) r1 = i;
  for (int i = 1; i <= n; ++i)
    a2[i] = a1[i], d2[i] = d1[i], i2[i] = i1[i], o2[i] = o1[i], s2[i] = s1[i],
    f2[i] = f1[i];
  a1[r1] = 0;
  st = 0;
  dfs(r1, 0);
  bld1(1, 1, n);
  bld2(1, 1, n);
  scanf("%d", &m);
  while (m--) {
    int x;
    scanf("%d", &x);
    L = i1[f1[x]], R = o1[f1[x]];
    mk1(1, 1, n);
    L = i2[f2[x]], R = o2[f2[x]];
    mk2(1, 1, n);
    printf("%d\n", mx(t1[1][0], t2[1][0]) - 1);
  }
  return 0;
}
