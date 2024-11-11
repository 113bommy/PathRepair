#include <bits/stdc++.h>
using namespace std;
int a[100][100];
int main() {
  int n, m;
  cin >> n >> m;
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      cin >> a[i][j];
    }
  }
  int x, y;
  cin >> x >> y;
  int mm = 1000000000;
  for (int i = 0; i <= n - x; i++) {
    for (int j = 0; j <= m - y; j++) {
      int c = 0;
      for (int k = 0; k < x; k++) {
        for (int g = 0; g < y; g++) {
          if (a[i + k][j + g]) c++;
        }
      }
      mm = min(mm, c);
    }
  }
  int xx = x;
  x = y;
  y = xx;
  for (int i = 0; i <= n - x; i++) {
    for (int j = 0; j <= m - y; j++) {
      int c = 0;
      for (int k = 0; k < x; k++) {
        for (int g = 0; g < y; g++) {
          if (a[i + k][j + g]) c++;
        }
      }
      mm = min(mm, c);
    }
  }
  cout << mm << endl;
}
