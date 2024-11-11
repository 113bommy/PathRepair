#include <bits/stdc++.h>
using namespace std;
inline int read() {
  int x = 0, f = 1, ch = getchar();
  while (ch < '0' || ch > '9') {
    if (ch == '-') {
      f = -1;
    }
    ch = getchar();
  }
  while (ch >= '0' && ch <= '9') {
    x = x * 10 + ch - '0';
    ch = getchar();
  }
  return x * f;
}
bitset<2005> a[2005], inv[2005];
int n, flag;
inline void guess() {
  for (int i = 1; i <= n; i++) {
    int tot = i;
    while (!a[i][tot] && tot <= n) tot++;
    if (tot > n) {
      flag = 1;
      break;
    }
    swap(a[i], a[tot]), swap(inv[i], inv[tot]);
    for (int j = 1; j <= n; j++)
      if (j != i && a[j][i]) a[j] ^= a[i], inv[j] ^= inv[i];
  }
}
int m;
int p1[500005], p2[500005];
int main() {
  n = read(), m = read();
  for (int i = 1; i <= m; i++) p1[i] = read(), p2[i] = read();
  for (int i = 1; i <= m; i++) a[p1[i]][p2[i]] = 1;
  for (int i = 1; i <= n; i++) inv[i][i] = 1;
  guess();
  for (int i = 1; i <= m; i++) {
    if (flag || inv[p2[i]][p1[i]])
      puts("NO");
    else
      puts("YES");
  }
  return 0;
}
