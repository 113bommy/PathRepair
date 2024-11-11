#include <bits/stdc++.h>
using namespace std;
long long n, m;
long long mod_pow(long long base, long long exp, long long mod) {
  if (exp == 0)
    return 1;
  else if (exp == 1)
    return base % mod;
  if (exp % 2 != 0) return (mod_pow(base, exp - 1, mod) * base) % mod;
  long long rt = mod_pow(base, exp >> 1, mod);
  return (rt * rt) % mod;
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cin >> n >> m;
  long long res = mod_pow(3, n, m);
  res--;
  if (res < 0) res += m;
  cout << res << "\n";
  return 0;
}
