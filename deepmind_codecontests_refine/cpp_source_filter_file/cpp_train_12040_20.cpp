#include <bits/stdc++.h>
using namespace std;
int arr[1000005];
int dp[1000005][10];
void fun() {
  for (int i = 1; i <= 1000000; i++) {
    if (i < 10)
      arr[i] = i;
    else {
      int n = i;
      int s = 1, l;
      while (n > 0) {
        l = n % 10;
        if (l == 0)
          s *= 1;
        else
          s *= l;
        n = n / 10;
      }
      arr[i] = arr[s];
    }
    for (int j = 0; j < 10; j++) dp[i][j] = dp[i - 1][j];
    dp[i][arr[i]]++;
  }
}
int main() {
  int q;
  cin >> q;
  fun();
  while (q--) {
    int l, r, k;
    cin >> l >> r >> k;
    cout << dp[r][k] - dp[l][k] + 1 << '\n';
  }
}
