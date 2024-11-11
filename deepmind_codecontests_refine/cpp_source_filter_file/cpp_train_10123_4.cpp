#include <bits/stdc++.h>
using namespace std;
signed main() {
  long long n;
  cin >> n;
  if (n < 3) {
    cout << -1 << endl;
    exit(0);
  }
  if (n == 3) {
    cout << "2 1 7\n8 3 6\n4 9 5" << endl;
    exit(0);
  }
  if (n == 4) {
    cout << "4 3 6 12\n"
         << "7 5 9 15\n"
         << "14 1 11 10\n"
         << "13 8 16 2\n";
    exit(0);
  }
  long long arr[n][n];
  memset(arr, 0, sizeof arr);
  long long k = n - 4;
  long long curr = 1;
  for (long long i = 0; i < k; i++) {
    if (i % 2 == 0) {
      for (long long j = 0; j < n; j++) {
        arr[i][j] = curr;
        curr++;
      }
    } else {
      for (long long j = n - 1; j >= 0; j--) {
        arr[i][j] = curr;
        curr++;
      }
    }
  }
  if (n % 2 == 0) {
    for (long long i = 0; i < n; i++) reverse(arr[i], arr[i] + n);
  }
  long long f = n - k;
  for (long long i = n - 1; i >= f; i--) {
    if (i % 2 == (n - 1) % 2) {
      for (long long j = k; j < n; j++) {
        arr[j][i] = curr;
        curr++;
      }
    } else {
      for (long long j = n - 1; j >= k; j--) {
        arr[j][i] = curr;
        curr++;
      }
    }
  }
  long long delta = (n * n) - 16;
  if (n % 2 == 0) {
    swap(arr[n - 2][4], arr[k][4]);
  } else {
    swap(arr[n - 2][4], arr[n - 1][4]);
  }
  long long base[4][4];
  base[0][0] = 4;
  base[0][1] = 3;
  base[0][2] = 6;
  base[0][3] = 12;
  base[1][0] = 7;
  base[1][1] = 5;
  base[1][2] = 9;
  base[1][3] = 15;
  base[2][0] = 14;
  base[2][1] = 1;
  base[2][2] = 11;
  base[2][3] = 10;
  base[3][0] = 13;
  base[3][1] = 8;
  base[3][2] = 16;
  base[3][3] = 2;
  for (long long i = k; i < n; i++) {
    for (long long j = 0; j < 4; j++) {
      arr[i][j] = base[i - k][j] + delta;
    }
  }
  for (long long i = 0; i < n; i++) {
    for (long long j = 0; j < n; j++) {
      cout << arr[i][j] << ' ';
    }
    cout << endl;
  }
}
