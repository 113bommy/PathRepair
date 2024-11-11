#include <bits/stdc++.h>
using namespace std;
int main() {
  int n;
  cin >> n;
  int **a = new int *[n];
  int count = 0;
  for (int i = 0; i < n; i++) {
    a[i] = new int[n];
  }
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
      cin >> a[i][j];
      if ((i == j) || (i == n - 1 - j) || (i == (n - 2) / 2) ||
          (j == (n - 2) / 2)) {
        count = count + a[i][j];
      }
    }
  }
  cout << count;
  return 0;
}
