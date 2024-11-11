#include <bits/stdc++.h>
using namespace std;
const int N = 5e2 + 9;
int f[N][N];
int n;
char s[N];
int read() {
  int f = 1, x = 0;
  char s = getchar();
  while (s < '0' || s > '9') {
    if (s == '-') f = -1;
    s = getchar();
  }
  while (s >= '0' && s <= '9') {
    x = (x << 1) + (x << 3) + (s ^ '0');
    s = getchar();
  }
  return f * x;
}
void prepare() {
  memset(f, 0x3f3f3f3f, sizeof(f));
  f[0][0] = 0;
  for (int i = 1; i <= n; i++) f[i][i] = 1;
  for (int len = 1; len <= n; len++)
    for (int i = 1; i + len <= n; i++) {
      int j = i + len;
      f[i][j] = f[i][j - 1] + 1;
    }
  for (int i = 1; i < n; i++)
    if (s[i] == s[i + 1]) f[i][i + 1] = 1;
}
void DP() {
  for (int len = 2; len <= n; len++)
    for (int i = 1; i + len - 1 <= n; i++) {
      int j = i + len - 1;
      for (int k = i; k < j; k++)
        if (s[k] == s[j])
          f[i][j] = min(f[i][j], f[i][k] + f[k + 1][j] - 1);
        else
          f[i][j] = min(f[i][j], f[i][k] + f[k + 1][j]);
    }
}
int main() {
  n = read();
  for (int i = 1; i <= n; i++) cin >> s[i];
  prepare();
  DP();
  printf("%d\n", f[1][n]);
  return 0;
}
