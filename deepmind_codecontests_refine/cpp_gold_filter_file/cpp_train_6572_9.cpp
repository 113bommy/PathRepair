#include <bits/stdc++.h>
using namespace std;
int main() {
  int n;
  cin >> n;
  char a[n][n];
  for (int i = 0; i < n; i++) cin >> a[i];
  int c = 0;
  for (int i = 1; i < n - 1; i++) {
    for (int j = 1; j < n - 1; j++) {
      if (a[i][j] == 'X' and a[i - 1][j - 1] == 'X' and
          a[i - 1][j + 1] == 'X' and a[i + 1][j - 1] == 'X' and
          a[i + 1][j + 1] == 'X')
        c++;
    }
  }
  cout << c;
}
