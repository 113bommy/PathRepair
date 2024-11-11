#include <bits/stdc++.h>
using namespace std;
const double eps = 1e-5;
const int inf = 0x3f3f3f3f;
const int maxn = 1e5 + 5;
const int mod = 1e9 + 7;
int a[6];
int ans[2005];
int b[3];
int solve(void) {
  int sum = a[0] + a[5];
  memset(ans, 0, sizeof(ans));
  ans[0] = a[0];
  int h = a[1] + a[2];
  b[1] = a[1], b[2] = a[5];
  for (int i = 1; i <= h - 1; i++) {
    ans[i] += ans[i - 1];
    if (i <= b[1] && i <= b[2])
      ans[i]++;
    else if (i > b[1] && i > b[2])
      ans[i]--;
    sum += 2 * ans[i];
  }
  return sum;
}
int main(void) {
  while (1) {
    for (int i = 0; i < 6; i++)
      if (scanf("%d", &a[i]) != 1) return 0;
    printf("%d\n", solve());
  }
  return 0;
}
