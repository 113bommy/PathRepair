#include <bits/stdc++.h>
using namespace std;
const long long MOD = 1e9 + 7;
long long pow(long long &k) {
  long long result = 1;
  for (int i = 0; i < k; ++i) {
    result *= 2;
  }
  return result;
}
int main() {
  long long n, huz, seven;
  cin >> n;
  long long a[n + 1];
  a[1] = 20;
  seven = 7;
  for (int i = 2; i <= n; ++i) {
    huz = a[i - 1];
    huz = ((huz * 7) % MOD + (((huz + seven) % MOD) * 20) % MOD) % MOD;
    seven = (seven * 7) % MOD;
    a[i] = huz;
  }
  cout << a[n];
  return 0;
}
