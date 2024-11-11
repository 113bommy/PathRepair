#include <bits/stdc++.h>
using namespace std;
int main() {
  int na, ma, nb, mb;
  string A[51], B[51];
  cin >> ma >> na;
  for (int i = 1; i <= ma; ++i) {
    cin >> A[i];
    A[i] = " " + A[i];
  }
  cin >> mb >> nb;
  for (int i = 1; i <= mb; ++i) {
    cin >> B[i];
    B[i] = " " + B[i];
  }
  int r1, r2, m = 0;
  for (int x = -50; x <= 50; ++x) {
    for (int y = -50; y <= 50; ++y) {
      int S = 0;
      for (int i = 1; i <= ma; ++i)
        if (i + y > 0 && i + y <= mb) {
          for (int j = 1; j <= na; ++j)
            if (j + x > 0 && j + x <= nb) {
              S += (A[i][j] - 48) * (B[i + y][j + x] - 48);
            }
        }
      if (S > m) {
        m = S;
        r1 = x;
        r2 = y;
      }
    }
  }
  cout << r2 << " " << r1;
  return 0;
}
