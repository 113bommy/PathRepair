#include <bits/stdc++.h>
using namespace std;
long long a[4][4], h[4], w[4], v[16], s;
int n, m;
char u[16];
vector<long long> e[4][(1 << 16)], g[5];
bool in(vector<long long> &v, long long t) {
  int l, r, c;
  for (l = 0, r = v.size(), r--; l <= r;) {
    c = (l + r) >> 1;
    if (v[c] == t) return 1;
    if (v[c] < t)
      l = c + 1;
    else
      r = c - 1;
  }
  return 0;
}
bool rec(int i, int j) {
  int k, p = -1;
  if (i == n) {
    long long q;
    for (q = 0, k = 0; k < n; q += a[k][k], k++)
      ;
    if (q != s) return 0;
    for (q = 0, k = 0; k < n; q += a[n - 1 - k][k], k++)
      ;
    if (q != s) return 0;
    return 1;
  }
  if (i == n - 1 && j > 0) {
    if (w[j - 1] != s) return 0;
  }
  if (j == n) {
    if (h[i] != s)
      return 0;
    else
      return rec(i + 1, 0);
  }
  if (n - j <= 3) {
    if (!in(e[n - j][m], s - h[i])) return 0;
  } else if (!in(g[n - j], s - h[i]))
    return 0;
  if (n - i <= 3) {
    if (!in(e[n - i][m], s - w[j])) return 0;
  } else if (!in(g[n - i], s - w[j]))
    return 0;
  for (k = 0; k < n * n; k++)
    if (!u[k] && (p == -1 || v[p] != v[k])) {
      u[k] = 1;
      m &= ~(1 << k);
      a[i][j] = v[k];
      h[i] += v[k];
      w[j] += v[k];
      if (rec(i, j + 1)) return 1;
      h[i] -= v[k];
      w[j] -= v[k];
      u[k] = 0;
      m |= 1 << k;
      p = k;
    }
  return 0;
}
int main() {
  int i, j, k, l, p;
  long long t;
  for (scanf("%d", &n), s = 0, j = 0, i = 0; i < n * n;
       scanf("%I64d", &v[i]), s += v[i] / n, j += v[i] % n, i++)
    ;
  s += j / n;
  for (i = 1; i < (1 << n * n); i++) {
    for (k = 0, t = 0, j = 0; j < n * n; j++)
      if ((i >> j) & 1) {
        t += v[j];
        k++;
        e[1][i].push_back(v[j]);
        for (l = j + 1; l < n * n; l++)
          if ((i >> l) & 1) {
            e[2][i].push_back(v[j] + v[l]);
            for (p = l + 1; p < n * n; p++)
              if ((i >> p) & 1) e[3][i].push_back(v[j] + v[l] + v[p]);
          }
      }
    sort(e[1][i].begin(), e[1][i].end());
    sort(e[2][i].begin(), e[2][i].end());
    sort(e[3][i].begin(), e[3][i].end());
    if (k <= 4) g[k].push_back(t);
  }
  sort(g[1].begin(), g[1].end());
  sort(g[2].begin(), g[2].end());
  sort(g[3].begin(), g[3].end());
  sort(g[4].begin(), g[4].end());
  m = (1 << n * n) - 1;
  rec(0, 0);
  for (printf("%I64d\n", s), i = 0; i < n; printf("\n"), i++)
    for (j = 0; j < n; printf("%I64d ", a[i][j]), j++)
      ;
  return 0;
}
