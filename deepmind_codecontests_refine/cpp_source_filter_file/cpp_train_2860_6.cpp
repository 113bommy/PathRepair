#include <bits/stdc++.h>
using namespace std;
inline long long read() {
  register long long x = 0, f = 1;
  char ch = getchar();
  while (!isdigit(ch)) {
    if (ch == '-') f = -1;
    ch = getchar();
  }
  while (isdigit(ch)) {
    x = (x << 1) + (x << 3) + (ch ^ 48);
    ch = getchar();
  }
  return x * f;
}
const long long N = 1e5 + 10;
long long n, m, k, p;
long long h[N], a[N];
long long c[N];
struct node {
  long long t, id;
  bool operator<(const node& x) const { return t > x.t; }
};
priority_queue<node> q;
bool check(long long x) {
  while (!q.empty()) q.pop();
  memset(c, 0, sizeof c);
  for (long long i = 1; i <= n; i++)
    if (x - a[i] * m < h[i]) q.push((node){x / a[i], i});
  for (long long i = 1; !q.empty() && i <= m; i++)
    for (long long j = 1; !q.empty() && j <= k; j++) {
      node u = q.top();
      q.pop();
      if (u.t < i) return 0;
      ++c[u.id];
      if (x + c[u.id] * p - a[u.id] * m < h[u.id])
        q.push((node){(x + c[u.id] * p) / a[u.id], u.id});
    }
  return q.empty();
}
signed main() {
  n = read(), m = read(), k = read(), p = read();
  for (long long i = 1; i <= n; i++) h[i] = read(), a[i] = read();
  long long l = 0, r = 1e12, ans;
  while (l <= r) {
    long long mid = l + r >> 1;
    if (check(mid))
      ans = mid, r = mid - 1;
    else
      l = mid + 1;
  }
  cout << ans;
}
