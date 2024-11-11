#include <bits/stdc++.h>
using namespace std;
struct ss {
  int n, ps;
};
ss s[100006];
int n;
int ans[1000006];
int dp[1000006];
bool cmp(const ss &a, const ss &b) {
  if (a.n == b.n) return a.ps < b.ps;
  return a.n < b.n;
}
int main() {
  scanf("%d", &n);
  for (int i = 0; i < n; i++) {
    scanf("%d", &s[i].n);
    s[i].ps = i;
  }
  sort(s, s + n, cmp);
  for (int i = 0; i < n; i++) {
    if (i == 0) {
      dp[i] = s[i].ps;
      ans[s[i].ps] = -1;
    } else {
      if (s[i].ps > dp[i - 1])
        dp[i] = s[i].ps;
      else
        dp[i] = dp[i - 1];
      if (s[i].n == s[i - 1].n) {
        if (ans[s[i - 1].ps] == -1)
          ans[s[i].ps] = -1;
        else {
          if (ans[s[i - 1].ps] + s[i - 1].ps + 1 > s[i].ps)
            ans[s[i].ps] = -s[i].ps + (ans[s[i - 1].ps] + s[i - 1].ps + 1) - 1;
          else
            ans[s[i].ps] = -1;
        }
      } else {
        ans[s[i].ps] = dp[i] - s[i].ps - 1;
        if (ans[s[i].ps] < 0) ans[s[i].ps] = -1;
      }
    }
  }
  for (int i = 0; i < n; i++) {
    if (i) printf(" ");
    printf("%d", ans[i]);
  }
  printf("\n");
  return 0;
}
