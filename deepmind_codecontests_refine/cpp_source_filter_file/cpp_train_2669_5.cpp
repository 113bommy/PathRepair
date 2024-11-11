#include <bits/stdc++.h>
using namespace std;
int read() {
  char c;
  int x;
  while (c = getchar(), c < '0' || c > '9')
    ;
  x = c - '0';
  while (c = getchar(), c >= '0' && c <= '9') x = x * 10 + c - '0';
  return x;
}
int n, m, ans, f[25], lst[4200000], num[4200000];
int main() {
  n = read();
  m = read();
  for (int i = 1; i < (1 << n); i++) num[i] = num[i >> 1] + (i & 1);
  for (int i = 1; i < (1 << n); i++) lst[i] = (i & 1) ? 1 : lst[i >> 1] + 1;
  for (int i = 1; i <= n; i++) f[i] |= (1 << i - 1);
  for (int i = 1; i <= m; i++) {
    int x = read(), y = read();
    f[x] |= (1 << y - 1);
    f[y] |= (1 << x - 1);
  }
  for (int i = 1; i <= n; i++)
    if (f[i] != (1 << n - 1)) ans = (1 << i) - 1;
  for (int i = 1; i < (1 << n); i++) {
    int cheq = 0, vis = 0, Q = i & -i;
    for (int j = 1; j <= n; j++)
      if ((i & (1 << j - 1))) cheq |= f[j];
    if (cheq != (1 << n) - 1) continue;
    while (Q) {
      int p = lst[Q];
      Q ^= (1 << p - 1);
      vis |= (1 << p - 1);
      Q |= f[p] & i & ~vis;
    }
    if (vis == i && num[i] < num[ans]) ans = i;
  }
  printf("%d\n", num[ans]);
  for (int p = 1; ans; ans /= 2, p++)
    if (ans & 1) printf("%d ", p);
  return 0;
}
