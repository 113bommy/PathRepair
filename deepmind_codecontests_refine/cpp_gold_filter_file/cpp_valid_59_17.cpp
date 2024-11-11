#include <bits/stdc++.h>
using namespace std;
int main() {
  long long tt;
  cin >> tt;
  while (tt--) {
    long long n, m;
    cin >> n >> m;
    vector<long long> a(n), b(n);
    for (long long i = 1; i < n; ++i) cin >> a[i];
    for (long long i = 1; i < n; ++i) cin >> b[i];
    vector<vector<long long>> edg(n);
    for (long long i = 0; i < m; ++i) {
      long long u, v;
      cin >> u >> v;
      --u, --v;
      edg[u].push_back(v);
      edg[v].push_back(u);
    }
    function<long long(long long)> solve = [&](long long cur) {
      vector<long long> act(n, 0), acts;
      act[0] = 1;
      acts.push_back(0);
      while (acts.size() != n) {
        vector<long long> vis = act;
        vector<long long> pre(n, -1);
        function<void(long long)> dod = [&](long long u) {
          if (act[u]) return;
          cur += b[u];
          act[u] = 1;
          acts.push_back(u);
          if (pre[u] != -1) dod(pre[u]);
        };
        long long gre = 1;
        function<void(long long, long long, long long)> dfs =
            [&](long long u, long long p, long long meja) {
              vis[u] = 1;
              pre[u] = p;
              meja += b[u];
              for (auto&& v : edg[u])
                if (gre and v != p) {
                  if (gre and vis[v])
                    gre = 0, dod(u), dod(v);
                  else if (gre and meja > a[v])
                    dfs(v, u, meja);
                }
            };
        for (auto&& u : acts)
          if (gre)
            for (auto&& v : edg[u])
              if (gre and !act[v] and cur > a[v]) {
                dfs(v, u, cur);
                if (!gre) break;
              }
        if (gre) return (long long)0;
      }
      return (long long)1;
    };
    long long l = 0, r = 1000000001;
    while (l < r) {
      long long mid = (l + r) / 2;
      if (solve(mid))
        r = mid;
      else
        l = mid + 1;
    }
    cout << l << endl;
  }
}
