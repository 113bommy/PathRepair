#include <bits/stdc++.h>
using namespace std;
const int N = 100010, MP = 30;
int val[MP + 2][N], n, m, ans[N];
struct data {
  int l, r;
};
vector<data> dat[MP];
bool solve(int sgn) {
  int x, y;
  for (int i = 1; i <= n; ++i) val[sgn][i] += val[sgn][i - 1];
  for (int i = 1; i <= n; ++i) val[sgn][i] = (val[sgn][i] ? 1 : 0);
  for (int i = 1; i <= n; ++i) val[sgn][i] += val[sgn][i - 1];
  for (int i = 0; i < (int)dat[sgn].size(); ++i) {
    x = dat[sgn][i].l, y = dat[sgn][i].r;
    if (val[sgn][y] - val[sgn][x - 1] == y - x + 1) return 0;
  }
  return 1;
}
int main() {
  int a, b, c, t;
  scanf("%d%d", &n, &m);
  for (int i = 1; i <= m; ++i) {
    scanf("%d%d%d", &a, &b, &c);
    for (int j = 0; j <= MP; ++j) {
      t = (c & (1 << j));
      if (t) {
        ++val[j][a];
        ++val[j][b + 1];
      } else {
        dat[j].push_back((data){a, b});
      }
    }
  }
  for (int i = 0; i <= MP; ++i)
    if (!solve(i)) return 0 * printf("NO\n");
  puts("YES");
  for (int j = 0; j <= MP; ++j)
    for (int i = 1; i <= n; ++i) {
      ans[i] += (1 << j) * (val[j][i] - val[j][i - 1]);
    }
  for (int i = 1; i <= n; ++i) printf("%d ", ans[i]);
  return 0;
}
