#include <bits/stdc++.h>
using namespace std;
int main() {
  long long n, m, max = -1, index;
  cin >> n >> m;
  long long arr[m][n];
  long long arr1[n];
  for (long long i = 0; i < n; i++) {
    arr1[i] = 0;
  }
  for (long long i = 0; i < m; i++) {
    for (long long j = 0; j < n; j++) {
      cin >> arr[i][j];
      if (arr[i][j] > max) {
        max = arr[i][j];
        index = j;
      }
    }
    arr1[index]++;
    max = -1;
  }
  max = -1;
  index = 0;
  for (long long i = 0; i < n; i++) {
    if (arr1[i] > max) {
      max = arr1[i];
      index = i + 1;
    }
  }
  cout << index << endl;
  return 0;
}
