#include <bits/stdc++.h>
using namespace std;
int main() {
  int t;
  cin >> t;
  for (int ii = 0; ii < t; ii++) {
    int n;
    cin >> n;
    bool A[52];
    char Aa[52][52];
    for (int i = 0; i < n; i++) {
      char t;
      cin >> t;
      if (t == '1')
        A[i] = 0;
      else
        A[i] = 1;
    }
    int k = 0;
    int t = -1;
    for (int i = n - 1; i >= 0; i--) {
      if (A[i] == 0) {
        k++;
      } else {
        t = i;
      }
    }
    if (n - k > 1 || n - k == 0)
      cout << "YES" << endl;
    else {
      cout << "NO" << endl;
      continue;
    }
    for (int i = 0; i < n; i++) {
      for (int j = 0; j < n; j++) {
        Aa[i][j] = '=';
      }
    }
    for (int i = 0; i < n; i++) Aa[i][i] = 'X';
    int c1 = t;
    if (n - k > 1) {
      for (int i = t + 1; i < n; i++) {
        if (A[i] == 1) {
          Aa[c1][i] = '+';
          Aa[i][c1] = '-';
          c1 = i;
        }
      }
      Aa[c1][t] = '+';
      Aa[t][c1] = '-';
    }
    for (int i = 0; i < n; i++) {
      for (int j = 0; j < n; j++) {
        cout << Aa[i][j];
      }
      cout << endl;
    }
  }
  return 0;
}
