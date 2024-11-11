#include <bits/stdc++.h>
using namespace std;
int main() {
  int A[2][100000] = {0};
  int n, total = 0;
  cin >> n;
  for (int i = 0; i < n; i++) cin >> A[0][i] >> A[1][i];
  for (int i = 0; i < n; i++) {
    total += A[0][i] * A[1][i];
    if (i != n - 1) {
      int j = i + 1;
      while (A[1][i] < A[1][j]) {
        total += A[0][j] * A[1][i];
        j++;
      }
      if (j != i + 1) i = j - 1;
    }
  }
  cout << total << endl;
  return 0;
}
