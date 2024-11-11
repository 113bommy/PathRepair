#include <bits/stdc++.h>
using namespace std;
const int N = 1e5 + 5;
char s[N];
long long l[N], f[N], g[N];
int main() {
  int n;
  scanf("%d", &n);
  for (int i = 1; i <= n; ++i) scanf("%lld", &l[i]);
  scanf("%s", s + 1);
  int fg = 0, ix;
  for (int i = 1; i <= n; ++i) {
    if (s[i] == 'G') {
      f[i] = f[i - 1] + 5 * l[i];
      g[i] = g[i - 1] + l[i];
      if (!fg) fg = 1, ix = i;
    } else if (s[i] == 'L') {
      if (g[i - 1] < l[i]) {
        long long add = l[i] - g[i - 1];
        if (fg == 1) {
          f[i] += 5 * add;
        } else {
          f[i] += 3 * add;
        }
        f[i] += f[i - 1] + l[i];
        g[i] = 0;
      } else {
        f[i] = f[i - 1] + l[i];
        g[i] = g[i - 1] - l[i];
      }
    } else {
      f[i] = f[i - 1] + 3 * l[i];
      g[i] = g[i - 1] + l[i];
      if (fg != 2) fg = 2, ix = i;
    }
  }
  long long G = 0, tmp = 0, T = f[n], S = 0;
  for (int i = 1; i <= n; ++i) {
    if (s[i] == 'G') G += 2 * l[i];
    S = g[i];
    if (G > S) G = S;
  }
  T -= 2 * G;
  T -= (S - G);
  printf("%lld\n", T);
  return 0;
}
