#include <bits/stdc++.h>
using namespace std;
int n, m;
int solve(int length, int width, vector<vector<int> > sum_matrix,
          vector<vector<int> > init_matrix) {
  int i, j, k, sum = 0, min = 2500000;
  for (i = 0; i < n - width; i++)
    for (j = 0; j < m - length; j++) {
      sum = 0;
      for (k = 0; k < length; k++) {
        sum += sum_matrix[i + width - 1][j + k] - sum_matrix[i][j + k];
        sum += init_matrix[i][j + k];
      }
      if (sum < min) min = sum;
    }
  return min;
}
int main() {
  int i, j, length, width;
  while (cin >> n >> m) {
    vector<vector<int> > init_matrix(n, vector<int>(m));
    vector<vector<int> > sum_matrix(n, vector<int>(m, 0));
    for (j = 0; j < m; j++) {
      cin >> init_matrix[0][j];
      sum_matrix[0][j] = init_matrix[0][j];
    }
    for (i = 1; i < n; i++)
      for (j = 0; j < m; j++) {
        cin >> init_matrix[i][j];
        sum_matrix[i][j] = sum_matrix[i - 1][j] + init_matrix[i][j];
      }
    cin >> length >> width;
    int min1 = solve(length, width, sum_matrix, init_matrix);
    int min2 = solve(width, length, sum_matrix, init_matrix);
    min1 = min1 < min2 ? min1 : min2;
    cout << min1 << endl;
  }
}
