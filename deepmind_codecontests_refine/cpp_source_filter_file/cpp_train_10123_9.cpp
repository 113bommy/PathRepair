#include <bits/stdc++.h>
using namespace std;
inline void Boost() {
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
}
const int NMAX = 505;
int n, mat[NMAX][NMAX];
int main() {
  Boost();
  int i, j;
  cin >> n;
  if (n < 3) {
    cout << -1;
    return 0;
  }
  int cn = n, elem = 0;
  while (cn > 3) {
    if (cn & 1) {
      for (i = 1; i <= cn; i++) mat[cn][i] = ++elem;
      for (i = cn - 1; i >= 1; i--) mat[i][cn] = ++elem;
    } else {
      for (i = 1; i <= cn; i++) mat[i][cn] = ++elem;
      for (i = cn - 1; i >= 1; i--) mat[cn][i] = ++elem;
    }
    cn--;
  }
  mat[3][1] = ++elem;
  mat[3][2] = ++elem;
  mat[2][2] = ++elem;
  mat[1][2] = ++elem;
  mat[1][3] = ++elem;
  mat[3][3] = ++elem;
  mat[2][3] = ++elem;
  mat[2][1] = ++elem;
  mat[1][1] = ++elem;
  for (i = 1; i <= n; i++) {
    for (j = 1; j <= n; j++) cout << mat[i][j] << " ";
    cout << "\n";
  }
  return 0;
}
