#include <bits/stdc++.h>
using namespace std;
const int N = 500010, inf = 2000000010;
int n, t, l, r, dp1[N], dp2[N], dp3[N], z[N];
char s[N];
int main() {
  scanf("%d %d %s", &n, &t, s + 1);
  for (int i = 1; i <= n; i++) {
    z[i] = z[i - 1];
    if (s[i] == 'H')
      z[i]--;
    else if (s[i] == 'S')
      z[i]++;
  }
  l = -1;
  r = n + 1;
  while (l < r - 1) {
    int k = l + r >> 1, opt2 = 0, opt3 = 0;
    for (int i = 1; i <= n; i++) {
      dp1[i] = dp2[i] = dp3[i] = -1;
      opt2 += 2;
      opt3 += 3;
      if (k + z[i] < 0) continue;
      if (dp1[i - 1] != -1) dp1[i] = dp1[i - 1] + 1;
      if (dp3[i - 1] != -1 && (dp3[i - 1] + 1 < dp1[i] || dp1[i] == -1))
        dp1[i] = dp3[i - 1] + 1;
      dp2[i] = opt2;
      dp3[i] = opt3;
      if (dp1[i] != -1) opt2 = min(opt2, dp1[i]), opt3 = min(opt3, dp1[i]);
    }
    int sol = inf;
    for (int i = n; i; i--) {
      if (dp1[i] != -1) sol = min(sol, dp1[i]);
      if (dp2[i] != -1) sol = min(sol, dp2[i]);
      if (dp3[i] != -1) sol = min(sol, dp3[i]);
      if (s[i] == 'H') break;
    }
    if (sol <= t)
      r = k;
    else
      l = k;
  }
  if (l == n)
    printf("-1");
  else
    printf("%d", r);
  return 0;
}
