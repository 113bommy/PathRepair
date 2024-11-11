#include <bits/stdc++.h>
using namespace std;
char grid[60][60];
bool all_p(long long int r, long long int c) {
  for (int i = 0; i < r; i++) {
    for (int j = 0; j < c; j++) {
      if (grid[i][j] != 'P') return false;
    }
  }
  return true;
}
bool all_a(long long int r, long long int c) {
  for (int i = 0; i < r; i++) {
    for (int j = 0; j < c; j++) {
      if (grid[i][j] != 'A') return false;
    }
  }
  return true;
}
bool one_row(long long int r, long long int c) {
  long long int counter = 0;
  for (int i = 0; i < r; i++) {
    counter = 0;
    for (int j = 0; j < c; j++) {
      if (grid[i][j] == 'A') counter++;
    }
    if (counter == c) return true;
  }
  return false;
}
bool one_col(long long int r, long long int c) {
  long long int counter = 0;
  for (int i = 0; i < c; i++) {
    counter = 0;
    for (int j = 0; j < r; j++) {
      if (grid[j][i] == 'A') counter++;
    }
    if (counter == r) return true;
  }
  return false;
}
bool edge_row1(long long int r, long long int c) {
  long long int first = 0, end_row = r - 1, end_col = c - 1;
  for (int i = 0; i < c; i++) {
    if (grid[first][i] != 'A') return false;
  }
  return true;
}
bool edge_row2(long long int r, long long int c) {
  long long int first = 0, end_row = r - 1, end_col = c - 1;
  for (int i = 0; i < c; i++) {
    if (grid[end_row][i] != 'A') return false;
  }
  return true;
}
bool edge_col1(long long int r, long long int c) {
  long long int first = 0, end_row = r - 1, end_col = c - 1;
  for (int i = 0; i < r; i++) {
    if (grid[i][first] != 'A') return false;
  }
  return true;
}
bool edge_col2(long long int r, long long int c) {
  long long int first = 0, end_row = r - 1, end_col = c - 1;
  for (int i = 0; i < r; i++) {
    if (grid[i][end_col] != 'A') return false;
  }
  return true;
}
bool corner_cell(long long int r, long long int c) {
  if (grid[0][0] == 'A' || grid[r - 1][0] == 'A' || grid[0][c - 1] == 'A' ||
      grid[r - 1][c - 1] == 'A')
    return true;
  return false;
}
bool edge_cell(long long int r, long long int c) {
  long long int first = 0, end_row = r - 1, end_col = c - 1;
  for (int i = 0; i < c; i++) {
    if (grid[first][i] == 'A') return true;
    if (grid[end_row][i] == 'A') return true;
  }
  for (int i = 0; i < r; i++) {
    if (grid[i][first] == 'A') return true;
    if (grid[i][end_col] == 'A') return true;
  }
  return false;
}
int main() {
  long long int t;
  cin >> t;
  while (t--) {
    long long int r, c;
    cin >> r >> c;
    for (int i = 0; i < r; i++) {
      for (int j = 0; j < c; j++) {
        cin >> grid[i][j];
      }
    }
    if (all_p(r, c))
      cout << "MORTAL";
    else if (all_a(r, c))
      cout << "0";
    else if (edge_row1(r, c) || edge_row2(r, c) || edge_col1(r, c) ||
             edge_col2(r, c))
      cout << "1";
    else if (corner_cell(r, c) || one_row(r, c) || one_col(r, c))
      cout << "2";
    else if (edge_cell(r, c))
      cout << "3";
    else
      cout << "4";
    cout << endl;
  }
  return 0;
}
