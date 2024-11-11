#include <bits/stdc++.h>
using namespace std;
int s[111], team[21];
char mv[21];
int dp[1 << 20];
int main() {
  int n;
  scanf("%d", &n);
  for (int i = 0; i < int(n); i++) scanf("%d", s + i);
  sort(s, s + n);
  reverse(s, s + n);
  int m;
  scanf("%d ", &m);
  for (int i = 0; i < int(m); i++) scanf("%c %d ", mv + i, team + i);
  n = m;
  int S = 1 << n;
  dp[0] = 0;
  for (int st = 1; st < S; st++) {
    dp[st] = -1000000000;
    int j = n - __builtin_popcount(st);
    for (int i = 0; i < int(n); i++)
      if (st & (1 << i)) {
        int nst = (1 << i) ^ st;
        int tmp = team[j + 1] == team[j] ? dp[nst] : -dp[nst];
        if (mv[j] == 'p') tmp = tmp + s[i];
        dp[st] = max(dp[st], tmp);
      }
  }
  printf("%d\n", team[0] == 2 ? -dp[S - 1] : dp[S - 1]);
}
