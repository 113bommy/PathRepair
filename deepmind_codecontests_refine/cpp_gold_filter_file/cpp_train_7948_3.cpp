#include <bits/stdc++.h>
using namespace std;
const int MAXN = 1e3 + 5;
int n, m;
long long c[MAXN], g[MAXN], a1[MAXN], a2[MAXN], b1[MAXN], b2[MAXN];
void work(long long x, long long n, long long *d1, long long *d2) {
  if (n == 0) {
    d1[n] = d2[n] = 0;
    return;
  }
  if (n == 1) {
    d1[n] = (x == 2);
    d2[n] = (x == 1);
    return;
  }
  if (x <= c[n - 1]) {
    work(x, n - 1, d1, d2);
    d1[n] = min(d1[n - 1], d2[n - 1] + 2);
    d2[n] = min(d2[n - 1], d1[n - 1]) + 1 + g[n - 2];
  } else {
    work(x - c[n - 1], n - 2, d1, d2);
    d1[n] = d1[n - 2] + 1;
    d2[n] = d2[n - 2];
  }
}
long long dis(long long u, long long v, int n) {
  if (n <= 1) return (u != v);
  if (u <= c[n - 1]) {
    if (v > c[n - 1])
      return min(a1[n - 1], a2[n - 1]) + b1[n - 2] + 1;
    else
      return min(dis(u, v, n - 1),
                 min(a1[n - 1] + b2[n - 1], b1[n - 1] + a2[n - 1]) + 2);
  } else
    return dis(u - c[n - 1], v - c[n - 1], n - 2);
}
int main() {
  scanf("%d %d", &m, &n);
  n = min(n, 80);
  c[0] = 1;
  c[1] = 2;
  for (int i = 2; i <= n; i++) c[i] = c[i - 1] + c[i - 2];
  g[0] = 0;
  g[1] = g[2] = 1;
  for (int i = 3; i <= n; i++) g[i] = g[i - 2] + 1;
  while (m--) {
    long long u, v;
    scanf("%lld %lld", &u, &v);
    if (u > v) swap(u, v);
    work(u, n, a1, a2);
    work(v, n, b1, b2);
    printf("%lld\n", dis(u, v, n));
  }
  return 0;
}
