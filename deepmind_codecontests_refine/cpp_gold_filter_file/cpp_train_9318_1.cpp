#include <bits/stdc++.h>
using namespace std;
const long long sd = 17;
const int bl = 4, sbl = 2;
const int mm = 1000000007;
char ch[5111];
int mh[bl] = {1000000007, 1000000009, 0, 0};
long long h[bl][5111], pw[bl][5111];
int a[5111], f[5111][5111], s[5111][5111], i, j, k, n, sa[5111], rk[5111], ans;
bool cmp(int x, int y) {
  int i;
  for (i = 0; x + i <= n && y + i <= n; i++) {
    if (a[x + i] < a[y + i]) return 1;
    if (a[x + i] > a[y + i]) return 0;
  }
  return x > y;
}
bool hequ(int x, int y, int len) {
  int i;
  long long t1, t2;
  for (i = 0; i < bl; i++) {
    t1 = (h[i][x + len - 1] - h[i][x - 1] * pw[i][len] % mh[i] + mh[i]) % mh[i];
    t2 = (h[i][y + len - 1] - h[i][y - 1] * pw[i][len] % mh[i] + mh[i]) % mh[i];
    if (t1 != t2) return 0;
  }
  return 1;
}
int check(int x, int y, int len) {
  if (hequ(x, y, len)) return 0;
  return rk[x] > rk[y] ? 1 : -1;
}
int main() {
  srand(time(NULL));
  for (i = sbl; i < bl; i++) mh[i] = rand() * rand() % 1010000000;
  scanf("%d%s", &n, ch);
  for (i = 0; i < bl; i++)
    for (h[i][0] = 0, pw[i][0] = 1, j = 1; j <= n; j++)
      pw[i][j] = sd * pw[i][j - 1] % mh[i];
  for (i = 1; i <= n; i++) {
    a[i] = ch[i - 1] - '0';
    sa[i] = i;
    for (j = 0; j < bl; j++) h[j][i] = (sd * h[j][i - 1] + a[i] + 1) % mh[j];
  }
  sort(sa + 1, sa + 1 + n, cmp);
  for (i = 1; i <= n; i++) rk[sa[i]] = i;
  for (i = 1; i <= n; i++) {
    f[1][i] = 1;
    for (j = 2; j <= i; j++) {
      if (!a[j]) {
        f[j][i] = 0;
        continue;
      }
      k = i - j + 1;
      f[j][i] = s[max(1, j - k)][j - 1];
      if (j - k >= 1 && check(j - k, j, k) >= 0)
        f[j][i] = (f[j][i] - f[j - k][j - 1] + mm) % mm;
    }
    for (s[i][i] = f[i][i], j = i - 1; j; j--)
      s[j][i] = (s[j + 1][i] + f[j][i]) % mm;
  }
  for (i = 1; i <= n; i++) ans = (ans + f[i][n]) % mm;
  printf("%d\n", ans);
  return 0;
}
