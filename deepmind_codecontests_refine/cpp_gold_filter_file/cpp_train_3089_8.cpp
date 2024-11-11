#include <bits/stdc++.h>
using namespace std;
int mat[1010][1010];
int main() {
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  int n, a, b;
  cin >> n >> a >> b;
  if (n > 1 && n < 4) {
    if (a == 1 && b == 1) {
      cout << "NO";
      return 0;
    }
  }
  if (min(a, b) > 1) {
    cout << "NO";
    return 0;
  }
  int schimb = 0;
  int fac = a;
  if (a == 1) {
    fac = b;
    schimb = 1;
  }
  fac = n - fac + 1;
  for (int i = 1; i <= fac; i++) {
    mat[i][i - 1] = 1;
    mat[i][i + 1] = 1;
  }
  mat[fac][fac + 1] = 0;
  if (schimb) {
    for (int i = 1; i <= n; i++) {
      for (int j = 1; j <= n; j++) {
        if (i == j) {
          continue;
        }
        mat[i][j] ^= 1;
      }
    }
  }
  cout << "YES" << '\n';
  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= n; j++) {
      cout << mat[i][j];
    }
    cout << '\n';
  }
  return 0;
}
