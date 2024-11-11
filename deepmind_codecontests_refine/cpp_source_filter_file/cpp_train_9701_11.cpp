#include <bits/stdc++.h>
#pragma GCC optimize("Ofast,unroll-loops")
#pragma GCC target("avx,avx2,sse,sse2")
using namespace std;
const double pi = 3.141592653589793238460;
template <typename T, typename T1>
T ama(T& a, T1 b) {
  if (b > a) a = b;
  return a;
}
template <typename T, typename T1>
T amm(T& a, T1 b) {
  if (b < a) a = b;
  return a;
}
template <typename Arg1>
void __f(const char* name, Arg1&& arg1) {
  cout << name << " : " << arg1 << endl;
}
template <typename Arg1, typename... Args>
void __f(const char* names, Arg1&& arg1, Args&&... args) {
  const char* comma = strchr(names + 1, ',');
  cout.write(names, comma - names) << " : " << arg1 << " | ";
  __f(comma + 1, args...);
}
const long long N = 3e5 + 5;
long long dx[4] = {0, 0, +1, -1};
long long dy[4] = {+1, -1, 0, 0};
void fun() {
  long long n;
  cin >> n;
  long long k;
  cin >> k;
  ;
  string s;
  cin >> s;
  ;
  vector<long long> a(n + 5, n), dp(n + 5, 1e18);
  for (long long i = n - 1; i >= 0; i--) {
    if (s[i] == '1') {
      a[i] = i;
    } else {
      a[i] = a[i + 1];
    }
  }
  dp[0] = 0;
  for (int i = 0; i < (n + 1); i++) {
    if (i) amm(dp[i], dp[i - 1] + i);
    long long p = a[max(i - k - 1, 0ll)];
    if (p - k < i) {
      amm(dp[i], dp[max(p - k, 0ll)] + p + 1);
    }
  }
  cout << dp[n] << '\n';
}
int32_t main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  long long t = 1;
  while (t--) {
    fun();
  }
  return 0;
}
