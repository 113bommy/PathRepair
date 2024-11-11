#include <bits/stdc++.h>
using namespace std;
void check(int A[][252], int i, int j, int &v, int n, int m);
bool type1(int A[][252], int i, int j, int k, int l);
bool type2(int A[][252], int i, int j, int k, int m);
int main() {
  int n, m, i, j, v = 0, p, q;
  char in[250][250];
  int A[252][252] = {0};
  cin >> q;
  for (p = 0; p < q; p++) {
    for (i = 1; i <= n; i++)
      for (j = 1; j <= m; j++) A[i][j] = 0;
    v = 0;
    cin >> n >> m;
    for (i = 0; i < n; i++) {
      cin >> in[i];
      for (j = 0; j < m; j++) A[i + 1][j + 1] = in[i][j] - '0';
    }
    for (i = 1; i < n; i++)
      for (j = 1; j < m; j++)
        if (A[i][j] == 1) check(A, i, j, v, n, m);
    cout << v << endl;
  }
}
void check(int A[][252], int i, int j, int &v, int n, int m) {
  int k, l;
  for (k = i + 1, l = j + 1; k <= n && l <= m; k++, l++)
    if (type1(A, i, j, k, l)) v++;
  for (k = i + 2; k <= n; k += 2)
    if (type2(A, i, j, k, m)) v++;
}
bool type1(int A[][252], int i, int j, int k, int l) {
  int x, y;
  if (!A[i][l] || !A[k][j] || !A[k][l])
    return false;
  else if (A[i - 1][j - 1] || A[i - 1][j] || A[i][j - 1])
    return false;
  else if (A[i - 1][l + 1] || A[i - 1][l] || A[i][l + 1])
    return false;
  else if (A[k + 1][l + 1] || A[k][l + 1] || A[k + 1][l])
    return false;
  else if (A[k + 1][j - 1] || A[k + 1][j] || A[k][j - 1])
    return false;
  for (x = i + 1; x < k; x++) {
    if (!A[x][j] || !A[x][l] || A[x][j + 1] || A[x][j - 1] || A[x][l + 1] ||
        A[x][l - 1])
      return false;
  }
  for (y = j + 1; y < l; y++) {
    if (!A[i][y] || !A[k][y] || A[i - 1][y] || A[i + 1][y] || A[k - 1][y] ||
        A[k + 1][y])
      return false;
  }
  return true;
}
bool type2(int A[][252], int i, int j, int k, int m) {
  int x, y, z = (k - i) / 2;
  if (j + z > m || j - z < 1)
    return false;
  else if (A[i - 1][j - 1] || A[i - 1][j] || A[i - 1][j + 1] || A[i][j - 1] ||
           A[i][j + 1])
    return false;
  else if (!A[k][j] || A[k + 1][j - 1] || A[k + 1][j] || A[k + 1][j + 1] ||
           A[k][j - 1] || A[k][j + 1])
    return false;
  else if (!A[i + z][j + z] || A[i + z - 1][j + z + 1] || A[i + z][j + z + 1] ||
           A[i + z + 1][j + z + 1] || A[i + z][j + z - 1])
    return false;
  else if (!A[i + z][j - z] || A[i + z - 1][j - z - 1] || A[i + z][j - z - 1] ||
           A[i + z + 1][j - z - 1] || A[i + z][j - z + 1])
    return false;
  for (x = i + 1, y = j + 1; x < i + z; x++, y++) {
    if (!A[x][y] || A[x][y - 1] || A[x + 1][y - 1] || A[x - 1][y + 1] ||
        A[x][y + 1])
      return false;
    else if (!A[x + z][y - z] || A[x + z][y - 1 - z] ||
             A[x + 1 + z][y - 1 - z] || A[x - 1 + z][y + 1 - z] ||
             A[x + z][y + 1 - z])
      return false;
  }
  for (x = i + 1, y = j - 1; x < i + z; x++, y--) {
    if (!A[x][y] || A[x - 1][y - 1] || A[x][y - 1] || A[x][y + 1] ||
        A[x + 1][y + 1])
      return false;
    else if (!A[x + z][y + z] || A[x - 1 + z][y - 1 + z] ||
             A[x + z][y - 1 + z] || A[x + z][y + 1 + z] ||
             A[x + 1 + z][y + 1 + z])
      return false;
  }
  return true;
}
