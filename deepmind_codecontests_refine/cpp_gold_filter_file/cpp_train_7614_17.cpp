#include <bits/stdc++.h>
void print_array(int *a, int n) {
  printf("#");
  for (int i = 0; i < n; i++) printf("%d%c", a[i], i == n - 1 ? '\n' : ' ');
}
using namespace std;
const double EPS = 1e-8;
const int INF = 0x3f3f3f3f;
const long long LLINF = 0x3f3f3f3f3f3f3f3f;
int mp[200][200];
int n, m, h;
void optr(int i, int j) {
  int rowmax = 0;
  for (int k = 0; k < m; ++k) {
    if (k == j) continue;
    rowmax = max(rowmax, mp[i][k]);
  }
  int colmax = 0;
  for (int k = 0; k < n; ++k) {
    if (k == i) continue;
    colmax = max(colmax, mp[k][j]);
  }
  if (rowmax > colmax) swap(rowmax, colmax);
  if (mp[i][j] <= rowmax) {
    mp[i][j] = 1;
  } else if (mp[i][j] <= colmax) {
  } else {
  }
}
int main() {
  scanf("%d%d%d", &n, &m, &h);
  int x;
  for (int i = 0; i < m; ++i) {
    scanf("%d", &x);
    for (int j = 0; j < n; ++j) {
      mp[j][i] = x;
    }
  }
  for (int i = 0; i < n; ++i) {
    scanf("%d", &x);
    for (int j = 0; j < m; ++j) {
      mp[i][j] = min(mp[i][j], x);
    }
  }
  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < m; ++j) {
      scanf("%d", &x);
      if (x == 0) mp[i][j] = 0;
    }
  }
  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < m; ++j) {
      if (mp[i][j] == 0) continue;
      optr(i, j);
    }
  }
  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < m; ++j) {
      printf("%d", mp[i][j]);
      if (j != m - 1) putchar(' ');
    }
    puts("");
  }
  return 0;
}
