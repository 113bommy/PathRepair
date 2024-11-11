#include <bits/stdc++.h>
using namespace std;
const long long int lg = 22;
const long long int N = 1e5 + 5;
const long long int M = 162;
const long long int INF = 1e9 + 5;
const long long int mod = 1e9 + 7;
const double PI = 3.14159265358979323846;
template <typename T>
T power(T x, T y) {
  T ans = 1;
  while (y > 0) {
    if (y & 1LL) ans = (ans * x) % mod;
    y >>= 1LL;
    x = (x * x) % mod;
  }
  return ans % mod;
}
inline long long int mul(long long int a, long long int b) {
  return (a * 1ll * b) % mod;
}
inline long long int sub(long long int a, long long int b) {
  long long int c = a - b;
  if (c < 0) c += mod;
  return c;
}
inline long long int add(long long int a, long long int b) {
  long long int c = a + b;
  if (c > mod) c -= mod;
  return c;
}
inline long long int inv(long long int a) { return power(a, mod - 2); }
template <typename Arg1>
void __f(const char* name, Arg1&& arg1) {
  cerr << name << " : " << arg1 << '\n';
}
template <typename Arg1, typename... Args>
void __f(const char* names, Arg1&& arg1, Args&&... args) {
  const char* comma = strchr(names + 1, ',');
  cerr.write(names, comma - names) << " : " << arg1 << " | ";
  __f(comma + 1, args...);
}
int n;
string r;
int powx[705], dp[705][2][11][705];
int Get(int idx, int val, int checker) {
  int valatIdx = r[idx] - '0';
  if (checker) {
    if (val > valatIdx) {
      return -1;
    }
    if (val == valatIdx) {
      return 1;
    }
    return 0;
  } else {
    return 0;
  }
}
int F(int idx, int checker, int dig, int pos) {
  int res = 0;
  if (idx == n) {
    return pos == 0;
  }
  if (dp[idx][checker][dig][pos] != -1) {
    return dp[idx][checker][dig][pos];
  }
  for (int i = 0; i <= 9; i++) {
    int newchecker = Get(idx, i, checker);
    if (newchecker == -1) {
      continue;
    }
    res = add(res, F(idx + 1, newchecker, dig, max(0, pos - (i >= dig))));
  }
  return dp[idx][checker][dig][pos] = res;
}
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  ;
  cin >> r;
  int res = 0;
  memset(dp, -1, sizeof(dp));
  n = r.length();
  powx[n - 1] = 1;
  for (int i = n - 2; i >= 0; i--) {
    powx[i] = mul(powx[i + 1], 10);
  }
  for (int i = 1; i <= n; i++) {
    for (int j = 0; j <= 9; j++) {
      int cnt = F(0, 1, j, n - i + 1) - F(0, 1, j + 1, n - i + 1);
      res = add(res, mul(mul(powx[i - 1], j), cnt));
    }
  }
  cout << res << endl;
}
