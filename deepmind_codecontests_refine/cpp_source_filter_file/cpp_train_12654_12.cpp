#include <bits/stdc++.h>
using namespace std;
int main() {
  int n;
  cin >> n;
  vector<vector<long long> > magic(n);
  for (int i = 0; i < n; ++i) {
    magic[i].resize(n);
    for (int j = 0; j < n; ++j) cin >> magic[i][j];
  }
  vector<long long> row_sum(n);
  vector<long long> col_sum(n);
  long long diag1, diag2;
  int xzero, yzero;
  diag1 = diag2 = 0;
  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < n; ++j) {
      row_sum[i] += magic[i][j];
      col_sum[j] += magic[i][j];
      if (i == j) diag1 += magic[i][j];
      if (i + j == n - 1) diag2 += magic[i][j];
      if (magic[i][j] == 0) {
        xzero = i;
        yzero = j;
      }
    }
  }
  long long required_sum;
  for (int i = 0; i < n; ++i) {
    if (xzero != i) {
      required_sum = row_sum[i];
      break;
    }
  }
  long long answer = required_sum - row_sum[xzero];
  if (answer < 0) answer = -1;
  for (int i = 0; i < n; ++i) {
    if (row_sum[i] != required_sum && i != xzero) {
      answer = -1;
      break;
    }
    if (i == yzero && (answer + col_sum[i]) != required_sum) {
      answer = -1;
      break;
    } else if (col_sum[i] != required_sum && i != yzero) {
      answer = -1;
      break;
    }
  }
  if ((diag1 != required_sum && xzero != yzero)) {
    answer = -1;
  }
  if (diag1 + answer != required_sum && xzero == yzero) {
    answer = -1;
  }
  if (diag2 + answer != required_sum && (xzero + yzero == n - 1)) {
    answer = -1;
  }
  if (diag2 != required_sum && (xzero + yzero != n - 1)) {
    answer = -1;
  }
  if (n == 1) answer = 1;
  cout << answer << "\n";
  return 0;
}
