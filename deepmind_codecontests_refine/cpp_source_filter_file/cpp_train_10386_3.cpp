#include <bits/stdc++.h>
using namespace std;
inline int read() {
  int x = 0, c = 0, f = 1;
  for (; c < '0' || c > '9'; c = getchar()) f = c != '-';
  for (; c >= '0' && c <= '9'; c = getchar()) x = x * 10 + c - '0';
  return f ? x : -x;
}
int n;
const int N = 200010;
vector<int> v[N << 1];
int x[N], y[N], xx[N], yy[N];
set<int> s[N << 2];
int mx[N << 2], mn[N << 2];
bool vis[N];
int xi[N << 1], yi[N << 1], cntx, cnty;
void pushup(int x, int l, int r) {
  if (l == r)
    mx[x] = mn[x] = 0;
  else
    mx[x] = max(mx[(x << 1)], mx[(x << 1 | 1)]),
    mn[x] = min(mn[(x << 1)], mn[(x << 1 | 1)]);
  if (s[x].size()) {
    int val = *s[x].rbegin();
    if (!vis[val])
      mx[x] = max(mx[x], val);
    else
      mn[x] = max(mn[x], val);
  }
  if (mn[x] > mx[x]) mx[x] = 0;
}
void update(int x, int l, int r, int L, int R, int val) {
  if (l > R || L > r) return;
  if (L <= l && r <= R) {
    if (val) {
      if (val > 0)
        s[x].insert(val);
      else
        s[x].erase(-val);
    }
    pushup(x, l, r);
    return;
  }
  update((x << 1), l, (l + r >> 1), L, R, val);
  update((x << 1 | 1), (l + r >> 1) + 1, r, L, R, val);
  pushup(x, l, r);
}
int ans = 0;
int main() {
  n = read();
  for (int i = 1; i <= n; i++) {
    x[i] = read(), y[i] = read(), xx[i] = read(), yy[i] = read();
    xi[++cntx] = x[i];
    xi[++cntx] = xx[i];
    yi[++cnty] = y[i];
    yi[++cnty] = yy[i];
  }
  sort(xi + 1, xi + cntx + 1);
  cntx = unique(xi + 1, xi + cntx + 1) - xi - 1;
  sort(yi + 1, yi + cnty + 1);
  cnty = unique(yi + 1, yi + cnty + 1) - yi - 1;
  for (int i = 1; i <= n; i++) {
    x[i] = lower_bound(xi + 1, xi + cntx + 1, x[i]) - xi;
    xx[i] = lower_bound(xi + 1, xi + cntx + 1, xx[i]) - xi;
    y[i] = lower_bound(yi + 1, yi + cnty + 1, y[i]) - yi;
    yy[i] = lower_bound(yi + 1, yi + cnty + 1, yy[i]) - yi;
    v[x[i]].push_back(i);
    v[xx[i]].push_back(-i);
  }
  for (int i = 1; i <= cntx; i++) {
    for (int j = 0; j < v[i].size(); j++) {
      int k = v[i][j];
      update(1, 1, cnty, y[abs(k)], yy[abs(k)], k);
    }
    while (mx[1]) {
      ans++;
      vis[mx[1]] = 1;
      update(1, 1, cnty, y[mx[1]], yy[mx[1]], 0);
    }
  }
  printf("%d\n", ans + 1);
  return 0;
}
