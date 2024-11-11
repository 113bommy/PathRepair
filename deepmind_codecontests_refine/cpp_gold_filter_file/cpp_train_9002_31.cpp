#include <bits/stdc++.h>
using namespace std;
int a[101][101];
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
  for (int i = 1; i < 101; i++) {
    for (int j = 1; j < 101; j++) {
      res += a[i][j];
    }
  }
  cout << res;
  return 0;
}
