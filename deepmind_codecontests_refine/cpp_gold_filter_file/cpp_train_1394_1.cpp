#include <bits/stdc++.h>
using namespace std;
long long mod = 1000000007LL;
int numb[51][51];
int cnt[2];
long long OPT[510][51][51];
long long add(long long a, long long b) { return (a + b) % mod; }
long long mul(long long a, long long b) { return (a * b) % mod; }
long long nCr[51][51];
int main() {
  for (int i = 0; i <= 50; i++) {
    nCr[i][0] = nCr[i][i] = 1;
    for (int j = 1; j < i; j++)
      nCr[i][j] = add(nCr[i - 1][j], nCr[i - 1][j - 1]);
  }
  int n, w;
  cin >> n >> w;
  for (int i = 0; i < n; i++) {
    int m;
    scanf("%d", &m);
    cnt[(m - 1) / 50]++;
  }
  OPT[0][cnt[0]][cnt[1]] = 1;
  for (int time = 0; time < 500; time++) {
    if (OPT[time][0][0]) {
      cout << time << endl;
      cout << OPT[time][0][0] << endl;
      return 0;
    }
    if (time & 1) {
      for (int j = 0; j <= cnt[0]; j++) {
        for (int k = 0; k <= cnt[1]; k++) {
          for (int a = 0; a <= cnt[0] - j; a++) {
            for (int b = 0; b <= cnt[1] - k; b++) {
              if ((a == 0) && (b == 0)) continue;
              if (a * 50 + b * 100 > w) break;
              OPT[time + 1][j + a][k + b] =
                  add(OPT[time + 1][j + a][k + b],
                      mul(mul(OPT[time][j][k], nCr[cnt[0] - j][a]),
                          nCr[cnt[1] - k][b]));
            }
          }
        }
      }
    } else {
      for (int j = 0; j <= cnt[0]; j++) {
        for (int k = 0; k <= cnt[1]; k++) {
          for (int a = 0; a <= j; a++) {
            for (int b = 0; b <= k; b++) {
              if ((a == 0) && (b == 0)) continue;
              if (a * 50 + b * 100 > w) break;
              OPT[time + 1][j - a][k - b] =
                  add(OPT[time + 1][j - a][k - b],
                      mul(mul(OPT[time][j][k], nCr[j][a]), nCr[k][b]));
            }
          }
        }
      }
    }
  }
  cout << -1 << endl << 0 << endl;
}
