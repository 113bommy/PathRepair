#include <bits/stdc++.h>
using namespace std;
const int mod = 998244353;
int fact[200005], ifact[200005];
int powmod(int b, int p) {
  int ans = 1;
  while (p) {
    if (p & 1) {
      ans = (1ll * ans * b) % mod;
    }
    p >>= 1;
    b = (1ll * b * b) % mod;
  }
  return ans;
}
void pre() {
  fact[0] = 1;
  ifact[0] = 1;
  for (int i = 1; i < 200005; i++) {
    fact[i] = (1ll * fact[i - 1] * i) % mod;
    ifact[i] = powmod(fact[i], mod - 2);
  }
}
int ncr(int n, int r) {
  int ans = (1ll * fact[n] * ifact[r]) % mod;
  return (1ll * ans * ifact[n - r]) % mod;
}
int main() {
  pre();
  int n, k;
  cin >> n >> k;
  vector<int> a(n);
  for (int i = 0; i < n; i++) {
    cin >> a[i];
  }
  int la = 0, cmp = 0;
  for (int i = 1; i < n; i++) {
    if (a[i] != a[la]) {
      cmp++;
      la = i;
    }
  }
  if (a.back() != a[0]) {
    cmp++;
  }
  int ans = 0;
  for (int p = 0; p <= cmp; p++) {
    int val = ncr(cmp, p);
    if (p) {
      if (k >= 2) {
        val = (1ll * val * powmod(k - 2, p)) % mod;
      } else {
        val = 0;
      }
    }
    int cur;
    if ((cmp - p) & 1) {
      cur = powmod(2, cmp - p - 1);
    } else {
      cur = powmod(2, cmp - p) - ncr(cmp - p, (cmp - p) / 2);
      if (cur < 0) cur += mod;
      cur = (1ll * cur * ifact[2]) % mod;
    }
    ans = (ans + 1ll * val * cur) % mod;
  }
  cout << (1ll * ans * powmod(k, n - cmp)) % mod << endl;
  return 0;
}
