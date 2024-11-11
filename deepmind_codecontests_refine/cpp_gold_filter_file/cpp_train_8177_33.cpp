#include <bits/stdc++.h>
using namespace std;
bitset<4010> a[2010];
int n, m;
int x[2000010], y[2000010];
inline int read() {
  int ans = 0;
  char ch = getchar();
  while (ch < '0' || ch > '9') ch = getchar();
  while (ch >= '0' && ch <= '9')
    ans = (ans << 1) + (ans << 3) + ch - '0', ch = getchar();
  return ans;
}
void gauss() {
  for (int i = 1; i <= n; i++) {
    int pos = 0;
    for (int j = i; j <= n; j++)
      if (a[j][i]) {
        pos = j;
        break;
      }
    if (pos != i) swap(a[i], a[pos]);
    for (int j = 1; j <= n; j++)
      if (i != j && a[j][i]) a[j] ^= a[i];
  }
}
int main() {
  n = read(), m = read();
  for (int i = 1; i <= m; i++) {
    x[i] = read(), y[i] = read();
    a[x[i]][y[i]] = 1;
  }
  for (int i = 1; i <= n; i++) a[i][i + n] = 1;
  gauss();
  for (int i = 1; i <= m; i++)
    if (a[y[i]][x[i] + n])
      puts("NO");
    else
      puts("YES");
}
