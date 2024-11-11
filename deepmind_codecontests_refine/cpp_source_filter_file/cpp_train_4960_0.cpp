#include <bits/stdc++.h>
using namespace std;
int main(void) {
  ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
  int testCase = 1;
  while (testCase--) {
    int n;
    cin >> n;
    vector<int> A(n);
    for (int& a : A) cin >> a;
    vector<vector<int>> adj(n);
    vector<int> uf(n);
    for (int i = 1; i < n; ++i) {
      int u, v;
      cin >> u >> v;
      --u, --v;
      adj[u].push_back(v);
      adj[v].push_back(u);
    }
    vector<pair<int, int>> verts;
    verts.reserve(n);
    for (int i = 0; i < n; ++i) verts.emplace_back(A[i], i);
    sort(verts.begin(), verts.end());
    function<int(int)> getPa = [&](int x) {
      return uf[x] < 0 ? x : (uf[x] = getPa(uf[x]));
    };
    function<void(int, int)> merge = [&](int x, int y) {
      x = getPa(x), y = getPa(y);
      assert(x != y);
      if (-uf[x] < -uf[y]) swap(x, y);
      uf[x] += uf[y], uf[y] = x;
    };
    long long ans = 0;
    for (int t = 0, v = 1; t < 2; v *= -1, ++t) {
      vector<bool> is(n, 0);
      for (int& i : uf) i = -1;
      for (auto x : verts) {
        int u = x.second;
        is[u] = 1;
        long long basic = 1;
        for (int v : adj[u])
          if (is[v]) {
            basic += uf[getPa(u)] * uf[getPa(v)];
            merge(u, v);
          }
        ans += 1ll * v * basic * x.first;
      }
      reverse(verts.begin(), verts.end());
    }
    cout << ans << '\n';
  }
  return 0;
}
