#include <bits/stdc++.h>
int read() {
  bool flag = true;
  int ch = getchar(), num = 0;
  while (ch < 48 || ch > 57) {
    if (ch == '-') flag = false;
    ch = getchar();
  }
  while (ch >= 48 && ch <= 57)
    num = (num << 3) + (num << 1) + (ch ^ 48), ch = getchar();
  return flag ? num : -num;
}
const long long mod = 998244353;
const int maxn = 100005;
int n, x[maxn], v[maxn], p[maxn][2];
bool limit[maxn][2][2];
long long val[maxn << 2][2][2];
int mid[maxn << 2], id[maxn];
void pushup(int u) {
  int i, j, x, y;
  for (i = 0; i < 2; i++)
    for (j = 0; j < 2; j++) {
      val[u][i][j] = 0;
      for (x = 0; x < 2; x++)
        for (y = 0; y < 2; y++)
          if (!limit[mid[u]][x][y])
            val[u][i][j] += val[u << 1][i][x] * val[u << 1 | 1][y][j] % mod;
      val[u][i][j] %= mod;
    }
}
void build(int u, int l, int r) {
  if (l == r) {
    val[u][0][0] = p[l][0];
    val[u][1][1] = p[l][1];
    return;
  }
  int m = (l + r) >> 1;
  mid[u] = m;
  id[m] = u;
  build(u << 1, l, m);
  build(u << 1 | 1, m + 1, r);
  pushup(u);
}
struct Node {
  int x, d1, d2, l, v;
} c[maxn << 1];
bool operator<(Node a, Node b) {
  return (long long)a.l * b.v < (long long)b.l * a.v;
}
long long inv[1000005];
int main() {
  inv[1] = 1;
  for (int i = 2; i <= 1000000; i++)
    inv[i] = (mod - mod / i) * inv[mod % i] % mod;
  const long long inv100 = inv[100];
  n = read();
  for (int i = 1; i <= n; i++) {
    x[i] = read(), v[i] = read(), p[i][1] = read();
    p[i][1] = p[i][1] * inv100 % mod;
    p[i][0] = (1 - p[i][1] + mod) % mod;
  }
  build(1, 1, n);
  int m = 0;
  for (int i = 2; i <= n; i++) {
    c[m++] = Node{i - 1, 1, 0, x[i] - x[i - 1], v[i - 1] + v[i]};
    if (v[i - 1] > v[i])
      c[m++] = Node{i - 1, 1, 1, x[i] - x[i - 1], v[i - 1] - v[i]};
    else if (v[i - 1] < v[i])
      c[m++] = Node{i - 1, 0, 0, x[i] - x[i - 1], v[i] - v[i - 1]};
  }
  std::sort(c, c + m);
  long long answer = 0ll, last = 1ll, now;
  for (int i = 0; i < m; i++) {
    limit[c[i].x][c[i].d1][c[i].d2] = true;
    for (int u = id[c[i].x]; u; u >>= 1) pushup(u);
    now = (val[1][0][0] + val[1][0][1] + val[1][1][0] + val[1][1][1]) % mod;
    answer += c[i].l * inv[c[i].v] % mod * (last - now + mod) % mod;
    last = now;
  }
  printf("%lld", answer % mod);
  return 0;
}
