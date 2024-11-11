#include <bits/stdc++.h>
using namespace std;
int main() {
  int n;
  cin >> n;
  vector<string> M;
  int A[n][n];
  int R[n], C[n];
  for (int i = 0; i < n; i++) {
    string s;
    cin >> s;
    R[i] = C[i] = 0;
    for (int j = 0; j < n; j++) {
      A[i][j] = s[j] == '.' ? 0 : 1;
    }
  }
  bool row_found = 0;
  bool col_found = 0;
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
      if (A[i][j] == 1) {
        R[i]++;
        C[j]++;
        if (R[i] == n) row_found = true;
        if (C[i] == n) col_found = true;
      }
    }
  }
  if (row_found && col_found)
    cout << -1 << endl;
  else if (row_found) {
    for (int i = 0; i < n; i++) {
      for (int j = 0; j < n; j++) {
        if (A[j][i] == 0) {
          cout << j + 1 << " " << i + 1 << endl;
          break;
        }
      }
    }
  } else {
    for (int i = 0; i < n; i++) {
      for (int j = 0; j < n; j++) {
        if (A[i][j] == 0) {
          cout << i + 1 << " " << j + 1 << endl;
          break;
        }
      }
    }
  }
  return 0;
}
