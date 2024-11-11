#include <bits/stdc++.h>
#pragma comment(linker, "/STACK:268435456,268435456")
using namespace std;
bool dp[510001];
int main() {
  int n, d, t;
  scanf("%d %d", &n, &d), dp[0] = 1;
  for (int i = 0; i < n; i++) {
    scanf("%d", &t);
    for (int j = 510001; j - t >= 0; j--) dp[j] |= dp[j - t];
  }
  int curr = 0, num = 0, sum = 0;
  while (true) {
    for (int i = d; i >= 1; i--)
      if (dp[curr + i]) {
        curr += i, num++;
        break;
      }
    if (curr > sum)
      sum = curr;
    else
      break;
  }
  printf("%d %d\n", sum, num);
  return 0;
}
