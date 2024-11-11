#include <bits/stdc++.h>
using namespace std;
long long n, m;
const long long p = 1e9 + 7;
long long ans;
inline long long read() {
  long long x = 0, f = 1;
  char c = getchar();
  while (c < '0' || c > '9') {
    if (c == '-') f = -1;
    c = getchar();
  }
  while (c >= '0' && c <= '9') x = (x << 3) + (x << 1) + c - '0', c = getchar();
  return x * f;
}
signed main() {
  n = read(), m = read(), ans = (n % p) * (m % p);
  for (long long l = 1, r; l <= m && l <= n; l = r + 1) {
    r = n / (n / l);
    r = min(r, m);
    ans = ((ans - ((r - l + 1) % p) * ((l + r) % p) % p * (n / l % p) % p *
                      (p - p / 2) % p) %
               p +
           p) %
          p;
  }
  cout << ans << endl;
  return 0;
}
