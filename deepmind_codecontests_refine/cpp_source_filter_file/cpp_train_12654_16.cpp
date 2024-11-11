#include <bits/stdc++.h>
using namespace std;
const int maxn = 1005;
long long n;
long long grid[maxn][maxn], x, y;
long long ans = 0;
long long temp_sum, sum, small_sum;
long long row_sum(int row) {
  temp_sum = 0;
  for (int i = 0; i < n; i++) {
    temp_sum += grid[row][i];
  }
  return temp_sum;
}
long long col_sum(int col) {
  temp_sum = 0;
  for (int i = 0; i < n; i++) {
    temp_sum += grid[i][col];
  }
  return temp_sum;
}
long long dia1_sum() {
  temp_sum = 0;
  for (int i = 0; i < n; i++) temp_sum += grid[i][i];
  return temp_sum;
}
long long dia2_sum() {
  temp_sum = 0;
  for (int i = 0; i < n; i++) temp_sum += grid[i][n - 1 - i];
  return temp_sum;
}
long long is() {
  for (int i = 0; i < n; i++) {
    if (i == x) {
      if (small_sum != row_sum(i)) return -1;
    } else {
      if (sum != row_sum(i)) return -1;
    }
    if (i == y) {
      if (small_sum != col_sum(i)) return -1;
    } else {
      if (sum != col_sum(i)) return -1;
    }
  }
  if (x == y) {
    if (small_sum != dia1_sum()) return -1;
  } else {
    if (sum != dia1_sum()) return -1;
  }
  if (x == n - 1 - y) {
    if (small_sum != dia2_sum()) return -1;
  } else {
    if (sum != dia2_sum()) return -1;
  }
  return sum - small_sum;
}
int main() {
  cin >> n;
  if (n == 1)
    cout << "1" << endl;
  else {
    for (int i = 0; i < n; i++)
      for (int j = 0; j < n; j++) {
        cin >> grid[i][j];
        if (grid[i][j] == 0) {
          x = i;
          y = j;
        }
      }
    sum = 0;
    small_sum = row_sum(x);
    if (x == 0)
      sum = row_sum(1);
    else
      sum = row_sum(0);
    if (is() <= 0)
      cout << is() << endl;
    else
      cout << "-1" << endl;
  }
  return 0;
}
