#include <bits/stdc++.h>
using namespace std;
int main() {
  string A[2], B[1001][2];
  cin >> A[0] >> A[1];
  int n;
  cin >> n;
  for (int i = 0; i < 2; i++) {
    B[0][i] = A[i];
    cout << B[0][i] << " ";
  }
  cout << endl;
  for (int i = 1; i < n + 1; i++) {
    string x, y;
    cin >> x >> y;
    for (int t = 0; t < 2; t++) {
      if (A[t] == x) A[t] = y;
      B[i][t] = A[t];
      cout << B[i][t] << " ";
    }
    cout << endl;
  }
  return 0;
}
