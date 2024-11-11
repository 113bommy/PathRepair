#include <bits/stdc++.h>
using namespace std;
int xinyue, n, f[25], dp[1200005], siz[1200005], prt[25], ans, N = 20;
char s1[200005], s2[200005];
int get(int x) {
  if (prt[x] == x) return x;
  return prt[x] = get(prt[x]);
}
int main() {
  scanf("%d", &xinyue);
  while (xinyue--) {
    scanf("%d", &n);
    scanf("%s", s1 + 1);
    scanf("%s", s2 + 1);
    ans = 0;
    memset(f, 0, sizeof(f));
    memset(dp, 0, sizeof(dp));
    for (int i = 1; i <= N; i++) prt[i] = i;
    for (int i = 1; i <= n; i++) {
      f[s1[i] - 'a'] |= 1 << (s2[i] - 'a');
      prt[get(s1[i] - 'a' + 1)] = get(s2[i] - 'a' + 1);
    }
    dp[0] = 1;
    for (int i = 1; i < 1 << N; i++) {
      siz[i] = siz[i >> 1] + (i & 1);
      for (int t = 0; t < N; t++) {
        if ((i >> t) & 1) {
          int ls = i ^ (1 << t);
          if (!(f[t] & ls)) dp[i] |= dp[ls];
        }
      }
    }
    for (int i = 0; i < 1 << N; i++) {
      if (dp[i]) ans = max(ans, siz[i]);
    }
    ans = 2 * N - ans;
    for (int i = 1; i <= N; i++) {
      if (get(i) == i) ans--;
    }
    printf("%d\n", ans);
  }
}
