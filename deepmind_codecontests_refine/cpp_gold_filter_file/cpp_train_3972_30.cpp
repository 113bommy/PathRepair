#include <bits/stdc++.h>
using namespace std;
const int MAXN = 300005;
template <typename T>
inline void read(T &AKNOI) {
  T x = 0, flag = 1;
  char ch = getchar();
  while (!isdigit(ch)) {
    if (ch == '-') flag = -1;
    ch = getchar();
  }
  while (isdigit(ch)) {
    x = x * 10 + ch - '0';
    ch = getchar();
  }
  AKNOI = flag * x;
}
int n, f[MAXN << 1], xcnt[MAXN << 1], ycnt[MAXN << 1], top;
map<pair<int, int>, int> mp;
map<pair<int, int>, int>::iterator iter;
vector<pair<int, int> > seg[MAXN << 2];
pair<int, int> stk[MAXN];
long long ans;
int getf(int v) { return (!f[v]) ? v : getf(f[v]); }
void Insert(int rt, int b, int e, int l, int r, pair<int, int> p) {
  if (l <= b && e <= r) {
    seg[rt].push_back(p);
    return;
  }
  int mid = (b + e) >> 1;
  if (l <= mid) Insert((rt << 1), b, mid, l, r, p);
  if (r > mid) Insert((rt << 1) | 1, mid + 1, e, l, r, p);
}
void GetAns(int rt, int b, int e) {
  long long tmp = ans;
  int sz = top;
  for (int i = 0; i < seg[rt].size(); ++i) {
    int u = getf(seg[rt][i].first), v = getf(seg[rt][i].second);
    if (u == v) continue;
    if (xcnt[u] + ycnt[u] > xcnt[v] + ycnt[v]) swap(u, v);
    ans -= 1LL * xcnt[u] * ycnt[u] + 1LL * xcnt[v] * ycnt[v];
    f[u] = v;
    xcnt[v] += xcnt[u];
    ycnt[v] += ycnt[u];
    ans += 1LL * xcnt[v] * ycnt[v];
    stk[++top] = make_pair(u, v);
  }
  if (b == e) {
    printf("%lld ", ans);
  } else {
    int mid = (b + e) >> 1;
    GetAns((rt << 1), b, mid);
    GetAns((rt << 1) | 1, mid + 1, e);
  }
  ans = tmp;
  for (; top > sz; --top) {
    int u = stk[top].first, v = stk[top].second;
    f[u] = 0;
    xcnt[v] -= xcnt[u];
    ycnt[v] -= ycnt[u];
  }
}
void solve() {
  read(n);
  for (int i = 1; i <= n; ++i) {
    int x, y;
    read(x);
    read(y);
    pair<int, int> p = make_pair(x, MAXN + y);
    iter = mp.find(p);
    if (iter != mp.end()) {
      Insert(1, 1, n, iter->second, i - 1, p);
      mp.erase(iter);
    } else {
      mp[p] = i;
    }
  }
  for (iter = mp.begin(); iter != mp.end(); ++iter) {
    Insert(1, 1, n, iter->second, n, iter->first);
  }
  for (int i = 1; i < MAXN; ++i) {
    xcnt[i] = ycnt[MAXN + i] = 1;
  }
  GetAns(1, 1, n);
}
int main() {
  solve();
  return 0;
}
