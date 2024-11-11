#include <bits/stdc++.h>
using namespace std;
const int N = 102;
int n, a[5][N][N];
int ans = 1000000000;
int bst1[N][N], bst2[N][N];
int main() {
  scanf("%d", &n);
  for (int i = 1; i <= 4; ++i)
    for (int j = 1; j <= n; ++j)
      for (int k = 1; k <= n; ++k) scanf("%1d", &a[i][j][k]);
  for (int i = 1; i <= 2 * n; ++i)
    for (int j = 1; j <= 2 * n; ++j) {
      bst1[i][j] = (i + j) & 1;
      bst2[i][j] = (i + j) % 2 == 0;
    }
  int p[] = {1, 2, 3, 4};
  do {
    int curr = 0;
    for (int i = 0; i <= 3; ++i) {
      for (int x = 1; x <= n; ++x)
        for (int y = 1; y <= n; ++y)
          curr += a[p[i]][x][y] != bst1[x + n * (i > 1)][y + n * (i & 1)];
    }
    ans = min(ans, curr);
    curr = 0;
    for (int i = 0; i <= 3; ++i) {
      for (int x = 1; x <= n; ++x)
        for (int y = 1; y <= n; ++y)
          curr += a[p[i]][x][y] != bst2[x + n * (i > 1)][y + n * (i & 1)];
    }
    ans = min(ans, curr);
  } while (next_permutation(p, p + 4));
  cout << ans;
}
