#include <bits/stdc++.h>
using namespace std;
long long dx[] = {1, -1, 0, 0};
long long dy[] = {0, 0, 1, -1};
const long long sz = 3e5 + 5, mod = 1e9 + 7;
long long t, n, m, k;
string s;
long long const mask = 1LL << 19;
long long dp[2][mask];
const long long lim = 1e18;
const long long inf = 1e15;
long long Power(long long a, long long b) {
  if (a == 0) return 0;
  if (b == 0) return 1;
  long long ans = Power((a * a) % mod, b / 2);
  if (b & 1) return (a * ans) % mod;
  return ans % mod;
}
long long Inv(long long a) { return Power(a, mod - 2); }
long long a;
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  ;
  cin >> n >> m;
  long long x = n - m;
  if (x < 0) {
    cout << 0;
    return 0;
  }
  if (x & 1) {
    cout << 0;
    return 0;
  }
  x = x / 2;
  if (x & m) {
    cout << 0;
    return 0;
  }
  long long tot = 0;
  long long sum = 0;
  long long i = 0;
  long long ans = 1;
  while (1) {
    if ((x & (1LL << i)) == 0 && (m & (1LL << i))) sum += (1LL << i);
    if ((x & (1LL << i))) sum += (1LL << (i + 1));
    if (sum > n) break;
    if ((x & (1LL << i)) == 0 && (m & (1LL << i))) ans *= 2;
    i++;
    if ((1LL << i) > n) break;
  }
  if (x == 0) ans -= 2;
  cout << ans;
  return 0;
}
