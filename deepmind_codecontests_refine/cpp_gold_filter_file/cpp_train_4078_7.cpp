#include <bits/stdc++.h>
using namespace std;
long long mod = 998244353;
long long power(long long a, long long b) {
  if (!b) return 1ll;
  if (b == 1) return a % mod;
  long long r = power(a, b / 2ll) % mod;
  if (b % 2ll)
    return ((r * (a % mod) % mod) * r) % mod;
  else
    return (r * r) % mod;
}
int main() {
  int w, h;
  cin >> w >> h;
  cout << power(2, w) * power(2, h) % mod;
}
