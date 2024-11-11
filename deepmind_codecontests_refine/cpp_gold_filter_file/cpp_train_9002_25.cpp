#include <bits/stdc++.h>
using namespace std;
const int N = 102;
int a[N][N];
int main() {
  int n;
  scanf("%d", &n);
  for (int i = 0; i < n; ++i) {
    int x1, y1, x2, y2;
    scanf("%d %d %d %d", &x1, &y1, &x2, &y2);
    for (int j = x1; j <= x2; ++j) {
      for (int k = y1; k <= y2; ++k) {
        ++a[j][k];
      }
    }
  }
  int sum = 0;
  for (int i = 1; i <= 100; ++i) {
    for (int j = 1; j <= 100; ++j) {
      sum += a[i][j];
    }
  }
  printf("%d", sum);
}
