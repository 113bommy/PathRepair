#include <bits/stdc++.h>
using namespace std;
const int maxn = 500010;
const double pai = acos(-1.0);
char s[maxn], t[maxn];
int n, m, a[maxn], b[maxn], ans[maxn], fa[maxn][6], rev[maxn], bin[600010];
struct node {
  double a, b;
  node(double t0 = 0.0, double t1 = 0.0) {
    a = t0;
    b = t1;
  }
} A[maxn], B[maxn];
node operator+(node a, node b) {
  node c;
  c.a = a.a + b.a;
  c.b = a.b + b.b;
  return c;
}
node operator-(node a, node b) {
  node c;
  c.a = a.a - b.a;
  c.b = a.b - b.b;
  return c;
}
node operator*(node a, node b) {
  node c;
  c.a = a.a * b.a - a.b * b.b;
  c.b = a.b * b.a + a.a * b.b;
  return c;
}
void FFT(node *t, int n, int id) {
  int len = bin[n];
  for (int i = 0; i < n; i++)
    rev[i] = (rev[i >> 1] >> 1) | ((i & 1) << (len - 1));
  for (int i = 0; i < n; i++)
    if (i < rev[i]) swap(t[i], t[rev[i]]);
  for (int i = 1; i < n; i <<= 1) {
    node Wn;
    Wn.a = cos(pai / i);
    Wn.b = id * sin(pai / i);
    for (int j = 0; j < n; j += (i << 1)) {
      node W;
      W.a = 1;
      W.b = 0;
      for (int k = j; k < j + i; k++) {
        node t1 = t[k], t2 = t[k + i] * W;
        t[k] = t1 + t2;
        t[k + i] = t1 - t2;
        W = W * Wn;
      }
    }
  }
}
int find(int *f, int x) {
  if (f[x] == x) return x;
  return f[x] = find(f, f[x]);
}
void solve(int x, int y) {
  int len = 1;
  while (len <= 2 * (n + m)) len <<= 1;
  for (int i = 0; i < len; i++) A[i].a = A[i].b = B[i].a = B[i].b = 0;
  for (int i = 0; i < n; i++)
    if (s[i] - 'a' == x) A[i].a = 1;
  for (int i = 0; i < m; i++)
    if (t[i] - 'a' == y) B[i].a = 1;
  reverse(B, B + m);
  FFT(A, len, 1), FFT(B, len, 1);
  for (int i = 0; i < len; i++) A[i] = A[i] * B[i];
  FFT(A, len, -1);
  for (int i = m - 1; i < n; i++) {
    int temp = (int)(A[i].a / len + 0.5);
    if (!temp) continue;
    if (find(fa[i], x) != find(fa[i], y)) {
      fa[i][fa[i][x]] = fa[i][y];
      ans[i]++;
    }
  }
}
int main() {
  for (int i = 0; i <= 19; i++) bin[1 << i] = i;
  scanf("%s", s);
  scanf("%s", t);
  n = strlen(s);
  m = strlen(t);
  for (int i = 0; i < n; i++)
    for (int j = 0; j < 6; j++) fa[i][j] = j;
  for (int i = 0; i < 6; i++)
    for (int j = 0; j < 6; j++)
      if (i != j) solve(i, j);
  for (int i = m - 1; i < n; i++) printf("%d ", ans[i]);
  return 0;
}
