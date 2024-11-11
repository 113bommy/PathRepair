#include <bits/stdc++.h>
using namespace std;
inline int read() {
  char ch = getchar();
  int u = 0, f = 1;
  while (!isdigit(ch)) {
    if (ch == '-') f = -1;
    ch = getchar();
  }
  while (isdigit(ch)) {
    u = (u << 1) + (u << 3) + ch - 48;
    ch = getchar();
  }
  return u * f;
}
const int maxn = 5005;
int f[maxn][3], n, a[maxn];
int main() {
  n = read();
  for (int i = 1; i <= n; ++i) a[i] = read();
  memset(f, 0x3f, sizeof f);
  f[0][0] = f[1][1] = 0;
  for (int i = 2; i <= n; ++i) {
    for (int j = (i + 1) / 2; j >= 1; --j) {
      f[j][0] = min(f[j][0], f[j][2]);
      f[j][2] = f[j][1] + max(0, a[i] - a[i - 1] + 1);
      f[j][1] =
          min(f[j - 1][0] + max(0, a[i - 1] - a[i] + 1),
              f[j - 1][2] + max(0, min(a[i - 1], a[i - 2] - 1) - a[i] + 1));
    }
  }
  for (int i = 1; i <= (n + 1) / 2; ++i)
    cout << min(min(f[i][0], f[i][1]), f[i][2]) << " ";
  return 0;
}
