#include <bits/stdc++.h>
int n, k;
char s[1000010];
int r[1000010], sa[1000010], rank[1000010], height[1000010], wa[1000010],
    wb[1000010], ws[1000010], wv[1000010];
int f[1000010], g[1000010], b[1000010];
bool q[1000010];
int cmp(int *r, int a, int b, int l) {
  return r[a] == r[b] && r[a + l] == r[b + l];
}
void da(int *r, int *sa, int n, int m) {
  int i, j, p, *x = wa, *y = wb, *t;
  for (i = 0; i < m; i++) ws[i] = 0;
  for (i = 0; i < n; i++) ws[x[i] = r[i]]++;
  for (i = 1; i < m; i++) ws[i] += ws[i - 1];
  for (i = n - 1; i >= 0; i--) sa[--ws[x[i]]] = i;
  for (j = 1, p = 1; p < n; j *= 2, m = p) {
    for (p = 0, i = n - j; i < n; i++) y[p++] = i;
    for (i = 0; i < n; i++)
      if (sa[i] >= j) y[p++] = sa[i] - j;
    for (i = 0; i < n; i++) wv[i] = x[y[i]];
    for (i = 0; i < m; i++) ws[i] = 0;
    for (i = 0; i < n; i++) ws[wv[i]]++;
    for (i = 1; i < m; i++) ws[i] += ws[i - 1];
    for (i = n - 1; i >= 0; i--) sa[--ws[wv[i]]] = y[i];
    for (t = x, x = y, y = t, x[sa[0]] = 0, p = 1, i = 1; i < n; i++)
      x[sa[i]] = cmp(y, sa[i - 1], sa[i], j) ? p - 1 : p++;
  }
}
void calheight(int *r, int n, int *height) {
  int i, j, k = 0;
  for (i = 1; i <= n; i++) rank[sa[i]] = i;
  for (i = 0; i < n; height[rank[i++]] = k)
    for (k ? k-- : 0, j = sa[rank[i] - 1]; r[i + k] == r[j + k]; k++)
      ;
}
void getfail(char *P, int *f) {
  int m = strlen(P);
  f[0] = f[1] = 0;
  for (int i = 1; i < m; i++) {
    int j = f[i];
    while (j && P[i] != P[j]) j = f[j];
    f[i + 1] = P[i] == P[j] ? j + 1 : 0;
  }
}
int m3(int a, int b, int c) {
  if (a > b) a = b;
  if (a > c) a = c;
  return a;
}
int main() {
  memset(q, false, sizeof(q));
  memset(b, 0, sizeof(b));
  scanf("%d%d", &n, &k);
  scanf("%s", s);
  getfail(s, f);
  for (int i = 0; i < n; i++) r[i] = s[i];
  r[++n] = 0;
  da(r, sa, n, 256);
  calheight(r, --n, height);
  g[0] = n;
  for (int i = rank[0] - 1; i && height[i + 1]; i--)
    g[sa[i]] = std::min(g[sa[i + 1]], height[i + 1]);
  for (int i = rank[0] + 1; i < n && height[i]; i++)
    g[sa[i]] = std::min(g[sa[i - 1]], height[i]);
  if (k == 1)
    for (int i = 1; i <= n; i++) b[i] = 1;
  for (int i = 1; i <= n; i++)
    if (f[i] > 0 && i % (i - f[i]) == 0 && (i / (i - f[i])) % k == 0) {
      q[i] = true;
      b[i] += 1;
      b[i + m3(i / k, g[i], n - i) + 1] -= 1;
    }
  for (int i = 1; i <= n; i++) {
    b[i] += b[i - 1];
    printf(b[i] ? "1" : "0");
  }
  putchar('\n');
  return 0;
}
