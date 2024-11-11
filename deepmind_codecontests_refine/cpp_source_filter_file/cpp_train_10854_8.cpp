#include <bits/stdc++.h>
using namespace std;
template <class T>
bool uin(T &a, T b) {
  return a > b ? (a = b, true) : false;
}
template <class T>
bool uax(T &a, T b) {
  return a < b ? (a = b, true) : false;
}
const long long P = 998244353;
const int maxn = 2100000;
long long fact[maxn], tcaf[maxn];
long long deg(long long x, long long d) {
  if (d < 0) d += P - 1;
  long long y = 1;
  while (d) {
    if (d & 1) (y *= x) %= P;
    d /= 2;
    (x *= x) %= P;
  }
  return y;
}
long long cnk(int n, int k) { return fact[n] * tcaf[k] % P * tcaf[n - k] % P; }
int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.precision(10);
  cout << fixed;
  int n, m;
  cin >> n >> m;
  fact[0] = 1;
  for (int i = 0; i < (int)(n); ++i) fact[i + 1] = fact[i] * (i + 1) % P;
  for (int i = 0; i < (int)(n + 1); ++i) tcaf[i] = deg(fact[i], -1);
  long long p = deg(m + 1, -1), q = (P + 1 - p) % P;
  long long ans = 0;
  for (int k = 1; k <= (int)(n); ++k) {
    (ans += cnk(n, k) % P * (1 + m * deg(k, -1)) * (k % 2 ? 1 : -1)) %= P;
  }
  if (ans < 0) ans += P;
  (ans *= n * p % P + 1) %= P;
  cout << ans << '\n';
  return 0;
}
