#include <bits/stdc++.h>
using namespace std;
const int MAXN = 102;
struct matrix {
  int arr[MAXN][MAXN];
  int n, m;
  matrix(int x, int y) { n = x, m = y; };
  matrix(int x, int y, int v) {
    n = x, m = y;
    for (int i = 0; i < n; i++)
      for (int j = 0; j < m; j++) arr[i][j] = v;
  };
  matrix operator*(const matrix &mat) const {
    matrix res(n, mat.m, 0);
    for (int i = 0; i < n; i++)
      for (int j = 0; j < mat.m; j++)
        for (int k = 0; k < m; k++)
          res.arr[i][j] =
              (arr[i][k] * 1LL * mat.arr[k][j] + res.arr[i][j]) % 1000000007;
    return res;
  }
  bool operator>(const matrix &mat) const {
    for (int i = 0; i < n; i++)
      for (int j = 0; j < m; j++) {
        if (arr[i][j] > mat.arr[i][j]) return true;
        if (arr[i][j] < mat.arr[i][j]) return false;
      }
    return true;
  }
  void print(int x, int y) {
    for (int i = 0; i < x; i++) {
      for (int j = 0; j < y; j++) printf("%d ", arr[i][j]);
      printf("\n");
    }
  }
};
matrix mat_pow(const matrix &base, int power) {
  if (power == 1) return base;
  if (power & 1) return base * mat_pow(base, power - 1);
  matrix temp = mat_pow(base, power / 2);
  return temp * temp;
}
int cnt[105];
int main() {
  int n, k, x;
  scanf("%d %d", &n, &k);
  if (!k) {
    printf("1");
    return 0;
  }
  for (int i = 0; i < n; i++) {
    scanf("%d", &x);
    cnt[x]++;
  }
  matrix m(101, 101, 0);
  for (int i = 0; i < 100; i++) m.arr[i][0] = cnt[i + 1];
  for (int i = 0; i < 99; i++) m.arr[i][i + 1] = 1;
  m.arr[100][100] = 1;
  m.arr[100][0] = 1;
  m = mat_pow(m, k + 1);
  printf("%d", m.arr[100][0]);
  return 0;
}
