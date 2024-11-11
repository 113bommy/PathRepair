#include <bits/stdc++.h>
using namespace std;
const int MOD = 1e9 + 7;
const int N = 100100;
const long long oo = 2e18;
int n, u, v;
long long sub[N], lon[N], a[N];
vector<int> g[N];
long long ans = 0;
void pre(int u, int p) {
  vector<long long> all;
  lon[u] = a[u];
  sub[v] = a[u];
  for (int i = 0; i < g[u].size(); ++i) {
    int v = g[u][i];
    if (v == p) continue;
    pre(v, u);
    sub[u] = max(sub[u], sub[v]);
    lon[u] = max(lon[u], a[u] + lon[v]);
    all.push_back(lon[v]);
  }
  sort(all.begin(), all.end());
  if (all.size()) sub[u] = max(sub[u], a[u] + all.back());
  if (all.size() >= 2)
    sub[u] = max(sub[u], a[u] + all.back() + all[all.size() - 2]);
  ;
}
void fn(int u, int p, long long b1, long long b2) {
  ans = max(ans, b2 + sub[u]);
  multiset<long long> k1, k2;
  k1.insert(b1);
  k2.insert(b2);
  for (int i = 0; i < g[u].size(); ++i) {
    int v = g[u][i];
    if (v == p) continue;
    k1.insert(lon[v]);
    k2.insert(sub[v]);
  }
  for (int i = 0; i < g[u].size(); ++i) {
    int v = g[u][i];
    if (v == p) continue;
    k1.erase(k1.find(lon[v]));
    k2.erase(k2.find(sub[v]));
    long long fx = a[u];
    multiset<long long>::iterator it = k1.end();
    if (k1.size() > 0) {
      --it;
      fx += *it;
    }
    if (k1.size() > 1) {
      --it;
      fx += *it;
    }
    fn(v, u, *(--k1.end()) + a[u], max(fx, *(--k2.end())));
    k1.insert(lon[v]);
    k2.insert(sub[v]);
  }
}
int main() {
  scanf("%d", &n);
  for (int i = 1; i <= n; ++i) {
    scanf("%lld", &a[i]);
  }
  for (int i = 0; i < n - 1; ++i) {
    scanf("%d%d", &u, &v);
    g[u].push_back(v);
    g[v].push_back(u);
  }
  pre(1, -1);
  fn(1, -1, 0ll, 0ll);
  printf("%lld\n", ans);
  return 0;
}
