#include <bits/stdc++.h>
using namespace std;
char A[100009], B[100009], C[100009];
int n, k, a[29][29], minim, caracter;
int min(int z, int x) {
  if (z < x) return z;
  return x;
}
void citire() {
  int i, x, t, y;
  char c1, c2;
  cin >> A;
  cin >> B;
  k = strlen(A);
  cin >> n;
  for (i = 0; i < n; ++i) {
    cin >> c1 >> c2 >> x;
    t = c1 - 'a' + 1;
    y = c2 - 'a' + 1;
    if (a[t][y] > x) a[t][y] = x;
  }
}
void rf() {
  int i, j, k;
  for (k = 1; k <= 26; k++)
    for (i = 1; i <= 26; i++)
      for (j = 1; j <= 26; j++)
        if ((a[i][j] > a[i][k] + a[k][j]) && i != j)
          a[i][j] = a[i][k] + a[k][j];
}
int main() {
  int z, x, s, j, i;
  for (i = 1; i <= 26; ++i)
    for (j = 1; j <= 26; ++j) a[i][j] = 999999999;
  citire();
  rf();
  s = 0;
  if (strlen(A) != strlen(B)) {
    cout << -1;
    return 0;
  }
  for (i = 0; i < k; ++i) {
    z = A[i] - 'a' + 1;
    x = B[i] - 'a' + 1;
    minim = 999999;
    caracter = 0;
    if (A[i] != B[i]) {
      for (j = 1; j <= 26; ++j) {
        if (a[z][j] + a[x][j] < minim) {
          minim = a[z][j] + a[x][j];
          caracter = j;
        }
      }
      if (minim > a[z][x]) {
        minim = a[z][x];
        caracter = x;
      }
      if (minim > a[x][z]) {
        caracter = z;
        minim = a[x][z];
      }
      if (minim == 999999999) {
        cout << -1;
        return 0;
      }
      s += minim;
      C[i] = caracter + 'a' - 1;
    } else
      C[i] = A[i];
  }
  cout << s << '\n';
  for (i = 0; i < k; ++i) cout << C[i];
}
