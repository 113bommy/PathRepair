#include <bits/stdc++.h>
using namespace std;
long long dp[1001][1001][2][2];
int K;
const long long MOD = 1000000007LL;
long long Calc(int pos, int k, bool first, bool solved) {
  if (pos == -1) {
    return solved;
  } else {
    if (dp[pos][k][first][solved] == -1) {
      dp[pos][k][first][solved] = 0;
      if (solved) {
        int fac = 10;
        dp[pos][k][first][solved] = fac * Calc(pos - 1, k, first, true);
      } else {
        int fac1 = 2;
        if (!first) {
          dp[pos][k][first][solved] = fac1 * Calc(pos - 1, pos, true, false);
        } else {
          if (k - pos <= K) {
            dp[pos][k][first][solved] = fac1 * Calc(pos - 1, pos, true, true);
          } else {
            dp[pos][k][first][solved] = fac1 * Calc(pos - 1, pos, true, false);
          }
        }
        int fac2 = 8;
        dp[pos][k][first][solved] += fac2 * Calc(pos - 1, k, first, solved);
      }
      dp[pos][k][first][solved] %= MOD;
    }
    return dp[pos][k][first][solved];
  }
}
long long Solve(char* ch) {
  int len = strlen(ch);
  long long sol = 0;
  bool solution = false;
  int lastK = -1;
  int a = 0;
  for (int n = len - 1; n >= 0; n--, a++) {
    char help = '0';
    while (help != ch[a]) {
      if (help == '4' || help == '7') {
        if (lastK == -1) {
          sol += Calc(n - 1, n, true, false);
        } else {
          if (lastK - n <= K || solution) {
            sol += Calc(n - 1, 0, 0, true);
          } else {
            sol += Calc(n - 1, n, true, false);
          }
        }
      } else {
        if (lastK == -1) {
          sol += Calc(n - 1, 0, false, false);
        } else if (solution) {
          sol += Calc(n - 1, 0, true, true);
        } else {
          sol += Calc(n - 1, lastK, true, false);
        }
      }
      help++;
    }
    if (!solution) {
      if (ch[a] == '4' || ch[a] == '7') {
        if (lastK == -1) {
          lastK = n;
        } else if (lastK - n <= K) {
          solution = true;
        } else {
          lastK = n;
        }
      }
    }
    sol = sol % MOD;
  }
  return sol;
}
char ch[2][1010];
int check(char* help) {
  int last = -1;
  int len = strlen(help);
  for (int n = 0; n < len; n++) {
    if (help[n] == '4' || help[n] == '7') {
      if (last == -1) {
        last = n;
      } else if (n - last <= K) {
        return 1;
      } else {
        last = n;
      }
    }
  }
  return 0;
}
int main() {
  memset(dp, -1, sizeof(dp));
  int N;
  scanf("%d %d", &N, &K);
  for (int(n) = 0; n < (int)N; n++) {
    scanf("%s %s", ch[0], ch[1]);
    cout << (Solve(ch[1]) - Solve(ch[0]) + check(ch[1]) + MOD) % MOD << endl;
  }
}
