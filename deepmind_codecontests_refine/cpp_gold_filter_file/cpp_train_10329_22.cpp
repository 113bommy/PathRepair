#include <bits/stdc++.h>
using namespace std;
void solve() {
  long long n, mod;
  cin >> n >> mod;
  long long fact[n + 1], i, ans = 0;
  fact[1] = fact[0] = 1;
  for (i = 2; i <= n; i++) fact[i] = (fact[i - 1] * i) % mod;
  for (i = 1; i <= n; i++) {
    ans = (ans +
           (fact[i] * ((n - i + 1) * (fact[n - i + 1]) % mod) % mod) % mod) %
          mod;
  }
  cout << ans << endl;
}
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(NULL);
  long long t = 1;
  while (t--) {
    solve();
  }
  return 0;
}
