#include <bits/stdc++.h>
using namespace std;
const int mod = 998244353;
const int INF = 1e9;
const int maxn = 1e6 + 10;
const double eps = 1e-8;
int add(int x, int y) {
  x += y;
  return x >= mod ? x - mod : x;
}
int sub(int x, int y) {
  x -= y;
  return x < 0 ? x + mod : x;
}
int mul(int x, int y) { return 1LL * x * y % mod; }
int dep[maxn], tot, ans;
vector<pair<int, int> > g[maxn];
queue<pair<int, int> > q;
int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int n;
  cin >> n;
  bool ok = false;
  for (int i = 1; i <= n; i++) {
    vector<int> fac;
    int x;
    cin >> x;
    for (int d = 2; d * d <= x; d++)
      if (x % d == 0) {
        int cnt = 0;
        while (x % d == 0) cnt++, x /= d;
        if (cnt & 1) fac.push_back(d);
      }
    if (x > 1) fac.push_back(x);
    if (fac.size() == 2) {
      int p = fac[0], q = fac[1];
      g[p].push_back(pair<int, int>{q, ++tot}),
          g[q].push_back(pair<int, int>{p, tot});
    } else if (fac.size() == 1) {
      int p = fac[0];
      g[p].push_back(pair<int, int>{1, ++tot}),
          g[1].push_back(pair<int, int>{p, tot});
    } else
      ok = true;
  }
  if (ok) {
    cout << 1 << endl;
    return 0;
  }
  ans = INF;
  fill(dep + 1, dep + 1000000 + 1, INF);
  for (int i = 2; i <= 2; i++) {
    vector<int> save;
    dep[i] = 0, q.push(pair<int, int>{i, 0});
    while (!q.empty()) {
      pair<int, int> x = q.front();
      q.pop();
      int u = x.first, pre = x.second;
      save.push_back(u);
      for (auto e : g[u]) {
        int v = e.first, id = e.second;
        if (id == pre) continue;
        if (dep[v] == INF) {
          dep[v] = dep[u] + 1;
          q.push(pair<int, int>{v, id});
        } else
          ans = min(ans, dep[u] + dep[v] + 1);
      }
    }
    for (auto x : save) dep[x] = INF;
  }
  if (ans == INF)
    cout << -1 << endl;
  else
    cout << ans << endl;
  return 0;
}
