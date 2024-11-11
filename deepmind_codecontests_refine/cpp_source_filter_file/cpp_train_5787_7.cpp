#include <bits/stdc++.h>
using namespace std;
const int N = 1e5 + 10, M = 1e6 + 10, inf = 2e9 + 10, mod = 6;
const long long INF = 1e18 + 10;
long long c[N], w[N];
struct is {
  long long x;
  int y;
  is() {}
  is(long long a, int b) { x = a, y = b; }
  bool operator<(const is &b) const { return x > b.x; }
};
priority_queue<is> q;
int out[N];
int main() {
  int n;
  long long m;
  scanf("%d%lld", &n, &m);
  for (int i = 1; i <= n; i++) scanf("%lld", &c[i]);
  for (int i = 1; i <= n; i++) scanf("%lld", &w[i]);
  long long ans = 0;
  for (int i = 1; i <= n; i++) {
    long long p = c[i] % 100 ? c[i] % 100 : 100;
    if (m >= p) {
      m -= p;
      long long qq = w[i] * (100 - p);
      q.push(is(qq, i));
    } else {
      long long qq = w[i] * (100 - p);
      if (q.empty()) {
        ans += qq;
        m += 100 - p;
        out[i] = 1;
      } else {
        is b = q.top();
        if (qq <= b.x)
          ans += qq, m += 100 - p, out[i] = 1;
        else {
          q.pop();
          ans += b.x;
          out[b.y] = 1;
          m += 100;
          i--;
        }
      }
    }
  }
  printf("%lld\n", ans);
  for (int i = 1; i <= n; i++) {
    if (out[i])
      printf("%lld %lld\n", c[i] / 100 + (c[i] % 100 ? 1 : 0), 0);
    else
      printf("%lld %lld\n", c[i] / 100, c[i] % 100);
  }
  return 0;
}
