#include <bits/stdc++.h>
using namespace std;
int n, m, i, j, A[105], B[105];
int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  cin >> n >> m;
  if (n == 1)
    A[1] = 1;
  else {
    if (n == 2) {
      A[1] = 3;
      A[2] = 4;
    } else {
      for (i = 1; i < n; i++) A[i] = 1;
      if (n % 2 == 0)
        A[n] = (n - 2) / 2;
      else {
        A[1] = 2;
        A[n] = (n + 1) / 2;
      }
    }
  }
  if (m == 1)
    B[1] = 1;
  else {
    if (m == 2) {
      B[1] = 3;
      B[2] = 4;
    } else {
      for (i = 1; i < m; i++) B[i] = 1;
      if (m % 2 == 0)
        B[m] = (m - 2) / 2;
      else {
        B[1] = 2;
        B[m] = (m + 1) / 2;
      }
    }
  }
  for (i = 1; i <= n; i++) {
    for (j = 1; j <= m; j++) cout << A[i] * B[j] << " ";
    cout << "\n";
  }
  return 0;
}
