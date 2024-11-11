#include <bits/stdc++.h>
using namespace std;
int main() {
  int n;
  cin >> n;
  int k = n * n;
  int a[n][n];
  memset(a, 0, sizeof(a));
  int mid = n / 2;
  int odd = 1, even = 2;
  if (n == 1)
    cout << "1";
  else {
    for (int i = 0; i < n; i++) {
      a[mid][i] = odd;
      odd += 2;
      if (mid != i) {
        a[i][mid] = odd;
        odd += 2;
      }
    }
    odd -= 2;
    if (odd < k) {
      for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - 1; j++) {
          if (odd >= k) break;
          if (a[i][j] == 0 and a[i][j + 1] == 0 and a[i + 1][j] == 0 and
              a[i + 1][j + 1] == 0) {
            odd += 2, a[i][j] = odd;
            odd += 2, a[i][j + 1] = odd;
            odd += 2, a[i + 1][j] = odd;
            odd += 2, a[i + 1][j + 1] = odd;
          }
        }
        if (odd >= k) break;
      }
    }
    for (int i = 0; i < n; i++) {
      for (int j = 0; j < n; j++) {
        if (a[i][j] == 0) {
          a[i][j] = even;
          even += 2;
        }
      }
    }
    for (int i = 0; i < n; i++) {
      for (int j = 0; j < n; j++) cout << a[i][j] << " ";
      cout << '\n';
    }
  }
}
