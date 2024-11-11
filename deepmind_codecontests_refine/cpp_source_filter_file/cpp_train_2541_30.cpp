#include <bits/stdc++.h>
using namespace std;
bool dp[500005];
int c[55];
int main() {
  int n, d;
  scanf("%d%d", &n, &d);
  dp[0] = 1;
  for (int i = 1; i <= n; i++) {
    scanf("%d", &c[i]);
    for (int j = 10000 * n; j >= 0; j--) {
      if (dp[j]) dp[j + c[i]] = 1;
    }
  }
  set<int> cur;
  set<int>::iterator its;
  for (int i = 1; i <= 500000; i++) {
    if (dp[i]) cur.insert(i);
  }
  int sum = 0, ans = 0;
  while (1) {
    its = cur.upper_bound(sum + d);
    its--;
    if (*its > sum)
      sum = *its, ans++;
    else
      break;
  }
  printf("%d %d\n", sum, ans);
}
