#include <bits/stdc++.h>
using namespace std;
int a[5005], cnt1[5005][5005], cnt2[5005][5005];
int main() {
  ios::sync_with_stdio(0);
  int n;
  cin >> n;
  for (int i = 1; i <= n; ++i) cin >> a[i];
  int sum1, sum2, tot = 0;
  for (int i = 1; i <= n; ++i) {
    sum1 = sum2 = 0;
    for (int j = 1; j <= n; ++j) {
      if (a[j] > a[i]) sum1++;
      if (a[j] < a[i]) sum2++;
      cnt1[i][j] = sum1;
      cnt2[i][j] = sum2;
    }
    tot += cnt1[i][i - 1];
  }
  int ans1 = 0, ans2 = 0, t;
  for (int i = 2; i <= n; ++i) {
    for (int j = 1; j < i; ++j) {
      t = +(cnt1[i][i - 1] - cnt1[i][j]) - (cnt2[i][i - 1] - cnt2[i][j]) -
          (cnt1[j][i - 1] - cnt1[j][j]) + (cnt2[j][i - 1] - cnt2[j][j]);
      if (a[i] > a[j]) t--;
      if (a[i] < a[j]) t++;
      if (t == ans1) {
        ans2++;
      } else if (t > ans1) {
        ans1 = t;
        ans2 = 1;
      }
    }
  }
  cout << tot - ans1 << ' ' << ans2;
}
