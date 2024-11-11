#include <bits/stdc++.h>
using namespace std;
int main() {
  int n, c = 0;
  char arr[105][105];
  cin >> n;
  for (int i = 1; i <= n; i++)
    for (int j = 1; j <= n; j++) cin >> arr[i][j];
  for (int i = 0; i <= n; i++) arr[i][0] = 'x';
  for (int j = 0; j <= n; j++) arr[0][j] = 'x';
  for (int i = 0; i <= n; i++) arr[i][n + 1] = 'x';
  for (int j = 0; j <= n + 1; j++) arr[n + 1][j] = 'x';
  for (int i = 1; i < n; i++) {
    for (int j = 0; j < n; j++) {
      c = 0;
      if (arr[i + 1][j] == 'o') c++;
      if (arr[i - 1][j] == 'o') c++;
      if (arr[i][j - 1] == 'o') c++;
      if (arr[i][j + 1] == 'o') c++;
      if (c % 2 != 0) {
        cout << "NO" << endl;
        return 0;
      }
    }
  }
  cout << "YES" << endl;
  return 0;
}
