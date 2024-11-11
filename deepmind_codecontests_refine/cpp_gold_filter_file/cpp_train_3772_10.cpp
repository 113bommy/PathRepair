#include <bits/stdc++.h>
using namespace std;
const long long LINF = ~(((long long)0x1) << 63) / 2;
const int INF = 0X3F3F3F3F;
const double eps = 1e-7;
int col[300000];
int row[300000];
int dig[300000];
int xx[300000];
int x_col[300000][2], x_row[300000][2], x_dig[300000][2], x_xx[300000][2];
int num[10];
int p[300000][2];
int main() {
  int n, m, i, j, k;
  cin >> n >> m;
  for (i = 0; i < 300000; i++)
    x_col[i][0] = x_row[i][0] = x_dig[i][0] = x_xx[i][0] = INF;
  for (i = 0; i < m; i++) {
    int x, y;
    cin >> x >> y;
    p[i][0] = x;
    p[i][1] = y;
    row[x]++;
    x_row[x][0] = min(y, x_row[x][0]);
    x_row[x][1] = max(y, x_row[x][1]);
    col[y]++;
    x_col[y][0] = min(x, x_col[y][0]);
    x_col[y][1] = max(x, x_col[y][1]);
    dig[x + y]++;
    x_dig[x + y][0] = min(x, x_dig[x + y][0]);
    x_dig[x + y][1] = max(x, x_dig[x + y][1]);
    xx[x - y + n]++;
    x_xx[x - y + n][0] = min(x, x_xx[x - y + n][0]);
    x_xx[x - y + n][1] = max(x, x_xx[x - y + n][1]);
  }
  for (i = 0; i < m; i++) {
    int x = p[i][0], y = p[i][1];
    int now = 0;
    if (x_row[x][0] < y) now++;
    if (x_row[x][1] > y) now++;
    if (x_col[y][0] < x) now++;
    if (x_col[y][1] > x) now++;
    if (x_dig[x + y][0] < x) now++;
    if (x_dig[x + y][1] > x) now++;
    if (x_xx[x - y + n][0] < x) now++;
    if (x_xx[x - y + n][1] > x) now++;
    num[now]++;
  }
  cout << num[0];
  for (i = 1; i <= 8; i++) cout << " " << num[i];
  cout << endl;
  return 0;
}
