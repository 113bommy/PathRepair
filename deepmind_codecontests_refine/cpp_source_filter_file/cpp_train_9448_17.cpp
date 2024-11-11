#include <bits/stdc++.h>
using namespace std;
long long gcd(long long a, long long b) {
  if (b == 0) return a;
  return gcd(b, a % b);
}
long long power(long long first, unsigned long long second,
                unsigned long long m) {
  if (second == 0) return 1;
  long long p = power(first, second / 2, m) % m;
  p = (p * p) % m;
  return (second % 2 == 0) ? p : (first * p) % m;
}
long long modInverse(long long a, long long m) {
  { return power(a, m - 2, m); }
}
void __print(long long first) { cerr << first; }
void __print(float first) { cerr << first; }
void __print(double first) { cerr << first; }
void __print(long double first) { cerr << first; }
void __print(char first) { cerr << '\'' << first << '\''; }
void __print(const char *first) { cerr << '\"' << first << '\"'; }
void __print(const string &first) { cerr << '\"' << first << '\"'; }
void __print(bool first) { cerr << (first ? "true" : "false"); }
template <typename T, typename V>
void __print(const pair<T, V> &first) {
  cerr << '{';
  __print(first.fi);
  cerr << ',';
  __print(first.se);
  cerr << '}';
}
template <typename T>
void __print(const T &first) {
  long long f = 0;
  cerr << '{';
  for (auto &i : first) cerr << (f++ ? "," : ""), __print(i);
  cerr << "}";
}
void _print() { cerr << "]\n"; }
template <typename T, typename... V>
void _print(T t, V... v) {
  __print(t);
  if (sizeof...(v)) cerr << ", ";
  _print(v...);
}
void solve() {
  long long n, k;
  cin >> n >> k;
  long long dp[n + 1][k + 1];
  long long num = 0;
  long long a[n + 1];
  for (long long i = 1; i <= n; i++) cin >> a[i];
  for (long long i = 50; i >= 0; i--) {
    num |= (1LL << i);
    memset(dp, 0, sizeof dp);
    dp[0][0] = 1;
    for (long long kk = 1; kk <= k; kk++) {
      for (long long j = 1; j <= n; j++) {
        long long sum = 0;
        for (long long go = j; go > 0; go--) {
          sum += a[go];
          if ((sum & (num)) == num) {
            dp[j][kk] |= dp[go - 1][kk - 1];
          }
        }
      }
    }
    num ^= (!(dp[n][k])) * (1LL << i);
  }
  cout << num << "\n";
}
signed main() {
  ios_base ::sync_with_stdio(0);
  cin.tie(NULL);
  cout.tie(NULL);
  solve();
  return 0;
}
