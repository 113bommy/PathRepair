#include <bits/stdc++.h>
using namespace std;
#pragma GCC optimize("O2,no-stack-protector,unroll-loops,fast-math")
const long long maxn = 1e5 + 20, maxm = 32e3 + 10, lg = 18, mod = 998244353,
                inf = 1e18;
long long n, d[maxn];
vector<long long> g[maxn];
bool mk[maxn];
int main() {
  ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
  cin >> n;
  for (int i = 1; i < n; i++) {
    long long v, u;
    cin >> v >> u;
    g[v].push_back(u), g[v].push_back(u);
  }
  for (int i = 1; i <= n; i++)
    if ((long long)(g[i].size()) == 1) {
      queue<long long> q;
      q.push(i);
      while (!q.empty()) {
        long long v = q.front();
        q.pop();
        mk[v] = 1;
        for (auto u : g[v])
          if ((long long)(g[u].size()) <= 2 && !mk[u]) q.push(u);
      }
    }
  for (int i = 1; i <= n; i++)
    if (!mk[i])
      for (auto u : g[i]) d[i] += mk[u];
  for (int i = 1; i <= n; i++) {
    long long dd = 0;
    for (auto u : g[i])
      dd += (!mk[u] && ((long long)(g[u].size()) - d[u] > 1 || d[u] > 2));
    if (dd > 2) return cout << "No", 0;
  }
  cout << "Yes";
  return 0;
}
