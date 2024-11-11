#include <bits/stdc++.h>
using namespace std;
const int inf = 0x3f3f3f3f;
const double PI = acos(-1.0);
int m, n, x, t, y, a[500005], k, l, r, z, all, ans, b[500005], d[500005];
char c;
long long gcd(long long a, long long b) { return b ? gcd(b, a % b) : a; }
long long qpow(long long a, long long n, long long p = (long long)1000000007) {
  long long r = 1 % p;
  for (a %= p; n; a = a * a % p, n >>= 1)
    if (n & 1) r = r * a % p;
  return r;
}
long long inv(long long x, long long p = (long long)1000000007) {
  return x <= 1 ? 1 : inv(p % x, p) * (p - p / x) % p;
}
void init() {}
int LIS() {
  int len = 1;
  memset(d, 0, sizeof(d));
  d[1] = a[1], d[0] = 0;
  for (int i = 2; i <= n; i++) {
    if (d[len] < a[i]) {
      d[++len] = a[i];
    } else {
      int pos = lower_bound(d, d + len, a[i]) - d;
      d[pos] = a[i];
      cout << i << " " << pos << endl;
    }
  }
  return len;
}
void solve() {
  scanf("%d%d", &n, &m);
  for (int i = 1; i <= n; i++) {
    scanf("%d", &a[i]);
    a[i] -= i;
  }
  for (int i = 1; i <= m; i++) {
    scanf("%d", &b[i]);
    if (i > 1 && a[b[i - 1]] > a[b[i]]) {
      cout << -1 << endl;
      return;
    }
  }
  b[0] = 0;
  a[0] = -600005;
  b[m + 1] = n + 1;
  a[n + 1] = 1006000000;
  for (int i = 0; i <= m; i++) {
    l = a[b[i]];
    r = a[b[i + 1]];
    z = b[i + 1] - b[i] - 1;
    if (!z) continue;
    int j = b[i] + 1;
    int len = 0;
    while ((a[j] < l || a[j] > r) && j < b[i + 1]) j++;
    if (j != b[i + 1]) d[1] = a[j], len++;
    d[0] = a[0];
    for (j = j + 1; j < b[i + 1]; j++) {
      if (a[j] < l || a[j] > r) continue;
      if (d[len] <= a[j]) {
        d[++len] = a[j];
      } else {
        int pos = upper_bound(d, d + len, a[j]) - d;
        d[pos] = a[j];
      }
    }
    ans += z - len;
  }
  cout << ans << endl;
}
int main() {
  int T;
  T = 1;
  for (int i = 1; i <= T; i++) {
    init();
    solve();
  }
  return 0;
}
