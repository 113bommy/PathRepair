#include <bits/stdc++.h>
using namespace std;
int main() {
  int n, m, k, total_score = 0, total_cost = 0;
  vector<vector<int> > matrix;
  cin >> n >> m >> k;
  matrix.resize(n);
  for (int i = 0; i < n; ++i) {
    matrix[i].resize(m);
    for (int j = 0; j < m; ++j) {
      cin >> matrix[i][j];
    }
  }
  for (int j = 0; j < m; ++j) {
    int score = 0, max_score = 0, max_score_cost = 0, cost = 0;
    for (int i = 0; i < k - 1; ++i) {
      score += matrix[i][j];
    }
    for (int i = 0; i <= n - k; ++i) {
      score += matrix[i + k - 1][j];
      if (matrix[i][j] == 1) {
        if (score > max_score) {
          max_score = score;
          max_score_cost = cost;
        }
        cost += 1;
      }
      score -= matrix[i][j];
    }
    if (max_score < score) {
      max_score = score;
      total_cost = cost;
    }
    total_cost += max_score_cost;
    total_score += max_score;
  }
  cout << total_score << " " << total_cost << endl;
  return 0;
}
