#include <bits/stdc++.h>
using namespace std;
template <class T, class L>
bool smax(T& x, L y) {
  return x < y ? (x = y, 1) : 0;
}
template <class T, class L>
bool smin(T& x, L y) {
  return x > y ? (x = y, 1) : 0;
}
const int maxn = 2e3 + 17, maxk = 10;
int n, m, nq;
int d[maxk][maxk], rl[maxn][maxk], rf[maxn][maxk];
vector<pair<int, int> > pos[maxk];
int hmmmmmmmm(int x) { return x < 0 ? -x : x; }
void build(int x, int y) {
  for (auto a : pos[x])
    for (auto b : pos[y])
      smax(d[x][y],
           hmmmmmmmm(a.first - b.first) + hmmmmmmmm(a.second - b.second));
  d[y][x] = d[x][y];
}
int main() {
  memset(rl, -1, sizeof rl), memset(rf, -1, sizeof rl);
  {
    int tmp;
    scanf("%d %d %d %d ", &n, &m, &tmp, &nq);
  }
  for (int i = 0; i < n; i++)
    for (int j = 0; j < m; j++, getchar()) {
      char c = getchar() - '1';
      rl[i][c] = j;
      if (rf[i][c] == -1) rf[i][c] = j;
    }
  for (int k = 0; k < maxk; k++)
    for (int i = 0; i < n; i++)
      if (~rf[i][k])
        pos[k].push_back({i, rf[i][k]}), pos[k].push_back({i, rl[i][k]});
  for (int i = 0; i < maxk; i++)
    for (int j = i; j < maxk; j++) build(i, j);
  char o = getchar() - '1';
  getchar();
  int ans = 0;
  while (--nq) {
    char c = getchar() - '1';
    getchar();
    smax(ans, d[o][c]);
    o = c;
  }
  printf("%d\n", ans);
  return 0;
}
