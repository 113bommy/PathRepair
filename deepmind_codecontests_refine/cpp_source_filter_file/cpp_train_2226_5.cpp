#include <bits/stdc++.h>
#pragma GCC optimize("Ofast")
using namespace std;
const long long MOD = 1e9 + 7;
long long pow(long long a, long long n) {
  long long re = 1;
  for (; n; n /= 2, a = a * a % MOD)
    if (n & 1) re = re * a % MOD;
  return re;
}
int main() {
  long long n, k, ans = 1, a[9] = {0, 0, 2, 9, 64, 625, 7776, 117649, 2097152};
  cin >> n >> k, ans = pow(n - k, n - k);
  cout << a[k] * ans % MOD << "\n";
}
