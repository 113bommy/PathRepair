#include <bits/stdc++.h>
using namespace std;
int n, now;
unsigned long long f[100200], ans = 1;
char c[100200];
inline int read() {
  int s = 0, w = 1;
  char ch = getchar();
  while (ch < '0' || ch > '9') {
    if (ch == '-') w = -1;
    ch = getchar();
  }
  while (ch >= '0' && ch <= '9')
    s = (s << 1) + (s << 3) + ch - '0', ch = getchar();
  return s * w;
}
signed main() {
  n = read();
  f[0] = 1;
  if (n & 1) {
    printf("0\n");
    return 0;
  }
  int m = n >> 1;
  scanf("%s", c + 1);
  for (int i = 1; i <= n; i++)
    if (c[i] == '?')
      for (int j = i >> 1; j >= i - m && j; j--) f[j] += f[j - 1];
    else
      now++;
  for (int i = 1; i <= m - now; i++) ans *= 25;
  cout << ans * f[m];
  return 0;
}
