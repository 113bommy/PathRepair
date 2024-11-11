#include <bits/stdc++.h>
using namespace std;
int compare(const void *x1, const void *x2) {
  return (*(int *)x1 - *(int *)x2);
}
double eps = 0.0001;
void fun(int i, int j, int **mas) {
  if (i == 0) {
    while (j--) cout << "R";
    return;
  }
  if (j == 0) {
    while (i--) cout << "D";
    return;
  }
  if (mas[i - 1][j] < mas[i][j - 1]) {
    fun(i - 1, j, mas);
    cout << "D";
  } else {
    fun(i, j - 1, mas);
    cout << "R";
  }
}
int main() {
  int n;
  cin >> n;
  int **mas = new int *[n];
  int **mas2 = new int *[n];
  int **mas5 = new int *[n];
  for (int i = 0; (i) < (n); ++i) {
    mas[i] = new int[n];
    mas2[i] = new int[n];
    mas5[i] = new int[n];
  }
  int q, w, f = 0;
  for (int i = 0; (i) < (n); ++i)
    for (int j = 0; (j) < (n); ++j) {
      cin >> mas[i][j];
    }
  mas2[0][0] = 0;
  mas5[0][0] = 0;
  if (mas[0][0] == 0 || mas[n - 1][n - 1] == 0) {
    cout << 1;
    for (int i = 0; (i) < (n - 1); ++i) cout << "D";
    for (int i = 0; (i) < (n - 1); ++i) cout << "R";
    return 0;
  }
  for (int i = 0; (i) < (n); ++i)
    for (int j = 0; (j) < (n); ++j) {
      if (mas[i][j] == 0) {
        mas[i][j] = 10;
        q = i;
        w = j;
        f = 1;
      }
    }
  while (mas[0][0] % 2 == 0) {
    mas2[0][0]++;
    mas[0][0] /= 2;
  }
  while (mas[0][0] % 5 == 0) {
    mas5[0][0]++;
    mas[0][0] /= 5;
  }
  for (int i = 1; i < n; i++) {
    mas2[0][i] = mas2[0][i - 1];
    mas5[0][i] = mas5[0][i - 1];
    while (mas[0][i] % 2 == 0) {
      mas2[0][i]++;
      mas[0][i] /= 2;
    }
    while (mas[0][i] % 5 == 0) {
      mas5[0][i]++;
      mas[0][i] /= 5;
    }
    mas2[i][0] = mas2[i - 1][0];
    mas5[i][0] = mas5[i - 1][0];
    while (mas[i][0] % 2 == 0) {
      mas2[i][0]++;
      mas[i][0] /= 2;
    }
    while (mas[i][0] % 5 == 0) {
      mas5[i][0]++;
      mas[i][0] /= 5;
    }
  }
  for (int i = 1; i < n; i++)
    for (int j = 1; j < n; j++) {
      mas2[i][j] = 0;
      mas5[i][j] = 0;
      while (mas[i][j] % 2 == 0) {
        mas2[i][j]++;
        mas[i][j] /= 2;
      }
      while (mas[i][j] % 5 == 0) {
        mas5[i][j]++;
        mas[i][j] /= 5;
      }
      mas2[i][j] += min(mas2[i][j - 1], mas2[i - 1][j]);
      mas5[i][j] += min(mas5[i][j - 1], mas5[i - 1][j]);
    }
  if (f == 1 && mas2[n - 1][n - 1] * mas5[n - 1][n - 1] != 0) {
    cout << 1 << endl;
    for (int i = 0; i < q; i++) cout << "D";
    for (int i = 0; i < w; i++) cout << "R";
    for (int i = q; i < n; i++) cout << "D";
    for (int i = w; i < n; i++) cout << "R";
  } else {
    if (mas2[n - 1][n - 1] > mas5[n - 1][n - 1]) {
      cout << mas5[n - 1][n - 1] << endl;
      fun(n - 1, n - 1, mas5);
    } else {
      cout << mas2[n - 1][n - 1] << endl;
      fun(n - 1, n - 1, mas2);
    }
  }
  return 0;
}
