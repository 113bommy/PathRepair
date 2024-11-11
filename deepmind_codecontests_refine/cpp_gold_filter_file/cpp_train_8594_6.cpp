#include <bits/stdc++.h>
using namespace std;
const int N = 1100000;
int n, t1, t2, dir[N];
long long ans, sum1[N], sum2[N];
int main() {
  scanf("%d", &n);
  for (int i = 1; i <= n; i++) {
    char c;
    while (c = getchar(), c != 'U' && c != 'D')
      ;
    if (c == 'U') dir[i] = 1;
  }
  for (int i = n; i >= 1; i--)
    if (!dir[i]) {
      t2++;
      sum2[t2] = sum2[t2 - 1] + 2 * i;
    }
  for (int i = 1; i <= n; i++) {
    if (!dir[i]) t2--;
    if (t1 == t2) {
      ans = sum2[t2] - sum1[t1];
      if (!dir[i])
        ans += i;
      else
        ans += n + 1 - i;
    }
    if (t1 > t2) {
      if (!dir[i])
        ans = sum2[t2] - sum1[t1] + sum1[t1 - t2 - 1] + n + 1 + i;
      else
        ans = sum2[t2] - sum1[t1] + sum1[t1 - t2] + n + 1 - i;
    } else if (t1 < t2) {
      if (!dir[i])
        ans = sum2[t2] - sum2[t2 - t1] - sum1[t1] + i;
      else
        ans = sum2[t2] - sum2[t2 - t1 - 1] - sum1[t1] - i;
    }
    printf("%I64d ", ans);
    if (dir[i]) {
      t1++;
      sum1[t1] = sum1[t1 - 1] + 2 * i;
    }
  }
  printf("\n");
  return 0;
}
