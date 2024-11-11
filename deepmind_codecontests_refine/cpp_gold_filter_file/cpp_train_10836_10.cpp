#include <bits/stdc++.h>
using namespace std;
#pragma GCC optimize("-O2")
const int LIM = 1e6 + 5, MOD = 998244353;
int t, n, m, k, x, y;
long long a[LIM];
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  cin >> n;
  for (int i = 1; i < n + 1; i++) cin >> a[i];
  long long sum = 0, val = 1;
  for (int i = n - 1; i >= 1; i--) {
    sum = (sum + (((n - i + 2) * val) % MOD) * a[i]) % MOD;
    val = (val * 2) % MOD;
  }
  sum = (sum + (a[n])) % MOD;
  cout << sum;
  return 0;
}
