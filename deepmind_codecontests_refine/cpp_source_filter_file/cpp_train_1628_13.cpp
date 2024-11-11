#include <bits/stdc++.h>
using namespace std;
const int N = 5e5 + 100;
int par[N], v[N], u[N], w[N], a[N];
vector<int> vec;
int n, m, q, k;
int getPar(int v) { return (par[v] == v ? v : par[v] = getPar(par[v])); }
void merge(int v, int u) {
  v = getPar(v);
  u = getPar(u);
  par[u] = v;
}
void reset() {
  for (int i = 0; i < n; i++) par[i] = i;
}
int main() {
  ios_base::sync_with_stdio(false), cin.tie(0), cout.tie(0);
  cin >> n >> m;
  for (int i = 0; i < m; i++) {
    cin >> v[i] >> u[i] >> w[i];
    v[i]--;
    u[i]--;
    a[i] = i;
  }
  sort(a, a + n, [&](int i, int j) { return w[i] < w[j]; });
  reset();
  for (int i = 0; i < n;) {
    int j = i;
    for (; w[a[i]] == w[a[j]]; j++) {
      v[a[j]] = getPar(v[a[j]]);
      u[a[j]] = getPar(u[a[j]]);
    }
    for (; i < j; i++) merge(v[a[i]], u[a[i]]);
  }
  reset();
  cin >> q;
  while (q--) {
    cin >> k;
    bool ok = true;
    for (int j = 0; j < k; j++) {
      int i;
      cin >> i;
      i--;
      vec.push_back(v[i]);
      vec.push_back(u[i]);
      if (getPar(v[i]) == getPar(u[i])) ok = false;
      merge(v[i], u[i]);
    }
    cout << (ok ? "YES" : "NO") << '\n';
    for (auto v : vec) par[v] = v;
    vec.clear();
  }
}
