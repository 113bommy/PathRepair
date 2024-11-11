#include <bits/stdc++.h>
using namespace std;
int main() {
  int n, arr[100][100], x1, y1, x2, y2, ans = 0;
  memset(arr, 0, sizeof(arr));
  cin >> n;
  for (int i = 0; i < n; i++) {
    cin >> x1 >> y1 >> x2 >> y2;
    for (int j = x1; j <= y2; j++)
      for (int k = y1; k <= x2; k++) arr[j][k]++;
  }
  for (int i = 0; i < 100; i++)
    for (int j = 0; j < 100; j++) ans += arr[i][j];
  cout << ans << endl;
  return 0;
}
