#include <bits/stdc++.h>

using namespace std;

const int N = 100;

int main() {
  int a, b;
  cin >> a >> b;
  vector<vector<char>> grid(N);
  for (int i = 0; i < N; ++i) {
    grid[i] = vector<char>(N, i < N / 2 ? '.' : '#');
  }
  for (int i = 1; i < b; ++i) {
    int x = i / 50 * 2;
    int y = i % 50 * 2;
    grid[x][y] = '#';
  }
  for (int i = 1; i < a; ++i) {
    int x = i / 50 * 2;
    int y = i % 50 * 2;
    grid[N - 1 - x][N - 1 - y] = '.';
  }
  cout << N << ' ' << N << '\n';
  for (int i = 0; i < N; ++i) {
    for (int j = 0; j < N; ++j) {
      cout << grid[i][j];
    }
    cout << '\n';
  }
  return 0;
}