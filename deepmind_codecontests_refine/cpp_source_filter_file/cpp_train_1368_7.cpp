#include <bits/stdc++.h>
using namespace std;
inline int gi() {
  int w = 0, x = 0;
  char ch = 0;
  while (!isdigit(ch)) w |= ch == '-', ch = getchar();
  while (isdigit(ch)) x = (x << 1) + (x << 3) + (ch ^ 48), ch = getchar();
  return w ? -x : x;
}
int n, m;
int f[1000005][5][5], sum[1000005];
int main() {
  n = gi(), m = gi();
  memset(f, -1, sizeof(f));
  f[0][0][0] = 0;
  for (int i = 1; i <= n; i++) sum[gi()]++;
  for (int i = 1; i <= n; i++) {
    for (int j = 0; j < 3; j++) {
      for (int k = 0; k < 3; k++) {
        for (int l = 0; l < 3; l++)
          if (sum[i] < j + k + l)
            continue;
          else
            f[i][k][l] =
                max(f[i][k][l], f[i - 1][j][k] + (sum[i] - j - k - l) / 3 + l);
      }
    }
  }
  printf("%d\n", f[m][0][0]);
  return 0;
}
