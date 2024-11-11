#include <bits/stdc++.h>
using namespace std;
int i, n, t, k, l, o, x, y, sum;
int matrix[101][101];
int main() {
  cin >> o;
  for (i = 0; i < o; i++)
    for (l = 0; l < o; l++) cin >> matrix[i][l];
  for (i = 0; i < o; i++) {
    sum += matrix[i][i];
    sum += matrix[i][o - 1 - i];
    sum += matrix[o / 2][i];
    sum += matrix[i][o / 2];
  }
  cout << sum - 3 * matrix[o / 2][o / 2] << endl;
  return 0;
}
