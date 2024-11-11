#include <bits/stdc++.h>
using namespace std;
int main() {
  unsigned n;
  cin >> n;
  vector<vector<char>> M(n, vector<char>(n, '.'));
  for (auto& x : M) {
    for (auto& y : x) cin >> y;
  }
  int nCross = 0;
  if (n > 4) {
    for (int i = 1; i < n - 1; i++)
      for (int j = 1; j < n - 1; j++) {
        if (M[i][j] != 'X')
          continue;
        else {
          if (M[i - 1][j - 1] == 'X' && M[i + 1][j + 1] == 'X' &&
              M[i - 1][j + 1] == 'X' && M[i + 1][j - 1] == 'X')
            nCross++;
        }
      }
  }
  cout << nCross;
  return 0;
}
