#include <bits/stdc++.h>
using namespace std;
int n, q, fa[300005], que[300005], l, r, mxson[300005], size[300005];
int ans[300005];
vector<int> son[300005];
int dfsx[300005], st[300005], en[300005], cnt = 0;
void dfs(int x) {
  dfsx[++cnt] = x;
  st[x] = cnt;
  for (int i = 0, _end = son[x].size(); i < _end; i++) dfs(son[x][i]);
  en[x] = cnt;
}
int maxi[1200005];
int query(int x, int L, int R, int ll, int rr) {
  if (L == ll && R == rr)
    return maxi[x];
  else {
    int mid = (L + R) >> 1, lc = x << 1, rc = lc | 1;
    if (rr <= mid)
      return query(lc, L, mid, ll, rr);
    else if (ll > mid)
      return query(rc, mid + 1, R, ll, rr);
    else
      return max(query(lc, L, mid, ll, mid),
                 query(rc, mid + 1, R, mid + 1, rr));
  }
}
int Query(int x, int L, int R, int ll, int rr, int val) {
  if (L == R)
    return L;
  else {
    int mid = (L + R) >> 1, lc = x << 1, rc = lc | 1;
    if (rr <= mid)
      return Query(lc, L, mid, ll, rr, val);
    else if (ll > mid)
      return Query(rc, mid + 1, R, ll, rr, val);
    else if (query(rc, mid + 1, R, mid + 1, rr) >= val)
      return Query(rc, mid + 1, R, mid + 1, rr, val);
    else
      return Query(lc, L, mid, ll, mid, val);
  }
}
void modify(int x, int L, int R, int to, int val) {
  if (L == R)
    maxi[x] = val;
  else {
    int mid = (L + R) >> 1, lc = x << 1, rc = lc | 1;
    if (to <= mid)
      modify(lc, L, mid, to, val);
    else
      modify(rc, mid + 1, R, to, val);
    maxi[x] = max(maxi[lc], maxi[rc]);
  }
}
int main() {
  scanf("%d%d", &n, &q);
  for (int i = 2; i <= n; i++) {
    scanf("%d", fa + i);
    son[fa[i]].push_back(i);
  }
  dfs(1);
  l = 0, r = 1, que[1] = 1;
  while (l < r) {
    int x = que[++l];
    mxson[x] = 0, size[x] = 1;
    for (int i = 0, _end = son[x].size(); i < _end; i++) que[++r] = son[x][i];
  }
  for (int i = r; i >= 1; i--) {
    int x = que[i];
    mxson[fa[x]] = max(mxson[fa[x]], size[x]);
    size[fa[x]] += size[x];
    ans[x] = dfsx[Query(1, 1, n, st[x], en[x], (size[x] + 1) / 2)];
    modify(1, 1, n, st[x], size[x]);
  }
  for (int i = 1; i <= q; i++) {
    int x;
    scanf("%d", &x);
    printf("%d\n", ans[x]);
  }
  return 0;
}
