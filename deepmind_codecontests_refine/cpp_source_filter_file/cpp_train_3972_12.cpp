#include <bits/stdc++.h>
using namespace std;
inline int read() {
  int out = 0, fh = 1;
  char jp = getchar();
  while ((jp > '9' || jp < '0') && jp != '-') jp = getchar();
  if (jp == '-') fh = -1, jp = getchar();
  while (jp >= '0' && jp <= '9') out = out * 10 + jp - '0', jp = getchar();
  return out * fh;
}
const int MAXN = 6e5 + 10;
int siz[MAXN], sizx[MAXN], sizy[MAXN];
int fa[MAXN];
int Find(int x) { return x == fa[x] ? x : Find(fa[x]); }
pair<int, int> stk[MAXN];
int tp = 0;
long long ans = 0;
void Merge(int x, int y) {
  x = Find(x), y = Find(y);
  if (x == y) return;
  if (siz[x] < siz[y]) swap(x, y);
  ans -= 1LL * sizx[x] * sizy[x];
  ans -= 1LL * sizx[y] * sizy[y];
  fa[y] = x;
  siz[x] += siz[y], sizx[x] += sizx[y], sizy[x] += sizy[y];
  ans += 1LL * sizx[x] * sizy[x];
  stk[++tp] = make_pair(x, y);
}
void Split(int x, int y) {
  ans -= 1LL * sizx[x] * sizy[x];
  fa[y] = y;
  siz[x] -= siz[y], sizx[x] -= sizx[y], sizy[x] -= sizy[y];
  ans += 1LL * sizx[x] * sizy[x];
  ans += 1LL * sizx[y] * sizy[y];
}
int n;
map<pair<int, int>, int> mp;
vector<pair<int, int> > Tree[MAXN << 1];
set<pair<int, int> > s;
void modifiy(int o, int l, int r, int L, int R, pair<int, int> c) {
  if (l > R || L > r) return;
  if (L <= l && r <= R) {
    Tree[o].push_back(c);
    return;
  }
  int mid = (l + r) >> 1;
  if (L <= mid) modifiy(o << 1, l, mid, L, R, c);
  if (R > mid) modifiy(o << 1 | 1, mid + 1, r, L, R, c);
}
void solve(int o, int l, int r) {
  int curt = tp;
  int sz = Tree[o].size();
  for (int i = 0; i < sz; ++i) Merge(Tree[o][i].first, Tree[o][i].second);
  if (l == r)
    printf("%I64d ", ans);
  else {
    int mid = (l + r) >> 1;
    solve(o << 1, l, mid);
    solve(o << 1 | 1, mid + 1, r);
  }
  while (tp > curt) {
    Split(stk[tp].first, stk[tp].second);
    --tp;
  }
}
int main() {
  n = read();
  for (int i = 1; i <= n; ++i) {
    int x = read(), y = read() + 300001;
    fa[x] = x, siz[x] = 1, sizx[x] = 1;
    fa[y] = y, siz[y] = 1, sizy[y] = 1;
    pair<int, int> k = make_pair(x, y);
    if (mp.find(k) == mp.end()) {
      mp[k] = i;
      s.insert(k);
    } else {
      modifiy(1, 1, n, mp[k], i - 1, k);
      mp[k] = 0;
      s.erase(k);
    }
  }
  set<pair<int, int> >::iterator it;
  for (it = s.begin(); it != s.end(); ++it) {
    pair<int, int> k = *it;
    modifiy(1, 1, n, mp[k], n, k);
  }
  solve(1, 1, n);
  return 0;
}
