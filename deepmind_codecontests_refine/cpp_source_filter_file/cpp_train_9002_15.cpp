#include <bits/stdc++.h>
using namespace std;
int a[100][100];
int main() {
  int n, x1, y1, x2, y2, res = 0;
  cin >> n;
  for (int i = 0; i < n; i++) {
    cin >> x1 >> y1 >> x2 >> y2;
    for (int j = x1; j <= x2; j++) {
      for (int h = y1; h <= y2; h++) {
        a[j][h]++;
      }
    }
  }
  for (int i = 0; i <= 100; i++) {
    for (int j = 0; j <= 100; j++) {
      res += a[i][j];
    }
  }
  cout << res;
  return 0;
}
