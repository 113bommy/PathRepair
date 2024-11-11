#include <bits/stdc++.h>
using namespace std;
int dp[2][716], tut[(1 << (21))], msk[716], po[15], a[2005], b[2005];
int ans = 105000000, tot, n;
void encode(int now, int rem, int mask) {
  if (rem < 0) return;
  if (now == 9) {
    tut[mask] = ++tot;
    msk[tot] = mask;
    return;
  }
  encode(now, rem - 1, mask + po[now]);
  encode(now + 1, rem, mask);
}
int getcost(int start, int endd, int mn, int mx) {
  return min(abs(start - mn) + abs(mn - mx) + abs(mx - endd),
             abs(start - mx) + abs(mx - mn) + abs(mn - endd));
}
void solve(int fr[], int now, int mask, int start, int endd, int mn, int mx,
           int add, int w, int tp) {
  if (now == 9) {
    if (tp + 1 >= 5) return;
    dp[1][tut[mask + po[b[w]]]] =
        min(dp[1][tut[mask + po[b[w]]]], add + getcost(start, endd, mn, mx));
    return;
  }
  solve(fr, now + 1, mask, start, endd, mn, mx, add, w, tp + fr[now]);
  if (fr[now]) {
    mask -= po[now] * fr[now];
    mn = min(mn, now);
    mx = max(mx, now);
    solve(fr, now + 1, mask, start, endd, mn, mx, add, w, tp);
  }
}
void dist(int now, int state) {
  int start = a[now];
  int endd = a[now + 1];
  int mask = msk[state];
  int fr[9] = {0};
  for (int i = 0; i < 9; i++) {
    fr[i] = mask % 5;
    mask /= 5;
  }
  solve(fr, 0, msk[state], start, endd, min(start, endd), max(start, endd),
        dp[0][state], now + 1, 0);
}
int main() {
  po[0] = 1;
  for (int i = 1; i < 9; i++) po[i] = po[i - 1] * 5;
  scanf("%d", &n);
  for (int i = 1; i <= n; i++) {
    scanf("%d %d", a + i, b + i);
    a[i]--;
    b[i]--;
  }
  encode(0, 4, 0);
  for (int j = 1; j <= tot; j++) {
    dp[0][j] = 105000000;
    dp[1][j] = 105000000;
  }
  dp[0][tut[0]] = 0;
  for (int i = 0; i < n; i++) {
    for (int j = 1; j <= tot; j++) {
      dist(i, j);
    }
    for (int j = 1; j <= tot; j++) {
      swap(dp[1][j], dp[0][j]);
      dp[1][j] = 105000000;
    }
  }
  for (int i = 1; i <= tot; i++) {
    int start = a[n];
    int mask = msk[i];
    int mn = start, mx = start;
    for (int j = 0; j < 9; j++) {
      if (mask % 5) {
        mn = min(mn, j);
        mx = max(mx, j);
      }
      mask /= 5;
    }
    ans = min(ans, dp[0][i] + min(getcost(start, mx, mn, mx),
                                  getcost(start, mn, mn, mx)));
  }
  printf("%d", ans + 2 * n);
}
