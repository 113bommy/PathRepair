#include <bits/stdc++.h>
#pragma comment(linker, "/STACK:268435456,268435456")
using namespace std;
int a[50];
bool dp[510001];
int main() {
  int n, d;
  scanf("%d %d", &n, &d), dp[0] = 1;
  for (int i = 0; i < n; i++) {
    scanf("%d", &a[i]);
    for (int j = 510001 - 1; j >= a[i]; j--) dp[j] |= dp[j - a[i]];
  }
  int curr = 0, ans = 0, ans2 = 0;
  while (true) {
    int temp = curr;
    for (int i = d; i >= 1; i--)
      if (dp[temp + i]) {
        temp += i, ans++, ans2 = max(ans2, temp);
        break;
      }
    if (temp == curr) break;
    curr = temp;
  }
  printf("%d %d\n", ans2, ans);
  return 0;
}
