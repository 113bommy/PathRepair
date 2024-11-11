#include <bits/stdc++.h>
using namespace std;
const double pi = acos(-1.0);
const double eps = 1e-11;
const int inf = 0x7FFFFFFF;
template <class T>
inline void checkmin(T &a, T b) {
  if (b < a) a = b;
}
template <class T>
inline void checkmax(T &a, T b) {
  if (b > a) a = b;
}
template <class T>
inline T sqr(T x) {
  return x * x;
}
template <class T>
void show(T a, int n) {
  for (int i = 0; i < n; ++i) cout << a[i] << ' ';
  cout << endl;
}
template <class T>
void show(T a, int r, int l) {
  for (int i = 0; i < r; ++i) show(a[i], l);
  cout << endl;
}
long long dp[1000005][2];
const long long mod = 1000000007;
int main() {
  int n;
  while (cin >> n) {
    for (int i = 1; i <= n; i++) {
      if (i & 1) {
        dp[i][0] = dp[i - 1][0] % mod;
        dp[i][1] = (dp[i - 1][1] + dp[i - 1][0] + 1) % mod;
      } else {
        dp[i][1] = dp[i - 1][1] % mod;
        dp[i][0] = (dp[i - 1][1] + dp[i - 1][0] + 1) % mod;
      }
    }
    cout << (dp[n][0] + dp[n][1]) % mod << endl;
  }
  return 0;
}
