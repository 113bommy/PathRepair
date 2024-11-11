#include <bits/stdc++.h>
using namespace std;
using ll = long long;
ll max(ll a, ll b) { return (a > b ? a : b); }
ll min(ll a, ll b) { return (a > b ? b : a); }
ll a, b, c, d, e, n, m, k, q, x, y, z, w, t, cur, cnt, ma,
    mi = LONG_LONG_MAX, l, r, mid, sum, i, j, pro = 1, f;
ll arr[200005];
ll arr1[200005];
ll arr2[200005];
ll dp[200005];
ll arr3[1000][1000];
vector<ll> v[2000];
string s;
int dfs(int i) {
  arr[i] = 1;
  int len = 1;
  for (auto c : v[i]) {
    if (!arr[c]) {
      d = dfs(c);
    }
  }
  dp[i] = len;
  return len;
}
void solve() {
  cin >> n >> m;
  for (int i = 0; i < n; i++) cin >> s;
  s += '.' + s + '.';
  for (int i = 1; i <= m; i++) {
    if (s[i] == 'B') {
      cnt++;
      while (i <= m && s[i] == 'B') i++;
    }
  }
  cout << cnt;
}
int main() {
  ll t;
  t = 1;
  while (t--) {
    solve();
  }
  return 0;
}
