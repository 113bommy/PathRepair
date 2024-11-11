#include <bits/stdc++.h>
#pragma GCC optimize("O3")
using namespace std;
const double EPS = 1e-9;
const int N = 2e3 + 9;
long long n, x, mod = 1e9 + 7, mem[505][500 * 30 + 9];
map<long long, long long> m;
long long dp(int i, int c) {
  if (c == 0) return 1;
  if (i > n) return 0;
  long long& ret = mem[i][c];
  if (~ret) return ret;
  ret = dp(i + 1, c) % mod;
  ret += dp(i, c - 1) % mod;
  ret %= mod;
  return ret;
}
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cin >> n;
  for (int i = 1; i <= n; i++) {
    cin >> x;
    for (long long j = 2; j * j <= x; j++) {
      while (x % j == 0) {
        m[j]++;
        x /= j;
      }
    }
    if (x > 1) m[x]++;
  }
  memset(mem, -1, sizeof mem);
  long long ans = 1;
  for (auto p : m) {
    ans *= dp(1, p.second);
    ans %= mod;
  }
  cout << (ans + mod + mod) % mod;
  return 0;
}
