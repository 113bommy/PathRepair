#include <bits/stdc++.h>
using namespace std;
const double PI = acos(-1);
template <typename T>
void chmin(T &x, const T &y) {
  if (x > y) x = y;
}
template <typename T>
void chmax(T &x, const T &y) {
  if (x < y) x = y;
}
template <typename T>
T gcd(T x, T y) {
  return y ? gcd(y, x % y) : x;
}
const int mod = 998244353;
template <typename T>
void Mod(T &x) {
  while (x >= mod) x -= mod;
}
long long qk(long long x, long long y) {
  long long r = 1;
  for (; y; y >>= 1) {
    if (y & 1) r = (r * x) % mod;
    x = (x * x) % mod;
  }
  return r;
}
map<int, vector<int>> dps;
int cal(int a, int b, int c, int d) {
  int x = d + b - a;
  if (x < 0) return 0;
  int k = d + c;
  chmin(x, k);
  if (dps.count(k)) return dps[k][x];
  auto &dp = dps[k];
  dp.resize(k + 1);
  int t = 0, w = 1;
  for (int i = 0; i <= k; ++i) {
    Mod(t += w);
    dp[i] = t;
    w = (long long)w * (k - i) % mod;
    w = (long long)w * qk(i + 1, mod - 2);
  }
  return dp[x];
}
void solve(int times) {
  string s;
  cin >> s;
  int n = s.length();
  int a = 0, b = 0, c = 0, d = 0;
  for (int i = 0; i < n; ++i) {
    if (s[i] == ')')
      ++b;
    else if (s[i] == '?')
      ++d;
  }
  long long ans = 0;
  for (int i = 0; i < n; ++i) {
    if (s[i] == '(') {
      ++a;
    } else if (s[i] == '?') {
      ++c;
      --d;
    } else if (s[i] == ')') {
      --b;
    }
    if (s[i] == '(') {
      Mod(ans += cal(a, b, c, d));
    } else if (s[i] == '?') {
      ++a;
      --c;
      Mod(ans += cal(a, b, c, d));
      ++c;
      --a;
    }
  }
  cout << ans << endl;
}
void Init() {}
int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  int times = 1;
  {
    solve(times++);
    Init();
  }
  return 0;
}
