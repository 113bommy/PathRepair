#include <bits/stdc++.h>
using namespace std;
const int lg = 8, lg2 = 14, maxx = 1 << lg, maxx2 = 1 << lg2;
int n, k, B[lg];
int dp[maxx2][maxx][lg2];
long long ans[maxx2];
char A[lg2][lg2];
int main() {
  scanf("%d", &n);
  for (int i = 0; i < n; i++) {
    scanf("%s", A[i]);
  }
  int xx2 = 1 << n;
  int xx0 = (1 << ((n - 1) / 2));
  int xx1 = (1 << ((n) / 2));
  for (int mask1 = 0; mask1 < xx2; mask1++) {
    int sz = 0;
    for (int i = 0; i < n; i++) {
      if ((mask1 >> i) & 1) {
        B[sz++] = i;
      }
    }
    if (sz != (n + 2) / 2 && sz != (n + 1) / 2) {
      continue;
    }
    do {
      int mask2 = 0;
      for (int i = 0; i < sz - 1; i++) {
        if (A[B[i]][B[i + 1]] == '1') {
          mask2 |= 1 << i;
        }
      }
      dp[mask1][mask2][B[0]]++;
    } while (next_permutation(B, B + sz));
  }
  int xr = xx2 - 1;
  for (int i = 0; i < n; i++) {
    for (int mask = 0; mask < xx2; mask++) {
      int sz = 0;
      for (int j = 0; j < n; j++) {
        if ((mask >> j) & 1) {
          sz++;
        }
      }
      if (sz != (n + 1) / 2 || ((mask >> i) & 1) == 0) {
        continue;
      }
      for (int mask1 = 0; mask1 < xx0; mask1++) {
        int msk = mask1 * xx1;
        for (int mask2 = 0; mask2 < xx1; mask2++) {
          ans[msk ^ mask2] +=
              dp[mask][mask1][i] * dp[xr ^ mask ^ (1 << i)][mask2][i];
        }
      }
    }
  }
  for (int i = 0; i < xx2 / 2; i++) {
    int j = 0;
    for (int k = 0; k < n - 1; k++) {
      if (((i >> k) & 1) && k < (n) / 2) {
        j ^= (1 << ((n) / 2 - k - 1));
      }
      if (((i >> k) & 1) && k >= (n) / 2) {
        j ^= (1 << k);
      }
    }
    printf("%lld ", ans[j]);
  }
  printf("\n");
}
