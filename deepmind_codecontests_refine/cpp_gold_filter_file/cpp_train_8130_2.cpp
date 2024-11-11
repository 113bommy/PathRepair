#include <bits/stdc++.h>
using namespace std;
pair<int, int> check[300][300];
int mat[10][10];
pair<int, int> dp[3][100];
int n;
const int inf = 1e6;
void help1(int i, int j) {
  int val1 = mat[i][j];
  int ii = i + 1;
  int jj = j + 1;
  while (ii < n && jj < n) {
    int val2 = mat[ii][jj];
    check[val1][val2] = {1, 0};
    ++ii;
    ++jj;
  }
  ii = i - 1;
  jj = j - 1;
  while (ii >= 0 && jj >= 0) {
    int val2 = mat[ii][jj];
    check[val1][val2] = {1, 0};
    --ii;
    --jj;
  }
  ii = i - 1;
  jj = j + 1;
  while (ii >= 0 && jj < n) {
    int val2 = mat[ii][jj];
    check[val1][val2] = {1, 0};
    --ii;
    ++jj;
  }
  ii = i + 1;
  jj = j - 1;
  while (ii < n && jj >= 0) {
    int val2 = mat[ii][jj];
    check[val1][val2] = {1, 0};
    ++ii;
    --jj;
  }
}
void help2(int i, int j) {
  int val1 = mat[i][j];
  for (int ii = i + 1; ii < n; ++ii) {
    int val2 = mat[ii][j];
    check[val1 + 100][val2 + 100] = {1, 0};
  }
  for (int ii = i - 1; ii >= 0; --ii) {
    int val2 = mat[ii][j];
    check[val1 + 100][val2 + 100] = {1, 0};
  }
  for (int jj = j + 1; jj < n; ++jj) {
    int val2 = mat[i][jj];
    check[val1 + 100][val2 + 100] = {1, 0};
  }
  for (int jj = j - 1; jj >= 0; --jj) {
    int val2 = mat[i][jj];
    check[val1 + 100][val2 + 100] = {1, 0};
  }
}
bool possible(int i, int j) { return (i >= 0 && j >= 0 && i < n && j < n); }
void help3(int i, int j) {
  int val1 = mat[i][j];
  int row[] = {-2, -2, 2, 2, -1, -1, 1, 1};
  int col[] = {-1, 1, -1, 1, 2, -2, 2, -2};
  for (int k = 0; k < 8; ++k) {
    int ii = i + row[k];
    int jj = j + col[k];
    if (possible(ii, jj)) {
      int val2 = mat[ii][jj];
      check[200 + val1][200 + val2] = {1, 0};
    }
  }
}
int32_t main() {
  cin >> n;
  for (int i = 0; i < 300; ++i) {
    for (int j = 0; j < 300; ++j) {
      check[i][j] = {inf, inf};
    }
  }
  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < n; ++j) {
      cin >> mat[i][j];
      --mat[i][j];
    }
  }
  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < n; ++j) {
      help1(i, j);
      help2(i, j);
      help3(i, j);
    }
  }
  for (int i = 0; i < n * n; ++i) {
    check[i][100 + i] = {1, 1};
    check[i][200 + i] = {1, 1};
    check[100 + i][i] = {1, 1};
    check[200 + i][i] = {1, 1};
    check[100 + i][200 + i] = {1, 1};
    check[200 + i][100 + i] = {1, 1};
  }
  for (int i = 0; i < n * n; ++i) {
    check[i][i] = {0, 0};
    check[100 + i][100 + i] = {0, 0};
    check[200 + i][200 + i] = {0, 0};
  }
  for (int k = 0; k < 300; ++k) {
    for (int i = 0; i < 300; ++i) {
      for (int j = 0; j < 300; ++j) {
        if ((check[i][k].first + check[k][j].first) < check[i][j].first) {
          check[i][j].first = check[i][k].first + check[k][j].first;
          check[i][j].second = check[i][k].second + check[k][j].second;
        } else if ((check[i][k].first + check[k][j].first) == check[i][j].first)
          check[i][j].second =
              min(check[i][j].second, check[i][k].second + check[k][j].second);
      }
    }
  }
  for (int j = 1; j < n * n; ++j) {
    for (int i = 0; i < 3; ++i) {
      dp[i][j].first = inf;
      dp[i][j].second = inf;
    }
  }
  for (int j = 0; j < n * n - 1; ++j) {
    for (int i = 0; i < 3; ++i) {
      int val1 = i * 100 + j;
      for (int k = 0; k < 3; ++k) {
        int val2 = k * 100 + j + 1;
        if ((dp[i][j].first + check[val1][val2].first) < dp[k][j + 1].first) {
          dp[k][j + 1].first = dp[i][j].first + check[val1][val2].first;
          dp[k][j + 1].second = dp[i][j].second + check[val1][val2].second;
        } else if ((dp[i][j].first + check[val1][val2].first) ==
                   dp[k][j + 1].first) {
          int val3 = dp[i][j].second + check[val1][val2].second;
          dp[k][j + 1].second = min(dp[k][j + 1].second, val3);
        }
      }
    }
  }
  int ans1 = inf + 1;
  int ans2 = inf;
  for (int i = 0; i < 3; ++i) {
    if (dp[i][n * n - 1].first < ans1) {
      ans1 = dp[i][n * n - 1].first;
      ans2 = dp[i][n * n - 1].second;
    } else if (dp[i][n * n - 1].first == ans1)
      ans2 = min(ans2, dp[i][n * n - 1].second);
  }
  cout << ans1 << " " << ans2;
  return 0;
}
