#include <bits/stdc++.h>
using namespace std;
const long long M = 1e9 + 7;
char in[1002][1002];
long long dp[251];
int vt[] = {0000, 0020, 0104, 0124, 0505, 0525, 0555};
int hz[] = {0000, 0020, 0401, 0421, 0505, 0525, 0707};
int ct(int i, int j) {
  int u = 0;
  int k = 0;
  for (int a = i * 4 + 1; a < i * 4 + 4; a++) {
    for (int b = j * 4 + 1; b < j * 4 + 4; b++) {
      if (in[a][b] == 'O') {
        u |= (1 << k);
      }
      k++;
    }
  }
  int r = 0;
  for (int k = 0; k < 7; k++) {
    if (u == vt[k]) {
      r |= 1;
    }
    if (u == hz[k]) {
      r |= 2;
    }
  }
  return r;
}
bool check(int i, int j, int p, int q) {
  auto r = ct(i, j);
  auto s = ct(p, q);
  if (j == q) {
    return r & s & 1;
  } else {
    return r & s & 2;
  }
}
int main() {
  int n, m;
  scanf("%d%d", &n, &m);
  for (int i = 0; i < 4 * n + 1; i++) {
    scanf("%s", in[i]);
  }
  int v2[251] = {};
  dp[0] = 1;
  for (int j = 0; j < m; j++) {
    if (n % 2 == 0) {
      bool ok = true;
      for (int i = 0; i < n; i += 2) {
        if (!check(i, j, i + 1, j)) {
          ok = false;
          break;
        }
      }
      if (ok) {
        dp[j + 1] += dp[j];
        dp[j + 1] %= M;
        v2[j] = 1;
      }
    }
    if (j == 0) {
      continue;
    }
    long long dp2[251] = {};
    dp2[0] = 1;
    for (int i = 0; i < n; i++) {
      if (check(i, j - 1, i, j)) {
        dp2[i + 1] += dp2[i];
        dp2[i + 1] %= M;
      }
      if (i == 0) {
        continue;
      }
      if (check(i, j - 1, i - 1, j - 1) && check(i, j, i - 1, j)) {
        dp2[i + 1] += dp2[i - 1];
        dp2[i + 1] %= M;
      }
    }
    if (v2[j] && v2[j - 1]) {
      dp2[n] += M - 1;
      dp2[n] %= M;
    }
    dp[j + 1] += dp[j - 1] * dp2[n] % M;
    dp[j + 1] %= M;
  }
  printf("%lld\n", dp[m]);
  return 0;
}
