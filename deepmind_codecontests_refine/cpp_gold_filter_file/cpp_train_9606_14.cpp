#include <bits/stdc++.h>
using namespace std;
int dp[40];
int a[100010];
int main() {
  int t;
  scanf("%d", &t);
  while (t--) {
    int n;
    scanf("%d", &n);
    int i;
    for (i = 0; i < 40; i++) {
      dp[i] = 0;
    }
    for (i = 0; i < n; i++) {
      scanf("%d", &a[i]);
    }
    long long sum = 0;
    for (i = 0; i < n; i++) {
      int x = a[i];
      int cnt = 0;
      while (x) {
        cnt++;
        x = x >> 1;
      }
      sum += dp[cnt];
      dp[cnt]++;
    }
    printf("%lld\n", sum);
  }
  return 0;
}
