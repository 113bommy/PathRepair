#include <bits/stdc++.h>
using namespace std;
const int mr[] = {0, 1, 0, -1};
const int mc[] = {-1, 0, 1, 0};
int a[2050][2050];
int s[2050][2050];
vector<pair<int, int> > at;
inline double calc(double x, double y) { return x * x + y * y; }
void flood(int r, int c) {
  a[r][c] = 0;
  at.push_back({r, c});
  for (int o = 0; o < 4; o++) {
    int dr = r + mr[o];
    int dc = c + mc[o];
    if (a[dr][dc]) flood(dr, dc);
  }
}
int main() {
  int n, ans[2] = {};
  scanf("%d", &n);
  for (int i = 5; i < n + 10; i++)
    for (int j = 5; j < n + 10; j++) {
      if (i < n + 5 && j < n + 5) do
          a[i][j] = getchar() - 48;
        while (a[i][j] < 0 || a[i][j] > 1);
      s[i][j] = a[i][j] + s[i][j - 1] + s[i - 1][j] - s[i - 1][j - 1];
    }
  for (int i = 5; i < n + 5; i++)
    for (int j = 5; j < n + 5; j++)
      a[i][j] = (s[i + 2][j + 2] - s[i + 2][j - 3] - s[i - 3][j + 2] +
                     s[i - 3][j - 3] >=
                 13);
  for (int i = 5; i < n + 5; i++)
    for (int j = 5; j < n + 5; j++)
      if (a[i][j]) {
        at.clear();
        flood(i, j);
        if (at.size() < 30) continue;
        double r = 0, c = 0, l = 0;
        for (auto& x : at) {
          r += x.first;
          c += x.second;
        }
        r /= at.size();
        c /= at.size();
        for (auto& x : at) l = max(l, calc(r - x.first, c - x.second));
        ans[at.size() < 2.5 * l]++;
      }
  printf("%d %d\n", ans[0], ans[1]);
}
