#include <bits/stdc++.h>
using namespace std;
const int MOD = 1000000007;
using ll = long long;
int main() {
  ll n, m, k;
  cin >> n >> m >> k;
  ll res = 1;
  if (k == 1 || k > n)
    for (int i = 0; i < n; i++) res = (res * m) % MOD;
  else if (k == n)
    for (int i = 0; i < (n + 1) / 2; i++) res = (res * m) % MOD;
  else if (m % 2)
    res = ((m % MOD) * (m % MOD)) % MOD;
  else
    res = m;
  cout << res;
  return 0;
}
