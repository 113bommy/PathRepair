#include <bits/stdc++.h>
using namespace std;
int main() {
  int a, b, n;
  cin >> n >> a >> b;
  int mat[n][n];
  memset(mat, 0, sizeof mat);
  if (b > n || a > n) {
    cout << "NO\n";
    return 0;
  }
  if ((n == 3 || n == 2) && a == 1 && b == 1) {
    cout << "NO\n";
    return 0;
  }
  if (n == 2 && a == 2 && b == 1) {
    cout << "YES\n";
    for (int i = 0; i < n; i++) {
      for (int j = 0; j < n; j++) cout << mat[i][j];
      cout << endl;
    }
    return 0;
  }
  if (n == 2 && a == 1 && b == 2) {
    mat[0][1] = 1;
    mat[1][0] = 1;
    cout << "YES\n";
    for (int i = 0; i < n; i++) {
      for (int j = 0; j < n; j++) cout << mat[i][j];
      cout << endl;
    }
    return 0;
  }
  if (a == 1 && b == 1) {
    for (int i = 0; i < n - 1; i++) {
      mat[i][i + 1] = 1;
      mat[i + 1][i] = 1;
    }
    cout << "YES\n";
    int j;
    for (int i = 0; i < n; i++) {
      for (j = 0; j < n; j++) cout << mat[i][j];
      cout << endl;
    }
  } else if (a == 1) {
    int j;
    for (int i = 0; i < b - 1; i++) {
      for (j = 0; j < n; j++) {
        mat[i][j] = 1;
        mat[j][i] = 1;
        if (i == j) mat[i][j] = 0;
      }
    }
    cout << "YES\n";
    for (int i = 0; i < n; i++) {
      for (j = 0; j < n; j++) cout << mat[i][j];
      cout << endl;
    }
  } else if (b == 1) {
    int final = n - a + 1;
    for (int i = 0; i < final; i++) {
      mat[i][i + 1] = 1;
      mat[i + 1][i] = 1;
    }
    cout << "YES\n";
    int j;
    for (int i = 0; i < n; i++) {
      for (j = 0; j < n; j++) cout << mat[i][j];
      cout << endl;
    }
  } else {
    cout << "NO\n";
    return 0;
  }
}
