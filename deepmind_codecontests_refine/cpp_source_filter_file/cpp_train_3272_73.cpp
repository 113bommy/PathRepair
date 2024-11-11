#include <bits/stdc++.h>
using namespace std;
int main() {
  int nCol = 0;
  cin >> nCol;
  int arr[nCol];
  for (size_t i = 0; i < nCol; i++) {
    cin >> arr[i];
  }
  sort(arr, arr + nCol);
  for (size_t j = 0; j < nCol; j++) {
    cout << arr[j];
  }
}
