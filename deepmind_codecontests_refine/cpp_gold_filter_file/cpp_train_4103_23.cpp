#include <bits/stdc++.h>
using namespace std;
int main() {
  int n = 0, m = 0;
  long long all = 0, ans = 0, k = 0;
  cin >> n >> m >> k;
  int row = 0, mk = 0;
  int *arr = new int[m + 1];
  for (int j = 0; j <= m; j++) arr[j] = 9999999;
  for (int j = 1; j <= n; j++) {
    cin >> row >> mk;
    arr[row] = min(arr[row], mk);
  }
  for (int i = 1; i <= m; i++) all += arr[i];
  ans = min(all, k);
  cout << ans;
  return 0;
}
