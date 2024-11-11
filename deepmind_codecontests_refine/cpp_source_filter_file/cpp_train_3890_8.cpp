#include <bits/stdc++.h>
using namespace std;
long long powermod(long long base, long long power, long long mod) {
  if (power == 1) {
    return base % mod;
  }
  if (power == 0) {
    return 1 % mod;
  }
  long long shortoutput;
  if (power % 2 == 0) {
    shortoutput = powermod((base % mod) * (base % mod) % mod, power / 2, mod);
    return shortoutput % mod;
  } else {
    shortoutput =
        powermod((base % mod) * (base % mod) % mod, (power - 1) / 2, mod);
    return ((base % mod) * (shortoutput % mod)) % mod;
  }
}
void solve() {
  long long n, m;
  cin >> n >> m;
  long long ans = powermod(3, n, m);
  cout << (ans % m - (1 % m)) % m << endl;
}
int main() {
  ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
  int t = 1;
  while (t--) solve();
}
