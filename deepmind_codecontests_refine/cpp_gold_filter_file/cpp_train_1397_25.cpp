#include <bits/stdc++.h>
using namespace std;
int a[105];
int b[105];
int num[105];
int dp1[10010];
int dp2[10010];
int main() {
  int n, k;
  while (cin >> n >> k) {
    for (int i = 1; i <= 10001; i++) dp1[i] = dp2[i] = -1001000;
    dp1[0] = dp2[0] = 0;
    for (int i = 1; i <= n; i++) cin >> a[i];
    for (int i = 1; i <= n; i++) cin >> b[i];
    for (int i = 1; i <= n; i++) {
      num[i] = a[i] - k * b[i];
      if (num[i] < 0) {
        num[i] = -num[i];
        for (int j = 10001; j >= num[i]; j--) {
          dp1[j] = max(dp1[j], dp1[j - num[i]] + a[i]);
        }
      } else {
        for (int j = 10001; j >= num[i]; j--) {
          dp2[j] = max(dp2[j], dp2[j - num[i]] + a[i]);
        }
      }
    }
    int Max = -1;
    for (int i = 10000; i >= 0; i--) {
      Max = max(Max, dp1[i] + dp2[i]);
    }
    if (Max == 0)
      cout << "-1" << endl;
    else
      cout << Max << endl;
  }
  return 0;
}
