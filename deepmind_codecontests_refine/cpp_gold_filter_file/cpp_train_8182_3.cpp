#include <bits/stdc++.h>
using namespace std;
long long read() {
  long long x = 0, f = 1;
  char c = getchar();
  while (c > '9' || c < '0') {
    if (c == '-') f = -1;
    c = getchar();
  }
  while (c >= '0' && c <= '9') {
    x = x * 10 + c - '0';
    c = getchar();
  }
  return f * x;
}
int n, a[100003], mx;
long long ans, f[100003], s;
long long pow_mod(long long a, long long b) {
  long long ans = 1;
  while (b) {
    if (b & 1) ans = ans * a % 1000000007;
    b >>= 1;
    a = a * a % 1000000007;
  }
  return ans;
}
int main() {
  n = read();
  for (int i = 1; i <= n; ++i) a[i] = read(), s += a[i], mx = max(mx, a[i]);
  f[1] =
      (s - 1) * (s - 1) % 1000000007 * pow_mod(s, 1000000007 - 2) % 1000000007;
  f[2] = (2 * f[1] - 1 + 1000000007) % 1000000007;
  for (int i = 2; i < mx; ++i) {
    long long x = (f[i - 1] - f[i] + 1000000007) % 1000000007;
    x = (x + (s - 1) * pow_mod(s - i, 1000000007 - 2) % 1000000007) %
        1000000007;
    f[i + 1] = (f[i] - x + 1000000007) % 1000000007;
  }
  for (int i = 1; i <= n; ++i) ans = (ans + f[a[i]]) % 1000000007;
  cout << ans << '\n';
  return 0;
}
