#include <bits/stdc++.h>
using namespace std;
int main() {
  int n, m, arr1[50001];
  cin >> n >> m;
  int arr[50001][6];
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      cin >> arr[i][j];
    }
  }
  for (int i = 0; i < m; i++) {
    int count = 0;
    for (int j = 0; j < n; j++) {
      int st = max(count, arr1[j]);
      arr1[j] = st + arr[j][i];
      count = arr1[j];
    }
  }
  for (int i = 0; i < n; i++) {
    cout << arr1[i] << " ";
  }
  return 0;
}
