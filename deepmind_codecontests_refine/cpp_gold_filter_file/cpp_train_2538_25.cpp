#include <bits/stdc++.h>
using namespace std;
int n, m, k;
int used[16][16][16], arr[16][16], cnt[16];
int work(int x, int y) {
  if (y >= m) {
    x++;
    y = 0;
  }
  if (x >= n) return 1;
  int ans = 0, res = -1;
  for (int i = 1; i <= k; i++) {
    if (arr[x][y] && arr[x][y] != i) continue;
    if (used[x][y][i]) continue;
    for (int xx = 0; xx <= x; xx++) {
      for (int yy = 0; yy <= y; yy++) used[xx][yy][i]++;
    }
    for (int xx = x; xx < n; xx++) {
      for (int yy = y; yy < m; yy++) used[xx][yy][i]++;
    }
    if (!arr[x][y]) cnt[i]++;
    if (cnt[i] == 1) {
      if (res == -1) res = work(x, y + 1);
      ans += res;
    } else
      ans += work(x, y + 1);
    if (ans >= 1000000007) ans -= 1000000007;
    if (!arr[x][y]) cnt[i]--;
    for (int xx = 0; xx <= x; xx++) {
      for (int yy = 0; yy <= y; yy++) used[xx][yy][i]--;
    }
    for (int xx = x; xx < n; xx++) {
      for (int yy = y; yy < m; yy++) used[xx][yy][i]--;
    }
  }
  return ans;
}
int main() {
  scanf("%d%d%d", &n, &m, &k);
  if (n + m - 1 > k) {
    printf("0\n");
    return 0;
  }
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      scanf("%d", arr[i] + j);
      cnt[arr[i][j]]++;
      if (arr[i][j]) {
        for (int xx = 0; xx <= i; xx++) {
          for (int yy = 0; yy <= j; yy++) used[xx][yy][arr[i][j]]++;
        }
        for (int xx = i; xx < n; xx++) {
          for (int yy = j; yy < m; yy++) used[xx][yy][arr[i][j]]++;
        }
        used[i][j][arr[i][j]] -= 2;
      }
    }
  }
  printf("%d\n", work(0, 0));
  return 0;
}
