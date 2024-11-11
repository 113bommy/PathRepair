#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using i2 = pair<int, int>;
using ll2 = pair<ll, ll>;
const int N = 5e5 + 9;
int A[N], lazy[N << 2], cnt[N];
i2 tree[N << 2];
vector<int> pos[N];
int dsize;
void build_tree(int u, int lo, int hi) {
  tree[u] = {0, hi - lo + 1};
  if (lo != hi) {
    int mid = (lo + hi) >> 1;
    build_tree(u << 1, lo, mid);
    build_tree(u << 1 | 1, mid + 1, hi);
  }
}
void tree_push(int u, int lo, int hi) {
  tree[u].first += lazy[u];
  if (lo != hi) {
    lazy[u << 1] += lazy[u];
    lazy[u << 1 | 1] += lazy[u];
  }
  lazy[u] = 0;
}
void tree_upd(int u, int lo, int hi) {
  i2 l = tree[u << 1], r = tree[u << 1 | 1];
  if (l > r) swap(l, r);
  if (l.first == r.first)
    tree[u] = {l.first, l.second + r.second};
  else
    tree[u] = l;
}
void rng_add(int u, int lo, int hi, int a, int b, int x) {
  tree_push(u, lo, hi);
  if (a > b) return;
  if (a == lo && b == hi) {
    lazy[u] += x;
    tree_push(u, lo, hi);
    return;
  }
  int mid = (lo + hi) >> 1;
  rng_add(u << 1, lo, mid, a, min(b, mid), x);
  rng_add(u << 1 | 1, mid + 1, hi, max(a, mid + 1), b, x);
  tree_upd(u, lo, hi);
}
i2 rng_min(int u, int lo, int hi, int a, int b) {
  tree_push(u, lo, hi);
  if (a > b) return {INT_MAX, 0};
  if (a == lo && b == hi) return tree[u];
  int mid = (lo + hi) >> 1;
  i2 l = rng_min(u << 1, lo, mid, a, min(b, mid));
  i2 r = rng_min(u << 1 | 1, mid + 1, hi, max(a, mid + 1), b);
  tree_upd(u, lo, hi);
  if (l > r) swap(l, r);
  if (l.first == r.first) return {l.first, l.second + r.second};
  return l;
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  int n;
  cin >> n;
  dsize = 1;
  while (dsize < n) dsize <<= 1;
  build_tree(1, 1, dsize);
  for (int i = 1; i <= n; ++i) pos[i].push_back(0);
  for (int i = 1; i <= n; ++i) {
    cin >> A[i];
    pos[A[i]].push_back(i);
  }
  ll res = 0;
  for (int i = 1; i <= n; ++i) {
    int a = A[i], k = ++cnt[a];
    rng_add(1, 1, dsize, pos[a][k - 1] + 1, i, 1);
    if (k >= 3) rng_add(1, 1, dsize, pos[a][k - 3] + 1, pos[a][k - 2], -1);
    if (k >= 4) rng_add(1, 1, dsize, pos[a][k - 4] + 1, pos[a][k - 3], 1);
    i2 mn = rng_min(1, 1, dsize, 1, i);
    if (mn.first == 0) res += mn.second;
  }
  cout << res;
  return 0;
}
