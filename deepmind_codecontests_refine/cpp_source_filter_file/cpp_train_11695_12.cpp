#include <bits/stdc++.h>
using namespace std;
int n, matrix[101][101];
bool marked[101][101];
long long int S;
int main() {
  int i, j;
  cin >> n;
  for (i = 1; i <= n; i++) {
    for (j = 1; j <= n; j++) {
      cin >> matrix[i][j];
    }
  }
  for (i = 1; i <= n; i++) {
    S += matrix[i][i];
    marked[i][i] = true;
  }
  for (i = n; i >= 1; i--) {
    if (!marked[n - i + 1][i]) {
      S += matrix[n - i + 1][i];
      marked[n - i + 1][i] = true;
    }
  }
  for (i = 1; i <= n; i++) {
    if (!marked[n / 2 + 1][i]) {
      S += matrix[n / 2 + 1][i];
      marked[n / 2 + 1][i] = true;
    }
  }
  for (i = 1; i <= n; i++) {
    if (!marked[i][n / 2 + 1]) {
      S += matrix[i][n / 2 + 1];
      marked[i][n / 2 + 1] = true;
    }
  }
  cout << S;
  return 0;
}
