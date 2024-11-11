#include <bits/stdc++.h>
using namespace std;
int arr[207][207];
int brr[207][207];
int main() {
  int n, m;
  cin >> n >> m;
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      arr[i][j] = 1;
    }
  }
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      cin >> brr[i][j];
      if (brr[i][j]) continue;
      for (int ii = 0; ii < n; ii++) arr[ii][j] = 0;
      for (int jj = 0; jj < m; jj++) arr[i][jj] = 0;
    }
  }
  int x = 0;
  for (int i = 0; i < n; i++)
    for (int j = 0; j < m; j++) {
      x = 0;
      for (int ii = 0; ii < n; ii++) x = x | arr[ii][j];
      for (int jj = 0; jj < m; jj++) x = x | arr[i][jj];
      if (brr[i][j] != x) return cout << "NO" << endl, 0;
    }
  cout << "YES" << endl;
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      cout << arr[i][j] << " ";
    }
    cout << endl;
  }
  return 0;
}
