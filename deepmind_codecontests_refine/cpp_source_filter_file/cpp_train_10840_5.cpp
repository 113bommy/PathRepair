#include <bits/stdc++.h>
using namespace std;
const int N = 30007;
int d, m, n, g[N], w[N], st[N];
long long l, r;
struct node {
  bitset<30007> a, b;
  long long len, sum;
} f[70][70];
bitset<30007> all, opt;
inline node merge(node a, node b) {
  node c;
  c.len = a.len + b.len, c.sum = a.sum + b.sum;
  c.a = (a.a & ((all >> a.len) ^ all)) | ((b.a >> a.len) & a.a);
  c.b = (b.b & ((all << b.len) ^ all)) | ((a.b << b.len) & b.b);
  opt = (a.b & (b.a >> 1));
  opt = (opt & ((all << (a.len)) ^ all));
  opt = (opt & ((all >> (b.len + 1)) ^ all));
  c.sum = c.sum + opt.count();
  return c;
}
inline long long solve(long long len) {
  int c = 0, k = 1;
  st[0] = 0;
  while (len > 0) st[++st[0]] = len % d, len /= d;
  for (int i = 1; i <= st[0]; i++) {
    if (i > 1) {
      for (int j = 0; j < d; j++) {
        f[i][j] = f[i - 1][j];
        for (int x = 1; x < d; x++) {
          f[i][j] = merge(f[i][j], f[i - 1][(j + g[x]) % m]);
        }
      }
    } else {
      for (int j = 0; j < d; j++) {
        f[i][j] = f[i - 1][j];
        for (int x = 1; x < d; x++) {
          f[i][j] = merge(f[i][j], f[i - 1][(j + g[x]) % m]);
        }
      }
    }
  }
  int opt = 0;
  bool fl = 0;
  node ans;
  for (int i = st[0]; i >= 1; i--) {
    if (i > 1) {
      for (int j = 0; j < st[i]; j++) {
        if (!fl)
          ans = f[i - 1][(g[j] + opt) % m], fl = 1;
        else
          ans = merge(ans, f[i - 1][(g[j] + opt) % m]);
      }
    } else {
      for (int j = 0; j < st[i]; j++) {
        if (!fl)
          ans = f[0][(g[j] + opt) % m], fl = 1;
        else
          ans = merge(ans, f[i - 1][(g[j] + opt) % m]);
      }
    }
    opt += g[st[i]];
  }
  if (!fl) return 0;
  return ans.sum;
}
int main() {
  cin >> d >> m;
  for (int i = 0; i < d; i++) scanf("%d", &g[i]);
  cin >> n;
  for (int i = 1; i <= n; i++) scanf("%d", &w[i]), all[i] = 1;
  for (int i = 1; i <= n; i++)
    for (int j = 0; j <= w[i]; j++) {
      f[0][j].a[i] = f[0][j].b[i] = 1;
      if (n == 1) f[0][j].sum++;
    }
  for (int i = 0; i < m; i++) f[0][i].len = 1;
  cin >> l >> r;
  cout << solve(r) - solve(l + n - 2ll) << endl;
}
