#include <bits/stdc++.h>
using namespace std;
template <typename T>
void chkmax(T &first, T second) {
  first < second ? first = second : T();
}
template <typename T>
void chkmin(T &first, T second) {
  first > second ? first = second : T();
}
template <typename T>
void readint(T &first) {
  first = 0;
  int f = 1;
  char c;
  for (c = getchar(); !isdigit(c); c = getchar())
    if (c == '-') f = -1;
  for (; isdigit(c); c = getchar()) first = first * 10 + c - '0';
  first *= f;
}
const int MOD = 1000000007;
inline int dmy(int first) { return first >= MOD ? first - MOD : first; }
inline void inc(int &first, int second) { first = dmy(first + second); }
int qmi(int first, int second) {
  int ans = 1;
  for (; second; second >>= 1, first = 1ll * first * first % MOD)
    if (second & 1) ans = 1ll * ans * first % MOD;
  return ans;
}
const int MAXN = 2005;
int n, k, L;
pair<pair<int, int>, int> a[MAXN];
int mx, px[MAXN], my, py[MAXN];
multiset<int> cp[MAXN];
int sum[MAXN << 2], fir[MAXN << 2], sec[MAXN << 2], d[MAXN << 2],
    tag[MAXN << 2];
void update(int id) {
  if (fir[id << 1] == fir[id << 1 | 1]) {
    fir[id] = fir[id << 1];
    sec[id] = min(sec[id << 1], sec[id << 1 | 1]);
    d[id] = d[id << 1] + d[id << 1 | 1];
  } else if (fir[id << 1] < fir[id << 1 | 1]) {
    fir[id] = fir[id << 1];
    sec[id] = min(sec[id << 1], fir[id << 1 | 1]);
    d[id] = d[id << 1];
  } else {
    fir[id] = fir[id << 1 | 1];
    sec[id] = min(fir[id << 1], sec[id << 1 | 1]);
    d[id] = d[id << 1 | 1];
  }
  sum[id] = sum[id << 1] + sum[id << 1 | 1];
}
void pushdown(int id) {
  if (!tag[id]) return;
  if (tag[id] > fir[id << 1 | 1])
    inc(sum[id << 1 | 1], 1ll * (py[fir[id << 1 | 1]] - py[tag[id]] + MOD) *
                              d[id << 1 | 1] % MOD),
        fir[id << 1 | 1] = tag[id << 1 | 1] = tag[id];
  if (tag[id] > fir[id << 1])
    inc(sum[id << 1],
        1ll * (py[fir[id << 1]] - py[tag[id]] + MOD) * d[id << 1] % MOD),
        fir[id << 1] = tag[id << 1] = tag[id];
  tag[id] = 0;
}
void modify(int id, int l, int r, int ql, int qr, int c) {
  if (ql > qr) return;
  if (c <= fir[id]) return;
  if (l == ql && r == qr && c < sec[id]) {
    inc(sum[id], 1ll * (py[fir[id]] - py[c] + MOD) * d[id] % MOD);
    fir[id] = tag[id] = c;
    return;
  }
  pushdown(id);
  int mid = (l + r) >> 1;
  if (qr <= mid)
    modify(id << 1, l, mid, ql, qr, c);
  else if (ql > mid)
    modify(id << 1 | 1, mid + 1, r, ql, qr, c);
  else
    modify(id << 1, l, mid, ql, mid, c),
        modify(id << 1 | 1, mid + 1, r, mid + 1, qr, c);
  update(id);
}
void build(int id, int l, int r) {
  tag[id] = 0;
  if (l == r) {
    d[id] = py[l] - py[l - 1];
    fir[id] = l;
    sec[id] = 1 << 30;
    sum[id] = 1ll * (py[l] - py[l - 1]) * (L - py[l] + 1) % MOD;
    return;
  }
  int mid = (l + r) >> 1;
  build(id << 1, l, mid);
  build(id << 1 | 1, mid + 1, r);
  update(id);
}
int main() {
  readint(n), readint(k), readint(L);
  for (int i = 1; i <= n; ++i)
    readint(a[i].first.first), readint(a[i].first.second), readint(a[i].second),
        px[i] = ++a[i].first.first, py[i] = ++a[i].first.second;
  sort(px + 1, px + n + 1), mx = unique(px + 1, px + n + 1) - px - 1;
  px[mx + 1] = L + 1;
  sort(py + 1, py + n + 1), my = unique(py + 1, py + n + 1) - py - 1;
  py[my + 1] = L + 1;
  for (int i = 1; i <= n; ++i)
    a[i].first.first = lower_bound(px + 1, px + mx + 1, a[i].first.first) - px,
    a[i].first.second =
        lower_bound(py + 1, py + my + 1, a[i].first.second) - py;
  sort(a + 1, a + n + 1);
  a[n + 1].first = make_pair(mx + 1, my + 1);
  int ans = 0;
  for (int i = 1; i <= mx; ++i) {
    build(1, 1, my + 1);
    for (int j = 1; j <= k; ++j) cp[j].clear();
    for (int j = 1; j <= n && a[j].first.first <= i; ++j)
      cp[a[j].second].insert(a[j].first.second);
    for (int j = 1; j <= k; ++j) {
      int las = 0;
      cp[j].insert(my + 1);
      for (auto t : cp[j]) modify(1, 1, my + 1, las + 1, t, t), las = t;
      cp[j].insert(0);
    }
    inc(ans,
        1ll * px[a[1].first.first] * sum[1] % MOD * (px[i + 1] - px[i]) % MOD);
    for (int j = 1; j <= n && a[j].first.first < i; ++j) {
      int c = a[j].second, second = a[j].first.second;
      multiset<int>::iterator it = cp[c].find(second);
      int u = *(--it);
      ++it;
      int v = *(++it);
      --it;
      cp[c].erase(it);
      modify(1, 1, my + 1, u + 1, second, v);
      inc(ans, 1ll * (px[a[j + 1].first.first] - px[a[j].first.first]) *
                   sum[1] % MOD * (px[i + 1] - px[i]) % MOD);
    }
  }
  printf("%d\n", ans);
  return 0;
}
