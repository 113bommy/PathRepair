#include <bits/stdc++.h>
using namespace std;
int main() {
  int n, count = 0;
  cin >> n;
  char a[n][n];
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) cin >> a[i][j];
  }
  for (int i = 1; i < n - 1; i++) {
    for (int j = 1; j < n - 1; j++) {
      if (a[i][j] == 'x' && a[i - 1][j - 1] == 'x' && a[i - 1][j + 1] == 'x' &&
          a[i + 1][j + 1] == 'x' && a[i + 1][j - 1] == 'x')
        count++;
    }
  }
  cout << count << endl;
  return 0;
}
