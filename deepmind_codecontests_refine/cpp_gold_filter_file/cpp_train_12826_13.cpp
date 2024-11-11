#include <bits/stdc++.h>
#pragma GCC optimize(2)
using namespace std;
const int INF = 0x3f3f3f3f;
const int MAXN = 1e5 + 5;
const int MAXM = 2e5 + 5;
const int MOD = 1e9 + 7;
const int dir[4][2] = {1, 0, -1, 0, 0, 1, 0, -1};
const double PI = acos(-1.0);
const double EXP = 1e-8;
int sat[505], val[505];
int main(void) {
  int n = 0, k = 0, m = 0;
  scanf("%d%d", &n, &k);
  for (int i = 1; i <= k + 1; i++) {
    printf("?");
    for (int j = 1; j <= i - 1; j++) printf(" %d", j);
    for (int j = i + 1; j <= k + 1; j++) printf(" %d", j);
    puts("");
    fflush(stdout);
    scanf("%d%d", sat + i, val + i);
  }
  int now = sat[k + 1], temp = val[k + 1];
  int cnt = 0, big = 0, small = 0;
  for (int i = 1; i <= k; i++)
    if (sat[i] != now) {
      cnt++;
      if (val[i] > temp)
        big++;
      else
        small++;
    }
  int ans1 = cnt, ans2 = k + 1 - cnt;
  int ans;
  if (big > small)
    ans = ans1;
  else
    ans = ans2;
  printf("! %d\n", ans);
  fflush(stdout);
  return 0;
}
