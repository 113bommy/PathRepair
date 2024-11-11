#include <bits/stdc++.h>
using namespace std;
int main() {
  long long int n, m;
  int arr[50][50];
  cin >> n >> m;
  for (long long int i = 0; i < n; i++)
    for (long long int j = 0; j < m; j++) cin >> arr[i][j];
  for (long long int i = 0; i < n; i++) {
    if (arr[0][i] == 1 || arr[m - 1][i] == 1) {
      cout << 2 << endl;
      return 0;
    }
  }
  for (long long int i = 0; i < m; i++) {
    if (arr[i][0] == 1 || arr[i][n - 1] == 1) {
      cout << 2 << endl;
      return 0;
    }
  }
  cout << 4;
  return 0;
}
