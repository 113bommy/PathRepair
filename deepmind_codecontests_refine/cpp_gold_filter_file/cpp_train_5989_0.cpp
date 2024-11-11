#include <bits/stdc++.h>
using namespace std;
int main() {
  int n;
  cin >> n;
  char a[n][n];
  int i, i2;
  for (i = 0; i < n; i++) {
    for (i2 = 0; i2 < n; i2++) {
      cin >> a[i][i2];
    }
  }
  int i4;
  int result = 0;
  for (i = 0; i < n; i++) {
    for (i2 = 0; i2 < n; i2++) {
      if (a[i][i2] == 'C') {
        for (i4 = i2 + 1; i4 < n; i4++) {
          if (a[i][i4] == 'C') result++;
        }
        for (i4 = i + 1; i4 < n; i4++) {
          if (a[i4][i2] == 'C') result++;
        }
      }
    }
  }
  cout << result;
}
