#include <bits/stdc++.h>
using namespace std;
int sa[1007], n, t, x, d[1007], s;
bool f[1007], c[1007];
int main() {
  scanf("%d%d", &n, &x);
  for (int i = 1; i <= n; ++i) {
    scanf("%d", &t), sa[t] = i;
    if (t == 0) c[i] = 1;
  }
  for (int i = 1; i <= n; ++i) {
    if (!c[i]) continue;
    int kt = 1, t2 = 1, j = i;
    while (j) {
      if (j == x) kt = 0, t = t2;
      j = sa[j], ++t2;
    }
    if (kt) d[++s] = t2 - 1;
  }
  f[0] = 1;
  for (int i = 1; i <= s; ++i)
    for (int j = 1000; j >= i; --j)
      if (f[j - d[i]]) f[j] = 1;
  printf("%d\n", t);
  for (int i = 1; i <= n; ++i)
    if (f[i] && t + i <= n) printf("%d\n", t + i);
  return 0;
}
