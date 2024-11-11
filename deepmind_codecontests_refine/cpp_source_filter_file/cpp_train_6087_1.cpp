#include <bits/stdc++.h>
using namespace std;
const long long maxn = 1e5 + 20, maxt = 200, Mod = 1e9 + 7;
long long W[8], dp[8][maxt];
struct mat {
  long long part[maxt][maxt];
  long long* operator[](long long x) { return part[x]; }
};
mat zarb(mat A, mat B, long long le) {
  mat res;
  for (long long i = 0; i < le; i++) {
    for (long long j = 0; j < le; j++) {
      res[i][j] = 0;
      for (long long k = 0; k < le; k++) {
        res[i][j] = (res[i][j] + A[i][k] * B[j][k]) % Mod;
      }
    }
  }
  return res;
}
mat poww(mat A, long long le, long long B) {
  mat res = A;
  if (B == 1) {
    return res;
  }
  long long j = 8;
  while ((B & (1 << j)) == 0) j--;
  for (long long i = j - 1; i >= 0; i--) {
    res = zarb(res, res, le);
    if (B & (1 << i)) res = zarb(res, A, le);
  }
  return res;
}
int32_t main() {
  for (long long i = 1; i < 8; i++) {
    scanf("%d", &W[i]);
  }
  dp[0][0] = 1;
  for (long long i = 1; i < 8; i++) {
    mat D;
    for (long long j = 0; j < (1 << i); j++)
      for (long long k = 0; k < (1 << i); k++) D[j][k] = 0;
    for (long long j = 0; j < (1 << i); j++) {
      for (long long k = 0; k < (1 << i); k++) {
        for (long long l = 0; l < (1 << (i - 1)); l++) {
          long long flag = 0;
          if ((l & (1 << 0)) && (j & (1 << 0)) && (k & (1 << 0))) continue;
          for (long long m = 1; m < i - 1; m++) {
            if ((l & (1 << m)) && (l & (1 << (m - 1))) && (j & (1 << m)) &&
                (k & (1 << m)))
              flag = 1;
          }
          if (flag || ((l & (1 << (i - 2))) && (j & (1 << (i - 1))) &&
                       (k & (1 << (i - 1)))))
            continue;
          if (i == 1 && j == 1 && k == 1 && l == 0) continue;
          D[j][k]++;
        }
      }
    }
    for (long long j = 0; j < (1 << (i - 1)); j++) {
      dp[i - 1][j + (1 << (i - 1))] = dp[i - 1][j];
      dp[i - 1][j] = 0;
    }
    for (long long j = 0; j < (1 << i); j++) {
      dp[i][j] = dp[i - 1][j];
    }
    if (W[i] == 0) continue;
    mat tmp = poww(D, (1 << i), W[i]);
    for (long long j = 0; j < (1 << i); j++) {
      long long res = 0;
      for (long long k = 0; k < (1 << i); k++) {
        res = (res + tmp[j][k] * dp[i - 1][k]) % Mod;
      }
      dp[i][j] = res;
    }
  }
  cout << dp[7][127] << endl;
  ;
  return 0;
}
