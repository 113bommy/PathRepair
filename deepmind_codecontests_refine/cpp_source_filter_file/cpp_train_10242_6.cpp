#include <bits/stdc++.h>
using namespace std;
int main(int argc, char const *argv[]) {
  int lights[3][3] = {{1, 1, 1}, {1, 1, 1}, {1, 1, 1}}, state;
  for (int i = 0; i < 3; ++i) {
    for (int j = 0; j < 3; ++j) {
      cin >> state;
      lights[i][j] ^= (state % 2);
      if (i == 0 || j == 0) {
        if (i == 0 && j == 0) {
          lights[i + 1][j] ^= state % 2;
          lights[i][j + 1] ^= state % 2;
        } else if (i == 0) {
          lights[i + 1][j] ^= state % 2;
          lights[i][j - 1] ^= state % 2;
          if (j < 2) {
            lights[i][j + 1] ^= state % 2;
          }
        } else {
          lights[i - 1][j] ^= state % 2;
          lights[i][j + 1] ^= state % 2;
          if (i < 2) {
            lights[i + 1][j] ^= state % 2;
          }
        }
      } else if (i == 1 && j == 1) {
        lights[i + 1][j] ^= state % 2;
        lights[i][j + 1] ^= state % 2;
        lights[i - 1][j] ^= state % 2;
        lights[i][j - 1] ^= state % 2;
      } else {
        if (i == 2 && j == 2) {
          lights[i - 1][j] ^= state % 2;
          lights[i][j - 1] ^= state % 2;
        } else if (i == 2) {
          lights[i - 1][j] ^= state % 2;
          lights[i][j - 1] ^= state % 2;
          lights[i][j + 1] ^= state % 2;
        } else {
          lights[i - 1][j] ^= state % 2;
          lights[i + 1][j] ^= state % 2;
          lights[i][j - 1] ^= state % 2;
        }
      }
    }
  }
  for (int i = 0; i < 3; ++i) {
    for (int j = 0; j < 3; ++j) {
      cout << lights[i][j] << " ";
    }
    cout << endl;
  }
  return 0;
}
