#include <bits/stdc++.h>
const long long mod = 1e9 + 7;
using namespace std;
int main() {
  long long m, n;
  cin >> n >> m;
  long long temp = 1, sum = m * 2 % mod;
  for (int i = 2; i <= n; i++) {
    temp = temp * m % mod;
    sum = (sum * (2 * m - 1) % mod + temp + mod) % mod;
  }
  cout << sum << endl;
  return 0;
}
