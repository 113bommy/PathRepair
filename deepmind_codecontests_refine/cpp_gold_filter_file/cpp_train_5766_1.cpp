#include <bits/stdc++.h>
using namespace std;
const int e[4][2] = {{-1, -1}, {-1, 1}, {1, -1}, {1, 1}};
int N, M, K, X, Y, D;
set<pair<int, int> > A[200005], B[200005];
map<int, int> F[200005], G[200005];
void init() {
  char s[3];
  scanf("%d%d%d", &N, &M, &K);
  for (int i = 1, x, y; i <= K; i++)
    scanf("%d%d", &x, &y), A[x - (y) + M + 1].insert(pair<int, int>(x, y)),
        B[x + y].insert(pair<int, int>(x, y)), F[x][y] = 1;
  scanf("%d%d%s", &X, &Y, s), D = (s[1] == 'E') | ((s[0] == 'S') << 1);
  for (int i = 0; i <= N + 1; i++)
    A[i - (0) + M + 1].insert(pair<int, int>(i, 0)),
        B[i + 0].insert(pair<int, int>(i, 0)),
        F[i][0] = 1, A[i - (M + 1) + M + 1].insert(pair<int, int>(i, M + 1)),
        B[i + M + 1].insert(pair<int, int>(i, M + 1)), F[i][M + 1] = 1;
  for (int i = 0; i <= M + 1; i++)
    A[0 - (i) + M + 1].insert(pair<int, int>(0, i)),
        B[0 + i].insert(pair<int, int>(0, i)),
        F[0][i] = 1, A[N + 1 - (i) + M + 1].insert(pair<int, int>(N + 1, i)),
        B[N + 1 + i].insert(pair<int, int>(N + 1, i)), F[N + 1][i] = 1;
}
void find(int x, int y, int d, int& xx, int& yy, int& dd, int& px, int& py) {
  int a, b;
  if (!d) {
    auto p = A[x - y + M + 1].lower_bound(pair<int, int>(x, y));
    p--;
    px = p->first, py = p->second, a = F[px + 1].count(py),
    b = F[px].count(py + 1);
    if (!a && b)
      xx = px + 1, yy = py, dd = 2;
    else if (a && !b)
      xx = px, yy = py + 1, dd = 1;
    else
      xx = px + 1, yy = py + 1, dd = 3;
  } else if (d == 1) {
    auto p = B[x + y].lower_bound(pair<int, int>(x, y));
    p--;
    px = p->first, py = p->second, a = F[px + 1].count(py),
    b = F[px].count(py - 1);
    if (!a && b)
      xx = px + 1, yy = py, dd = 3;
    else if (a && !b)
      xx = px, yy = py - 1, dd = 0;
    else
      xx = px + 1, yy = py - 1, dd = 2;
  } else if (d == 2) {
    auto p = B[x + y].upper_bound(pair<int, int>(x, y));
    px = p->first, py = p->second, a = F[px - 1].count(py),
    b = F[px].count(py + 1);
    if (!a && b)
      xx = px - 1, yy = py, dd = 0;
    else if (a && !b)
      xx = px, yy = py + 1, dd = 3;
    else
      xx = px - 1, yy = py + 1, dd = 1;
  } else {
    auto p = A[x - y + M + 1].upper_bound(pair<int, int>(x, y));
    px = p->first, py = p->second, a = F[px - 1].count(py),
    b = F[px].count(py - 1);
    if (!a && b)
      xx = px - 1, yy = py, dd = 1;
    else if (a && !b)
      xx = px, yy = py - 1, dd = 2;
    else
      xx = px - 1, yy = py - 1, dd = 0;
  }
}
void doit() {
  long long ans = 0, bg = 0;
  int xx, yy, dd, px, py;
  find(X, Y, D, X, Y, D, px, py);
  for (int x = X, y = Y, d = D;; x = xx, y = yy, d = dd) {
    find(x, y, d, xx, yy, dd, px, py), ans += abs(x - px), G[x][y] = 1;
    if (xx == X && yy == Y && dd == D) break;
    if (G[xx][yy] || dd + d == 3) bg = 1;
  }
  if (bg) ans /= 2;
  cout << ans << endl;
}
int main() {
  init();
  doit();
  return 0;
}
