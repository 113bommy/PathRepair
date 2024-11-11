#include <bits/stdc++.h>
using namespace std;
int n, m, op;
long long a[25];
bool vis[25];
void build(int p, long long x) {
  memset(vis, 0, sizeof(vis));
  long long k = 1;
  for (int i = 1; i < p; i++) k = k * i;
  for (int i = 1; i < p; i++) {
    int g = 1;
    while (vis[g] == 1) g++;
    while (x - k >= 0) {
      x = x - k;
      g++;
      while (vis[g] == 1) g++;
    }
    a[i] = g;
    vis[g] = 1;
    k = k / (p - i);
  }
  for (int i = 1; i <= p; i++)
    if (vis[i] == 0) a[p] = i;
}
int main() {
  scanf("%d%d", &n, &m);
  int q = min(n, 15);
  long long x = 0;
  for (int i = 1; i <= q; i++) {
    a[i] = i;
  }
  for (int i = 1; i <= m; i++) {
    scanf("%d", &op);
    if (op == 2) {
      int s;
      scanf("%lld", &s);
      x += s;
      build(q, x);
    }
    if (op == 1) {
      int l, r;
      scanf("%d%d", &l, &r);
      if (r <= n - q) {
        printf("%lld\n", 1ll * (r + l) * (r - l + 1) / 2);
      } else if (l > n - q) {
        long long ans = 0;
        for (int i = l + q - n; i <= r + q - n; i++) ans = ans + (a[i] + n - q);
        printf("%lld\n", ans);
      } else {
        long long ans = 0;
        for (int i = 1; i <= r + q - n; i++) ans = ans + (a[i] + n - q);
        printf("%lld\n", ans + 1ll * (n - q - l + 1) * (l + n - q) / 2);
      }
    }
  }
}
