#include <bits/stdc++.h>
using namespace std;
int n, m;
long long k;
map<long long, long long> xorValues[23][23], xorValuesReverse[23][23];
long long grid[23][23];
int distance(int i, int j) { return i + j; }
int main() {
  if (fopen("FILENAME.in", "r")) {
    freopen("FILENAME.in", "r", stdin);
    freopen("FILENAME.out", "w", stdout);
  }
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cin >> n >> m >> k;
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      cin >> grid[i][j];
    }
  }
  int middleDistance = (n + m - 2) / 2;
  xorValues[0][0][grid[0][0]] = 1;
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      if (distance(i, j) >= middleDistance) {
        continue;
      }
      for (pair<long long, long long> v : xorValues[i][j]) {
        if (i + 1 < n) {
          xorValues[i + 1][j][v.first ^ grid[i + 1][j]] += v.second;
        }
        if (j + 1 < m) {
          xorValues[i][j + 1][v.first ^ grid[i][j + 1]] += v.second;
        }
      }
    }
  }
  xorValuesReverse[n - 1][m - 1][0] = 1;
  for (int i = n - 1; i >= 0; i--) {
    for (int j = m - 1; j >= 0; j--) {
      if (distance(i, j) <= middleDistance) {
        continue;
      }
      for (pair<long long, long long> v : xorValuesReverse[i][j]) {
        if (i - 1 >= 0) {
          xorValuesReverse[i - 1][j][v.first ^ grid[i][j]] += v.second;
        }
        if (j - 1 >= 0) {
          xorValuesReverse[i][j - 1][v.first ^ grid[i][j]] += v.second;
        }
      }
    }
  }
  long long answer = 0;
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
      if (distance(i, j) == middleDistance) {
        for (pair<long long, long long> v : xorValues[i][j]) {
          long long desiredReverse = v.first ^ k;
          if (xorValuesReverse[i][j].find(desiredReverse) !=
              xorValuesReverse[i][j].end()) {
            answer += v.second * xorValuesReverse[i][j][desiredReverse];
          }
        }
      }
    }
  }
  cout << answer << endl;
}
