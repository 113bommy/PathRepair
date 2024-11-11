#include <bits/stdc++.h>
using namespace std;
const int MAX = int(1e5 + 1);
const int MOD = int(1e9 + 7);
const long long oo = LLONG_MAX;
void update(unordered_map<long long, long long>& cost, long long u, long long v,
            long long w) {
  if (u > v) swap(u, v);
  long long lvl = __builtin_clz(u);
  while (lvl != __builtin_clz(v)) {
    cost[v] += w;
    v >>= 1;
  }
  while (u != v) {
    cost[u] += w;
    u >>= 1;
    cost[v] += w;
    v >>= 1;
  }
}
long long query(unordered_map<long long, long long>& cost, long long u,
                long long v) {
  if (u > v) swap(u, v);
  long long r = 0;
  long long lvl = __builtin_clz(u);
  while (lvl != __builtin_clz(v)) {
    r += cost[v];
    v >>= 1;
  }
  while (u != v) {
    r += cost[u];
    u >>= 1;
    r += cost[v];
    v >>= 1;
  }
  return r;
}
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  int q;
  while (cin >> q) {
    unordered_map<long long, long long> cost;
    int t;
    long long u, v, w;
    while (q--) {
      cin >> t >> u >> v;
      if (t == 1) {
        cin >> w;
        update(cost, u, v, w);
      } else
        cout << query(cost, u, v) << "\n";
    }
  }
  return 0;
}
