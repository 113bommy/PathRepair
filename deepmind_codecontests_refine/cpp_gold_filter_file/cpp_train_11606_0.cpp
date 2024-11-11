#include <bits/stdc++.h>
using namespace std;
int const N = 11;
int v[N][N];
int main() {
  int n;
  cin >> n;
  for (int i = 0; i < n; i++) v[0][i] = 1;
  for (int i = 1; i < n; i++) {
    v[i][0] = 1;
    for (int j = 1; j < n; j++) v[i][j] = v[i][j - 1] + v[i - 1][j];
  }
  cout << v[n - 1][n - 1];
}
