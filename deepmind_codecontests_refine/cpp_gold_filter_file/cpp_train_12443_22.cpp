#include <bits/stdc++.h>
using namespace std;
int s[50], x[50];
long long an[50][2][2][2];
int N;
long long f(int n, int carry, bool q1, bool q2) {
  if (n == N) {
    return q1 * q2 * (carry == 0);
  }
  if (an[n][carry][q1][q2] != -1) return an[n][carry][q1][q2];
  if (!carry) {
    if (s[n] && !x[n]) an[n][carry][q1][q2] = 0;
    if (s[n] && x[n])
      an[n][carry][q1][q2] = f(n + 1, 0, q1, 1) + f(n + 1, 0, 1, q2);
    if (!s[n] && x[n]) an[n][carry][q1][q2] = 0;
    if (!s[n] && !x[n])
      an[n][carry][q1][q2] = f(n + 1, 0, q1, q2) + f(n + 1, 1, 1, 1);
  } else {
    if (s[n] && !x[n])
      an[n][carry][q1][q2] = f(n + 1, 0, q1, q2) + f(n + 1, 1, 1, 1);
    if (s[n] && x[n]) an[n][carry][q1][q2] = 0;
    if (!s[n] && x[n])
      an[n][carry][q1][q2] = f(n + 1, 1, q1, 1) + f(n + 1, 1, 1, q2);
    if (!s[n] && !x[n]) an[n][carry][q1][q2] = 0;
  }
  return an[n][carry][q1][q2];
}
int main(void) {
  long long a, b;
  for (int i = 0; i < 50; i++) {
    for (int j = 0; j < 2; j++)
      for (int k = 0; k < 2; k++)
        for (int l = 0; l < 2; l++) an[i][j][k][l] = -1;
  }
  int ind = 0;
  cin >> a >> b;
  while (a) {
    s[ind++] = a % 2;
    a /= 2;
  }
  N = ind;
  ind = 0;
  while (b) {
    x[ind++] = b % 2;
    b /= 2;
  }
  N = max(ind, N);
  cout << f(0, 0, 0, 0);
}
