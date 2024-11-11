#include <bits/stdc++.h>
using namespace std;
long long power(long long a, long long b) {
  if (b == 0) return 1;
  if (b % 2 == 0) return power(a, b / 2);
  return (a * power(a, b / 2));
}
int main() {
  int n, m;
  cin >> n >> m;
  bool ar[51][51];
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      cin >> ar[i][j];
    }
  }
  int minsum = -1;
  int a, b;
  cin >> a >> b;
  for (int i = 0; i + a - 1 < n; i++) {
    for (int j = 0; j + b - 1 < n; j++) {
      int sum = 0;
      for (int ii = 0; ii < a; ii++) {
        for (int jj = 0; jj < b; jj++) {
          sum += ar[i + ii][j + jj];
        }
      }
      if (minsum == -1 || sum < minsum) minsum = sum;
    }
  }
  swap(a, b);
  for (int i = 0; i + a - 1 < n; i++) {
    for (int j = 0; j + b - 1 < n; j++) {
      int sum = 0;
      for (int ii = 0; ii < a; ii++) {
        for (int jj = 0; jj < b; jj++) {
          sum += ar[i + ii][j + jj];
        }
      }
      if (minsum == -1 || sum < minsum) minsum = sum;
    }
  }
  cout << minsum << endl;
  return 0;
}
