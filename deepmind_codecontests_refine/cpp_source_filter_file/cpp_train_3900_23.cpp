#include <bits/stdc++.h>
using namespace std;
const int M = 2005;
int a[M][M];
long long L[M << 1];
long long R[M << 1];
int main() {
  int n;
  while (cin >> n) {
    memset(L, 0, sizeof(L));
    memset(R, 0, sizeof(R));
    for (int i = 1; i <= n; i++) {
      for (int j = 1; j <= n; j++) {
        scanf("%d", &a[i][j]);
        L[i - j + n] += a[i][j];
        R[i + j] += a[i][j];
      }
    }
    int x1, x2, y1, y2;
    long long max1, max2;
    max1 = max2 = 0;
    for (int i = 1; i <= n; i++) {
      for (int j = 1; j <= n; j++) {
        long long tp = L[i - j + n] + R[i + j] - a[i][j];
        if ((i + j) & 1) {
          if (max1 < tp) {
            max1 = tp;
            x1 = i;
            y1 = j;
          }
        } else {
          if (max2 < tp) {
            max2 = tp;
            x2 = i;
            y2 = j;
          }
        }
      }
    }
    cout << max1 + max2 << endl;
    cout << x1 << " " << y1 << " " << x2 << " " << y2 << endl;
  }
  return 0;
}
