#include <bits/stdc++.h>
using namespace std;
bool cmp(int a, int b) { return a > b; }
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  int n;
  cin >> n;
  int m;
  cin >> m;
  char a[n][m];
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      cin >> a[i][j];
    }
  }
  int count = 0;
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      if (a[i][j] == 'W') {
        if (j > 0 && a[i][j - 1] == 'P') {
          count++;
          a[i][j - 1] = '.';
        } else if (i > 0 && a[i - 1][j] == 'P') {
          count++;
          a[i - 1][j] = '.';
        } else if (j < n - 1 && a[i][j + 1] == 'P') {
          count++;
          a[i][j + 1] = '.';
        } else if (i < n - 1 && a[i + 1][j] == 'P') {
          count++;
          a[i][j] = '.';
        }
      }
    }
  }
  cout << count;
}
