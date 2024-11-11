#include <bits/stdc++.h>
using namespace std;
int dx[] = {0, -1, 0, 1};
int dy[] = {-1, 0, 1, 0};
int i, n, j, m, sumR, sumC, cnt, arr[35][35];
int main() {
  cin >> n;
  for (i = 0; i < n; i++) {
    for (j = 0; j < n; j++) cin >> arr[i][j];
  }
  for (i = 0; i < n; i++) {
    for (j = 0; j < n; j++) {
      sumR = sumC = 0;
      for (m = 0; m < n; m++) {
        sumR += arr[m][j];
        sumC += arr[i][m];
      }
      if (sumC > sumR) cnt++;
    }
  }
  cout << cnt;
  return 0;
}
