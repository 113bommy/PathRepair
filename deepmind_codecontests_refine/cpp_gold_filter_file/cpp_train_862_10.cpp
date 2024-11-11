#include <bits/stdc++.h>
using namespace std;
const long long mod = 1e9 + 7;
const int maxs = 796;
long long dp[maxs][maxs][9];
int Pair[maxs];
stack<int> S;
string seq;
void calc(int l, int r) {
  if (l + 1 == r) {
    dp[l][r][0] = 0;
    dp[l][r][1] = 1;
    dp[l][r][2] = 1;
    dp[l][r][3] = 1;
    dp[l][r][4] = 0;
    dp[l][r][5] = 0;
    dp[l][r][6] = 1;
    dp[l][r][7] = 0;
    dp[l][r][8] = 0;
  } else if (Pair[l] == r) {
    calc(l + 1, r - 1);
    dp[l][r][0] = 0;
    dp[l][r][1] =
        (dp[l + 1][r - 1][0] + dp[l + 1][r - 1][2] + dp[l + 1][r - 1][3] +
         dp[l + 1][r - 1][5] + dp[l + 1][r - 1][6] + dp[l + 1][r - 1][8]) %
        mod;
    dp[l][r][2] =
        (dp[l + 1][r - 1][0] + dp[l + 1][r - 1][1] + dp[l + 1][r - 1][3] +
         dp[l + 1][r - 1][4] + dp[l + 1][r - 1][6] + dp[l + 1][r - 1][7]) %
        mod;
    dp[l][r][3] =
        (dp[l + 1][r - 1][0] + dp[l + 1][r - 1][1] + dp[l + 1][r - 1][2] +
         dp[l + 1][r - 1][6] + dp[l + 1][r - 1][7] + dp[l + 1][r - 1][8]) %
        mod;
    dp[l][r][4] = 0;
    dp[l][r][5] = 0;
    dp[l][r][6] =
        (dp[l + 1][r - 1][0] + dp[l + 1][r - 1][1] + dp[l + 1][r - 1][2] +
         dp[l + 1][r - 1][3] + dp[l + 1][r - 1][4] + dp[l + 1][r - 1][5]) %
        mod;
    dp[l][r][7] = 0;
    dp[l][r][8] = 0;
  } else {
    int L = l, R = r;
    calc(L, Pair[L]);
    L = Pair[L] + 1;
    while (L < R) {
      calc(L, Pair[L]);
      dp[l][Pair[L]][0] = dp[l][L - 1][0] * dp[L][Pair[L]][0] +
                          dp[l][L - 1][0] * dp[L][Pair[L]][3] +
                          dp[l][L - 1][0] * dp[L][Pair[L]][6] +
                          dp[l][L - 1][1] * dp[L][Pair[L]][0] +
                          dp[l][L - 1][1] * dp[L][Pair[L]][6] +
                          dp[l][L - 1][2] * dp[L][Pair[L]][0] +
                          dp[l][L - 1][2] * dp[L][Pair[L]][3];
      dp[l][Pair[L]][1] = dp[l][L - 1][0] * dp[L][Pair[L]][1] +
                          dp[l][L - 1][0] * dp[L][Pair[L]][4] +
                          dp[l][L - 1][0] * dp[L][Pair[L]][7] +
                          dp[l][L - 1][1] * dp[L][Pair[L]][1] +
                          dp[l][L - 1][1] * dp[L][Pair[L]][7] +
                          dp[l][L - 1][2] * dp[L][Pair[L]][1] +
                          dp[l][L - 1][2] * dp[L][Pair[L]][7];
      dp[l][Pair[L]][2] = dp[l][L - 1][0] * dp[L][Pair[L]][2] +
                          dp[l][L - 1][0] * dp[L][Pair[L]][5] +
                          dp[l][L - 1][0] * dp[L][Pair[L]][8] +
                          dp[l][L - 1][1] * dp[L][Pair[L]][2] +
                          dp[l][L - 1][1] * dp[L][Pair[L]][8] +
                          dp[l][L - 1][2] * dp[L][Pair[L]][2] +
                          dp[l][L - 1][2] * dp[L][Pair[L]][5];
      dp[l][Pair[L]][3] = dp[l][L - 1][3] * dp[L][Pair[L]][0] +
                          dp[l][L - 1][3] * dp[L][Pair[L]][3] +
                          dp[l][L - 1][3] * dp[L][Pair[L]][6] +
                          dp[l][L - 1][4] * dp[L][Pair[L]][0] +
                          dp[l][L - 1][4] * dp[L][Pair[L]][6] +
                          dp[l][L - 1][5] * dp[L][Pair[L]][0] +
                          dp[l][L - 1][5] * dp[L][Pair[L]][3];
      dp[l][Pair[L]][4] = dp[l][L - 1][3] * dp[L][Pair[L]][1] +
                          dp[l][L - 1][3] * dp[L][Pair[L]][4] +
                          dp[l][L - 1][3] * dp[L][Pair[L]][7] +
                          dp[l][L - 1][4] * dp[L][Pair[L]][1] +
                          dp[l][L - 1][4] * dp[L][Pair[L]][7] +
                          dp[l][L - 1][5] * dp[L][Pair[L]][1] +
                          dp[l][L - 1][5] * dp[L][Pair[L]][4];
      dp[l][Pair[L]][5] = dp[l][L - 1][3] * dp[L][Pair[L]][2] +
                          dp[l][L - 1][3] * dp[L][Pair[L]][5] +
                          dp[l][L - 1][3] * dp[L][Pair[L]][8] +
                          dp[l][L - 1][4] * dp[L][Pair[L]][2] +
                          dp[l][L - 1][4] * dp[L][Pair[L]][8] +
                          dp[l][L - 1][5] * dp[L][Pair[L]][2] +
                          dp[l][L - 1][5] * dp[L][Pair[L]][5];
      dp[l][Pair[L]][6] = dp[l][L - 1][6] * dp[L][Pair[L]][0] +
                          dp[l][L - 1][6] * dp[L][Pair[L]][3] +
                          dp[l][L - 1][6] * dp[L][Pair[L]][6] +
                          dp[l][L - 1][7] * dp[L][Pair[L]][0] +
                          dp[l][L - 1][7] * dp[L][Pair[L]][6] +
                          dp[l][L - 1][8] * dp[L][Pair[L]][0] +
                          dp[l][L - 1][8] * dp[L][Pair[L]][3];
      dp[l][Pair[L]][7] = dp[l][L - 1][6] * dp[L][Pair[L]][1] +
                          dp[l][L - 1][6] * dp[L][Pair[L]][4] +
                          dp[l][L - 1][6] * dp[L][Pair[L]][7] +
                          dp[l][L - 1][7] * dp[L][Pair[L]][1] +
                          dp[l][L - 1][7] * dp[L][Pair[L]][7] +
                          dp[l][L - 1][8] * dp[L][Pair[L]][1] +
                          dp[l][L - 1][8] * dp[L][Pair[L]][4];
      dp[l][Pair[L]][8] = dp[l][L - 1][6] * dp[L][Pair[L]][2] +
                          dp[l][L - 1][6] * dp[L][Pair[L]][5] +
                          dp[l][L - 1][6] * dp[L][Pair[L]][8] +
                          dp[l][L - 1][7] * dp[L][Pair[L]][2] +
                          dp[l][L - 1][7] * dp[L][Pair[L]][8] +
                          dp[l][L - 1][8] * dp[L][Pair[L]][2] +
                          dp[l][L - 1][8] * dp[L][Pair[L]][5];
      for (int i = 0; i < 9; ++i) {
        dp[l][Pair[L]][i] %= mod;
      }
      L = Pair[L] + 1;
    }
  }
}
int main() {
  cin >> seq;
  for (int i = 0; i < seq.length(); ++i) {
    if (seq[i] == ')') {
      Pair[S.top()] = i;
      Pair[i] = S.top();
      S.pop();
    } else
      S.emplace(i);
  }
  calc(0, seq.length() - 1);
  cout << (accumulate(dp[0][seq.length() - 1], dp[0][seq.length() - 1] + 9,
                      (long long)0)) %
              mod
       << endl;
  return 0;
}
