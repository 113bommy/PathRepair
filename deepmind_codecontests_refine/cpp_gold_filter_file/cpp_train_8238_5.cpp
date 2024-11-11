#include <bits/stdc++.h>
using namespace std;
void swapp(long long &a, long long &b);
double fabss(double a);
long long maxx(long long a, long long b);
long long minn(long long a, long long b);
long long Del_bit_1(long long n);
long long lowbit(long long n);
long long abss(long long a);
const double E = 2.718281828;
const double PI = acos(-1.0);
const double ESP = 1e-6;
const long long inf = 0x7fffffff;
const long long N = 3e5 + 5;
const long long mod = 1e9 + 7;
long long a[N], dp[N][3];
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  ;
  long long n, k, i;
  cin >> n >> k;
  for (i = 1; i <= n; ++i) cin >> a[i];
  long long max_ = 0;
  for (i = 1; i <= n; ++i) {
    dp[i][0] = maxx(dp[i - 1][0] + a[i], a[i]);
    dp[i][1] =
        maxx(maxx(dp[i - 1][1] + a[i] * k, dp[i - 1][0] + a[i] * k), a[i] * k);
    dp[i][2] = maxx(maxx(dp[i - 1][1] + a[i], dp[i - 1][2] + a[i]), a[i]);
    max_ = maxx(max_, maxx(maxx(dp[i][0], dp[i][1]), dp[i][2]));
  }
  cout << max_ << endl;
  return 0;
}
long long maxx(long long a, long long b) { return a > b ? a : b; }
void swapp(long long &a, long long &b) {
  a ^= b;
  b ^= a;
  a ^= b;
}
long long lowbit(long long n) { return n & -n; }
long long Del_bit_1(long long n) { return n & n - 1; }
long long abss(long long a) { return a > 0 ? a : -a; }
double fabss(double a) { return a > 0 ? a : -a; }
long long minn(long long a, long long b) { return a < b ? a : b; }
