#include <bits/stdc++.h>
using namespace std;
int main() {
  int n, k = 0, k2 = 0;
  cin >> n;
  char a[n + 10][n + 10];
  for (int i = 1; i <= n; ++i) {
    for (int j = 1; j <= n; ++j) {
      cin >> a[i][j];
    }
  }
  for (int i = 1; i < n; ++i) {
    for (int j = 1; j < n; ++j) {
      if (i == j && a[i][j] != a[i + 1][j + 1]) {
        cout << "NO";
        return 0;
      }
      if (a[i][n - i + 1] != a[i + 1][n - i]) {
        cout << "NO";
        return 0;
      }
    }
  }
  for (char l = 'a'; l <= 'z'; ++l) {
    int k1 = 0;
    for (int i = 1; i <= n; ++i) {
      for (int j = 1; j <= n; ++j) {
        if (l == a[i][j] && k1 == 0) {
          k++;
          k1++;
        }
        if (l == a[i][j] && k1 > 0) {
          k1++;
        }
      }
    }
    if (k1 == (n * 2 - 1)) k2++;
  }
  if (k2 > 0 && k == 2) {
    cout << "YES";
  } else
    cout << "NO";
}
