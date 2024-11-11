#include <bits/stdc++.h>
using namespace std;
int logpow(int a, int b, int mod) {
  int ans = 1;
  while (b) {
    if (b & 1) ans = 1ll * ans * a % mod;
    a = 1ll * a * a % mod;
    b /= 2;
  }
  return ans;
}
long long a, b, p, x, ans;
int main() {
  cin >> a >> b >> p >> x;
  for (int i = 1; i < p; i++) {
    long long inv = (b * logpow(a, p - i - 1, p)) % p;
    int d = (inv - i + p) % p;
    d = (p - d) % p;
    int meh = i + d * (p - 1);
    if (meh <= x) ans += 1 + (x - meh) / (p * (p - 1));
  }
  cout << ans;
  return 0;
}
