#include <bits/stdc++.h>
using namespace std;
const int maxn = 300005;
struct pi {
  int le, ri, ma;
} pp[maxn << 2];
void build(int tot, int l, int r) {
  pp[tot].le = l;
  pp[tot].ri = r;
  pp[tot].ma = 0;
  if (l == r) return;
  build(2 * tot, l, (l + r) / 2);
  build(2 * tot + 1, (l + r) / 2 + 1, r);
}
void merg(int tot, int p, int k) {
  if (pp[tot].le == pp[tot].ri) {
    pp[tot].ma = k;
    return;
  }
  int mid = (pp[tot].le + pp[tot].ri) >> 1;
  if (p <= mid)
    merg(tot << 1, p, k);
  else
    merg((tot << 1) | 1, p, k);
  pp[tot].ma = max(pp[tot << 1].ma, pp[(tot << 1) | 1].ma);
}
int ss;
void query(int u, int tot, int r, int p) {
  if (r == 0) return;
  if (pp[tot].ri <= r) {
    if (pp[tot].ma >= p + u) {
      ss = tot;
    }
    return;
  }
  int mid = (pp[tot].le + pp[tot].ri) >> 1;
  if (r <= mid)
    query(u, tot << 1, r, p);
  else {
    query(u, tot << 1, r, p);
    query(u, (tot << 1) | 1, r, p);
  }
}
int find(int u, int tot, int p) {
  if (pp[tot].le == pp[tot].ri) return pp[tot].le;
  if (pp[(tot << 1) | 1].ma >= p + u) return find(u, (tot << 1) | 1, p);
  return find(u, tot << 1, p);
}
int b[maxn];
int a[maxn];
int r[maxn][44];
int l[maxn][44];
double er[61];
int main() {
  int i, j, n;
  cin >> n;
  for (i = 1; i <= n; i++) scanf("%d", &b[i]);
  build(1, 1, n);
  er[0] = 1;
  for (i = 1; i <= 40; i++) {
    er[i] = er[i - 1] * 2.0;
  }
  for (i = 1; i <= n; i++) {
    r[n - i + 1][0] = n - i + 1;
    r[n - i + 1][1] = -1;
    int no = i - 1;
    int p = 1;
    while (no && p < 35) {
      ss = -1;
      query(0, 1, no, b[i]);
      int q;
      if (ss > 0) ss = find(0, ss, b[i]);
      q = ss;
      r[n - i + 1][p] = q;
      if (q == -1)
        break;
      else
        r[n - i + 1][p] = n - q + 1;
      no = q - 1;
      p++;
    }
    r[n - i + 1][p] = -1;
    merg(1, i, b[i]);
  }
  for (i = 1; i <= n; i++) a[i] = b[n - i + 1];
  build(1, 1, n);
  double s = 0;
  for (i = 1; i <= n; i++) {
    l[i][0] = i;
    l[i][1] = -1;
    int no = i - 1;
    int p = 1;
    while (no && p < 35) {
      ss = -1;
      query(1, 1, no, a[i]);
      int q;
      if (ss > 0) ss = find(1, ss, a[i]);
      q = ss;
      l[i][p] = q;
      if (q == -1) break;
      no = q - 1;
      p++;
    }
    l[i][p] = -1;
    double s1 = 0, s2 = 0;
    for (j = 0; j < p; j++) {
      int x;
      if (l[i][j + 1] == -1)
        x = l[i][j];
      else
        x = l[i][j] - l[i][j + 1];
      s1 += (1.0 * x) / er[j];
    }
    for (j = 0; j < 35 && r[i][j] != -1; j++) {
      int x;
      if (r[i][j + 1] == -1)
        x = n - r[i][j] + 1;
      else
        x = r[i][j + 1] - r[i][j];
      s2 += (1.0 * x) / er[j];
    }
    s += s1 * s2 * a[i] / 2;
    merg(1, i, a[i]);
  }
  s /= 1.0 * n * n;
  printf("%.10lf\n", s);
}
