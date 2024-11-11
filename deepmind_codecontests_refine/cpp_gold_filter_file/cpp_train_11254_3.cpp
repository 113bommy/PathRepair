#include <bits/stdc++.h>
using namespace std;
long long c[500005], u[500005], v[500005], vis[500005], p2[500005],
    mod = 1e9 + 7, p[500005];
map<long long, vector<int> > ma;
void init() {
  for (int(i) = 1; (i) <= (500005 - 1); (i)++) {
    p2[i] = p2[i - 1] * 2 % mod;
  }
}
int par(int u) { return p[u] == -1 ? u : p[u] = par(p[u]); }
int main() {
  ios::sync_with_stdio(0);
  p2[0] = 1;
  init();
  int n, m;
  cin >> (n) >> (m);
  ;
  int k;
  cin >> (k);
  ;
  for (int(i) = 1; (i) <= (n); (i)++) cin >> c[i];
  for (int(i) = 0; (i) < (m); (i)++) cin >> u[i] >> v[i];
  for (int(i) = 0; (i) < (m); (i)++) {
    ma[c[u[i]] ^ c[v[i]]].push_back(i);
  }
  for (int(i) = 1; (i) <= (n); (i)++) p[i] = -1;
  long long ans = 0;
  int cntk = 0;
  for (auto k : ma) {
    cntk++;
    set<long long> s;
    int cnt = 0;
    for (auto i : ma[k.first]) {
      int x = u[i], y = v[i];
      if ((x = par(x)) != (y = par(y))) {
        p[y] = x;
        s.insert(x);
        s.insert(y);
      }
    }
    int rest = n - s.size();
    set<long long> ss;
    for (auto u : s) {
      ss.insert(par(u));
    }
    cnt = ss.size();
    for (auto u : s) p[u] = -1;
    ans += p2[cnt] * p2[rest] % mod;
  }
  ans += (p2[k] - cntk) * p2[n] % mod;
  cout << ans % mod << endl;
  return 0;
}
