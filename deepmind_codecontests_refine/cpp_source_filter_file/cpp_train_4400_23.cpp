#include <bits/stdc++.h>
using namespace std;
int m = 0, b = 0;
int main() {
  int n;
  cin >> n;
  int Arrpi[n];
  for (int j = 0; j < n; ++j) {
    cin >> Arrpi[j];
  }
  int A[n];
  for (int l = 0; l < n; ++l) {
    m = Arrpi[l] - 1;
    b = l + 1;
    A[m] = b;
  }
  for (int y = 0; y < n; ++y) {
    cout << A[y];
  }
  return 0;
}
