#include <bits/stdc++.h>
using namespace std;
int main(int argc, char const *argv[]) {
  int n;
  cin >> n;
  int arr[n][n];
  for (int i = 0; i < n; ++i) {
    arr[i][0] = 1;
    arr[0][i] = 1;
  }
  int max = 1;
  for (int i = 1; i < n; ++i) {
    for (int j = 1; j < n; ++j) {
      arr[i][j] = arr[i - 1][j] + arr[i][j - 1];
      if (arr[i][j] >= max) max = arr[i][j];
    }
  }
  cout << max << endl;
  return 0;
}
