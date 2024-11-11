#include <bits/stdc++.h>
using namespace std;
int64_t mod = 998244353;
int64_t mod1 = 1e9 + 5;
int64_t power(int64_t a, int64_t b) {
  if (b == 0)
    return 1;
  else if (b % 2 == 0)
    return power(((((a) % mod) * ((a) % mod)) % mod), b / 2) % mod;
  else
    return (((a) % mod) *
            (power(((((a) % mod) * ((a) % mod)) % mod), b / 2) % mod)) %
           mod;
}
inline int64_t inverse(int64_t a, int64_t md) {
  a %= md;
  if (a < 0) a += md;
  int64_t b = md, u = 0, v = 1;
  while (a) {
    int64_t t = b / a;
    b -= t * a;
    swap(a, b);
    u -= t * v;
    swap(u, v);
  }
  assert(b == 1);
  if (u < 0) u += md;
  return u;
}
const int64_t ce = 1e9 + 7;
int64_t fast_mod(int64_t input) { return input < ce ? input : input % ce; }
int32_t main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  int64_t n;
  cin >> n;
  string s;
  cin >> s;
  vector<pair<int64_t, int64_t>> v;
  int64_t f = -1, c = 0, p = 0;
  for (int64_t i = 0; i < s.length(); i++) {
    if (s[i] == '?') {
      p++;
      c++;
    } else {
      if (f == -1) {
        p = 0;
        f = s[i] - '0';
        c++;
        continue;
      }
      if (f == s[i] - '0') {
        p = 0;
        c++;
        continue;
      }
      if (f != s[i] - '0') {
        v.push_back({c, p});
        p = 0;
        f = s[i] - '0';
        c = 1;
      }
    }
  }
  v.push_back({c, p});
  v.push_back({n, 0});
  int64_t ans[n + 1];
  memset(ans, 0, sizeof(ans));
  int64_t rem[n + 1];
  memset(rem, 0, sizeof(rem));
  for (int64_t i = 0; i < (int64_t)v.size() - 1; i++) {
    for (int64_t j = 1; j <= min(30 * (v[i].first + v[i + 1].first), n); j++) {
      ans[j] += (v[i].first + rem[j]) / j;
      rem[j] = min((v[i].first + rem[j]) % j, v[i].second);
    }
  }
  for (int64_t i = 1; i <= n; i++) {
    cout << ans[i] << " ";
  }
}
