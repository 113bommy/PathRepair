#include <bits/stdc++.h>
using namespace std;
int n, m, a[202][202], r[202], c[202];
inline int output(bool check) {
  if (!check) {
    puts("NO");
    return 0;
  }
  puts("YES");
  for (int i = 1; i <= n; ++i) putchar(c[i] + '0');
  puts("");
  for (int i = 1; i <= m; ++i) putchar(r[i] + '0');
  return 0;
}
int main() {
  cin >> n >> m;
  for (int i = 1; i <= n; ++i)
    for (int j = 1; j <= m; ++j) scanf("%d", &a[i][j]);
  for (int i = 1; i <= m; ++i)
    if (a[1][i] == 0) r[i] ^= 1;
  for (int i = 0; i <= m; ++i) {
    if (i > 0) r[i] ^= 1;
    bool check = true;
    for (int j = 2; j <= n; ++j) {
      int tmp = 0;
      for (int k = 1; k <= m; ++k) tmp += a[j][k] ^ r[k];
      if (tmp == 0)
        c[j] = 1;
      else if (tmp == m)
        c[j] = 0;
      else {
        check = false;
        break;
      }
    }
    if (check) return output(true);
  }
  memset(c, 0, sizeof c);
  int now = 0;
  for (int i = 2; i <= n; ++i) {
    int tmp = 0;
    for (int j = 1; j <= m; ++j) tmp += a[i][j] ^ r[j];
    if (now == 0) {
      if (tmp == m)
        c[i] ^= 1;
      else if (tmp != 0) {
        now = 1;
        if (a[i][1] ^ r[1]) c[i] ^= 1;
        for (int k = 2; k <= m; ++k)
          if ((a[i][k - 1] ^ r[k - 1] ^ c[i]) > (a[i][k] ^ r[k] ^ c[i]))
            return output(false);
      }
    } else {
      if (tmp == 0)
        c[i] ^= 1;
      else if (tmp != m)
        return output(false);
    }
  }
  return output(true);
}
