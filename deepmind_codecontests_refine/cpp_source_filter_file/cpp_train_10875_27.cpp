#include <bits/stdc++.h>
using namespace std;
int arr[50][50];
int main() {
  int n, m;
  cin >> n >> m;
  for (int i = 0; i < n; i++)
    for (int j = 0; j < m; j++) cin >> arr[i][j];
  int ans = 100500;
  int a, b;
  cin >> a >> b;
  for (int i = 0; i < n; i++)
    for (int j = 0; j < m; j++) {
      int t = 0;
      if (i + a <= n && j + b <= m) {
        for (int k = i; k < i + a; k++)
          for (int l = j; l < j + b; l++) t += arr[k][l];
        ans = min(t, ans);
      }
      t = 0;
      if (i + a <= m && j + b <= n) {
        for (int k = i; k < i + b; k++)
          for (int l = j; l < j + a; l++) t += arr[k][l];
        ans = min(t, ans);
      }
    }
  cout << ans;
  return 0;
}
