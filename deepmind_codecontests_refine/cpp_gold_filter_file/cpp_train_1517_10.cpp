#include <bits/stdc++.h>
using namespace std;
const int N = 100005, P = 1000000007;
using ll = long long;
ll b[65];
int tot;
void insert(ll num) {
  for (int i = 62; i >= 0; --i)
    if (num & (1ll << i)) {
      if (!b[i]) {
        b[i] = num;
        ++tot;
        return;
      }
      num ^= b[i];
    }
}
int n, m;
vector<pair<int, ll>> v[N];
bool vis[N];
ll val[N];
vector<int> cur;
void dfs(int pos, ll vv) {
  vis[pos] = 1;
  val[pos] = vv;
  cur.push_back(pos);
  for (auto &i : v[pos])
    if (!vis[i.first])
      dfs(i.first, vv ^ i.second);
    else
      insert(vv ^ i.second ^ val[i.first]);
}
int main() {
  ios::sync_with_stdio(false);
  cin >> n >> m;
  int t1, t2;
  ll t3;
  for (int i = 1; i <= m; i++) {
    cin >> t1 >> t2 >> t3;
    v[t1].push_back({t2, t3});
    v[t2].push_back({t1, t3});
  }
  ll ans = 0;
  for (int i = 1; i <= n; i++) {
    if (vis[i]) continue;
    memset(b, 0, sizeof(b));
    cur.clear();
    tot = 0;
    dfs(i, 0);
    ll s = cur.size();
    for (int j = 0; j <= 62; j++) {
      bool ok = 0;
      ll cc = (1ll << j) % P;
      for (int k = 0; k <= 62 && !ok; k++)
        if (b[k] & (1ll << j)) ok = 1;
      if (ok)
        ans = (ans +
               s * (s - 1) / 2 % P * cc % P * ((1ll << (tot - 1)) % P) % P) %
              P;
      else {
        int tmp = 0;
        for (auto &i : cur)
          if (val[i] & (1ll << j)) ++tmp;
        ans = (ans + tmp * (s - tmp) % P * cc % P * ((1ll << tot) % P) % P) % P;
      }
    }
  }
  cout << ans << endl;
  return 0;
}
