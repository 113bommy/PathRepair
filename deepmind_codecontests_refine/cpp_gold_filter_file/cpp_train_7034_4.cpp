#include <bits/stdc++.h>
using namespace std;
const int N = 300300, P = 1000000007;
int i, j, k, n, m, ch, An, ma;
long long x;
int a[N], b[N], f[N], g[N], A[N];
char s[N];
void R(int &x) {
  x = 0;
  ch = getchar();
  while (ch < '0' || '9' < ch) ch = getchar();
  while ('0' <= ch && ch <= '9') x = x * 10 + ch - '0', ch = getchar();
}
int main() {
  R(n);
  a[1] = 1;
  for (i = 2; i <= n; i++) R(a[i]);
  for (i = 1; i <= n; i++) R(b[i]);
  scanf("%s", s + 1);
  m = strlen(s + 1);
  for (i = 1; i <= m; i++) A[i] = s[m - i + 1] - '0';
  for (i = 1; i <= m; i += 4)
    A[++An] = A[i] + A[i + 1] * 10 + A[i + 2] * 100 + A[i + 3] * 1000;
  for (i = An + 1; i <= m; i++) A[i] = 0;
  f[0] = 1;
  for (i = 1; i <= n; i++) {
    if (a[i] != 1) {
      x = 0;
      for (j = An; j; j--) {
        x = x * 10000 + A[j];
        A[j] = x / a[i];
        x %= a[i];
      }
      while (An > 1 && !A[An]) An--;
      for (j = 0; j <= ma; j++) {
        if (j + x > ma)
          f[j] = 0;
        else
          f[j] = f[j + x];
      }
      while (ma && !f[ma]) ma--;
      for (j = 0; j * a[i] <= ma; j++) f[j] = f[j * a[i]];
      for (; j <= ma; j++) f[j] = 0;
      while (ma && !f[ma]) ma--;
    }
    ma += b[i];
    g[0] = f[0];
    for (j = 1; j <= ma; j++) g[j] = (g[j - 1] + f[j]) % P;
    for (j = 0; j <= ma; j++) {
      f[j] = g[j];
      if (j > b[i]) f[j] = (f[j] + P - g[j - b[i] - 1]) % P;
    }
  }
  if (An > 2) return puts("0"), 0;
  k = A[2] * 10000 + A[1];
  if (k > ma) return puts("0"), 0;
  printf("%d\n", f[k]);
}
