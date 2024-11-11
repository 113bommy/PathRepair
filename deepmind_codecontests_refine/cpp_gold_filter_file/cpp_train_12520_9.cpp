#include <bits/stdc++.h>
using namespace std;
double DEG_to_RAD(double d) { return d * acos(-1.0) / 180.0; }
double RAD_to_DEG(double r) { return r * 180.0 / acos(-1.0); }
long long M = 1e9 + 7, n;
vector<long long> v, d;
vector<vector<long long> > g;
priority_queue<long long> p;
long long dfs(long long t) {
  if (!v[t]) {
    v[t] = 1;
    long long sum = 1;
    for (auto it : g[t]) {
      if (!v[it]) {
        sum += dfs(it);
      }
    }
    return d[t] = sum;
  }
  return d[t];
}
void dfs2(long long t) {
  if (!v[t]) {
    v[t] = 1;
    long long sum = 1;
    for (auto it : g[t]) {
      if (!v[it]) {
        p.push(d[it] * (n - d[it]) * 2);
        dfs2(it);
      }
    }
  }
}
int32_t main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  long long t;
  cin >> t;
  while (t--) {
    long long x, y;
    cin >> n;
    g.assign(n, vector<long long>(0));
    for (int i = 0; i < n - 1; i++) {
      cin >> x >> y;
      g[x - 1].push_back(y - 1);
      g[y - 1].push_back(x - 1);
    }
    long long m;
    cin >> m;
    vector<long long> c;
    for (int i = 0; i < m; i++) {
      cin >> x;
      c.push_back(x);
    }
    sort(c.begin(), c.end());
    while (c.size() > n - 1) {
      long long aux = c.back();
      c.pop_back();
      c.back() *= aux;
      c.back() %= M;
    }
    while (c.size() < n - 1) {
      c.push_back(1);
    }
    sort(c.rbegin(), c.rend());
    v.assign(n, 0);
    d.assign(n, 0);
    dfs(0);
    v.assign(n, 0);
    dfs2(0);
    long long ans = 0, in = 0;
    while (!p.empty()) {
      long long t = p.top();
      ans += (t / 2 * c[in]) % M;
      ans %= M;
      in++;
      p.pop();
    }
    cout << ans % M << "\n";
  }
  cerr << "\nTime elapsed: " << 1000 * clock() / CLOCKS_PER_SEC << "ms\n";
  return 0;
}
