#include <bits/stdc++.h>
using namespace std;
const int N = 110000, K = 205, mod = 998244343;
int n, a[N], f[K][2], sum[K][2], ans;
template <class T>
inline void read(T &x) {
  x = 0;
  char ch = getchar(), w = 0;
  while (!isdigit(ch)) w = (ch == '-'), ch = getchar();
  while (isdigit(ch)) x = (x << 1) + (x << 3) + (ch ^ 48), ch = getchar();
  x = w ? -x : x;
  return;
}
inline int addMod(int x, int y) { return (x += y) >= mod ? x - mod : x; }
int main() {
  read(n);
  for (register int i = 1; i <= n; ++i) read(a[i]);
  if (a[1] == -1) {
    for (register int i = 1; i <= 200; ++i) f[i][0] = 1;
  } else
    f[a[1]][0] = 1;
  for (register int i = 2; i <= n; ++i) {
    for (register int j = 1; j <= 200; ++j)
      sum[j][0] = addMod(sum[j - 1][0], f[j][0]),
      sum[j][1] = addMod(sum[j - 1][1], f[j][1]);
    for (register int j = 1; j <= 200; ++j)
      f[j][0] = addMod(sum[j - 1][0], sum[j - 1][1]),
      f[j][1] = addMod(addMod(sum[200][1], mod - sum[j - 1][1]),
                       addMod(sum[j][0], mod - sum[j - 1][0]));
    if (a[i] != -1)
      for (register int j = 1; j <= 200; ++j)
        if (j != a[i]) f[j][0] = f[j][1] = 0;
  }
  for (register int i = 1; i <= 200; ++i) ans = addMod(ans, f[i][1]);
  cout << ans;
  return 0;
}
