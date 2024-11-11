#include <bits/stdc++.h>
#pragma comment(linker, "/STACK:16777216")
using namespace std;
const long double pi = 3.14159265358979323846;
const int inf = (int)1e9;
const long long int llinf = (long long int)1e18;
const int base = 10;
double eps = 1e-9;
bool pred(const pair<pair<int, int>, int>& i,
          const pair<pair<int, int>, int>& j) {
  if (i.first.second == j.first.second) {
    return i.first.first < j.first.first;
  }
  return i.first.second < j.first.second;
}
const int mx = 1005;
int a[mx][mx];
int n, m;
long long int b[mx][mx][4];
void calc() {
  b[0][0][0] = a[0][0];
  for (int i = 1; i < m; ++i) {
    b[0][i][0] = b[0][i - 1][0] + a[0][i];
  }
  for (int i = 1; i < n; ++i) {
    b[i][0][0] = b[i - 1][0][0] + a[i][0];
  }
  for (int i = 1; i < n; ++i) {
    for (int j = i; j < m; ++j) {
      b[i][j][0] = max(b[i][j - 1][0], b[i - 1][j][0]) + a[i][j];
    }
  }
  b[0][m - 1][1] = a[0][m - 1];
  for (int i = m - 2; i >= 0; --i) {
    b[0][i][1] = b[0][i + 1][1] + a[0][i];
  }
  for (int i = 1; i < n; ++i) {
    b[i][m - 1][1] = b[i - 1][m - 1][1] + a[i][m - 1];
  }
  for (int i = 1; i < n; ++i) {
    for (int j = m - 2; j >= 0; --j) {
      b[i][j][1] = max(b[i][j + 1][1], b[i - 1][j][1]) + a[i][j];
    }
  }
  b[n - 1][m - 1][2] = a[n - 1][m - 1];
  for (int i = m - 2; i >= 0; --i) {
    b[n - 1][i][2] = b[n - 1][i + 1][2] + a[n - 1][i];
  }
  for (int i = n - 2; i >= 0; --i) {
    b[i][m - 1][2] = b[i + 1][m - 1][2] + a[i][m - 1];
  }
  for (int i = n - 2; i >= 0; --i) {
    for (int j = m - 2; j >= 0; --j) {
      b[i][j][2] = max(b[i][j + 1][2], b[i + 1][j][2]) + a[i][j];
    }
  }
  b[n - 1][0][3] = a[n - 1][0];
  for (int i = 1; i < m; ++i) {
    b[n - 1][i][3] = b[n - 1][i - 1][3] + a[n - 1][i];
  }
  for (int i = n - 2; i >= 0; --i) {
    b[i][0][3] = b[i + 1][0][3] + a[i][0];
  }
  for (int i = n - 2; i >= 0; --i) {
    for (int j = 1; j < m; ++j) {
      b[i][j][3] = max(b[i][j - 1][3], b[i + 1][j][3]) + a[i][j];
    }
  }
}
int main() {
  cin >> n >> m;
  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < m; ++j) {
      scanf("%d", &a[i][j]);
    }
  }
  calc();
  long long int res = 0;
  for (int i = 1; i < n - 1; ++i) {
    for (int j = 1; j < m - 1; ++j) {
      res = max(res, b[i - 1][j][0] + b[i][j + 1][1] + b[i + 1][j][2] +
                         b[i][j - 1][3]);
      res = max(res, b[i][j - 1][0] + b[i - 1][j][1] + b[i][j + 1][2] +
                         b[i + 1][j][3]);
    }
  }
  cout << res;
  return 0;
}
