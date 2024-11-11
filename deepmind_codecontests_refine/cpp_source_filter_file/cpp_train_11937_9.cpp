#include <bits/stdc++.h>
using namespace std;
char mat[4][105][105];
int main() {
  long long n, minsol = 5445242543543;
  cin >> n;
  for (long i = 0; i < 4; i++) {
    for (long j = 0; j < n; j++) {
      for (long h = 0; h < n; h++) {
        cin >> mat[i][j][h];
      }
    }
  }
  for (long i = 0; i < 4; i++) {
    for (long j = 0; j < 4; j++) {
      for (long h = 0; h < 4; h++) {
        for (long g = 0; g < 4; g++) {
          if (i != j && j != h && h != g && i != g && h != i && j != g) {
            long long sol = 0;
            for (long t = 0; t < n; t++) {
              for (long r = 0; r < n; r++) {
                if (t % 2 == 0) {
                  if (r % 2 == 0) {
                    if (mat[i][t][r] != '1') {
                      sol++;
                    }
                    if (mat[j][t][r] != '1') {
                      sol++;
                    }
                  } else {
                    if (mat[i][t][r] != '0') {
                      sol++;
                    }
                    if (mat[i][t][r] != '0') {
                      sol++;
                    }
                  }
                } else {
                  if (r % 2 == 0) {
                    if (mat[i][t][r] != '0') {
                      sol++;
                    }
                    if (mat[j][t][r] != '0') {
                      sol++;
                    }
                  } else {
                    if (mat[i][t][r] != '1') {
                      sol++;
                    }
                    if (mat[j][t][r] != '1') {
                      sol++;
                    }
                  }
                }
              }
            }
            for (long t = 0; t < n; t++) {
              for (long r = 0; r < n; r++) {
                if (t % 2 == 0) {
                  if (r % 2 == 0) {
                    if (mat[h][t][r] != '0') {
                      sol++;
                    }
                    if (mat[g][t][r] != '0') {
                      sol++;
                    }
                  } else {
                    if (mat[h][t][r] != '1') {
                      sol++;
                    }
                    if (mat[g][t][r] != '1') {
                      sol++;
                    }
                  }
                } else {
                  if (r % 2 == 0) {
                    if (mat[h][t][r] != '1') {
                      sol++;
                    }
                    if (mat[g][t][r] != '1') {
                      sol++;
                    }
                  } else {
                    if (mat[h][t][r] != '0') {
                      sol++;
                    }
                    if (mat[g][t][r] != '0') {
                      sol++;
                    }
                  }
                }
              }
            }
            minsol = min(minsol, sol);
          }
        }
      }
    }
  }
  cout << minsol << endl;
}
