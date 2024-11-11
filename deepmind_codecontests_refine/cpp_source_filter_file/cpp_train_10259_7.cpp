#include <bits/stdc++.h>
using namespace std;
const unsigned long long MOD = 1e9 + 7;
unsigned long long A, B;
unsigned long long f(unsigned long long xx) {
  return ((A * xx) % MOD + B) % MOD;
}
unsigned long long solve(unsigned long long n, unsigned long long curr) {
  if (n == 0) return curr;
  return f(solve(n - 1, curr) % MOD) % MOD;
}
unsigned long long mod_pow(unsigned long long b, unsigned long long e) {
  unsigned long long ans = 1;
  while (e) {
    if (e & 1) ans = (ans * b) % MOD;
    b = (b * b) % MOD;
    e >>= 1;
  }
  return ans;
}
int main() {
  ios_base::sync_with_stdio(false), cin.tie(0), cout.tie(0);
  unsigned long long x, n;
  cin >> A >> B >> n >> x;
  unsigned long long inter = mod_pow(A, n);
  unsigned long long aa = (inter * x) % MOD;
  unsigned long long bb = 0;
  if (A == 1)
    bb = n;
  else
    bb = ((((inter - 1LL) % MOD) + MOD) % MOD * mod_pow(A - 1, MOD - 2)) % MOD;
  bb *= B;
  bb %= MOD;
  cout << (aa + bb) % MOD << '\n';
  return 0;
}
