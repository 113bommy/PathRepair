#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const ll oo = 0x3f3f3f3f3f3f3f3f;
int main() {
  ll n, m;
  cin >> n >> m;
  vector<ll> w(n);
  for (auto &a : w) cin >> a;
  vector<ll> b(m);
  for (auto &a : b) cin >> a, a--;
  ll res = 0;
  for (ll i = 0; i < m; i++) {
    vector<bool> visited(m);
    for (ll j = i - 1; j >= 0; j--) {
      if (b[i] == b[j]) break;
      visited[j] = true;
    }
    for (ll j = 0; j < n; j++) res += visited[j] ? w[j] : 0;
  }
  cout << res << endl;
}
