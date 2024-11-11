#include <bits/stdc++.h>
using namespace std;
template <class c>
struct rge {
  c b, e;
};
template <class c>
rge<c> range(c i, c j) {
  return rge<c>{i, j};
}
template <class c>
auto dud(c *x) -> decltype(cerr << *x, 0);
template <class c>
char dud(...);
struct debug {
  ~debug() { cerr << '\n'; }
  template <class c>
  typename enable_if<sizeof dud<c>(0) != 1, debug &>::type operator<<(c i) {
    cerr << boolalpha << i;
    return *this;
  }
  template <class c>
  typename enable_if<sizeof dud<c>(0) == 1, debug &>::type operator<<(c i) {
    return *this << range(begin(i), end(i));
  }
  template <class c, class b>
  debug &operator<<(pair<b, c> d) {
    return *this << "(" << d.first << ", " << d.second << ")";
  }
  template <class c>
  debug &operator<<(rge<c> d) {
    *this << "[";
    for (auto it = d.b; it != d.e; ++it) *this << ", " + 2 * (it == d.b) << *it;
    return *this << "]";
  }
};
template <class T>
bool umin(T &a, T b) {
  return (a > b ? a = b, 1 : 0);
}
const long long inf = 1e18;
signed main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  ;
  int n, k;
  cin >> n >> k;
  vector<int> a(n);
  for (auto &z : a) cin >> z;
  sort(a.begin(), a.end());
  vector<vector<int>> dp(n + 1, vector<int>(k + 1, 0));
  vector<vector<int>> pref(n + 1, vector<int>(k + 1, 0));
  auto add = [&](int &x, int y) {
    x += y;
    if (x >= 998244353) x -= 998244353;
  };
  int sm = 0;
  int ans = 0;
  for (int x = 1e5 / (k - 1); x >= 0; x--) {
    int j = 0;
    int to = 0;
    for (int i = 0; i < n; i++) {
      for (int t = 1; t <= k; t++) {
        dp[i][t] = 0;
        pref[i][t] = 0;
      }
      dp[i][1] = 1;
      while (j + 1 < i && abs(a[j + 1] - a[i]) >= x) j++;
      for (int t = 1; t < k; t++) {
        if (abs(a[i] - a[j]) >= x) add(dp[i][t + 1], pref[j][t]);
      }
      if (i) pref[i] = pref[i - 1];
      for (int t = 1; t <= k; t++) {
        add(pref[i][t], dp[i][t]);
      }
      add(to, dp[i][k]);
    }
    to = (to - sm + 998244353) % 998244353;
    add(ans, (1ll * to * x) % 998244353);
    add(sm, to);
  }
  cout << ans;
  return 0;
}
