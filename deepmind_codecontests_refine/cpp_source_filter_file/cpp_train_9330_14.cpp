#include <bits/stdc++.h>
using namespace std;
const int T = 1e9 + 7;
const int maxn = 2e6 + 233;
long long fac[maxn], inv[maxn];
int exgcd(int a, int b, int& x, int& y) {
  if (b == 0) {
    x = 1;
    y = 0;
    return a;
  }
  int d = exgcd(b, a % b, y, x);
  y -= (a / b) * x;
  return d;
}
void init() {
  fac[0] = inv[0] = 1;
  for (int i = 1; i < maxn; i++) {
    fac[i] = fac[i - 1] * i % T;
    int x, y;
    exgcd(i, T, x, y);
    x = (x + T) % T;
    inv[i] = inv[i - 1] * x % T;
  }
}
inline long long A(int n, int k) {
  if (k > n) return 0;
  return fac[n] * inv[n - k] % T;
}
long long f[maxn];
int main() {
  init();
  int n, k;
  cin >> n >> k;
  k--;
  f[0] = 1;
  long long sum = 0;
  for (int i = 1; i <= n; i++) {
    sum = (sum * (i - 1) + f[i - 1]) % T;
    if (i - 1 >= k + 1)
      sum = (sum - A(i - 1, k + 1) * f[i - k - 2] % T + T) % T;
    f[i] = sum;
  }
  long long ans = 0;
  for (int i = 0; i <= n - 1; i++) ans = (ans + A(n - 1, i) * f[n - i - 1] % T);
  ans = (fac[n] - ans + T) % T;
  cout << ans << endl;
  return 0;
}
