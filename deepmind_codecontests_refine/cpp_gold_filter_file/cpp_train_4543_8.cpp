#include <bits/stdc++.h>
using namespace std;
long long n, m, k, mod = 1e9 + 7;
long long power(long long x, long long n) {
  if (n == 0) return 1;
  long long p = power(x, n / 2);
  p = (p * p) % mod;
  if (n % 2) return (p * x) % mod;
  return p;
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cin >> n >> m >> k;
  if ((n ^ m) & 1 && k == -1)
    cout << "0";
  else
    cout << power(power(2, m - 1), n - 1);
}
