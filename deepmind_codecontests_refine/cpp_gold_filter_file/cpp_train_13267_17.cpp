#include <bits/stdc++.h>
using namespace std;
#pragma GCC optimize("Ofast")
const long long int maxn = 3e3 + 16, md = 1e9 + 7, inf = 2e16;
long long int gcd(long long int a, long long int b) {
  if (a < b) swap(a, b);
  if (b == 0) return a;
  return gcd(b, a % b);
}
long long int tav(long long int n, long long int k) {
  long long int res = 1;
  while (k > 0) {
    if (k & 1) {
      res *= n;
      res %= md;
    }
    n *= n;
    n %= md;
    k >>= 1;
  }
  return res;
}
long long int ds[maxn], dsz[maxn], dsl[maxn];
long long int dsu(long long int v) {
  return (ds[v] == v ? v : ds[v] = dsu(ds[v]));
}
void merge(long long int v, long long int u) {
  v = dsu(v);
  u = dsu(u);
  dsz[v] += dsz[u];
  dsl[v] += dsl[u];
  ds[u] = v;
  return;
}
long long int n, lm[maxn], sum = 0;
vector<pair<long long int, pair<long long int, long long int> > > ed;
bool check(long long int x) {
  for (long long int i = 0; i < n; i++) {
    ds[i] = i;
    dsz[i] = 1;
    dsl[i] = lm[i];
  }
  for (auto q : ed) {
    pair<long long int, long long int> p = q.second;
    long long int v = p.first, u = p.second, w = q.first;
    if (w >= x) break;
    merge(v, u);
  }
  for (long long int i = 0; i < n; i++) {
    if (sum - dsl[i] < dsz[i]) return false;
  }
  return true;
}
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  cin >> n;
  for (long long int i = 1; i < n; i++) {
    long long int v, u, w;
    cin >> v >> u >> w;
    v--;
    u--;
    ed.push_back({w, {v, u}});
  }
  sort(ed.begin(), ed.end());
  for (long long int i = 0; i < n; i++) {
    cin >> lm[i];
    sum += lm[i];
  }
  long long int l = 0, r = 1e4 + 16;
  while (l < r - 1) {
    long long int m = (r + l) >> 1;
    if (check(m)) {
      l = m;
    } else {
      r = m;
    }
  }
  cout << l << '\n';
  return 0;
}
