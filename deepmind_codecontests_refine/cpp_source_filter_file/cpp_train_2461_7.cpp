#include <bits/stdc++.h>
inline int mod(int x) { return x < 1000000007 ? x : x - 1000000007; }
using namespace std;
int a[707][9], b[707][9], c[707], i, j, k, n, x;
char m[707];
int main() {
  scanf("%s", m), n = strlen(m), reverse(m, m + n);
  for (i = n; i; i--)
    for (j = 0, m[i - 1] ^= 48; j < 9; j++) {
      for (k = 0, c[i - 1] = (c[i] * 10ll + m[i - 1]) % 1000000007;
           k < m[i - 1]; k++)
        if (j < k)
          a[i - 1][j] = (a[i - 1][j] + 10ll * b[i][j] + 1) % 1000000007;
        else
          a[i - 1][j] = mod(a[i - 1][j] + b[i][j]);
      if (j < k)
        b[i - 1][j] = (10ll * b[i][j] + 1) % 1000000007;
      else
        b[i - 1][j] = b[i][j];
      for (k = 0; k <= j; k++) a[i - 1][j] = mod(a[i - 1][j] + a[i][j]);
      for (; k < 10; k++)
        a[i - 1][j] = (a[i - 1][j] + 10ll * a[i][j] + c[i]) % 1000000007;
    }
  for (i = 0; i < 9; i++) x = mod(x + a[0][i] + b[0][i]);
  return 0 & printf("%d\n", x);
}
