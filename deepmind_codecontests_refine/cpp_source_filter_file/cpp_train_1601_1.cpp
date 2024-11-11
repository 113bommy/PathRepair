#include <bits/stdc++.h>
using namespace std;
int matrix[300][300];
int main() {
  int n;
  cin >> n;
  int sum = 0;
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
      cin >> matrix[i][j];
      sum += matrix[i][j];
    }
  }
  sum /= 2;
  int k;
  cin >> k;
  for (int i = 0; i < k; i++) {
    sum = 0;
    int a, b, c;
    cin >> a >> b >> c;
    a--;
    b--;
    matrix[a][b] = matrix[b][a] = min(matrix[a][b], c);
    for (int x = 0; x < n; x++) {
      for (int y = 0; y < n; y++) {
        matrix[x][y] =
            min(matrix[x][y], matrix[x][a] + matrix[a][b] + matrix[b][y]);
        matrix[x][y] =
            min(matrix[x][y], matrix[x][b] + matrix[b][a] + matrix[a][y]);
        sum += matrix[x][y];
      }
    }
    if (i != 0) cout << " ";
    cout << sum / 2;
  }
  cout << endl;
  return 0;
}
