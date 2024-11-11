#include <bits/stdc++.h>
using namespace std;
int main() {
  int n;
  cin >> n;
  long int matrix[n][n];
  long long int sum = 0;
  long long int th_sum = 0;
  long long int miss_sum = 0;
  int x, y;
  bool flag = true;
  for (int i = 0; i < n; i++)
    for (int j = 0; j < n; j++) {
      cin >> matrix[i][j];
      if (matrix[i][j] == 0) {
        x = i;
        y = j;
      }
    }
  for (int i = 0; i < n; i++) {
    if (i != x) {
      for (int j = 0; j < n; j++) th_sum += matrix[i][j];
      break;
    }
  }
  for (int i = 0; i < n; i++) {
    sum = 0;
    if (i != x) {
      for (int j = 0; j < n; j++) sum += matrix[i][j];
      if (sum != th_sum) {
        cout << "-1";
        return 0;
      }
    }
  }
  for (int i = 0; i < n; i++) {
    sum = 0;
    if (i != y) {
      for (int j = 0; j < n; j++) sum += matrix[j][i];
      if (sum != th_sum) {
        cout << "-1";
        return 0;
      }
    }
  }
  sum = 0;
  int i, j;
  flag = true;
  for (i = 0; i < n; i++) {
    if (i == x && i == y) {
      flag = false;
      break;
    }
    sum += matrix[i][i];
  }
  if (sum != th_sum && flag == true) {
    cout << "-1";
    return 0;
  }
  sum = 0;
  flag = true;
  for (i = 0, j = n - 1; i < n; i++, j--) {
    if (i == x && j == y) {
      flag = false;
      break;
    }
    sum += matrix[i][j];
  }
  if (sum != th_sum && flag == true) {
    cout << "-1";
    return 0;
  }
  for (i = 0; i < n; i++) miss_sum += matrix[x][i];
  if (th_sum - miss_sum <= 0 && n != 1) {
    cout << "-1";
    return 0;
  }
  if (n != 1) {
    matrix[x][y] = th_sum - miss_sum;
    sum = 0;
    for (int j = 0; j < n; j++) sum += matrix[j][x];
    if (sum != th_sum) {
      cout << "-1";
      return 0;
    }
    sum = 0;
    for (int j = 0; j < n; j++) sum += matrix[j][j];
    if (sum != th_sum) {
      cout << "-1";
      return 0;
    }
    sum = 0;
    for (int j = 0; j < n; j++) sum += matrix[j][n - j - 1];
    if (sum != th_sum) {
      cout << "-1";
      return 0;
    }
    cout << matrix[x][y];
  } else
    cout << "1";
  return 0;
}
