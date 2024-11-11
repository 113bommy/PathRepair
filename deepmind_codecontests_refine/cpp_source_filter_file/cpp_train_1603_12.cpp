#include <bits/stdc++.h>
using namespace std;
const long long inf = INT_MAX, df = 2e6 + 7;
long long i, j, k, l, m, n, o, p, q, r, s, t, u, v, w, x, y, z, a[df], b[df],
    vis[df], ans;
priority_queue<long long> que[df];
inline long long read() {
  long long x = 0, y = 1;
  char ch = getchar();
  while (ch > '9' || ch < '0') ch = getchar();
  while (ch >= '0' && ch <= '9')
    x = (x << 3) + (x << 1) + ch - '0', ch = getchar();
  return x * y;
}
int main() {
  n = read(), m = read();
  for (long long i = (1); i <= (m); i++) {
    a[i] = read(), b[i] = read(), que[a[i]].push(a[i] + b[i] - 1);
  }
  long long fir = 0;
  for (long long i = (1); i <= (n); i++) {
    if (!fir) {
      for (i = 1; que[i].empty(); ++i)
        ;
      fir = 1;
    }
    long long maxr = que[i].top(), ty = 0;
    for (long long j = (i + 1); j <= (que[i].top()); j++) {
      if (!que[j].empty()) {
        if (maxr < que[j].top()) {
          ty = j, maxr = que[j].top();
        }
      }
    }
    vis[i] = 1;
    ans++;
    if (maxr > que[i].top()) {
      i = ty - 1;
    } else {
      for (i = que[i].top() + 1; que[i].empty(); i++)
        ;
      i--;
    }
  }
  printf("%lld\n", m - ans);
  for (long long i = (1); i <= (m); i++) {
    if (vis[a[i]]) {
      if (a[i] + b[i] - 1 != que[a[i]].top()) {
        printf("%lld ", i);
      } else
        vis[a[i]] = 0;
    } else
      printf("%lld ", i);
  }
  return puts(""), 0;
}
