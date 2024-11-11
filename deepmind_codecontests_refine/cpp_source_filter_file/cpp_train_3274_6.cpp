#include <bits/stdc++.h>
using namespace std;
const int p[17] = {0,  2,  3,  5,  7,  11, 13, 17, 19,
                   23, 29, 31, 37, 41, 43, 47, 53};
int f[108][1 << 17], n, a[108], tmp[11], s[108][1 << 11], l[108][1 << 11];
void dd(int d, int ap) {
  if (!d) return;
  dd(d - 1, l[d][ap]);
  printf("%d ", s[d][ap]);
}
int main() {
  scanf("%d", &n);
  for (int i = 1; i <= n; i++) scanf("%d", a + i);
  memset(f, 127, sizeof(f));
  f[0][0] = 0;
  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= 60; j++) {
      int t = abs(j - a[i]), o = j, w = 0;
      for (int k = 1; k <= 16; k++)
        while (o % p[k] == 0) o /= p[k], w |= 1 << k - 1;
      for (int k = 0; k < 1 << 16; k++) {
        if (k & w) continue;
        int x = k | w;
        if (f[i][x] > f[i - 1][k] + t)
          f[i][x] = f[i - 1][k] + t, s[i][x] = j, l[i][x] = k;
      }
    }
  }
  int ans = 0x7ffffff, ap = -1;
  for (int i = 0; i < 1 << 16; i++)
    if (ans > f[n][i]) ans = f[n][i], ap = i;
  dd(n, ap);
  printf("\n");
  return 0;
}
