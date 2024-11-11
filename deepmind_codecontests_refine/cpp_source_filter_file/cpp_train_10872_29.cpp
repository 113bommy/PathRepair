#include <bits/stdc++.h>
using namespace std;
const long long MAX = (long long)1e8;
int main() {
  int n, m;
  while (cin >> n >> m) {
    vector<int> A(n), B(m);
    if (n & 1) {
      A[0] = 2;
      A[n - 1] = (n - 1) / 2;
    } else {
      A[0] = 1;
      A[n - 1] = (n - 2) / 2;
    }
    if (m & 1) {
      B[0] = 2;
      B[m - 1] = (m - 1) / 2;
    } else {
      B[0] = 1;
      B[m - 1] = (m - 2) / 2;
    }
    for (int i = 1; i < n - 1; ++i) A[i] = 1;
    for (int j = 1; j < m - 1; ++j) B[j] = 1;
    if (n == 1)
      A[0] = 1;
    else if (n == 2) {
      A[0] = 3;
      A[1] = 4;
    }
    if (m == 1)
      B[0] = 1;
    else if (m == 2) {
      B[0] = 3;
      B[1] = 4;
    }
    for (int i = 0; i < n; ++i) {
      cout << A[i] * B[0];
      for (int j = 1; j < m; ++j) cout << " " << A[i] * B[j];
      cout << endl;
    }
  }
  return 0;
}
