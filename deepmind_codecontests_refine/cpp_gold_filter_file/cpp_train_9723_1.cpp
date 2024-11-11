#include <bits/stdc++.h>
using namespace std;
int n, m;
struct xunwen {
  int type, x, y;
} a[200005];
vector<int> v[200005 * 4];
int b[200005], L[200005], R[200005], fa[200005], ask[200005];
map<int, int> mp;
int find(int x) {
  if (fa[x] == x) return x;
  return fa[x] = find(fa[x]);
}
void modify(int x, int l, int r, int wh, int mu) {
  if (v[x].size()) {
    for (int i = 0; i < (int)v[x].size(); i++) {
      int p = find(v[x][i]);
      L[mu] = min(L[mu], L[p]);
      R[mu] = max(R[mu], R[p]);
      fa[p] = mu;
    }
    v[x].clear();
    v[x].push_back(mu);
  }
  if (l == r) return;
  int mid = (l + r) / 2;
  if (mid >= wh)
    modify(x * 2, l, mid, wh, mu);
  else
    modify(x * 2 + 1, mid + 1, r, wh, mu);
}
void add(int x, int l, int r, int tx, int ty, int val) {
  if (tx > ty) return;
  if (l >= tx && r <= ty) {
    v[x].push_back(val);
    return;
  }
  int mid = (l + r) / 2;
  if (mid >= tx) add(x * 2, l, mid, tx, ty, val);
  if (mid < ty) add(x * 2 + 1, mid + 1, r, tx, ty, val);
}
bool In(int x, int l, int r) { return (x > l) && (x < r); }
int main() {
  scanf("%d", &n);
  for (int i = 1; i <= n; i++) {
    scanf("%d%d%d", &a[i].type, &a[i].x, &a[i].y);
    if (a[i].type == 1) {
      b[++m] = a[i].x;
      b[++m] = a[i].y;
    }
  }
  sort(b + 1, b + m + 1);
  int cnt = 0;
  for (int i = 1; i <= m; i++) {
    if (i == 1 || b[i] != b[i - 1]) {
      mp[b[i]] = ++cnt;
    }
  }
  m = cnt;
  cnt = 0;
  for (int i = 1; i <= n; i++) {
    if (a[i].type == 1) {
      int x = mp[a[i].x], y = mp[a[i].y];
      L[++cnt] = x;
      R[cnt] = y;
      fa[cnt] = cnt;
      ask[cnt] = i;
      modify(1, 1, m, x, cnt);
      modify(1, 1, m, y, cnt);
      add(1, 1, m, L[cnt] + 1, R[cnt] - 1, cnt);
    } else {
      int x = a[i].x, y = a[i].y;
      int l = mp[a[ask[x]].x], r = mp[a[ask[x]].y];
      int t = find(y);
      if (find(x) == find(y) || In(l, L[t], R[t]) || In(r, L[t], R[t]))
        puts("YES");
      else
        puts("NO");
    }
  }
  return 0;
}
