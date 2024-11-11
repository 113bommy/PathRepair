#include <bits/stdc++.h>
using namespace std;
int n;
int m;
int k;
const long long int MOD2 = 4LL * 1000000007LL * 1000000007LL;
long long int dp[14][1 << 4];
long long int tmp[14][1 << 14];
long long int bt[208][208];
int mxt;
inline int id(int a, int b) {
  mxt = max(mxt, (a << m) + b + 1);
  return (a << m) + b;
}
long long int mat[208][208];
long long int ret[208][208];
int zero_lef[208];
int zero_rig[208];
int zero_lef2c[208];
int zero_rig2c[208];
int zero_lef2[208];
int zero_rig2[208];
int main() {
  cin >> n >> k >> m;
  for (int i2 = n; i2 >= n; i2--) {
    int cnt = 0;
    for (int i = 0; i <= k; i++) {
      for (int j = 0; j < (1 << m); j++) {
        int ava = 0;
        for (int k = 0; k < m; k++) {
          if ((j >> k) & 1) {
            ava++;
          }
        }
        ava++;
        int wa = ((j << 1) & ((1 << m) - 1));
        bt[id(i, wa)][id(i, j)] = 1;
        wa++;
        if (i + 1 <= k) {
          bt[id(i + 1, wa)][id(i, j)] = ava;
        }
      }
    }
  }
  for (int i = 0; i < mxt; i++) mat[i][i] = 1, zero_lef[i] = zero_rig[i] = i;
  for (int i = 0; i < mxt; i++)
    zero_lef2c[i] = zero_lef2[i] = 0, zero_rig2c[i] = zero_rig2[i] = mxt - 1;
  int N = n;
  n = mxt;
  while (N) {
    if ((N & 1LL)) {
      for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++) ret[i][j] = 0;
      for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
          for (int k = zero_lef[i]; k <= zero_rig[i]; k++) {
            ret[i][j] += mat[i][k] * bt[k][j];
            if (ret[i][j] >= MOD2) ret[i][j] -= MOD2;
          }
        }
      }
      for (int i = 0; i < n; i++) zero_lef[i] = INT_MAX, zero_rig[i] = INT_MIN;
      for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++) {
          mat[i][j] = ret[i][j];
          if (mat[i][j] >= 1000000007LL) mat[i][j] %= 1000000007LL;
          if (mat[i][j]) {
            zero_lef[i] = min(zero_lef[i], j);
            zero_rig[i] = max(zero_rig[i], j);
          }
        }
    }
    N >>= 1LL;
    if (N == 0) break;
    for (int i = 0; i < n; i++)
      for (int j = 0; j < n; j++) ret[i][j] = 0;
    for (int i = 0; i < n; i++) {
      for (int j = 0; j < n; j++) {
        int L = max(zero_lef2[i], zero_lef2c[i]);
        int R = min(zero_rig2[j], zero_rig2c[j]);
        for (int k = L; k <= R; k++) {
          ret[i][j] += bt[i][k] * bt[k][j];
          if (ret[i][j] >= MOD2) ret[i][j] -= MOD2;
        }
      }
    }
    for (int i = 0; i < n; i++)
      zero_lef2c[i] = zero_lef2[i] = INT_MAX,
      zero_rig2c[i] = zero_rig2[i] = INT_MIN;
    for (int i = 0; i < n; i++)
      for (int j = 0; j < n; j++) {
        bt[i][j] = ret[i][j];
        if (bt[i][j] >= 1000000007LL) bt[i][j] %= 1000000007LL;
        if (bt[i][j]) {
          zero_lef2[i] = min(zero_lef2[i], j);
          zero_rig2[i] = max(zero_rig2[i], j);
        }
      }
    for (int j = 0; j < n; j++)
      for (int i = 0; i < n; i++) {
        if (bt[i][j]) {
          zero_lef2c[j] = min(zero_lef2c[j], i);
          zero_rig2c[j] = max(zero_rig2c[j], i);
        }
      }
  }
  long long int ans = 0;
  for (int j = 0; j < (1 << m); j++) {
    ans += mat[id(k, j)][0];
    if (ans >= MOD2) ans -= MOD2;
  }
  ans %= 1000000007LL;
  printf("%lld\n", ans);
  return 0;
}
