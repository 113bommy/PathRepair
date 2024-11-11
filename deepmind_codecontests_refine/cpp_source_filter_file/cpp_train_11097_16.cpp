#include <bits/stdc++.h>
using namespace std;
const int md = 1e9 + 7;
long long f[40][2][2][2], sum[40][2][2][2];
int q, k, d[3][40], tmp[40];
void split(int x, int m) {
  for (int i = 1; i <= 30; i++) tmp[i] = (x >> (i - 1)) & 1;
  for (int i = 1; i <= 30; i++) d[m][i] = tmp[31 - i];
}
long long work(int x, int y) {
  if (x < 0 || y < 0) return 0;
  memset(f, 0, sizeof(f));
  memset(sum, 0, sizeof(sum));
  split(x, 0);
  split(y, 1);
  split(k, 2);
  f[0][0][0][0] = 1;
  for (int i = 0; i < 30; i++)
    for (int f1 = 0; f1 < 2; f1++)
      for (int f2 = 0; f2 < 2; f2++)
        for (int f3 = 0; f3 < 2; f3++)
          if (f[i][f1][f2][f3])
            for (int n1 = 0; n1 < 2; n1++)
              for (int n2 = 0; n2 < 2; n2++) {
                int nf1 = f1, nf2 = f2, nf3 = f3;
                if (nf1 == 0 && n1 > d[0][i + 1]) continue;
                if (n1 < d[0][i + 1]) nf1 = 1;
                if (nf2 == 0 && n2 > d[1][i + 1]) continue;
                if (n2 < d[1][i + 1]) nf2 = 1;
                int val = n1 ^ n2;
                if (nf3 == 0 && val > d[2][i + 1]) continue;
                if (val < d[2][i + 1]) nf3 = 1;
                f[i + 1][nf1][nf2][nf3] =
                    (f[i + 1][nf1][nf2][nf3] + f[i][f1][f2][f3]) % md;
                sum[i + 1][nf1][nf2][nf3] =
                    (sum[i + 1][nf1][nf2][nf3] + sum[i][f1][f2][f3] +
                     f[i][f1][f2][f3] * (val * 1ll << (29 - i)) % md) %
                    md;
              }
  long long ans = 0;
  for (int i = 0; i < 2; i++)
    for (int j = 0; j < 2; j++)
      for (int k = 0; k < 2; k++)
        ans = (ans + sum[30][i][j][k] + f[30][i][j][k]) % md;
  return ans;
}
int main() {
  scanf("%d", &q);
  while (q--) {
    int x1, y1, x2, y2;
    scanf("%d%d%d%d%d", &x1, &y1, &x2, &y2, &k);
    x1--;
    y1--;
    x2--;
    y2--;
    k--;
    printf("%I64d\n", (work(x2, y2) - work(x1 - 1, y2) - work(x2, y1 - 1) +
                       work(x1 - 1, y1 - 1) + 2ll * md) %
                          md);
  }
  return 0;
}
