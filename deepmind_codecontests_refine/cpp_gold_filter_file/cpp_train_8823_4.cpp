#include <bits/stdc++.h>
using namespace std;
const int N = 1e4 + 7;
const int32_t mod = 1e9 + 7;
template <class T>
inline void smax(T &x, T y) {
  x = max((x), (y));
}
template <class T>
inline void smin(T &x, T y) {
  x = min((x), (y));
}
long long po(long long x, long long n, long long mod) {
  long long res = 1LL;
  while (n) {
    if (n & 1) res = (res * x) % mod;
    x = (x * x) % mod;
    n = n / 2;
  }
  return res;
}
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(NULL);
  cout.tie(NULL);
  int i, j;
  long long n, k;
  cin >> n >> k;
  if (!n) return cout << 0, 0;
  if (!k) return cout << 2 * n % mod, 0;
  long long temp = ((n % mod * po(2, k + 1, mod)) % mod + 1) % mod;
  temp = (temp % mod - po(2, k, mod) + mod) % mod;
  cout << temp;
  return 0;
}
