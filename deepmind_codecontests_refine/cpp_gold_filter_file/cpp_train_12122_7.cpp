#include <bits/stdc++.h>
using namespace std;
int main() {
  int n, m;
  cin >> n >> m;
  int A[m];
  for (int i = 0; i < m; i++) {
    cin >> A[i];
  }
  int I[n];
  for (int i = 0; i < n; i++) {
    I[i] = -1;
  }
  for (int i = 0; i < m; i++) {
    for (int j = A[i] - 1; j < n; j++) {
      if (I[j] == -1) {
        I[j] = A[i];
      }
    }
  }
  for (int i = 0; i < n; i++) {
    cout << I[i] << " ";
  }
  return 0;
}
