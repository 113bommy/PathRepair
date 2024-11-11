#include <bits/stdc++.h>
using namespace std;
int main() {
  ios::sync_with_stdio(false);
  int mat[6][3];
  mat[0][0] = 0;
  mat[0][1] = 1;
  mat[0][2] = 2;
  mat[1][0] = 1;
  mat[1][1] = 0;
  mat[1][2] = 2;
  mat[2][0] = 1;
  mat[2][1] = 2;
  mat[2][2] = 0;
  mat[3][0] = 2;
  mat[3][1] = 1;
  mat[3][2] = 0;
  mat[4][0] = 2;
  mat[4][1] = 0;
  mat[4][2] = 1;
  mat[5][0] = 0;
  mat[5][1] = 2;
  mat[5][2] = 1;
  int n, m;
  cin >> n >> m;
  int temp = (n) % 6;
  cout << mat[temp][m];
  return 0;
}
