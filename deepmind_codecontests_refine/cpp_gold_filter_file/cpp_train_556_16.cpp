#include <bits/stdc++.h>
using namespace std;
int main() {
  long long n = 3;
  long long **arr = new long long *[n];
  for (long long i = 0; i < n; i++) arr[i] = new long long[n];
  for (int i = 0; i < n; i++)
    for (int j = 0; j < n; j++) {
      cin >> arr[i][j];
    }
  arr[0][0] =
      (arr[1][0] + arr[1][2] + arr[2][0] + arr[2][1] - arr[0][1] - arr[0][2]) /
      2;
  arr[1][1] =
      (-arr[1][0] - arr[1][2] + arr[2][0] + arr[2][1] + arr[0][1] + arr[0][2]) /
      2;
  arr[2][2] =
      (arr[1][0] + arr[1][2] - arr[2][0] - arr[2][1] + arr[0][1] + arr[0][2]) /
      2;
  for (long long i = 0; i < n; i++) {
    for (long long j = 0; j < n; j++) {
      cout << arr[i][j] << " ";
    }
    cout << endl;
  }
  return 0;
}
