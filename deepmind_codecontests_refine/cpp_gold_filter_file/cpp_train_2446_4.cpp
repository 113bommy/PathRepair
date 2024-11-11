#include <bits/stdc++.h>
using namespace std;
long long dp[2][20][48][2520];
int id[2521], totid;
int gcd(int a, int b) { return (b == 0) ? a : gcd(b, a % b); }
int lcm(int a, int b) {
  if (b == 0) return a;
  return a * b / gcd(a, b);
}
char l[20];
int len;
long long DP(int pos, int u, int lcmnow, int left) {
  if (pos == len) {
    return left % lcmnow == 0;
  }
  if (dp[u][pos][id[lcmnow]][left] == -1) {
    dp[u][pos][id[lcmnow]][left] = 0;
    int ed = (u == 0) ? 9 : (l[pos] - '0');
    for (int i = 0; i <= ed; i++) {
      dp[u][pos][id[lcmnow]][left] +=
          DP(pos + 1, (u == 1 && i == (l[pos] - '0')), lcm(lcmnow, i),
             (left * 10 + i) % 2520);
    }
  }
  return dp[u][pos][id[lcmnow]][left];
}
long long Gao(long long num) {
  sprintf(l, "%020I64d", num);
  len = strlen(l);
  memset(dp[1], -1, sizeof(dp[1]));
  return DP(0, 1, 1, 0);
}
int main() {
  totid = 0;
  for (int i = 1; i <= 2520; i++)
    if (2520 % i == 0) id[i] = totid++;
  memset(dp[0], -1, sizeof(dp[0]));
  int t;
  scanf("%d", &t);
  for (int ft = 1; ft <= t; ft++) {
    long long l, r;
    scanf("%I64d%I64d", &r, &l);
    printf("%I64d\n", Gao(l) - Gao(r - 1));
  }
  return 0;
}
