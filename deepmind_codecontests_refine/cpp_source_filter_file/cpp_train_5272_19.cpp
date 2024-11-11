#include <bits/stdc++.h>
using namespace std;
const long long MX = 1e5 + 5;
const int INF = 1e9 + 7;
const double EPS = 0.00000001;
vector<vector<int> > grid;
int n, m;
inline void shift_row(int i, int inc) {
  vector<int> tmp(m);
  for (int j = 0; j < m; j++) tmp[(j + inc) % m] = grid[i][j];
  for (int j = 0; j < m; j++) grid[i][j] = tmp[j];
}
inline void shift_col(int j, int inc) {
  vector<int> tmp(n);
  for (int i = 0; i < n; i++) tmp[(i + inc) % n] = grid[i][j];
  for (int i = 0; i < n; i++) grid[i][j] = tmp[i];
}
void print_grid() {
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      printf("%d ", grid[i][j]);
    }
    printf("\n");
  }
}
int main() {
  ios_base::sync_with_stdio(false);
  scanf("%d%d", &n, &m);
  if (n == 1 && m == 1) {
    cout << "YES" << endl;
    cout << 1 << endl;
    return 0;
  }
  if (n == 3 && m == 3) {
    cout << "YES" << endl;
    int arr[] = {6, 1, 8, 7, 5, 3, 2, 9, 4};
    int cntr = 0;
    grid.resize(3);
    for (int i = 0; i < 3; i++) {
      grid[i].resize(3);
      for (int j = 0; j < 3; j++) {
        grid[i][j] = arr[cntr++];
      }
    }
    print_grid();
    return 0;
  }
  if (m <= 3 && n <= 3) {
    cout << "NO" << endl;
    return 0;
  }
  cout << "YES" << endl;
  grid.resize(n);
  int cntr = 1;
  for (int i = 0; i < n; i++) {
    grid[i].resize(m);
    for (int j = 0; j < m; j++) {
      grid[i][j] = cntr++;
    }
  }
  if (n == 1) {
    if (m == 4) {
      grid[0][0] = 2;
      grid[0][1] = 4;
      grid[0][2] = 1;
      grid[0][3] = 3;
    } else {
      for (int j = 0; j < m - 2; j += 2) {
        swap(grid[0][j], grid[0][j + 2]);
        swap(grid[0][j + 1], grid[0][j + 2]);
      }
    }
  } else if (m == 1) {
    if (n == 4) {
      grid[0][0] = 2;
      grid[1][0] = 4;
      grid[2][0] = 1;
      grid[3][0] = 3;
    } else {
      for (int i = 0; i < n - 2; i += 2) {
        swap(grid[i][0], grid[i + 2][0]);
        swap(grid[i + 1][0], grid[i + 2][0]);
      }
    }
  } else {
    if (n == 2) {
      for (int i = 0; i < n; i++) {
        if (i % 2) shift_row(i, 2);
      }
      for (int j = 0; j < m; j++) {
        if (j % 2) shift_col(j, 1);
      }
    } else if (m == 2) {
      for (int j = 0; j < m; j++) {
        if (j % 2 == 0) shift_col(j, 2);
      }
      for (int i = 0; i < n; i++) {
        if (i % 2 == 0) shift_row(i, 1);
      }
    } else {
      for (int i = 0; i < n; i++) {
        if (i % 2) shift_row(i, 2);
      }
      for (int j = 0; j < m; j++) {
        if (j % 2) shift_col(j, 1);
      }
    }
  }
  print_grid();
  return 0;
}
