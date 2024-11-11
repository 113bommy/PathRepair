#include <bits/stdc++.h>
using namespace std;
const long long int MOD = 1e9 + 7;
const int maxn = 200005;
long long int bpow(long long int a, long long int p) {
  long long int ans = 1;
  bitset<65> bit(p);
  for (int i = 0; i < (int)65; i++) {
    if (bit[i]) ans *= a;
    a *= a;
    a %= MOD;
    ans %= MOD;
  }
  return ans;
}
int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  long long int n;
  cin >> n;
  cout << (6 * bpow(4ll, bpow(2ll, n) - 2)) % MOD << endl;
  return 0;
}
