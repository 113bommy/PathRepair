#include <bits/stdc++.h>
using namespace std;
namespace FGF {
int n, m;
const int N = 5e4 + 5;
struct matrx {
  long long a[2][3];
} t[N << 2], ans, c[N], b[N];
struct Node {
  long long pos, w;
  int op;
} q[N << 1];
long long K, p;
int a[N];
matrx operator*(matrx x, matrx y) {
  matrx s;
  memset(s.a, 0, sizeof(s.a));
  for (int i = 0; i < 2; i++)
    for (int j = 0; j < 2; j++)
      for (int k = 0; k < 2; k++)
        s.a[i][j] = (s.a[i][j] + x.a[i][k] * y.a[k][j] % p) % p;
  return s;
}
void build(int ro, int l, int r) {
  if (l == r) {
    c[l].a[0][1] = a[l - 1], c[l].a[1][0] = 1, c[l].a[1][1] = a[l % n];
    b[l] = t[ro] = c[l];
    return;
  }
  build(ro << 1, l, (l + r) / 2), build(ro << 1 | 1, (l + r) / 2 + 1, r);
  t[ro] = t[ro << 1] * t[ro << 1 | 1];
}
void updat(int ro, int l, int r, int pos) {
  if (l == r) {
    t[ro] = b[pos];
    return;
  }
  pos <= (l + r) / 2 ? updat(ro << 1, l, (l + r) / 2, pos)
                     : updat(ro << 1 | 1, (l + r) / 2 + 1, r, pos);
  t[ro] = t[ro << 1] * t[ro << 1 | 1];
}
matrx qpow(matrx x, long long y) {
  matrx s;
  s.a[0][0] = s.a[1][1] = 1, s.a[0][1] = s.a[1][0] = 0;
  while (y) {
    if (y & 1) s = s * x;
    x = x * x;
    y >>= 1;
  }
  return s;
}
bool cmp(Node x, Node y) { return x.pos < y.pos; }
void work() {
  scanf("%lld%lld", &K, &p);
  scanf("%d", &n);
  for (int i = 0; i < n; i++) scanf("%d", &a[i]), a[i] %= p;
  scanf("%d", &m);
  for (int i = 1; i <= m; i++) {
    scanf("%lld%lld", &q[i].pos, &q[i].w), q[i].w %= p;
    q[i].op = 1, q[i + m].pos = q[i].pos + 1, q[i + m].w = q[i].w;
  }
  m <<= 1;
  sort(q + 1, q + m + 1, cmp);
  while (m && q[m].pos > K) m--;
  build(1, 1, n);
  ans.a[0][0] = 0, ans.a[0][1] = 1;
  long long lst = 0;
  for (int i = 1, j = 1; i <= m; i = ++j) {
    long long now = (q[i].pos - 1) / n;
    while (j < m && (q[j + 1].pos - 1) / n == now) ++j;
    ans = ans * qpow(t[1], now - lst);
    lst = now;
    for (int k = i; k <= j; k++) {
      int pos = (q[k].pos - 1) % n + 1;
      b[pos].a[q[k].op][1] = q[k].w;
      updat(1, 1, n, pos);
    }
    if (now == K / n) break;
    ans = ans * t[1], lst = now + 1;
    for (int k = i; k <= j; k++) {
      int pos = (q[k].pos - 1) % n + 1;
      b[pos] = c[pos];
      updat(1, 1, n, pos);
    }
  }
  long long now = K / n;
  ans = ans * qpow(t[1], now - lst);
  for (int i = 1, d = K % n; i <= d; i++) ans = ans * b[i];
  printf("%lld", ans.a[0][1]);
}
}  // namespace FGF
int main() {
  FGF::work();
  return 0;
}
