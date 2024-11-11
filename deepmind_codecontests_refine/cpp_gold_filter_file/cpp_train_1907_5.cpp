#include <bits/stdc++.h>
using namespace std;
template <typename T, typename U>
inline void smin(T &a, const U &b) {
  if (a > b) a = b;
}
template <typename T, typename U>
inline void smax(T &a, const U &b) {
  if (a < b) a = b;
}
template <class T>
inline void gn(T &first) {
  char c, sg = 0;
  while (c = getchar(), (c > '9' || c < '0') && c != '-')
    ;
  for ((c == '-' ? sg = 1, c = getchar() : 0), first = 0; c >= '0' && c <= '9';
       c = getchar())
    first = (first << 1) + (first << 3) + c - '0';
  if (sg) first = -first;
}
template <class T1, class T2>
inline void gn(T1 &x1, T2 &x2) {
  gn(x1), gn(x2);
}
int power(int a, int b, int m, int ans = 1) {
  for (; b; b >>= 1, a = 1LL * a * a % m)
    if (b & 1) ans = 1LL * ans * a % m;
  return ans;
}
char s[155];
int a[155];
int best[155][155], pal[155][155][155];
int main() {
  int n;
  gn(n);
  for (int i = 1; i <= n; i++) {
    gn(a[i]);
    if (a[i] == -1) a[i] = -0x3f3f3f3f;
  }
  scanf("%s", s + 1);
  for (int i = 1; i <= n; i++)
    for (int j = i; j <= n; j++)
      for (int k = 0; k <= n; k++) pal[i][j][k] = -0x3f3f3f3f;
  for (int i = 1; i <= n; i++) {
    pal[i][i][1] = 0;
    pal[i][i][0] = a[1];
    smax(best[i][i], a[1]);
  }
  for (int L = 2; L <= n; L++) {
    for (int i = 1; i <= n; i++) {
      int j = i + L - 1;
      if (j > n) break;
      for (int k = 1; k <= L; k++) {
        if (s[i] == s[j] && k > 1) smax(pal[i][j][k], pal[i + 1][j - 1][k - 2]);
        for (int m = i + k - 1; m < j; m++)
          smax(pal[i][j][k], pal[i][m][k] + pal[m + 1][j][0]);
        for (int m = i; m <= j - k; m++)
          smax(pal[i][j][k], pal[i][m][0] + pal[m + 1][j][k]);
        smax(pal[i][j][0], pal[i][j][k] + a[k]);
      }
      smax(best[i][j], pal[i][j][0]);
      for (int m = i; m < j; m++) smax(best[i][j], best[i][m] + best[m + 1][j]);
    }
  }
  printf("%d\n", best[1][n]);
  return 0;
}
