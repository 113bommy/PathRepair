#include <bits/stdc++.h>
using namespace std;
const long long MOD = 1000000007;
long long POW(long long n, long long k) {
  if (k == 0) return 1;
  long long tmp = POW(n, k / 2);
  if (k % 2) return tmp * tmp % MOD * n % MOD;
  return tmp * tmp % MOD;
}
int main() {
  int m, n, k;
  cin >> m >> n >> k;
  if (k == 1 || (k == -1 && m % 2 == n % 2))
    cout << POW(POW(2, m - 1), n - 1);
  else
    cout << 0;
}
