#include <bits/stdc++.h>
using namespace std;
int INF = std::numeric_limits<int>().max();
double INFD = std::numeric_limits<double>().max();
double PI = acos(-1);
void print(vector<vector<long long>>& mat) {
  for (auto& row : mat) {
    for (auto& cell : row) {
      cout << cell << " ";
    }
    cout << endl;
  }
  cout << endl;
}
int main() {
  ios::sync_with_stdio(false);
  int n = 0, m = 0, x = 0, y = 0;
  long long k = 0;
  cin >> n >> m >> k >> x >> y;
  long long rounds = 0;
  if (n > 1) {
    rounds = k / ((n + n - 2) * m);
    k %= (n + n - 2) * m;
  } else {
    rounds = k / m;
    k %= m;
  }
  vector<vector<long long>> mat(n, vector<long long>(m, 2 * rounds));
  mat[0] = vector<long long>(m, rounds);
  mat[n - 1] = vector<long long>(m, rounds);
  int i = 0;
  while (i < n && k) {
    int j = 0;
    while (j < m && k) {
      mat[i][j]++;
      k--;
      j++;
    }
    i++;
  }
  if (k) {
    i--;
    while (i && k) {
      i--;
      int j = 0;
      while (j < m && k) {
        mat[i][j]++;
        k--;
        j++;
      }
    }
  }
  long long mins = -1, maxs = 0;
  for (auto& row : mat) {
    for (auto& cell : row) {
      if (mins == -1) {
        mins = cell;
      }
      mins = min(mins, cell);
      maxs = max(maxs, cell);
    }
  }
  cout << maxs << " " << mins << " " << mat[x - 1][y - 1] << endl;
  return 0;
}
