#include <bits/stdc++.h>
const int N = 1000010;
const int P = 20;
int n, r, c, st[N];
char s[N * 6];
int f[N][P], sum[N];
int len, a[N];
bool ok(int l, int r) { return sum[r] - sum[l] + r - l - 1 <= c; }
int get(int x, int len) {
  for (int i = P - 1; i >= 0; i--) {
    if (len & (1 << i)) x = f[x][i];
  }
  return x;
}
int main() {
  scanf("%d%d%d", &n, &r, &c);
  for (int i = 1, len = 0; i <= n; i++) {
    scanf("%s", s + len);
    st[i] = len;
    a[i] = strlen(s + len);
    len = len + a[i] + 1;
  }
  sum[0] = 0;
  for (int i = 1; i <= n; i++) sum[i] = sum[i - 1] + a[i];
  for (int i = 0, j = 0; i <= n; i++) {
    while (j <= n && ok(i, j + 1)) j++;
    f[i][0] = j;
  }
  for (int i = n; i >= 0; i--) {
    for (int j = 1; j < P; j++) {
      f[i][j] = f[f[i][j - 1]][j - 1];
    }
  }
  int beg = -1, mx = -1;
  for (int i = 0; i <= n; i++) {
    int j = get(i, r);
    if (j - i > mx) mx = j - i, beg = i;
  }
  for (int i = 0; i < r; i++) {
    int xx = beg + 1;
    for (; xx <= n && ok(beg, xx);) {
      if (xx != beg + 1) putchar(' ');
      printf("%s", s + st[xx]);
      xx++;
    }
    puts("");
    if (xx == beg + 1) break;
    beg = xx - 1;
  }
}
