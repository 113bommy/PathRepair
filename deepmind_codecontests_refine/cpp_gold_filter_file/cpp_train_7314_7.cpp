#include <bits/stdc++.h>
using namespace std;
const int N = 2e3 + 10;
const int MOD = 1e9 + 7;
void add(int &x, int y) {
  x += y;
  x -= (x >= MOD) * MOD;
}
struct obj {
  int x, y, c;
};
struct segTree {
  int d[N * 4], cnt[N * 4], sum[N * 4], lazy[N * 4];
  void build(int id, int l, int r, const int x[], const int v[]) {
    lazy[id] = -1;
    if (l == r) {
      d[id] = v[l];
      cnt[id] = x[l + 1] - x[l];
      sum[id] = (long long)d[id] * cnt[id] % MOD;
      return;
    }
    int mid = (l + r) >> 1;
    build(id << 1, l, mid, x, v);
    build(id << 1 | 1, mid + 1, r, x, v);
    d[id] = max(d[id << 1], d[id << 1 | 1]);
    cnt[id] = (cnt[id << 1] + cnt[id << 1 | 1]) % MOD;
    sum[id] = (sum[id << 1] + sum[id << 1 | 1]) % MOD;
  }
  void doLazy(int id, int l, int r) {
    if (lazy[id] == -1) return;
    d[id] = lazy[id];
    sum[id] = (long long)d[id] * cnt[id] % MOD;
    if (l < r) {
      lazy[id << 1] = lazy[id];
      lazy[id << 1 | 1] = lazy[id];
    }
    lazy[id] = -1;
  }
  void update(int id, int l, int r, int u, int v, int val) {
    doLazy(id, l, r);
    if (v < l || r < u) return;
    if (u <= l && r <= v) {
      lazy[id] = val;
      doLazy(id, l, r);
      return;
    }
    int mid = (l + r) >> 1;
    update(id << 1, l, mid, u, v, val);
    update(id << 1 | 1, mid + 1, r, u, v, val);
    d[id] = max(d[id << 1], d[id << 1 | 1]);
    cnt[id] = (cnt[id << 1] + cnt[id << 1 | 1]) % MOD;
    sum[id] = (sum[id << 1] + sum[id << 1 | 1]) % MOD;
  }
  int findPos(int id, int l, int r, int val) {
    doLazy(id, l, r);
    if (d[id] <= val) return N;
    if (l == r) return l;
    int mid = (l + r) >> 1;
    int res = findPos(id << 1, l, mid, val);
    if (res != N) return res;
    return findPos(id << 1 | 1, mid + 1, r, val);
  }
  int getSum() { return sum[1]; }
} ST;
int n, k, l;
obj a[N];
int nX, nY, x[N], y[N];
int pre[N], nxt[N], ini[N], cnt[N];
obj b[N];
set<int> col[N];
int calc(int v) {
  int m = 0;
  while (a[m + 1].y <= v && m < n) m++;
  for (int i = 1; i <= m; i++) b[i] = a[i];
  sort(b + 1, b + 1 + m, [](const obj &a, const obj &b) { return a.x < b.x; });
  for (int i = 1; i <= k; i++) cnt[i] = 0;
  int ptrL = 1, ptrR = 1, curCol = 0;
  for (int r = 1; r < nX; r++) {
    while (ptrR <= m && b[ptrR].x <= r) {
      if (cnt[b[ptrR].c]++ == 0) curCol++;
      ptrR++;
    }
    while (ptrL <= m && cnt[b[ptrL].c] > 1) {
      cnt[b[ptrL].c]--;
      ptrL++;
    }
    if (curCol == k)
      ini[r] = x[b[ptrL].x];
    else
      ini[r] = x[1];
  }
  for (int i = 1; i <= k; i++) {
    col[i].clear();
    col[i].insert(1);
    col[i].insert(nX);
  }
  for (int i = m; i > 0; i--) {
    auto it = col[a[i].c].lower_bound(a[i].x);
    nxt[i] = *it;
    if (nxt[i] != a[i].x) --it;
    pre[i] = *it;
    col[a[i].c].insert(a[i].x);
  }
  ST.build(1, 1, nX - 1, x, ini);
  int res = 0, curY = 0;
  for (int i = 1; i <= m; i++) {
    add(res, (long long)ST.getSum() * (y[a[i].y] - curY) % MOD);
    curY = y[a[i].y];
    int val = x[pre[i]];
    int pos = max(a[i].x, ST.findPos(1, 1, nX - 1, val));
    if (pos < nxt[i]) ST.update(1, 1, nX - 1, pos, nxt[i] - 1, val);
  }
  res = (long long)res * (y[v + 1] - y[v]) % MOD;
  return res;
}
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  cin >> n >> k >> l;
  for (int i = 1; i <= n; i++) {
    cin >> a[i].x >> a[i].y >> a[i].c;
    a[i].x++;
    a[i].y++;
    x[++nX] = a[i].x;
    y[++nY] = a[i].y;
  }
  x[++nX] = 0;
  x[++nX] = l + 1;
  y[++nY] = 0;
  y[++nY] = l + 1;
  sort(x + 1, x + 1 + nX);
  sort(y + 1, y + 1 + nY);
  nX = unique(x + 1, x + 1 + nX) - (x + 1);
  nY = unique(y + 1, y + 1 + nY) - (y + 1);
  for (int i = 1; i <= n; i++) {
    a[i].x = lower_bound(x + 1, x + 1 + nX, a[i].x) - x;
    a[i].y = lower_bound(y + 1, y + 1 + nY, a[i].y) - y;
  }
  sort(a + 1, a + 1 + n, [](const obj &a, const obj &b) { return a.y < b.y; });
  int ans = 0;
  for (int y = 2; y < nY; y++) add(ans, calc(y));
  cout << ans;
  return 0;
}
