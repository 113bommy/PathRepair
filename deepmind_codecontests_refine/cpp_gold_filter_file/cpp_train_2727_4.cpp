#include <bits/stdc++.h>
using namespace std;
const int MX = 1e3 + 5, MXX = 23;
const long long mod = 1e9 + 7;
int mat[MX][MX];
long long power(int a) {
  if (a == 0) return 1;
  long long f = power(a / 2);
  f *= f;
  f %= mod;
  if (a % 2) f *= 2;
  f %= mod;
  return f;
}
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  int h, w;
  cin >> h >> w;
  bool f = true;
  for (int i = 0; i < h; ++i) {
    int row;
    cin >> row;
    for (int j = 0; j < row; ++j) mat[i][j] = 1;
    mat[i][row] = -1;
  }
  for (int i = 0; i < w; ++i) {
    int col;
    cin >> col;
    for (int j = 0; j < col; ++j) {
      if (mat[j][i] == -1) f = false;
      mat[j][i] = 1;
    }
    if (mat[col][i] == 1) f = false;
    mat[col][i] = -1;
  }
  long long ans = 0;
  for (int i = 0; i < h; ++i)
    for (int j = 0; j < w; ++j)
      if (mat[i][j] == 0) ans++;
  if (f == false) {
    cout << 0 << endl;
    return 0;
  }
  cout << power(ans) << endl;
  return 0;
}
