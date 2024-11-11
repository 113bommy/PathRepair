#include <bits/stdc++.h>
using namespace std;
int dp[100004][3][3];
int n;
int a[100004];
int rec(int i, int chang, int is_take) {
  if (i > n) {
    if (is_take) return 0;
    return -1e9;
  }
  if (chang == 2 && a[i] <= a[i - 1]) return 0;
  if (chang == 1 && a[i] <= a[i - 2] + 1) return 0;
  int &ret = dp[i][chang][is_take];
  if (ret != -1) return ret;
  ret = -1e9;
  if (!is_take) ret = max(ret, rec(i + 1, chang, is_take));
  if (chang == 1) {
    ret = max(ret, rec(i + 1, 2, 1) + 1);
  } else if (a[i] > a[i - 1] || (!is_take))
    ret = max(ret, rec(i + 1, chang, 1) + 1);
  else {
    ret = max(ret, rec(i + 1, 1, 1) + 1);
  }
  return ret;
}
int rec2(int i, int chang, int is_take) {
  if (i > n) {
    if (is_take) return 0;
    return -1e9;
  }
  if (chang == 1 && a[i] >= a[i + 1]) return 0;
  if (chang == 0 && a[i] >= a[i + 1] && is_take) {
    if (a[i + 1] - 1 <= a[i - 1]) return 1;
  }
  int &ret = dp[i][chang][is_take];
  if (ret != -1) return ret;
  ret = -1e9;
  if (!is_take) ret = max(ret, rec2(i + 1, chang, is_take));
  if (a[i] < a[i + 1])
    ret = max(ret, rec2(i + 1, chang, 1) + 1);
  else {
    if (!is_take) {
      ret = max(ret, rec2(i + 1, 1, 1) + 1);
    } else {
      int g = a[i + 1];
      if (g - 1 > a[i - 1]) ret = max(ret, rec2(i + 1, 1, 1) + 1);
    }
  }
  return ret;
}
int main() {
  cin >> n;
  int i;
  for (i = 1; i <= n; i++) cin >> a[i];
  a[0] = -1;
  a[n + 1] = 1e9 + 4;
  memset(dp, -1, sizeof dp);
  int maxx1 = rec(1, 0, 0);
  memset(dp, -1, sizeof dp);
  int max2 = rec2(1, 0, 0);
  cout << max(maxx1, max2);
  return 0;
}
