#include <bits/stdc++.h>
using namespace std;
const int N = 1100;
int a[N][N];
int n, m;
pair<int, pair<int, int> > b[N * N];
char c[N][N];
char cnt[N][N];
int add(int x, int y) {
  c[x][y] = 1;
  for (int i = 0; i < n; i++)
    if (x != y) {
      if (c[i][y]) {
        cnt[i][x]++;
        cnt[x][i]++;
        if (cnt[i][x] > 1) return 1;
      }
    }
  return 0;
}
int main() {
  scanf("%d%d", &n, &m);
  for (int i = 0; i < n; i++)
    for (int j = 0; j < m; j++)
      scanf("%d", &a[i][j]), b[i * m + j].first = a[i][j],
                                       b[i * m + j].second = make_pair(i, j);
  sort(b, b + n * m);
  for (int i = n * m - 1; i >= 0; i--) {
    int x = b[i].second.first;
    int y = b[i].second.second;
    if (add(x, y)) {
      printf("%d\n", b[i].first);
      return 0;
    }
  }
  return 0;
}
