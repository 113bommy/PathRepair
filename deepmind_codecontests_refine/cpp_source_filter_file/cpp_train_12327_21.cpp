#include <bits/stdc++.h>
using namespace std;
const int maxn = 3005;
int a[maxn];
double dp[maxn * maxn];
int main() {
  int n;
  scanf("%d", &n);
  for (int i = 1; i <= n; i++) {
    scanf("%d", &a[i]);
  }
  int cnt = 0;
  for (int i = 1; i <= n; i++) {
    for (int j = i + 1; j <= n; j++) {
      if (a[i] > a[j]) cnt++;
    }
  }
  dp[0] = 0;
  dp[1] = 1;
  for (int i = 3; i <= cnt; i++) dp[i] = 4 + dp[i - 2];
  printf("%.6f\n", dp[cnt]);
  return 0;
}
