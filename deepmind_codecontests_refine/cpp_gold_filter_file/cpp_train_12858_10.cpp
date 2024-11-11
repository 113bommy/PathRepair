#include <bits/stdc++.h>
using namespace std;
const int MM = 1200000;
const long long int mod = 1e9 + 7;
long long int m, n, k, p1, p2, p3, p, f, a[MM];
string s, s1, s2;
const long long int i2 = 500000004;
long long int solve(long long int st, long long int en) {
  if (st == en) {
    return (n % st) % mod;
  }
  if (st > en) {
    return 0;
  }
  long long int cur = n / st;
  long long int las = min(n / (cur), en);
  if (las < st) {
    las++;
  }
  if (las == en) {
    las--;
  }
  long long int cnt = las - st + 1;
  cnt %= mod;
  cur %= mod;
  long long int ans = ((i2 * cnt) % mod) *
                      ((2 * (n % st) - ((cnt - 1) * cur) % mod + mod) % mod);
  return (ans + solve(las + 1, en)) % mod;
}
void solve2(long long int n, long long int m) {
  long long int ans = 0;
  for (long long int i = 1; i <= min((long long int)1e7, n - 1); i++) {
    ans = (ans + (n % i)) % mod;
  }
  long long int ans1 = ans + solve(1e7 + 1, n - 1);
  ans1 = (ans1 + ((n % mod) * ((m - n) % mod + mod)) % mod) % mod;
  cout << ans1;
}
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  cin >> n >> m;
  if (n < m) {
    solve2(n, m);
    return 0;
  }
  long long int ans = 0;
  for (long long int i = 1; i <= min((long long int)1e7, m); i++) {
    ans = (ans + (n % i)) % mod;
  }
  cout << (ans + solve(1e7 + 1, m)) % mod;
  return 0;
}
