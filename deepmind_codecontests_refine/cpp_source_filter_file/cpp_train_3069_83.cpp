#include <bits/stdc++.h>
using namespace std;
int main() {
  string A[8];
  for (int i = 0; i < 8; i++) cin >> A[i];
  int B[300];
  for (int i = 0; i < 300; i++) B[i] = 0;
  for (int i = 0; i < 8; i++) {
    for (int j = 0; j < 8; j++) {
      if (A[i][j] != '.') B[A[i][j]]++;
    }
  }
  int w = 0, b = 0;
  w = B['Q'] * 9 + B['R'] * 5 + B['B'] * 3 + B['K'] * 3 + B['P'] * 3;
  b = B['q'] * 9 + B['r'] * 5 + B['b'] * 3 + B['k'] * 3 + B['p'] * 3;
  if (w > b)
    cout << "White" << endl;
  else if (w == b)
    cout << "Draw" << endl;
  else if (w < b)
    cout << "Black" << endl;
}
