#include <bits/stdc++.h>
using namespace std;
int main() {
  int K[4];
  int C[4] = {0};
  cin >> K[0] >> K[1] >> K[2] >> K[3];
  int M[40][50];
  for (int i = 0; i < 40; i++) {
    for (int j = 0; j < 50; j++) {
      M[i][j] = i / 10;
    }
  }
  for (int k = 3; k >= 0; k--) {
    for (int i = (3 - k) * 10 + 1; i < (3 - k) * 10 + 10; i += 2) {
      for (int j = 0; j < 50; j += 2) {
        if (C[k] == K[k] - 1) break;
        M[i][j] = k;
        C[k]++;
      }
      if (C[k] == K[k] - 1) break;
    }
  }
  cout << 40 << " " << 50 << endl;
  for (int i = 0; i < 40; i++) {
    for (int j = 0; j < 50; j++) {
      switch (M[i][j]) {
        case 0:
          cout << "A";
          break;
        case 1:
          cout << "B";
          break;
        case 2:
          cout << "C";
          break;
        case 3:
          cout << "D";
          break;
      }
    }
    cout << endl;
  }
  return 0;
}
