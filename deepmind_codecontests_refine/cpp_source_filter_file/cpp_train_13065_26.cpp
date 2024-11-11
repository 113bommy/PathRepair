#include <bits/stdc++.h>
using namespace std;
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  int n, m, s = 0;
  cin >> n >> m;
  int arr[n][2 * m];
  for (int i = 0; i < n; i++)
    for (int j = 0; j < 2 * m; j++) cin >> arr[i][j];
  for (int i = 0; i < n; i++)
    for (int j = 0; j < 2 * m - 1; j++)
      if (arr[i][j] == 1 || arr[i][j + 1] == 1) s++;
  cout << s / 2;
}
