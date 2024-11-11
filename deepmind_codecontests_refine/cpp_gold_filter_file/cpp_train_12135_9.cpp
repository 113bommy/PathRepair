#include <bits/stdc++.h>
using namespace std;
int lsone(int n) { return (n & -n); }
void mult(long long int a[25][25], long long int b[25][25],
          long long int c[25][25], int m, int n, int p) {
  for (int i = 1; i <= m; i++) {
    for (int j = 1; j <= p; j++) {
      c[i][j] = 0;
      for (int k = 1; k <= n; k++) {
        c[i][j] += (a[i][k] * b[k][j]) % 1000000007;
        c[i][j] %= 1000000007;
      }
    }
  }
}
void mat_pow(long long int a[25][25], long long int c[25][25], int n,
             long long int p) {
  if (p == 0) {
    for (int i = 1; i <= n; i++) c[i][i] = 1;
  } else if (p == 1) {
    for (int i = 1; i <= n; i++) {
      for (int j = 1; j <= n; j++) c[i][j] = a[i][j];
    }
  } else {
    long long int d[25][25];
    mat_pow(a, d, n, p / 2);
    if (p % 2) {
      long long int e[25][25];
      mult(d, d, e, n, n, n);
      mult(e, a, c, n, n, n);
    } else {
      mult(d, d, c, n, n, n);
    }
  }
}
long long int pow(long long int a, long long int b) {
  if (b == 0)
    return 1ll;
  else if (b == 1)
    return a;
  else {
    long long int x = pow(a, b / 2);
    x *= x;
    x %= 1000000007;
    if (b % 2) {
      x *= a;
      x %= 1000000007;
    }
    return x;
  }
}
int mat[30][30], n, m, mat1[31][31];
int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  cin >> n >> m;
  int flag1 = 1;
  for (int i = 0; i < n; i++) {
    int c = 0;
    for (int j = 0; j < m; j++) {
      cin >> mat[i][j];
      if (mat[i][j] != j + 1) c++;
    }
    if (c > 2) flag1 = 0;
  }
  if (flag1) {
    cout << "YES\n";
    return 0;
  }
  for (int j = 0; j < m; j++) {
    for (int k = j + 1; k < m; k++) {
      for (int i = 0; i < n; i++) {
        for (int l = 0; l < m; l++) {
          if (l == j) {
            mat1[i][l] = mat[i][k];
          } else if (l == k)
            mat1[i][l] = mat[i][j];
          else
            mat1[i][l] = mat[i][l];
        }
      }
      int flag = 1;
      for (int i = 0; i < n; i++) {
        int c = 0;
        for (int l = 0; l < m; l++) {
          if (mat1[i][l] != l + 1) c++;
        }
        if (c > 2) flag = 0;
      }
      if (flag) {
        cout << "YES\n";
        return 0;
      }
    }
  }
  cout << "NO\n";
  return 0;
}
