#include <bits/stdc++.h>
using namespace std;
int main() {
  int arr[101][101];
  int n, k;
  cin >> n >> k;
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
      if (i == j)
        arr[i][j] = k;
      else
        arr[i][j] = 0;
    }
  }
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
      cout << arr[i][j] << " ";
    }
    cout << endl;
  }
  return 0;
}
