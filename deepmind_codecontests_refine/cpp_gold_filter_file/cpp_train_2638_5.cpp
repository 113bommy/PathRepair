#include <bits/stdc++.h>
using namespace std;
const int maxn = 2e5 + 10, mod = 1e9 + 7, INF = 0x3f3f3f3f;
int mn[maxn << 2];
void build(int l, int r, int rt) {
  mn[rt] = 0;
  if (l == r) return;
  int m = l + r >> 1;
  build(l, m, rt << 1);
  build(m + 1, r, rt << 1 | 1);
}
int qry(int l, int r, int rt) {
  if (l == r) {
    if (mn[rt]) return -1;
    mn[rt] = 1;
    return l;
  }
  int m = l + r >> 1, pos = -1;
  if (mn[rt << 1] == 0)
    pos = qry(l, m, rt << 1);
  else if (mn[rt << 1 | 1] == 0)
    pos = qry(m + 1, r, rt << 1 | 1);
  mn[rt] = min(mn[rt << 1], mn[rt << 1 | 1]);
  return pos;
}
int add(int L, int R, int l, int r, int rt) {
  if (L <= l && r <= R) return qry(l, r, rt);
  int m = l + r >> 1, pos = -1;
  if (L <= m) pos = add(L, R, l, m, rt << 1);
  if (pos == -1 && R > m) pos = add(L, R, m + 1, r, rt << 1 | 1);
  mn[rt] = min(mn[rt << 1], mn[rt << 1 | 1]);
  return pos;
}
void del(int p, int l, int r, int rt) {
  if (l == r) {
    mn[rt] = 0;
    return;
  }
  int m = l + r >> 1;
  if (p <= m)
    del(p, l, m, rt << 1);
  else
    del(p, m + 1, r, rt << 1 | 1);
  mn[rt] = min(mn[rt << 1], mn[rt << 1 | 1]);
}
struct node {
  int ty, id;
} a[maxn];
map<int, int> pos, hs;
vector<int> v[maxn];
int num, vis[maxn], rk[maxn], sz[maxn];
void init(int n, int m) {
  num = 0;
  for (int i = 0; i < n; ++i) {
    if (vis[i]) continue;
    ++num;
    int p = 0;
    for (int j = i; !vis[j]; j = (j + m) % n) vis[j] = num, rk[j] = ++p;
    sz[num] = p;
  }
}
int main() {
  int h, m, n;
  cin >> h >> m >> n;
  init(h, m);
  char ty[2];
  for (int i = 1; i <= n; ++i) {
    scanf("%s%d", ty, &a[i].id);
    if (ty[0] == '+') {
      int t;
      scanf("%d", &t);
      hs[a[i].id] = t;
      a[i].ty = 1;
      v[vis[t]].push_back(i);
    } else {
      int t = hs[a[i].id];
      a[i].ty = 0;
      v[vis[t]].push_back(i);
    }
  }
  long long ans = 0;
  for (int i = 1; i <= num; ++i) {
    if (!int(v[i].size())) continue;
    build(1, sz[i], 1);
    for (auto j : v[i]) {
      int ty = a[j].ty, id = a[j].id;
      if (ty) {
        int t = hs[id];
        int p = rk[t];
        int res = add(p, sz[i], 1, sz[i], 1);
        if (res == -1) {
          ans += sz[i] - p + 1;
          res = add(1, p - 1, 1, sz[i], 1);
          ans += res - 1;
        } else
          ans += res - p;
        pos[id] = res;
      } else
        del(pos[id], 1, sz[i], 1);
    }
  }
  cout << ans;
  return 0;
}
