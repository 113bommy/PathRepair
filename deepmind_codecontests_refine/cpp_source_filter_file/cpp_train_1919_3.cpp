#include <bits/stdc++.h>
using namespace std;
const int MOD = 1e9 + 7;
const int mx = 3e5 + 5;
vector<int> edges[mx];
int level[mx], st1[mx], st2[mx], ed1[mx], ed2[mx], tm1, tm2;
bool vis[mx];
void dfs(int u, int d) {
  vis[u] = true;
  level[u] = d;
  st1[u] = ++tm1, st2[u] = ++tm2;
  for (int v : edges[u]) {
    if (!vis[v]) dfs(v, d + 1);
  }
  ed1[u] = tm1, ed2[u] = ++tm2;
}
long long bit[2 * mx], path[2 * mx];
void bitU(int idx, int data, int val) {
  while (idx <= tm2) {
    bit[idx] = (bit[idx] + data) % MOD;
    path[idx] = (path[idx] + val) % MOD;
    idx += idx & (-idx);
  }
}
pair<long long, long long> bitQ(int idx) {
  long long res = 0, ans = 0;
  while (idx > 0) {
    res = (res + bit[idx]) % MOD;
    ans = (ans + path[idx]) % MOD;
    idx -= idx & (-idx);
  }
  return make_pair(res, ans);
}
long long seg[4 * mx];
long long lazy[4 * mx];
void propagate(int pos, int L, int R) {
  int mid = (L + R) / 2, x = pos * 2;
  seg[x] = (seg[x] + (mid - L + 1) * lazy[pos]) % MOD;
  seg[x + 1] = (seg[x + 1] + (R - mid) * lazy[pos]) % MOD;
  lazy[x] = (lazy[x] + lazy[pos]) % MOD;
  lazy[x + 1] = (lazy[x + 1] + lazy[pos]) % MOD;
  lazy[pos] = 0;
}
void segU(int pos, int L, int R, int l, int r, long long data) {
  if (L > r || l > R) return;
  if (L >= l && R <= r) {
    seg[pos] = (seg[pos] + (R - L + 1) * data) % MOD;
    lazy[pos] = (lazy[pos] + data) % MOD;
    return;
  }
  if (lazy[pos] != 0) propagate(pos, L, R);
  int mid = (L + R) / 2, x = pos * 2;
  segU(x, L, mid, l, r, data);
  segU(x + 1, mid + 1, R, l, r, data);
  seg[pos] = (seg[x] + seg[x + 1]) % MOD;
}
long long segQ(int pos, int L, int R, int node) {
  if (L > node || R < node) return 0;
  if (L == R && L == node) return seg[pos];
  if (lazy[pos] != 0) propagate(pos, L, R);
  int x = pos * 2, mid = (L + R) / 2;
  if (node <= mid)
    return segQ(x, L, mid, node);
  else
    return segQ(x + 1, mid + 1, R, node);
}
int main() {
  int i, n;
  scanf("%d", &n);
  for (i = 2; i <= n; i++) {
    int x;
    scanf("%d", &x);
    edges[x].push_back(i);
  }
  dfs(1, 1);
  int q, v, x, t;
  long long k;
  scanf("%d", &q);
  while (q--) {
    scanf("%d", &t);
    if (t == 1) {
      scanf("%d %d %lld", &v, &x, &k);
      segU(1, 1, tm1, st1[v], ed1[v], x);
      bitU(st2[v], k * level[v], k);
      bitU(ed2[v], -k * level[v], -k);
    } else {
      scanf("%d", &v);
      long long ans;
      ans = segQ(1, 1, tm1, st1[v]);
      auto temp = bitQ(st2[v] - 1);
      ans = (ans - temp.second * level[v] + temp.first) % MOD;
      ans = (ans + MOD) % MOD;
      printf("%lld\n", ans);
    }
  }
  return 0;
}
