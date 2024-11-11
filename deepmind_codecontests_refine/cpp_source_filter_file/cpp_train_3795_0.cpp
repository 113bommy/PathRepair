#include <bits/stdc++.h>
using namespace std;
char a[100][100];
int main() {
  int n, k = 0;
  cin >> n;
  int m;
  char c = 'D';
  m = ((n - 1) / 2) + 1;
  for (int i = 0; i < m; i++) {
    for (int j = 0; j < n; j++) {
      if (j == ((n + 1) / 2) - 1) {
        a[i][j] = c;
      } else if (j != ((n + 1) / 2) - 1) {
        a[i][j] = '*';
      }
    }
  }
  for (int i = 0; i < m; i++) {
    for (int j = 0; j < n; j++) {
      if (a[i - 1][j + 1] == c) {
        a[i][j] = c;
        a[i][j + 1] = c;
      }
    }
  }
  for (int i = 0; i < m; i++) {
    for (int j = n - 1; j >= 0; j--) {
      if (a[i - 1][j - 1] == c) {
        a[i][j] = c;
        a[i][j - 1] = c;
      }
    }
  }
  for (int i = 0; i < m; i++) {
    for (int j = 0; j < n; j++) cout << a[i][j];
    cout << endl;
  }
  for (int i = m - 2; i >= 0; i--) {
    for (int j = 0; j < n; j++) cout << a[i][j];
    cout << endl;
  }
  return 0;
}
