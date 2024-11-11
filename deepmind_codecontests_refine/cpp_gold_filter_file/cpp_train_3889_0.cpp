#include <bits/stdc++.h>
using namespace std;
double PI = 3.141592653589793;
const double EPS = 1e-9;
const int N = 1e6 + 5;
const long long mod = 1e9 + 7;
const int oo = 1e9 + 9;
int dx[] = {0, 0, 1, -1, 1, -1, 1, -1};
int dy[] = {1, -1, 0, 0, -1, 1, 1, -1};
int n, m;
long long row[1005], col[1005];
int main() {
  scanf("%d%d", &n, &m);
  for (int i = 0; i <= n - 1; i++) {
    for (int j = 0; j <= m - 1; j++) {
      int x;
      scanf("%d", &x);
      row[i] += x;
      col[j] += x;
    }
  }
  long long min_row = 1e18;
  int ans_row;
  for (int i = 0; i <= n; i++) {
    long long curr = 0;
    for (int j = i, x = 2; j < n; j++, x += 4) {
      curr += x * x * row[j];
    }
    for (int j = i - 1, x = 2; j >= 0; j--, x += 4) {
      curr += x * x * row[j];
    }
    if (curr < min_row) {
      ans_row = i;
      min_row = curr;
    }
  }
  long long min_col = 1e18;
  int ans_col;
  for (int i = 0; i <= m; i++) {
    long long curr = 0;
    for (int j = i, y = 2; j < m; j++, y += 4) {
      curr += (long long)y * y * col[j];
    }
    for (int j = i - 1, y = 2; j >= 0; j--, y += 4) {
      curr += (long long)y * y * col[j];
    }
    if (curr < min_col) {
      ans_col = i;
      min_col = curr;
    }
  }
  printf("%lld\n%d %d", min_col + min_row, ans_row, ans_col);
}
