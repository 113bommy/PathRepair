#include <bits/stdc++.h>
using namespace std;
using namespace chrono;
void read(vector<int> &a) {
  for (auto &x : a) cin >> x;
}
void read(vector<int64_t> &a) {
  for (auto &x : a) cin >> x;
}
mt19937_64 rng(chrono::steady_clock::now().time_since_epoch().count());
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
  template <class c>
  debug &operator<<(const c &) {
    return *this;
  }
};
const int MOD = 1e9 + 7;
const int INF = (int)2e9 + 7;
const int64_t LINF = (int64_t)1e18;
const long double PI = 3.1415926535897932384626433832795;
vector<int> z_function(string s) {
  int n = (int)s.length();
  vector<int> z(n);
  for (int i = 1, l = 0, r = 0; i < n; ++i) {
    if (i <= r) z[i] = min(r - i + 1, z[i - l]);
    while (i + z[i] < n && s[z[i]] == s[i + z[i]]) ++z[i];
    if (i + z[i] - 1 > r) l = i, r = i + z[i] - 1;
  }
  debug() << z;
  return z;
}
void solve() {
  string s, t;
  cin >> s >> t;
  int n = s.size(), m = t.size();
  int zero = 0, one = 0;
  for (char c : s) {
    if (c == '0') zero++;
  }
  one = n - zero;
  int j = 0;
  for (int i = 1; i < m; i++) {
    if (t[i] == t[j]) {
      j++;
    } else {
      j = 0;
    }
  }
  vector<int> z = z_function(t);
  int mx = 0;
  for (int i = m - 1; i >= 0; i--) {
    if (z[i] == m - i) {
      mx = max(z[i], mx);
    }
  }
  debug() << mx;
  string add = "";
  if (mx == 0)
    add = t;
  else {
    for (int k = mx; k < m; k++) {
      add += t[k];
      debug() << add;
    }
  }
  debug() << add;
  string res = t;
  while ((int)res.size() < n) {
    res += add;
  }
  for (int i = 0; i < res.size(); i++) {
    if (res[i] == '0' && zero) {
      zero--;
      cout << 0;
    } else if (res[i] == '1' && one) {
      cout << 1;
      one--;
    }
  }
  while (one--) {
    cout << 1;
  }
  while (zero--) {
    cout << 0;
  }
}
int32_t main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  int test_cases = 1;
  auto t1 = high_resolution_clock::now();
  for (int tt = 1; tt <= test_cases; tt++) {
    solve();
  }
  auto t2 = high_resolution_clock::now();
  auto time = duration_cast<duration<double>>(t2 - t1);
  cerr << "Time elapsed = " << time.count() << "\n";
}
