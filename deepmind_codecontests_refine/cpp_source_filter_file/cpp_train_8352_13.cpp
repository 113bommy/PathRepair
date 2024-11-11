#include <bits/stdc++.h>
using namespace std;
template <class T>
bool umin(T& a, const T& b) {
  return a > b ? a = b, true : false;
}
template <class T>
bool umax(T& a, const T& b) {
  return a < b ? a = b, true : false;
}
template <long long sz>
using tut = array<long long, sz>;
void usaco(string s) {
  freopen((s + ".in").c_str(), "r", stdin);
  freopen((s + ".out").c_str(), "w", stdout);
  ios::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
}
const long long N = 2e5 + 5;
const long long mod = (119 << 23) + 1;
const long long inf = LLONG_MAX;
const long double Pi = acos(-1);
void add(long long& a, long long b, long long mod = ::mod) {
  a = (a + b) % mod;
}
void sub(long long& a, long long b, long long mod = ::mod) {
  a = ((a - b) % mod + mod) % mod;
}
void mul(long long& a, long long b, long long mod = ::mod) {
  a = (a * 1ll * b) % mod;
}
long long n, m, k, t, q, ans, res, a[N];
long long rr[N];
void solve(long long t_case) {
  cin >> n >> k;
  for (long long i = 1; i <= n; i++) {
    cin >> a[i];
  }
  auto check2 = [&](long long b, long long a) -> long long {
    return (a - 3ll * b * b + 3ll * b - 1);
  };
  auto check = [&](long long mm) -> bool {
    long long cnt = 0;
    for (long long i = 1; i <= n; i++) {
      long long l = 0, r = a[i];
      while (l < r) {
        long long m = (l + r + 1) >> 1;
        if (check2(m, a[i]) >= mm)
          l = m;
        else
          r = m - 1;
      }
      rr[i] = l;
      cnt += l;
    }
    return (cnt >= k);
  };
  long long l = -inf, r = inf;
  while (l < r) {
    long long m = (l + r + 1) >> 1;
    if (check(m))
      l = m;
    else
      r = m - 1;
  }
  check(l);
  long long cnt = 0;
  for (long long i = 1; i <= n; i++) cnt += rr[i];
  cnt -= k;
  for (long long i = 1; i <= n && cnt; i++) {
    if (rr[i] && check2(rr[i] - 1, a[i]) >= l) cnt--, rr[i]--;
  }
  for (long long i = 1; i <= n; i++) cout << rr[i] << " ";
  cout << "\n";
}
signed main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  if (0) {
    long long t;
    cin >> t;
    for (long long t_case = 1; t_case <= t; t_case++) solve(t_case);
  } else
    solve(1);
  return 0;
}
