#include <bits/stdc++.h>
using namespace std;
ifstream fin("text.in");
const int N = 60;
struct lac {
  int v, i, j;
} a[3610];
int n, m, i, j, x, v[N][N], k, nr, nrl;
char s[60];
int dx[4] = {1, -1, 0, 0};
int dy[4] = {0, 0, -1, 1};
void umple(int x, int y) {
  int xa, ya;
  v[x][y] = -1;
  for (int d = 0; d < 4; ++d) {
    xa = x + dx[d];
    ya = y + dy[d];
    if (v[xa][ya] == 0) umple(xa, ya);
  }
}
int numara(int x, int y) {
  int xa, ya, nr = 1;
  v[x][y] = -1;
  for (int d = 0; d < 4; ++d) {
    xa = x + dx[d];
    ya = y + dy[d];
    if (v[xa][ya] == 0) nr += numara(xa, ya);
  }
  return nr;
}
void full(int x, int y) {
  int xa, ya;
  v[x][y] = 1;
  for (int d = 0; d < 4; ++d) {
    xa = x + dx[d];
    ya = y + dy[d];
    if (v[xa][ya] == -1) full(xa, ya);
  }
}
inline bool cmp(lac x, lac y) { return x.v > y.v; }
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cin >> n >> m >> k;
  for (i = 1; i <= n; ++i) {
    cin >> s;
    for (j = 1; j <= m; ++j)
      if (s[j - 1] == '*') v[i][j] = 1;
  }
  for (i = 0; i <= n + 1; ++i) v[i][0] = v[i][m + 1] = 1;
  for (j = 0; j <= m + 1; ++j) v[0][j] = v[n + 1][j] = 1;
  for (i = 1; i <= n; ++i) {
    if (v[i][1] == 0) umple(i, 1);
    if (v[i][m] == 0) umple(i, m);
  }
  for (j = 1; j <= m; ++j) {
    if (v[1][j] == 0) umple(1, j);
    if (v[n][j] == 0) umple(n, j);
  }
  for (i = 1; i <= n; ++i)
    for (j = 1; j <= m; ++j) {
      if (v[i][j] == 0) {
        nr++;
        a[nr].v = numara(i, j);
        a[nr].i = i;
        a[nr].j = j;
      }
    }
  sort(a + 1, a + nr + 1, cmp);
  for (i = nr; i > k; --i) {
    nrl += a[i].v;
    full(a[i].i, a[i].j);
  }
  cout << nrl << "\n";
  for (i = 1; i <= n; ++i) {
    for (j = 1; j <= m; ++j)
      if (v[i][j] == 1) {
        cout << '*';
      } else {
        cout << '.';
      }
    cout << "\n";
  }
  return 0;
}
