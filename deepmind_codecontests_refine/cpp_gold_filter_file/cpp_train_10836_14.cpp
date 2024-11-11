#include <bits/stdc++.h>
using namespace std;
const long long N = 100000 + 5, mod = 998244353;
long long fp(long long base, long long exp) {
  if (exp == 0) return 1;
  long long ans = fp(base, exp / 2);
  ans = (ans * ans) % mod;
  if (exp % 2 != 0) ans = (ans * (base % mod)) % mod;
  return ans;
}
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  int n;
  cin >> n;
  int power = n - 1;
  long long ans = 0;
  for (int i = 0; i < n; i++) {
    long long x;
    cin >> x;
    long long op = fp(2, power);
    if (power) op = (op + ((fp(2, power - 1) * (n - i - 1)) % mod)) % mod;
    ans = (ans + ((op * x) % mod)) % mod;
    power--;
  }
  cout << ans;
  return 0;
}
