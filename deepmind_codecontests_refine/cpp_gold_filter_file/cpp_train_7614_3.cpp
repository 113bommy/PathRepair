#include <bits/stdc++.h>
using namespace std;
int main() {
  long long int n, m, h;
  cin >> n >> m >> h;
  long long int arr1[m];
  long long int arr2[n];
  long long int arr3[n][m];
  long long int arr4[n][m];
  memset(arr4, 0, sizeof(arr4));
  for (long long int i = 0; i < m; i++) {
    cin >> arr1[i];
  }
  for (long long int i = 0; i < n; i++) {
    cin >> arr2[i];
  }
  for (long long int i = 0; i < n; i++) {
    for (long long int j = 0; j < m; j++) {
      cin >> arr3[i][j];
    }
  }
  for (long long int i = 0; i < n; i++) {
    for (long long int j = 0; j < m; j++) {
      if (arr3[i][j] == 1) {
        if (arr2[i] < arr1[j]) {
          arr4[i][j] = arr2[i];
        } else {
          arr4[i][j] = arr1[j];
        }
      }
    }
  }
  for (long long int i = 0; i < n; i++) {
    for (long long int j = 0; j < m; j++) {
      cout << arr4[i][j] << " ";
    }
    cout << endl;
  }
}
