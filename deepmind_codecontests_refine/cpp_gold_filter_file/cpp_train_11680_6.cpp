#include <bits/stdc++.h>
int read() {
  int r = 0, t = 1, c = getchar();
  while (c < '0' || c > '9') {
    t = c == '-' ? -1 : 1;
    c = getchar();
  }
  while (c >= '0' && c <= '9') {
    r = (r << 3) + (r << 1) + (c ^ 48);
    c = getchar();
  }
  return r * t;
}
const int N = 200010;
int n, m;
int a[N], s;
int d[N], b[N];
std::map<int, std::vector<int> > M;
int q, Q, qp;
int c[N], k, l[N], r[N];
int lst[N], t[N][20];
int main() {
  n = read();
  m = read();
  for (int i = (1), end_i = (n); i <= end_i; i++) s += (a[i] = read());
  assert(s % n == 0);
  s /= n;
  for (int i = (1), end_i = (n); i <= end_i; i++) {
    b[i] = a[i] + d[i - 1];
    d[i] = b[i] - s;
    M[d[i]].push_back(i);
  }
  Q = n;
  for (auto p : M) {
    int w = 0, W = n;
    k = 0;
    for (auto i : p.second) c[++k] = i;
    for (auto i : p.second) c[++k] = i + n;
    for (int i = (1), end_i = (k); i <= end_i; i++)
      for (int j = (0), end_j = (18); j <= end_j; j++) t[i][j] = k;
    for (int i = (k), end_i = (1); i >= end_i; i--) lst[c[i] % (m - 1)] = k;
    for (int i = (k), end_i = (1); i >= end_i; i--)
      lst[(c[i] + 1) % (m - 1)] = k;
    for (int i = (k), end_i = (1); i >= end_i; i--) {
      t[i][0] = lst[(c[i] + 1) % (m - 1)];
      lst[c[i] % (m - 1)] = i;
    }
    for (int j = (1), end_j = (18); j <= end_j; j++)
      for (int i = (1), end_i = (k); i <= end_i; i++)
        t[i][j] = t[t[i][j - 1]][j - 1];
    for (int i = (1), end_i = (k / 2); i <= end_i; i++) {
      int p = i, T = 1;
      for (int j = (18), end_j = (0); j >= end_j; j--)
        if (t[p][j] < i + k / 2) {
          p = t[p][j];
          T += 1 << j;
        }
      T = (n - T + m - 2) / (m - 1);
      if (T < W) {
        w = i;
        W = T;
      }
    }
    if (W < Q) {
      Q = W;
      q = p.first;
      qp = c[w];
    }
  }
  for (int i = (1), end_i = (n); i <= end_i; i++) d[i] -= q;
  d[0] = d[n];
  d[n + 1] = d[1];
  printf("%d\n", Q);
  k = 0;
  l[0] = qp;
  r[0] = qp;
  for (int i = (1), end_i = (Q); i <= end_i; i++) {
    l[i] = r[i - 1] % n + 1;
    while (!d[l[i]]) l[i] = l[i] % n + 1;
    r[i] = l[i];
    for (int j = m - 2; j && r[i] % n + 1 != qp; j--) r[i] = r[i] % n + 1;
  }
  for (int i = 1, j; i <= Q;) {
    j = i;
    while (j <= Q && d[r[j] % n + 1] < 0) j++;
    assert(j <= Q);
    for (int k = (j), end_k = (i); k >= end_k; k--) {
      for (int o = l[k]; o != r[k] % n + 1; o = o % n + 1) {
        a[o] -= d[o];
        a[o % n + 1] += d[o];
      }
      printf("%d ", l[k] - 1);
      for (int w = 1, o = l[k]; w <= m; w++, o = o % n + 1)
        printf("%d%c", a[o], w == m ? '\n' : ' ');
    }
    i = j + 1;
  }
  return 0;
}
