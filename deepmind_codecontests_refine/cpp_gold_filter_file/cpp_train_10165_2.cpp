#include <bits/stdc++.h>
using namespace std;
int n, a[500111], g[500111 * 16];
int gcd(int a, int b) {
  if (a < b) return gcd(b, a);
  if (!b) return a;
  return gcd(b, a % b);
}
void build(int p, int lo, int hi) {
  if (lo == hi) {
    g[p] = a[lo];
    return;
  }
  int c = p << 1, mid = (lo + hi) >> 1;
  build(c, lo, mid);
  build(c + 1, mid + 1, hi);
  g[p] = gcd(g[c], g[c + 1]);
}
void update(int p, int lo, int hi, int u, int val) {
  if (u < lo || hi < u) return;
  if (lo == hi) {
    g[p] = val;
    return;
  }
  int c = p << 1, mid = (lo + hi) >> 1;
  update(c, lo, mid, u, val);
  update(c + 1, mid + 1, hi, u, val);
  g[p] = gcd(g[c], g[c + 1]);
}
int get(int p, int lo, int hi, int u, int v, int x) {
  if (v < lo || hi < u) return 0;
  if (lo == hi) {
    return g[p] % x == 0 ? 0 : 1;
  }
  if (g[p] % x == 0) return 0;
  int c = p << 1, mid = (lo + hi) >> 1;
  if (u <= lo && hi <= v) {
    int g1 = g[c] % x;
    int g2 = g[c + 1] % x;
    if (g1 && g2) return 2;
    if (g1) return get(c, lo, mid, u, v, x);
    return get(c + 1, mid + 1, hi, u, v, x);
  }
  return get(c, lo, mid, u, v, x) + get(c + 1, mid + 1, hi, u, v, x);
}
int main() {
  int q, u, v, x, cmd;
  scanf("%d", &n);
  for (int i = (1), _b = (n); i <= _b; i++) scanf(" %d ", &a[i]);
  build(1, 1, n);
  scanf("%d", &q);
  while (q--) {
    scanf("%d", &cmd);
    if (cmd == 1) {
      scanf("%d %d %d", &u, &v, &x);
      puts(get(1, 1, n, u, v, x) <= 1 ? "YES" : "NO");
    } else {
      scanf("%d %d", &u, &x);
      update(1, 1, n, u, x);
    }
  }
  return 0;
}
