#include <bits/stdc++.h>
using namespace std;
const long long N = 4e5 + 7;
long long n, m, q, u, v, id, open[N], close[N], w[N];
long long node[8 * N], lazy[8 * N];
vector<long long> arr, adj[N];
long long poww(long long a, long long b) {
  if (b == 0) return 1;
  if (b == 1) return a;
  long long temp = poww(a, b / 2);
  if (b % 2 == 0)
    return temp * temp;
  else
    return temp * temp * a;
}
void dfs(long long u, long long par) {
  arr.push_back(u);
  open[u] = arr.size() - 1;
  for (auto v : adj[u]) {
    if (v != par) {
      dfs(v, u);
    }
  }
  arr.push_back(u);
  close[u] = arr.size() - 1;
}
void build(long long id, long long l, long long r) {
  if (l == r) {
    node[id] = poww(2, w[arr[r]]);
    return;
  }
  long long mid = (l + r) / 2;
  build(2 * id, l, mid);
  build(2 * id + 1, mid + 1, r);
  node[id] = node[2 * id] | node[2 * id + 1];
}
void down(long long id) {
  if (lazy[id] == -1) return;
  node[2 * id + 1] = node[2 * id] = poww(2, lazy[id]);
  lazy[2 * id + 1] = lazy[2 * id] = lazy[id];
  lazy[id] = -1;
}
void upd(long long id, long long l, long long r, long long a, long long b,
         long long val) {
  if (b < l || r < a) return;
  if (a <= l && r <= b) {
    node[id] = poww(2, val);
    lazy[id] = val;
    return;
  }
  long long mid = (l + r) / 2;
  down(id);
  upd(2 * id, l, mid, a, b, val);
  upd(2 * id + 1, mid + 1, r, a, b, val);
  node[id] = node[2 * id] | node[2 * id + 1];
}
long long get_ans(long long id, long long l, long long r, long long a,
                  long long b) {
  if (b < l || r < a) return 0;
  if (a <= l && r <= b) return node[id];
  long long mid = (l + r) / 2;
  down(id);
  return (get_ans(2 * id, l, mid, a, b) |
          get_ans(2 * id + 1, mid + 1, r, a, b));
}
long long get_one(long long ans) {
  long long i = 0, res = 0;
  while (i <= 60) {
    res += ((ans >> i) & 1);
    i++;
  }
  return res;
}
signed main() {
  scanf("%lld %lld", &n, &q);
  for (long long i = 1; i <= n; ++i) {
    scanf("%lld", &w[i]);
  }
  for (long long i = 1; i < n; ++i) {
    scanf("%lld %lld", &u, &v);
    adj[u].push_back(v);
    adj[v].push_back(u);
  }
  memset(lazy, -1, sizeof(lazy));
  dfs(1, 1);
  m = arr.size() - 1;
  build(1, 0, m);
  while (q--) {
    scanf("%lld", &id);
    if (id == 1) {
      scanf("%lld %lld", &u, &v);
      upd(1, 0, m, open[u], close[u], v);
    } else {
      scanf("%lld", &u);
      printf("%lld\n", get_one(get_ans(1, 0, m, open[u], close[u])));
    }
  }
}
