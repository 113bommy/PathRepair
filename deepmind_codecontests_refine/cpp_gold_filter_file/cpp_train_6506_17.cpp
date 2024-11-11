#include <bits/stdc++.h>
using namespace std;
long long dp[114514][16];
int N, M;
char s[114514];
long long res;
int main() {
  scanf("%d%d", &N, &M);
  scanf("%s", &s);
  dp[0][2] = 1;
  for (int(i) = 0; (i) < (N); (i)++)
    for (int(b) = (1); (b) < (16); (b)++)
      if (dp[i][b]) {
        for (int(j) = 0; (j) < (M); (j)++) {
          int nb = 0;
          if (b % 2 == 1 && s[i - 1] == j + 'a') nb |= 1;
          if (b % 2 == 1 && s[i] == j + 'a') nb |= 8;
          if (b / 2 % 2 == 1 && s[i] == j + 'a') nb |= 2;
          if (b / 2 % 2 == 1) nb |= 1;
          if (b / 2 % 2 == 1 && i + 1 < N && s[i + 1] == j + 'a') nb |= 4;
          if (b / 4 % 2 == 1) nb |= 8;
          if (b / 4 % 2 == 1 && i + 1 < N && s[i + 1] == j + 'a') nb |= 4;
          if (b >= 8 && s[i] == j + 'a') nb |= 8;
          if (b / 2 % 2 == 1) nb |= 8;
          dp[i + 1][nb] += dp[i][b];
        }
      }
  for (int(i) = (8); (i) < (16); (i)++) res += dp[N][i];
  cout << res - 1 + dp[N][1] + dp[N][4] + dp[N][5] << endl;
}
