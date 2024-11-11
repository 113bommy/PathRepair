#include <bits/stdc++.h>
using namespace std;
int T, n, m, k, a[350005], ans, res;
int read() {
  int res = 0, op = 1;
  char ch = getchar();
  while (!isdigit(ch)) {
    if (ch == '-') op = -1;
    ch = getchar();
  }
  while (isdigit(ch)) res = res * 10 + ch - '0', ch = getchar();
  return res * op;
}
void write(int x) {
  if (x > 9) write(x / 10);
  putchar(x % 10 + 48);
}
int main() {
  T = read();
  while (T--) {
    n = read(), m = read(), k = read();
    k = min(k, m - 1);
    m = n - m;
    ans = 0;
    for (int i = 1; i <= n; i++) a[i] = read();
    for (int L = 1, R = n - k; R <= n; L++, R++) {
      res = 1e9;
      for (int i = L, j = L + m; j <= R; i++, j++)
        res = min(res, max(a[i], a[j]));
      if (res < 1e9) ans = max(ans, res);
    }
    printf("%d\n", ans);
  }
  return 0;
}
