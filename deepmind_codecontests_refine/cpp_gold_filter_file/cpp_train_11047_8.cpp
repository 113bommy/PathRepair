#include <bits/stdc++.h>
const int MAXN = 1e5 + 5;
const int MOD = 1e9 + 7;
using namespace std;
int dough, m, c0, d0;
int leftStuff[13];
int requiredStuff[13];
int requiredDough[13];
int earned[13];
long long int dp[13][105][1005];
long long int max(long long int a, long long int b, long long int c) {
  return max(a, max(b, c));
}
long long int solve(int i, int stuffing, int dough) {
  if (i > m) {
    return 0;
  }
  if (dp[i][stuffing][dough] != -1) {
    return dp[i][stuffing][dough];
  }
  if (stuffing >= requiredStuff[i] && dough >= requiredDough[i]) {
    return dp[i][stuffing][dough] =
               max(earned[i] + solve(i, stuffing - requiredStuff[i],
                                     dough - requiredDough[i]),
                   earned[i] +
                       solve(i + 1, leftStuff[i + 1], dough - requiredDough[i]),
                   solve(i + 1, leftStuff[i + 1], dough));
  } else {
    return dp[i][stuffing][dough] = solve(i + 1, leftStuff[i + 1], dough);
  }
}
int main() {
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  memset(dp, -1, sizeof(dp));
  cin >> dough >> m >> c0 >> d0;
  for (int i = 1; i <= m; i++) {
    cin >> leftStuff[i] >> requiredStuff[i] >> requiredDough[i] >> earned[i];
  }
  m++;
  leftStuff[m] = 1, requiredStuff[m] = 0, requiredDough[m] = c0, earned[m] = d0;
  cout << solve(1, leftStuff[1], dough) << endl;
}
