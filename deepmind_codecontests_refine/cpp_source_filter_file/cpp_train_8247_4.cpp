#include <bits/stdc++.h>
using namespace std;
const int M = 2005;
int nu[10] = {119, 36, 93, 109, 46, 107, 123, 37, 127, 111};
int g[M];
char s[M];
int dp[M][M];
int nxt[M][M];
int n;
inline int cost(int a) {
  int ans = 0;
  while (a) {
    ans += a & 1;
    a >>= 1;
  }
  return ans;
}
int getdp(int cur, int k) {
  if (cur == n + 1) return k == 0;
  int &ans = dp[cur][k];
  if (ans != -1) return ans;
  ans = 0;
  for (int i = 9; i >= 0; i--) {
    if ((nu[i] | g[cur]) != nu[i]) continue;
    int c = cost(g[cur] ^ nu[i]);
    if (c > k) continue;
    if (getdp(cur + 1, k - c)) {
      ans = 1;
      nxt[cur][k] = i;
      break;
    }
  }
  return ans;
}
int main() {
  int k;
  scanf("%d%d", &n, &k);
  for (int i = 1; i <= n; i++) {
    scanf("%s", s);
    for (int j = 0; j < 7; j++) {
      if (s[j] == '1') g[i] |= 1 << j;
    }
  }
  memset(dp, -1, sizeof(dp));
  if (!getdp(1, k))
    printf("%d\n", -1);
  else {
    for (int i = 1; i <= n; i++) {
      printf("%d", nxt[i][k]);
      k -= cost(g[i] ^ nxt[i][k]);
    }
    printf("\n");
  }
  return 0;
}
