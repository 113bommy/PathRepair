#include <bits/stdc++.h>
using namespace std;
const long long mod = 1e9 + 7;
long long solve(long long x) {
  long long c = 1, k = 0;
  long long count[2] = {0, 0};
  while (x) {
    count[k] += min(c, x);
    x -= min(c, x);
    k ^= 1;
    c <<= 1;
  }
  long long res = 0;
  res += (count[0] % mod) * (count[0] % mod) % mod;
  res += (count[1] % mod) * ((count[1] + 1) % mod) % mod;
  return res % mod;
}
int main() {
  long long l, r;
  cin >> l >> r;
  cout << (solve(r) - solve(l - 1) + mod) % mod << endl;
}
