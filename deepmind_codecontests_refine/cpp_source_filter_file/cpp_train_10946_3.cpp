#include <bits/stdc++.h>
using namespace std;
int a, b, c;
vector<vector<int> > D(7, vector<int>(3, 0));
int proc(int x, int y) {
  int A = a, B = b, C = c;
  for (int i = x; i < 7; i++) {
    A -= D[i][0], B -= D[i][1], C -= D[i][2];
  }
  for (int i = 0; i <= y; i++) {
    A -= D[i][0], B -= D[i][1], C -= D[i][2];
  }
  if (A < 0 || B < 0 || C < 0) return 0;
  return y - x + 8 + min(min(A / 3, B / 2), C / 2) * 7;
}
int main() {
  cin >> a >> b >> c;
  D[0][0] = D[1][1] = D[2][2] = D[3][0] = D[4][2] = D[5][1] = D[6][0] = 1;
  int ans = 0;
  for (int i = 0; i < 7; i++) {
    for (int j = 0; j < 7; j++) {
      if (i <= j) {
        int A, B, C;
        A = a, B = b, C = c;
        for (int x = i; x <= j; x++) {
          A -= D[x][0], B -= D[i][1], C -= D[x][2];
        }
        if (A >= 0 && B >= 0 && C >= 0) ans = max(ans, j - i + 1);
      }
      ans = max(ans, proc(i, j));
    }
  }
  cout << ans;
}
