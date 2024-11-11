#include <bits/stdc++.h>
using namespace std;
const int N = 2e3 + 9;
bool p[N][N];
priority_queue<pair<pair<int, int>, pair<int, int> > > q;
int cu;
int n, m, si, sj, ml, mr, a, b, ti, tj;
char c;
bool valid(int i, int j) {
  return i > 0 && i <= n && j > 0 && j <= m && p[i][j];
}
void add(int x, int y, int i, int j) {
  p[i][j] = 0;
  ++cu;
  q.push({{x, y}, {i, j}});
}
int main() {
  scanf("%d %d %d %d %d %d", &n, &m, &si, &sj, &mr, &ml);
  for (int i = 1; i <= n; ++i)
    for (int j = 1; j <= m; ++j)
      p[i][j] = ((cin >> c, c) == '.' ? true : false);
  add(0, 0, si, sj);
  auto cr = q.top();
  while (!q.empty()) {
    cr = q.top();
    a = -cr.first.first;
    b = cr.first.second;
    ti = cr.second.first;
    tj = cr.second.second;
    q.pop();
    if (valid(ti + 1, tj)) add(-a, b, ti + 1, tj);
    if (valid(ti - 1, tj)) add(-a, b, ti - 1, tj);
    if (valid(ti, tj + 1) && b + 1 <= ml) add(-a, (b + 1), ti, tj + 1);
    if (valid(ti, tj - 1) && a + 1 <= mr) add(-(a + 1), b, ti, tj - 1);
  }
  printf("%d\n", cu);
}
