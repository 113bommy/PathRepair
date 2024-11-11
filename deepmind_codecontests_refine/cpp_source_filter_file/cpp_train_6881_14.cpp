#include <bits/stdc++.h>
using namespace std;
long long read() {
  register long long x = 0, w = 1;
  register char ch = getchar();
  while (ch < '0' || ch > '9') {
    if (ch == '-') w = -1;
    ch = getchar();
  }
  while (ch >= '0' && ch <= '9') {
    x = (x << 3) + (x << 1) + ch - '0';
    ch = getchar();
  }
  return x * w;
}
long long a[500005 << 2], mod, k;
int l[500005 << 2], r[500005 << 2];
long long lgcd(long long a, long long b, long long c, long long n) {
  if (!a) return 0;
  if (a >= c || b >= c) {
    return (((a / c) * (n * (n + 1) / 2) + (b / c) * (n + 1)) % mod +
            lgcd(a % c, b % c, c, n) % mod) %
           mod;
  }
  long long m = (a * n + b) / c;
  return (((m % mod) * (n % mod)) % mod - lgcd(c, c - b - 1, a, m - 1) % mod +
          mod) %
         mod;
}
long long work(int i) {
  return (lgcd(1, r[i] - i, k - 1, i - l[i]) - lgcd(1, 0, k - 1, i - l[i] - 1) +
          mod) %
         mod;
}
int main() {
  long long n = read();
  k = read();
  mod = 1000000007;
  long long ans = 0;
  for (register int i = 1; i <= n; ++i) a[i] = read();
  l[1] = 1, r[n] = n;
  for (int i = 2; i <= n; ++i) {
    int x = i;
    while (x > 1 && a[i] >= a[x - 1]) x = l[x - 1];
    l[i] = x;
  }
  for (int i = n - 1; i >= 1; --i) {
    register int x = i;
    while (x < n && a[i] >= a[x + 1]) x = r[x + 1];
    r[i] = x;
  }
  for (register int i = 1; i <= n; ++i) {
    ans = (ans + ((work(i) % mod) * (a[i] % mod)) % mod) % mod;
  }
  cout << ans;
}
