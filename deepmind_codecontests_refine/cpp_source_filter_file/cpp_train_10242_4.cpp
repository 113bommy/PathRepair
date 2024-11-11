#include <bits/stdc++.h>
using namespace std;
int main() {
  vector<vector<bool>> p(3, vector<bool>(3, true));
  int n;
  for (int i = 0; i < 3; i++) {
    for (int j = 0; j < 3; j++) {
      cin >> n;
      if (!n % 2) {
        continue;
      }
      p[i][j] = !p[i][j];
      if (j < 2) {
        p[i][j + 1] = !p[i][j + 1];
      }
      if (j > 0) {
        p[i][j - 1] = !p[i][j - 1];
      }
      if (i < 2) {
        p[i + 1][j] = !p[i + 1][j];
      }
      if (i > 0) {
        p[i - 1][j] = !p[i - 1][j];
      }
    }
  }
  for (int i = 0; i < 3; i++) {
    for (int j = 0; j < 3; j++) {
      cout << p[i][j];
    }
    cout << endl;
  }
}
