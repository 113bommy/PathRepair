#include <bits/stdc++.h>
using namespace std;
long long n, m;
long long mod = 1000000007;
inline long long saam(long long s, long long e, long long n) {
  s %= mod * 2;
  e %= mod * 2;
  n %= mod * 2;
  return (((s + e) * n) % (2 * mod)) / 2;
}
int main() {
  cin.sync_with_stdio(false);
  cout.sync_with_stdio(false);
  cin.tie(0);
  cin >> n >> m;
  long long _m = m;
  int s = 1;
  long long sol = 0;
  if (m > n) {
    sol = ((((m % mod) - (n % mod)) * (n % mod)) % mod + mod) % mod;
    m = n;
  }
  while (n / s > m && s <= 3200000) {
    s++;
  }
  s--;
  long long curr = m;
  for (; s <= 3200000 && curr != 0; s++) {
    sol += saam(n % curr, n % (n / (s + 1) + 1), curr - n / (s + 1));
    curr = n / (s + 1);
    if (sol > mod) sol -= mod;
  }
  for (; curr > 0; curr--) {
    sol += n % curr;
  }
  sol %= mod;
  cout << sol << endl;
}
