#include <bits/stdc++.h>
using namespace std;
const int maxn = 105;
int q, n, k;
int f[maxn][maxn], ans[maxn];
bitset<maxn * maxn> g[maxn];
int main() {
  n = 100;
  f[4][1] = 2;
  f[4][2] = 4;
  f[4][3] = 1;
  f[4][4] = 3;
  for (int i = 5; i <= n; i++) {
    int p = 1;
    while (f[i - 1][p] == i - 1 || f[i - 1][p + 1] == i - 1) p++;
    for (int j = 1; j <= i; j++) {
      if (j <= p)
        f[i][j] = f[i - 1][j];
      else if (j == p + 1)
        f[i][j] = i;
      else
        f[i][j] = f[i - 1][j - 1];
    }
  }
  g[1][1] = 1;
  for (int i = 2; i <= n; i++) {
    for (int j = 2; j <= i; j++) {
      if (j >= 4) g[i] |= g[i - j + 1] << j;
      g[i] |= g[i - j + 1] << (j * (j + 1) / 2 - 1);
    }
  }
  scanf("%d", &q);
  while (q--) {
    scanf("%d%d", &n, &k);
    if (!g[n][k])
      puts("NO");
    else {
      puts("YES");
      int l = 1, r = n, cl = 1, cr = n, t = 0;
      while (true) {
        if (l == r) {
          ans[l] = cl;
          break;
        }
        for (int i = 2; i <= r - l + 1; i++) {
          if (i >= 4 && k >= i && g[r - l - i + 2][k - i]) {
            for (int j = 1; j < i; j++) {
              if (f[i][j] < f[i][i])
                ans[l + j - 1] = cl + f[i][j] - 1;
              else
                ans[l + j - 1] = cr - (i - f[i][j]);
            }
            l += i - 1;
            cl += f[i][i] - 1;
            cr = cl + n - i;
            k -= i;
            break;
          }
          if (k >= i * (i + 1) / 2 - 1 &&
              g[r - l - i + 2][k - i * (i + 1) / 2 + 1]) {
            if (t == 0) {
              for (int j = 1; j < i; j++) ans[l + j - 1] = cl + j - 1;
              l += i - 1;
              cl += i - 1;
            } else {
              for (int j = 1; j < i; j++) ans[l + j - 1] = cr - j + 1;
              l += i - 1;
              cr -= i - 1;
            }
            k -= i * (i + 1) / 2 - 1;
            break;
          }
        }
        t ^= 1;
      }
      for (int i = 1; i <= n; i++) printf("%d%c", ans[i], i == n ? '\n' : ' ');
    }
  }
  return 0;
}
