#include <bits/stdc++.h>
using namespace std;
template <typename A, typename B>
ostream &operator<<(ostream &os, const pair<A, B> &p) {
  return os << '(' << p.first << ", " << p.second << ')';
}
template <typename T_container, typename T = typename enable_if<
                                    !is_same<T_container, string>::value,
                                    typename T_container::value_type>::type>
ostream &operator<<(ostream &os, const T_container &v) {
  os << '{';
  string sep;
  for (const T &x : v) os << sep << x, sep = ", ";
  return os << '}';
}
void dbg_out() { cerr << endl; }
template <typename Head, typename... Tail>
void dbg_out(Head H, Tail... T) {
  cerr << ' ' << H;
  dbg_out(T...);
}
using ll = long long;
using vi = vector<int>;
using ull = unsigned long long;
const int mod = 1e9 + 7;
const int inf = 0x3f3f3f3f;
const int maxn = 1e6 + 10;
int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int k;
  cin >> k;
  vector<ll> f(6), pow10(6);
  vector<ll> dp(maxn);
  vector<bool> vis(maxn);
  pow10[0] = 1;
  for (int i = int(1); i <= (int)(5); i++) pow10[i] = pow10[i - 1] * 10;
  for (int i = int(0); i <= (int)(5); i++) cin >> f[i];
  vis[0] = true;
  for (int i = int(0); i <= (int)(5); i++) {
    ll cnt = 3 * (k - 1), now = 1;
    cnt = min(cnt, (maxn - 5) / (pow10[i] * 3));
    while (now <= cnt) {
      cnt -= now;
      ll cost = now * pow10[i] * 3, val = now * f[i];
      for (int k = int(maxn - 5); k >= (int)(cost); k--) {
        if (vis[k - cost]) {
          vis[k] = true;
          dp[k] = max(dp[k], dp[k - cost] + val);
        }
      }
      now <<= 1;
    }
    if (cnt != 0) {
      ll cost = cnt * pow10[i] * 3, val = cnt * f[i];
      for (int k = int(maxn - 5); k >= (int)(cost); k--) {
        if (vis[k - cost]) {
          vis[k] = true;
          dp[k] = max(dp[k], dp[k - cost] + val);
        }
      }
    }
  }
  vector<ll> pre(maxn);
  vector<bool> pvis(maxn);
  for (int i = int(0); i <= (int)(5); i++) {
    pre = dp;
    pvis = vis;
    for (int j = int(1); j <= (int)(9); j++) {
      ll cost = pow10[i] * j, val = 0;
      if (j % 3 == 0) val = j / 3 * f[i];
      for (int k = int(maxn - 5); k >= (int)(cost); k--) {
        if (vis[k - cost]) {
          vis[k] = true;
          dp[k] = max(dp[k], pre[k - cost] + val);
        }
      }
    }
  }
  int q;
  cin >> q;
  while (q--) {
    int x;
    cin >> x;
    cout << dp[x] << '\n';
  }
  return 0;
}
