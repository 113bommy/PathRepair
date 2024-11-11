#include <bits/stdc++.h>
using namespace std;
int main() {
  int n, m;
  cin >> n >> m;
  long long mat[101][101];
  long long mas[300];
  for (int i = 0; i < 200; ++i) {
    mas[i] = 0;
  }
  long long bigmax = 0;
  long long ibigmax = 0;
  for (int i = 0; i < m; ++i) {
    long long max = 0;
    long long imax = 0;
    for (int j = 0; j < n; ++j) {
      cin >> mat[i][j];
      if (mat[i][j] > max) {
        imax = j;
        max = mat[i][j];
      }
    }
    mas[imax]++;
  }
  for (int i = 0; i < m; ++i) {
    if (mas[i] > bigmax) {
      ibigmax = i;
      bigmax = mas[i];
    }
  }
  cout << ibigmax + 1;
  return 0;
}
