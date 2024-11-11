#include <bits/stdc++.h>
using namespace std;
const int mod = 1e9 + 7;
template <typename T1, typename T2>
void chadd(T1 &a, T2 b) {
  a += b;
  if (a >= mod) a -= mod;
}
int dp[1005][1005][2][2][2][2][2];
int weight[5];
int multer[5];
int n, k;
inline int mul(int a, int b) { return 1LL * a * b % mod; }
int main() {
  cin >> n >> k;
  dp[1][0][1][0][0][0][0] = 1;
  dp[2][0][1][0][0][1][0] = 1;
  dp[2][2][0][1][1][0][1] = 1;
  int np1, np2, np3, np4, np5;
  for (int i = 2; i < n; i++) {
    for (int j = 0; j <= n; j++) {
      for (int p1 = 0; p1 < 2; p1++) {
        for (int p2 = 0; p2 < 2; p2++) {
          if (p1 && p2) {
            continue;
          }
          for (int p3 = 0; p3 < 2; p3++) {
            if (p1 && p3) {
              continue;
            }
            for (int p4 = 0; p4 < 2; p4++) {
              if (p2 && p4 || p3 && p4) {
                continue;
              }
              for (int p5 = 0; p5 < 2; p5++) {
                if (p3 && (!p5)) {
                  continue;
                }
                int tj = j - p2 - p5;
                if (tj < 0) {
                  continue;
                }
                memset(weight, 0, sizeof(weight));
                memset(multer, 0, sizeof(multer));
                weight[0] = -0 + 0;
                multer[0] = 1;
                weight[1] = p1 - p2 + 1;
                multer[1] = 1;
                weight[2] = -p5 + p3 + 0;
                multer[2] = 1;
                weight[3] = -1 + 0;
                multer[3] = tj;
                weight[4] = -0 + 0;
                multer[4] = i - 2 - tj;
                if ((!p1) && (!p3)) {
                  multer[4]--;
                }
                if (multer[4] < 0) {
                  continue;
                }
                for (int place = 0; place < 5; place++) {
                  if (j + weight[place] < 0) {
                    continue;
                  }
                  np1 = (place == 0);
                  np2 = ((p1 && place == 1) || (p3 && place == 2));
                  np3 = (place == 1);
                  np4 = (p1 && place != 1);
                  np5 = (place != 1 && p2 || place == 1);
                  chadd(dp[i + 1][j + weight[place]][np1][np2][np3][np4][np5],
                        mul(multer[place], dp[i][j][p1][p2][p3][p4][p5]));
                }
                if ((!p1) && (!p3)) {
                  chadd(dp[i + 1][j + 1][0][1][0][0][p2],
                        dp[i][j][p1][p2][p3][p4][p5]);
                }
              }
            }
          }
        }
      }
    }
  }
  int res = 0;
  for (int p1 = 0; p1 < 2; p1++) {
    for (int p2 = 0; p2 < 2; p2++) {
      for (int p3 = 0; p3 < 2; p3++) {
        for (int p4 = 0; p4 < 2; p4++) {
          for (int p5 = 0; p5 < 2; p5++) {
            chadd(res, dp[n][k][p1][p2][p3][p4][p5]);
          }
        }
      }
    }
  }
  cout << res << endl;
  return 0;
}
