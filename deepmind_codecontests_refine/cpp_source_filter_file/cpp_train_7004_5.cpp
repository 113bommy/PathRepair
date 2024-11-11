#include <bits/stdc++.h>
using namespace std;
long long read() {
  long long x = 0, y = 1;
  char c = getchar();
  while (c < '0' || c > '9') {
    if (c == '-') y = -1;
    c = getchar();
  }
  while (c >= '0' && c <= '9') {
    x = (x << 1) + (x << 3) + c - '0';
    c = getchar();
  }
  return x * y;
}
long long t, n, m;
long long a[200010], pl[200010], b[200010];
set<long long> q;
signed main() {
  t = read();
  while (t--) {
    n = read(), m = read();
    for (long long i = 1; i <= n; i++) a[i] = read(), pl[a[i]] = i;
    for (long long j = 1; j <= m; j++) {
      b[j] = read();
      q.insert(b[j]);
    }
    long long ans = 1;
    for (long long i = 1; i <= m; i++) {
      q.erase(b[i]);
      long long ji = 0;
      if (pl[b[i]] > 1 && q.count(a[pl[b[i]] - 1]) <= 0) ji++;
      if (pl[b[i]] < n && q.count(a[pl[b[i]] + 1]) <= 0) ji++;
      (ans *= ji) % 998244353;
    }
    cout << ans << "\n";
  }
}
