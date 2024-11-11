#include <bits/stdc++.h>
using namespace std;
inline int nextint() {
  int res = 0;
  int neg = 1;
  char c = 0;
  while (c != '-' && (c < '0' || c > '9')) c = getchar();
  if (c == '-') c = '0', neg = -1;
  while (c >= '0' && c <= '9') {
    res = res * 10 + c - '0';
    c = getchar();
  }
  return neg * res;
}
int n, m;
int data[2000][2000];
int get_col(int i, int j) {
  int v1 = i % 3;
  int v2 = j % 3;
  return 1 + 3 * v1 + v2;
}
const int dir[4][2] = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};
int main() {
  cin >> n >> m;
  for (int i = 0; i < (int)(n); ++i)
    for (int j = 0; j < (int)(m); ++j) {
      char c = 0;
      while (c != '.' && c != '#') c = getchar();
      data[i][j] = (c == '.') ? 0 : -1;
    }
  for (int i = 0; i < (int)(n); ++i) {
    int j = 0, k;
    for (; j < m; j = k + 1) {
      while (data[i][j] && j < m) j++;
      k = j;
      while (k + 1 < m && !data[i][k + 1]) k++;
      for (int pos = j; pos < k; pos += 2)
        data[i][pos] = data[i][pos + 1] = get_col(i, pos);
    }
  }
  for (int j = 0; j < (int)(m); ++j) {
    int i = 0, k;
    for (; i < n; i = k + 1) {
      while (data[i][j] && i < n) i++;
      k = i;
      while (k + 1 < n && !data[k + 1][j]) k++;
      for (int pos = i; pos < k; pos += 2)
        data[pos][j] = data[pos + 1][j] = get_col(pos, j);
    }
  }
  for (int i = 0; i < (int)(n); ++i)
    for (int j = 0; j < (int)(m); ++j)
      if (!data[i][j]) {
        for (int k = 0; k < (int)(4); ++k) {
          int _i = i + dir[k][0], _j = j + dir[k][1];
          if (_i < 0 || _j < 0 || _i >= n || _j >= m) continue;
          assert(data[_i][_j] != 0);
          if (data[_i][_j] != -1) {
            data[i][j] = data[_i][_j];
            break;
          }
        }
        if (!data[i][j]) {
          cout << -1 << endl;
          return 0;
        }
      }
  for (int i = 0; i < (int)(n); ++i) {
    for (int j = 0; j < (int)(m); ++j) {
      int v = data[i][j];
      if (v == -1)
        putchar('#');
      else
        putchar('0' + v);
    }
    putchar('\n');
  }
  return 0;
}
