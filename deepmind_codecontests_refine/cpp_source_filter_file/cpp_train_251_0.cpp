#include <bits/stdc++.h>
using namespace std;
void _main();
int main() {
  cin.tie(0);
  ios::sync_with_stdio(false);
  _main();
}
int mod = 1000000007;
int add(int x, int y) { return (x += y) >= mod ? x - mod : x; }
template <class... T>
int add(int x, T... y) {
  return add(x, add(y...));
}
int mul(int x, int y) { return 1LL * x * y % mod; }
template <class... T>
int mul(int x, T... y) {
  return mul(x, mul(y...));
}
int sub(int x, int y) { return add(x, mod - y); }
int modpow(int a, long long b) {
  int ret = 1;
  while (b > 0) {
    if (b & 1) ret = 1LL * ret * a % mod;
    a = 1LL * a * a % mod;
    b >>= 1;
  }
  return ret;
}
int modinv(int a) { return modpow(a, mod - 2); }
int fac[201010], ifac[201010];
void initfac() {
  fac[0] = ifac[0] = 1;
  for (int i = 1; i < 201010; i++) fac[i] = 1LL * i * fac[i - 1] % mod;
  for (int i = 1; i < 201010; i++) ifac[i] = modinv(fac[i]);
}
int aPb(int a, int b) {
  if (b < 0 || a < b) return 0;
  return mul(fac[a], ifac[a - b]);
}
int aCb(int a, int b) {
  if (b < 0 || a < b) return 0;
  return mul(fac[a], ifac[a - b], ifac[b]);
}
int nHk(int n, int k) {
  if (n == 0 && k == 0) return 1;
  if (n <= 0 || k < 0) return 0;
  return aCb(n + k - 1, k);
}
int N;
int A[1 << 20];
void _main() {
  cin >> N;
  for (int i = 0; i < N; i++) {
    int x;
    cin >> x;
    A[x]++;
  }
  for (int i = 0; i < 20; i++)
    for (int j = 0; j < 1 << 20; j++)
      if (j & (1 << i)) A[j] = add(A[j], A[j | (1 << i)]);
  int ans = 0;
  for (int ma = 0; ma < 1 << 20; ma++) {
    if (__builtin_popcount(ma) % 2)
      ans = sub(ans, modpow(2, A[ma]));
    else
      ans = add(ans, modpow(2, A[ma]));
  }
  cout << ans << endl;
}
