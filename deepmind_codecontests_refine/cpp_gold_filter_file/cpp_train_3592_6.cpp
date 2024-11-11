#include <bits/stdc++.h>
using namespace std;
const long long MaxLL = (long long)1e18;
const int MaxInt = (int)1e8, MaxN = (int)1e3, MaxM = 1e7 * 2;
char c, a[MaxN][MaxN];
int i, j, n, m, k, xx[MaxM], yy[MaxM], cc[MaxM], b[3][MaxN][MaxN], q1, q2,
    o = MaxInt;
void add(int x, int y, int c) {
  if (x < 0 || y < 0 || x > n - 1 || y > m - 1 || a[x][y] == '#') {
    return;
  }
  if (a[x][y] == '.') {
    c++;
  }
  if (b[k][x][y] <= c) {
    return;
  }
  b[k][x][y] = c;
  xx[q2] = x;
  yy[q2] = y;
  cc[q2] = c;
  q2++;
  if (q2 == MaxM) {
    q2 = 0;
  }
}
void pr() {
  q1 = q2 = 0;
  for (i = 0; i < n; i++) {
    for (j = 0; j < m; j++) {
      b[k][i][j] = MaxInt;
      if (a[i][j] != c) {
        continue;
      }
      add(i, j, 0);
    }
  }
  while (q1 != q2) {
    int x = xx[q1], y = yy[q1], c = cc[q1];
    q1++;
    if (q1 == MaxM) {
      q1 = 0;
      break;
    }
    add(x + 1, y, c);
    add(x - 1, y, c);
    add(x, y + 1, c);
    add(x, y - 1, c);
  }
}
int main() {
  cin >> n >> m;
  for (i = 0; i < n; i++) {
    for (j = 0; j < m; j++) {
      cin >> a[i][j];
    }
  }
  c = '1', k = 0, pr();
  c = '2', k = 1, pr();
  c = '3', k = 2, pr();
  for (i = 0; i < n; i++) {
    for (j = 0; j < m; j++) {
      int e = 0;
      if (a[i][j] == '.') {
        e = 2;
      }
      o = min(o, b[0][i][j] + b[1][i][j] + b[2][i][j] - e);
    }
  }
  if (o == MaxInt) {
    puts("-1");
    return 0;
  }
  cout << o << "\n";
}
