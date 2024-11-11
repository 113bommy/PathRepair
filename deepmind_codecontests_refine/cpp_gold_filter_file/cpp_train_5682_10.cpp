#include <bits/stdc++.h>
using namespace std;
const int MAXN = 500000;
const int SUPERN = 5000000;
const int MAXS = 325;
const int SUPERS = 1000;
const int MD = 1e9 + 7;
long long s, g, rt, x, dp[60][200][2], v, re;
long long sum(long long a, long long b) { return (a + b) % MD; }
long long mu(long long a, long long b) { return (a * b) % MD; }
long long mn(long long a, long long b) { return (a - b + MD) % MD; }
long long solve(long long h1, long long h2, long long pc, long long su) {
  memset(dp, 0, sizeof(dp));
  dp[0][pc][0] = 1;
  for (int i = 1; i <= 60; ++i)
    for (int j = 0; j <= pc; ++j) {
      if ((1LL << i - 1) > su) {
        return dp[i - 1][0][0];
      }
      if (su & ((1LL << i - 1))) {
        if (i < h1 - 1 && i < h2 - 1) {
          dp[i][j][0] += dp[i - 1][j][1];
          dp[i][j][0] += 2 * (dp[i - 1][j + 1][0]);
          dp[i][j][1] += dp[i - 1][j + 2][1];
        }
        if (i < h1 - 1 && i == h2 - 1) {
          dp[i][j][1] += dp[i - 1][j + 2][1];
          dp[i][j][0] += dp[i - 1][j + 1][0];
        }
        if (i < h1 - 1 && i == h2) {
          dp[i][j][1] += dp[i - 1][j + 2][1];
          dp[i][j][0] += dp[i - 1][j + 1][0];
        }
        if (i < h1 - 1 && i > h2) {
          dp[i][j][0] += dp[i - 1][j + 1][0] + dp[i - 1][j][1];
        }
        if (i == h1 - 1 && i < h2 - 1) {
          dp[i][j][0] += dp[i - 1][j + 1][0] + dp[i - 1][j][1];
        }
        if (i == h1 - 1 && i == h2 - 1) {
          dp[i][j][0] += dp[i - 1][j + 1][0];
        }
        if (i == h1 - 1 && i == h2) {
          dp[i][j][0] += dp[i - 1][j + 1][0];
        }
        if (i == h1 - 1 && i > h2) {
          dp[i][j][0] += dp[i - 1][j][1];
        }
        if (i == h1 && i < h2 - 1) {
          dp[i][j][0] += dp[i - 1][j + 1][0];
          dp[i][j][1] += dp[i - 1][j + 2][1];
        }
        if (i == h1 && i == h2 - 1) {
          dp[i][j][1] += dp[i - 1][j + 2][1];
        }
        if (i == h1 && i == h2) {
          dp[i][j][1] += dp[i - 1][j + 2][1];
        }
        if (i == h1 && i > h2) {
          dp[i][j][0] += dp[i - 1][j + 1][0];
        }
        if (i > h1 && i < h2 - 1) {
          dp[i][j][0] += dp[i - 1][j + 1][0] + dp[i - 1][j][1];
        }
        if (i > h1 && i == h2 - 1) {
          dp[i][j][0] += dp[i - 1][j + 1][0];
        }
        if (i > h1 && i == h2) {
          dp[i][j][0] += dp[i - 1][j + 1][0];
        }
        if (i > h1 && i > h2) {
          dp[i][j][0] += dp[i - 1][j][1];
        }
      } else {
        if (i < h1 - 1 && i < h2 - 1) {
          dp[i][j][1] += 2 * (dp[i - 1][j + 1][1]);
          dp[i][j][0] += dp[i - 1][j][0];
          dp[i][j][1] += dp[i - 1][j + 2][0];
        }
        if (i < h1 - 1 && i == h2 - 1) {
          dp[i][j][1] += dp[i - 1][j + 1][1] + dp[i - 1][j + 2][0];
        }
        if (i < h1 - 1 && i == h2) {
          dp[i][j][1] += dp[i - 1][j + 1][1] + dp[i - 1][j + 2][0];
        }
        if (i < h1 - 1 && i > h2) {
          dp[i][j][0] += dp[i - 1][j][0];
          dp[i][j][1] += dp[i - 1][j + 1][1];
        }
        if (i == h1 - 1 && i < h2 - 1) {
          dp[i][j][0] += dp[i - 1][j][0];
          dp[i][j][1] += dp[i - 1][j + 1][1];
        }
        if (i == h1 - 1 && i == h2 - 1) {
          dp[i][j][1] += dp[i - 1][j + 1][1];
        }
        if (i == h1 - 1 && i == h2) {
          dp[i][j][1] += dp[i - 1][j + 1][1];
        }
        if (i == h1 - 1 && i > h2) {
          dp[i][j][0] += dp[i - 1][j][0];
        }
        if (i == h1 && i < h2 - 1) {
          dp[i][j][1] += dp[i - 1][j + 1][1] + dp[i - 1][j + 2][0];
        }
        if (i == h1 && i == h2 - 1) {
          dp[i][j][1] += dp[i - 1][j + 2][0];
        }
        if (i == h1 && i == h2) {
          dp[i][j][1] += dp[i - 1][j + 2][0];
        }
        if (i == h1 && i > h2) {
          dp[i][j][1] += dp[i - 1][j + 1][1];
        }
        if (i > h1 && i < h2 - 1) {
          dp[i][j][0] += dp[i - 1][j][0];
          dp[i][j][1] += dp[i - 1][j + 1][1];
        }
        if (i > h1 && i == h2 - 1) {
          dp[i][j][1] += dp[i - 1][j + 1][1];
        }
        if (i > h1 && i == h2) {
          dp[i][j][1] += dp[i - 1][j + 1][1];
        }
        if (i > h1 && i > h2) {
          dp[i][j][0] += dp[i - 1][j][0];
        }
      }
    }
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  cin >> s;
  for (int h1 = 1; h1 <= 60; ++h1)
    for (int h2 = 1; h2 <= 60; ++h2) {
      if (h1 == 0 && h2 == 0) {
        re++;
        continue;
      }
      g = (1LL << h1) + (1LL << h2) - 3;
      rt = s / g;
      if (rt == 0) continue;
      x = g + s % g + 1;
      for (int pc = 2; pc <= h1 + h2; ++pc) {
        if ((pc + x) % 2) continue;
        v = solve(h1, h2, pc, (pc + x) / 2);
        re += v;
      }
    }
  cout << re;
  return 0;
}
