#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const ll oo = 0x3f3f3f3f3f3f3f3fLL;
vector<ll> p, c;
vector<ll> cyc;
vector<bool> visited;
ll dfs(ll i, ll cur) {
  if (visited[cur]) return i;
  visited[cur] = true;
  cyc.push_back(cur);
  return dfs(i + 1, p[cur]);
}
int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  ll t;
  cin >> t;
  while (t--) {
    ll n;
    cin >> n;
    p.resize(n);
    c.resize(n);
    for (auto &k : p) cin >> k, k--;
    for (auto &k : c) cin >> k, k--;
    visited.assign(n, false);
    ll res = oo;
    for (ll i = 0; i < n; i++)
      if (!visited[i]) {
        cyc.clear();
        ll am = dfs(0, i);
        res = min(res, am);
        for (ll k = 1; k < min(res, am); k++)
          if (am % k == 0) {
            for (ll st = 0; st < k; st++) {
              bool bad = false;
              for (ll ad = k; st + ad < am; ad += k) {
                if (c[cyc[ad + st]] != c[cyc[st]]) {
                  bad = true;
                  break;
                }
              }
              if (!bad) res = min(res, k);
            }
          }
      }
    cout << res << '\n';
  }
}
