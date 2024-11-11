#include <bits/stdc++.h>
using namespace std;
const long long mod = 1e9 + 7;
long long n, m;
long long fpow(long long a, long long b, long long mod) {
  if (b == 1) return a;
  long long x = fpow(a, b / 2, mod) % mod;
  if (b & 1)
    return (x * x % mod) * a % mod;
  else
    return x * x % mod;
}
int main() {
  cin >> n >> m;
  cout << fpow(fpow(2, m, mod) - 1, n, mod) << endl;
  return 0;
}
