#include <bits/stdc++.h>
using namespace std;
const int MAXN = 1005;
char M[MAXN][MAXN];
int cnt[MAXN][MAXN];
int n, m;
bool valid(int x, int y) { return x >= 0 and x < n and y >= 0 and y < m; }
void f(int x, int y) {
  for (int i = 0; i < 3; ++i)
    for (int j = 0; j < 3; ++j) {
      if (not valid(x + i, y + j)) return;
      if (i != 1 and j != 1 and M[x + i][y + j] != '#') return;
    }
  for (int i = 0; i < 3; ++i)
    for (int j = 0; j < 3; ++j) cnt[x + i][y + j] += 1;
  cnt[x + 1][y + 1] -= 1;
}
int main() {
  scanf("%d %d\n", &n, &m);
  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < m; ++j) M[i][j] = getchar();
    getchar();
  }
  for (int i = 0; i < n; ++i)
    for (int j = 0; j < m; ++j) f(i, j);
  bool ok = 1;
  for (int i = 0; i < n; ++i)
    for (int j = 0; j < m; ++j)
      if (M[i][j] == '#' and cnt[i][j] == 0) ok = 0;
  puts(ok ? "YES" : "NO");
  return 0;
}
