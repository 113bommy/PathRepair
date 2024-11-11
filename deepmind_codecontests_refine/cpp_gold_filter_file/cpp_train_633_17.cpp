#include <bits/stdc++.h>
using namespace std;
long long mod = 1e9 + 7;
long long power(long long first, long long n) {
  if (n == 0) return 1;
  if (n % 2)
    return (first % mod * power((first % mod * first % mod) % mod, n / 2) %
            mod) %
           mod;
  return power((first % mod * first % mod) % mod, n / 2) % mod;
}
void solve() {
  long long n, ans = 0;
  cin >> n;
  for (long long i = 2; i <= n; i++)
    for (long long j = i + i; j <= n; j += i) ans += 4 * (j / i);
  cout << ans;
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  long long t = 1;
  while (t--) {
    solve();
  }
  return 0;
}
