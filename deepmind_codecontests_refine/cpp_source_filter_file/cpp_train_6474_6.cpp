#include <bits/stdc++.h>
using namespace std;
const int xd = 1e6;
const long long mod = 1e9 + 7;
double dot(complex<double> a, complex<double> b) {
  return (conj(a) * b).real();
}
double cross(complex<double> a, complex<double> b) {
  return (conj(a) * b).imag();
}
long long fp(long long base, long long exp) {
  if (exp == 0) return 1;
  long long ans = fp(base, exp / 2);
  ans = (ans * ans) % mod;
  if (exp % 2 != 0) ans = (ans * (base % mod)) % mod;
  return ans;
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  long long n, m, ans;
  cin >> n >> m;
  ans = fp(fp(2, m), n) % mod;
  cout << ans;
  return 0;
}
