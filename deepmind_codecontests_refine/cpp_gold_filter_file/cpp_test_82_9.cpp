#include <bits/stdc++.h>
template <class p, class q>
void umin(p& a, const q& b) {
  if (a > b) a = b;
}
template <class p, class q>
void umax(p& a, const q& b) {
  if (a < b) a = b;
}
using ll = long long;
using VI = std::vector<int>;
using VLL = std::vector<ll>;
using namespace std;
using namespace std::chrono;
int n, q, k;
int const N = 3e5 + 3;
int const INF = 1e9 + 6;
int a[N];
int cnt = 0;
int prz[N];
int inv[N];
int stop[N];
int sparse[19][N];
int mink[N];
int st_min[N];
std::pair<int, int> st[(1 << 20)];
ll st_sum[(1 << 20)];
int lazy[(1 << 20)];
vector<pair<std::pair<int, int>, int>> queries;
ll ans[N];
std::pair<ll, ll> two_biggest(const std::pair<ll, ll>& x1,
                              const std::pair<ll, ll>& x2) {
  if (x1.first > x2.first)
    return make_pair(x1.first, max(x1.second, x2.first));
  else if (x1.first == x2.first)
    return make_pair(x1.first, max(x1.second, x2.second));
  else
    return make_pair(x2.first, max(x1.first, x2.second));
}
void build(int v = 1, int l = 1, int r = n) {
  if (l == r) {
    st_sum[v] = 0;
    st[v] = make_pair(0, -INF);
    return;
  }
  int m = (l + r) / 2;
  build(v * 2, l, m);
  build(v * 2 + 1, m + 1, r);
  st_sum[v] = st_sum[v * 2] + st_sum[v * 2 + 1];
  st[v] = two_biggest(st[v * 2], st[v * 2 + 1]);
}
void push(int v, int tl, int tr) {
  if (lazy[v]) {
    int mid = (tl + tr) / 2;
    st_sum[v * 2] += 1LL * (mid - tl + 1) * (lazy[v] - st[v * 2].first);
    st_sum[v * 2 + 1] += 1LL * (tr - mid) * (lazy[v] - st[v * 2 + 1].first);
    st[v * 2] = make_pair(lazy[v], -INF);
    st[v * 2 + 1] = make_pair(lazy[v], -INF);
    lazy[v * 2] = lazy[v * 2 + 1] = lazy[v];
    lazy[v] = 0;
  }
}
void sset(int pos, int val, int v = 1, int tl = 1, int tr = n) {
  if (tl == tr) {
    st[v] = make_pair(val, -INF);
    st_sum[v] = val;
    return;
  }
  push(v, tl, tr);
  int mid = (tl + tr) / 2;
  if (pos <= mid)
    sset(pos, val, v * 2, tl, mid);
  else
    sset(pos, val, v * 2 + 1, mid + 1, tr);
  st_sum[v] = st_sum[v * 2] + st_sum[v * 2 + 1];
  st[v] = two_biggest(st[v * 2], st[v * 2 + 1]);
}
void update(int l, int r, int x, int v = 1, int tl = 1, int tr = n) {
  if (l > tr || r < tl || st[v].first <= x)
    return;
  else if (l <= tl && tr <= r && st[v].second == -INF) {
    st_sum[v] += 1LL * (tr - tl + 1) * (x - st[v].first);
    st[v] = make_pair(x, -INF);
    lazy[v] = x;
  } else {
    push(v, tl, tr);
    int mid = (tl + tr) / 2;
    update(l, r, x, v * 2, tl, mid);
    update(l, r, x, v * 2 + 1, mid + 1, tr);
    st_sum[v] = st_sum[v * 2] + st_sum[v * 2 + 1];
    st[v] = two_biggest(st[v * 2], st[v * 2 + 1]);
  }
}
ll query(int l, int r, int v = 1, int tl = 1, int tr = n) {
  if (l > r)
    return 0;
  else if (l == tl && r == tr)
    return st_sum[v];
  else {
    push(v, tl, tr);
    int mid = (tl + tr) / 2;
    ll qw1 = query(l, min(mid, r), v * 2, tl, mid);
    ll qw2 = query(max(mid + 1, l), r, v * 2 + 1, mid + 1, tr);
    return qw1 + qw2;
  }
}
void sparse_calc() {
  for (int i = (1); i <= (n); i++) sparse[0][i] = a[i];
  for (int i = (1); i <= (19); i++) {
    for (int j = (1); j <= (n - (1 << i) + 1); j++)
      sparse[i][j] = min(sparse[i - 1][j], sparse[i - 1][j + (1 << (i - 1))]);
  }
}
int min_interval(int l, int r) {
  int w = (int)(log2)(r - l + 1);
  return min(sparse[w][l], sparse[w][r + 1 - (1 << w)]);
}
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cin >> n >> q >> k;
  for (int i = (1); i <= (n); i++) {
    cin >> a[i];
  }
  for (int i = (1); i <= (k); i++) {
    for (int j = i; j <= n; j += k) inv[j] = ++cnt;
    stop[i] = cnt;
  }
  sparse_calc();
  for (int i = (1); i <= (n - k + 1); i++) {
    mink[i] = min_interval(i, i + k - 1);
  }
  for (int i = (1); i <= (q); i++) {
    int x, y;
    cin >> x >> y;
    queries.push_back(make_pair(make_pair(x, y), i));
  }
  sort(queries.begin(), queries.end());
  reverse(queries.begin(), queries.end());
  int rb = n + 1;
  build();
  for (const auto& u : queries) {
    for (int i = (rb - 1); i >= (u.first.first); i--) {
      sset(inv[i], a[i]);
      if (i < n - k + 1) update(inv[i] + 1, stop[(i - 1) % k + 1], mink[i]);
    }
    rb = u.first.first;
    ans[u.second] =
        query(inv[u.first.first],
              inv[u.first.first] + (u.first.second - u.first.first) / k);
  }
  for (int i = (1); i <= (q); i++) cout << ans[i] << "\n";
  return 0;
}
