#include <bits/stdc++.h>
using namespace std;
int main() {
  int n;
  cin >> n;
  char A[n][n];
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
      if ((i + j) % 2 == 0)
        A[i][j] = 'W';
      else
        A[i][j] = 'B';
      cout << A[i][j] << " ";
    }
    cout << endl;
  }
}
