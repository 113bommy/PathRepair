#include <bits/stdc++.h>
using namespace std;
int x, k, P, X, Y, n, ma;
int b[1005][1005], c[1005][1005], d2[1005][1005], d5[1005][1005];
char sd[1005][1005];
void S() {
  cout << 1 << endl;
  for (int i = 0; i < X; i++) cout << 'D';
  for (int i = 0; i < Y; i++) cout << 'R';
  for (int i = X; i < n; i++) cout << 'D';
  for (int i = Y; i < n; i++) cout << 'R';
}
void D2() {
  for (int i = 1; i < n; i++) sd[0][i] = 'R', sd[i][0] = 'D';
  for (int i = 1; i < n; i++)
    for (int j = 1; j < n; j++) {
      d2[i][j] = min(d2[i - 1][j], d2[i][j - 1]) + b[i][j];
      if (d2[i - 1][j] < d2[i][j - 1])
        sd[i][j] = 'D';
      else
        sd[i][j] = 'R';
    }
  n--;
  cout << d2[n][n] << endl;
}
void D5() {
  for (int i = 1; i < n; i++) sd[0][i] = 'R', sd[i][0] = 'D';
  for (int i = 1; i < n; i++)
    for (int j = 1; j < n; j++) {
      d5[i][j] = min(d5[i - 1][j], d5[i][j - 1]) + c[i][j];
      if (d5[i - 1][j] < d5[i][j - 1])
        sd[i][j] = 'D';
      else
        sd[i][j] = 'R';
    }
  n--;
  cout << d5[n][n] << endl;
}
int main() {
  scanf("%d", &n);
  int A;
  for (int i = 0; i < n; i++)
    for (int j = 0; j < n; j++) {
      scanf("%d", &A);
      if (A == 0) {
        X = i;
        Y = j;
        P = 1;
        x = 1;
      }
      x = A;
      while (!(x % 2) && x > 0) b[i][j]++, x /= 2;
      x = A;
      while (!(x % 5) && x > 0) c[i][j]++, x /= 5;
    }
  d2[0][0] = b[0][0];
  for (int i = 1; i < n; i++)
    d2[0][i] += d2[0][i - 1] + b[0][i], d2[i][0] += d2[i - 1][0] + b[i][0];
  d5[0][0] = c[0][0];
  for (int i = 1; i < n; i++)
    d5[0][i] += d5[0][i - 1] + c[0][i], d5[i][0] += d5[i - 1][0] + c[i][0];
  for (int i = 1; i < n; i++)
    for (int j = 1; j < n; j++) {
      d2[i][j] = min(d2[i - 1][j], d2[i][j - 1]) + b[i][j];
      d5[i][j] = min(d5[i - 1][j], d5[i][j - 1]) + c[i][j];
    }
  if (P && min(d2[n - 1][n - 1], d5[n - 1][n - 1]) > 0) {
    S();
    return 0;
  }
  if (d2[n - 1][n - 1] < d5[n - 1][n - 1])
    D2();
  else
    D5();
  string S = "";
  int XX = n, YY = n;
  while (XX != 0 || YY != 0) {
    S = sd[XX][YY] + S;
    if (sd[XX][YY] == 'D')
      XX--;
    else
      YY--;
  }
  cout << S;
}
