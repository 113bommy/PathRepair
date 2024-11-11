#include <bits/stdc++.h>
using namespace std;
int gethex(long long val, int place) { return (val >> (4 * place)) & 15; }
int K, T;
long long cho[40][40];
long long dp[17][11];
int lim[16];
long long nways(int sum, int nvar) {
  if (nvar == 0) {
    return sum == 0;
  }
  return cho[sum + nvar - 1][nvar - 1];
}
void getdp(bool ok0) {
  memset(dp, 0, sizeof(dp));
  if (*min_element(lim, lim + 16) < 0) {
    return;
  }
  dp[16][0] = 1;
  for (int i = 15; i >= 0; i--) {
    for (int j = 0; j < 11; j++) {
      for (int k = 0; k <= lim[i] && j + k < 11; k++) {
        if (ok0) {
          dp[i][j + k] += dp[i + 1][j] * nways(k, j + 1);
        } else if (i || j || (!j && !k)) {
          dp[i][j + k] += dp[i + 1][j] * nways(k, j + bool(i));
        }
      }
    }
  }
}
long long moo(long long g) {
  long long vg = g;
  int lg16 = 0;
  while (vg >= 16) {
    vg /= 16;
    lg16++;
  }
  fill_n(lim, 16, T);
  getdp(false);
  long long ans = 0;
  for (int i = 1; i <= lg16; i++) {
    ans += dp[0][i];
  }
  for (int i = lg16; i >= 0; i--) {
    int digi = gethex(g, i);
    for (int j = (i == lg16); j < digi; j++) {
      fill_n(lim, 16, T);
      lim[j]--;
      for (int k = lg16; k > i; k--) {
        lim[gethex(g, k)]--;
      }
      getdp(true);
      ans += dp[0][i];
    }
  }
  memset(lim, 0, sizeof(lim));
  for (int i = 0; i <= lg16; i++) {
    lim[gethex(g, i)]++;
  }
  bool gvalid = true;
  for (int i = 0; i < 16; i++) {
    if (lim[i] > T) {
      gvalid = false;
      break;
    }
  }
  memset(lim, 0, sizeof(lim));
  ans += gvalid;
  return ans;
}
int main() {
  scanf("%d %d", &K, &T);
  cho[0][0] = 1;
  for (int i = 1; i < 40; i++) {
    cho[i][0] = 1;
    for (int j = 1; j <= i; j++) {
      cho[i][j] = cho[i - 1][j] + cho[i - 1][j - 1];
    }
  }
  long long lo = 0, hi = 1ll << 36;
  while (lo < hi) {
    long long mid = (lo + hi) / 2;
    if (moo(mid) >= K) {
      hi = mid;
    } else {
      lo = mid + 1;
    }
  }
  printf("%llx\n", hi);
}
