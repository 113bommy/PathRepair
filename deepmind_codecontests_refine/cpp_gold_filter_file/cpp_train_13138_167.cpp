#include <bits/stdc++.h>
#pragma GCC optimize(2)
using namespace std;
const int inf = 0x3f3f3f3f;
const int MOD = 1e9 + 7;
const double eps = 1e-4;
const double pi = acos(-1.0);
void debug() { cerr << '\n'; }
template <typename T, typename... Ts>
void debug(T x, Ts... y) {
  cerr << "\033[31m" << x << "\033[0m";
  if (sizeof...(y) > 0) cerr << ' ';
  debug(y...);
}
template <typename T>
void debug(const T &a, int l, int r, char c) {
  for (int i = l; i <= r; ++i)
    cerr << "\033[31m" << a[i] << "\033[0m" << (i == r ? '\n' : c);
}
template <typename T>
void debug(vector<T> a) {
  for (int i = 0; i < (int)a.size(); ++i)
    cerr << "\033[31m" << a[i] << "\033[31m"
         << " \n"[i == ((int)a.size() - 1)];
}
long long gcd(long long a, long long b) { return b == 0 ? a : gcd(b, a % b); }
long long lcm(long long a, long long b) { return a / gcd(a, b) * b; }
long long qpow(long long x, long long y) {
  long long ans = 1;
  for (; y > 0; y >>= 1) {
    if (y & 1) ans *= x;
    x *= x;
  }
  return ans;
}
long long qpow(long long x, long long y, int MOD) {
  long long ans = 1;
  for (; y > 0; y >>= 1) {
    if (y & 1) ans = ans * x % MOD;
    x = x * x % MOD;
  }
  return ans;
}
void exgcd(long long a, long long b, long long &x, long long &y) {
  if (!b) {
    x = 1;
    y = 0;
    return;
  }
  exgcd(b, a % b, x, y);
  long long X = x;
  x = y;
  y = X - a / b * y;
}
long long inv(long long x, int mod = MOD) { return qpow(x, mod - 2, mod); }
long long m_m(long long a, int mod = MOD) { return (a % mod + mod) % mod; }
int pre[1000005];
map<int, int> mp;
signed main() {
  ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
  string s;
  cin >> s;
  int n = s.size();
  for (int i = (2); i < (n + 1); ++i) {
    int j = pre[i - 1];
    while (j > 0 && s[i - 1] != s[j]) j = pre[j];
    if (s[i - 1] == s[j]) ++j;
    pre[i] = j;
  }
  for (int i = (2); i < (n); ++i) mp[pre[i]] = 1;
  int x = pre[n];
  while (x) {
    if (mp[x]) {
      for (int i = (0); i < (x); ++i) cout << s[i];
      return 0;
    }
    x = pre[x];
  }
  cout << "Just a legend";
  return 0;
}
