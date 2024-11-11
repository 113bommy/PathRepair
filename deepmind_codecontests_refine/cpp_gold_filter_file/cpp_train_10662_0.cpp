#include <bits/stdc++.h>
using namespace std;
const long double pi = acos(-1);
const int n_ = 2e5 + 5;
int n, q, st[n_ << 5], nodes[n_ << 2], f[n_], b[n_], arr[n_], cnt, odd[n_ << 5],
    even[n_ << 5];
vector<int> adj[n_];
void DFS(int u, int p = -1) {
  nodes[++cnt] = u;
  for (int i : adj[u]) {
    if (i != p) {
      DFS(i, u);
      nodes[++cnt] = u;
    }
  }
}
void upd(int parity, int s, int e, int v, int id = 1, int l = 1, int r = cnt) {
  if (s > r || e < l) return;
  if (s <= l && r <= e) {
    (parity ? odd : even)[id] += v;
    return;
  }
  upd(parity, s, e, v, id << 1, l, ((l + r) >> 1));
  upd(parity, s, e, v, id << 1 | 1, ((l + r) >> 1) + 1, r);
}
int get(int x, int id = 1, int l = 1, int r = cnt) {
  if (l == r) return arr[nodes[x]] + (odd[id] - even[id]) * (2 * (l & 1) - 1);
  if (odd[id]) {
    odd[id << 1] += odd[id];
    odd[id << 1 | 1] += odd[id];
  }
  if (even[id]) {
    even[id << 1] += even[id];
    even[id << 1 | 1] += even[id];
  }
  odd[id] = even[id] = 0;
  if (x <= ((l + r) >> 1))
    return get(x, id << 1, l, ((l + r) >> 1));
  else
    return get(x, id << 1 | 1, ((l + r) >> 1) + 1, r);
}
int main() {
  scanf("%d %d", &n, &q);
  for (int i = 1; i <= n; i++) scanf("%d", arr + i);
  for (int i = 1; i < n; i++) {
    int u, v;
    scanf("%d %d", &u, &v);
    adj[u].push_back(v);
    adj[v].push_back(u);
  }
  DFS(1);
  for (int i = 1; i <= cnt; i++) b[nodes[i]] = i;
  for (int i = cnt; i; --i) f[nodes[i]] = i;
  int t, x, v;
  while (q--) {
    scanf("%d", &t);
    if (t == 1) {
      scanf("%d %d", &x, &v);
      upd(f[x] % 2, f[x], b[x], v);
    } else {
      scanf("%d", &x);
      printf("%d\n", get(f[x]));
    }
  }
  return 0;
}
