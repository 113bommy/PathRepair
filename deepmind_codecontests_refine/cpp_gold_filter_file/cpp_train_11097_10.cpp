#include <bits/stdc++.h>
using namespace std;
long long k;
int numx[35], numy[35], numk[35];
long long sum[35][2][2][2], num[35][2][2][2];
long long ask(long long x, long long y) {
  long long ans = 0;
  long long z = k;
  if (x < 0 || y < 0) return 0;
  memset(sum, 0, sizeof(sum));
  memset(num, 0, sizeof(num));
  for (int i = 0; i < 32; i++) {
    numx[i] = x % 2;
    numy[i] = y % 2;
    numk[i] = z % 2;
    x >>= 1;
    y >>= 1;
    z >>= 1;
  }
  num[32][1][1][1] = 1;
  sum[32][1][1][1] = 0;
  int im, jm;
  for (int lens = 32; lens >= 0; lens--)
    for (int i = 0; i < 2; i++)
      for (int j = 0; j < 2; j++)
        for (int kk = 0; kk < 2; kk++)
          if (num[lens][i][j][kk]) {
            if (lens == 0) {
              ans = (ans + num[lens][i][j][kk] + sum[lens][i][j][kk]) %
                    1000000007;
              continue;
            }
            im = jm = 1;
            if (i) im = numx[lens - 1];
            if (j) jm = numy[lens - 1];
            for (int nowi = 0; nowi <= im; nowi++)
              for (int nowj = 0; nowj <= jm; nowj++) {
                if (!kk || (nowi ^ nowj) <= numk[lens - 1]) {
                  num[lens - 1][nowi == im && i][nowj == jm && j]
                     [(nowi ^ nowj == numk[lens - 1]) && kk] =
                         (num[lens - 1][nowi == im && i][nowj == jm && j]
                             [(nowi ^ nowj == numk[lens - 1]) && kk] +
                          num[lens][i][j][kk]) %
                         1000000007;
                  sum[lens - 1][nowi == im && i][nowj == jm && j]
                     [(nowi ^ nowj == numk[lens - 1]) && kk] =
                         (sum[lens - 1][nowi == im && i][nowj == jm && j]
                             [(nowi ^ nowj == numk[lens - 1]) && kk] +
                          (sum[lens][i][j][kk] << 1) +
                          (nowi ^ nowj) * num[lens][i][j][kk]) %
                         1000000007;
                }
              }
          }
  return ans;
}
int main() {
  int q;
  long long x1, y1, x2, y2;
  scanf("%d", &q);
  while (q--) {
    scanf("%lld%lld%lld%lld%lld", &x1, &y1, &x2, &y2, &k);
    x1--;
    y1--;
    x2--;
    y2--;
    k--;
    printf("%lld\n", (ask(x2, y2) - ask(x2, y1 - 1) - ask(x1 - 1, y2) +
                      ask(x1 - 1, y1 - 1) + 1000000007 * 2) %
                         1000000007);
  }
  return 0;
}
