#include <bits/stdc++.h>
int n, i = 0, a[21][200001], c, d, y = 0, s = 2, L;
long long sum = 0;
void SuperSebasort(int tab[][200001], int l, int r) {
  int lim = 2, limi = l + 1, limj = l + 2, j = limi, i = l, k = l, x = 1;
  while (lim / 2 <= r - l + 1) {
    while (i <= r) {
      if (limj > r) limj = r + 1;
      if ((tab[x - 1][j] < tab[x - 1][i] && j < limj) || i >= limi)
        tab[x][k] = tab[x - 1][j], j++;
      else
        tab[x][k] = tab[x - 1][i], i++;
      k++;
      if (i == limi && j == limj) limi += lim, limj += lim, i = j, j = limi;
    }
    lim *= 2, limi = l + lim / 2, limj = l + lim, j = limi, i = k = l, x++;
  }
}
inline int bin(int x, int l, int r, int v) {
  int m;
  while (l <= r) {
    m = (l + r) / 2;
    if (a[x][m] > v)
      r = m - 1;
    else
      l = m + 1;
  }
  return l;
}
int main() {
  scanf("%d", &n);
  while (i < n) {
    scanf("%d", &a[0][i]);
    i++;
  }
  i = 0;
  SuperSebasort(a, 0, n - 1);
  while (i < n) {
    c = i + 1, d = a[0][i] - 1;
    if (n <= d) d = n - 1;
    while (c <= d) {
      while (c % s == 0 && c + s - 1 <= d) y++, s *= 2;
      while (c + (s / 2) - 1 > d && s > 0) y--, s /= 2;
      if (s == 0) break;
      L = c + (s / 2) - 1;
      sum = sum + L - bin(y, c, L, i) + 1;
      c = L + 1;
    }
    y = 0, s = 2, i++;
  }
  printf("%lld\n", sum);
  return 0;
}
