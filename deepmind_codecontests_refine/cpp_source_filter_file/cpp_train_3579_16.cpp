#include <bits/stdc++.h>
using namespace std;
bool dp3[301][301][301];
bool dp2[301][301];
int main() {
  int n;
  cin >> n;
  if (n == 1) {
    int a;
    cin >> a;
    if (a == 0) {
      cout << "BitAryo";
      return 0;
    }
    if (a > 1) {
      cout << "BitLGM";
      return 0;
    }
  }
  if (n == 2) {
    for (int i = 0; i <= 300; i++) {
      for (int j = 0; j <= 300; j++) {
        if (!dp2[i][j]) {
          for (int k = 1; k + j <= 300; k++) {
            dp2[i][k + j] = 1;
          }
          for (int k = 1; k + i <= 300; k++) {
            dp2[i + k][j] = 1;
          }
          for (int k = 0; k + i <= 300 && k + j <= 300; k++) {
            dp2[i + k][j + k] = 1;
          }
        }
      }
    }
    int a1, a2;
    cin >> a1 >> a2;
    if (dp2[a1][a2]) {
      cout << "BitLGM";
      return 0;
    } else {
      cout << "BitAryo";
      return 0;
    }
  } else {
    for (int i = 0; i <= 300; i++) {
      for (int j = 0; j <= 300; j++) {
        for (int z = 0; z <= 300; z++) {
          if (!dp3[i][j]) {
            for (int k = 1; k + j <= 300; k++) {
              dp3[i][k + j][z] = 1;
            }
            for (int k = 1; k + i <= 300; k++) {
              dp3[i + k][j][z] = 1;
            }
            for (int k = 1; k + z <= 300; k++) {
              dp3[i][j][z + k] = 1;
            }
            for (int k = 0; k + i <= 300 && k + j <= 300 && k + z <= 300; k++) {
              dp3[i + k][j + k][z + k] = 1;
            }
          }
        }
      }
    }
    int a1, a2, a3;
    cin >> a1 >> a2 >> a3;
    if (dp3[a1][a2][a3]) {
      cout << "BitLGM";
      return 0;
    } else {
      cout << "BitAryo";
      return 0;
    }
  }
  return 0;
}
