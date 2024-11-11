#include <bits/stdc++.h>
using namespace std;
const int N = 200;
int n, t;
int mp[N << 1][N << 1];
int main() {
  scanf("%d%d", &n, &t);
  memset(mp, 0, sizeof mp);
  bool flag = 1;
  mp[N][N] = n;
  while (flag) {
    flag = 0;
    for (int i = 0; i < N * 2; i++) {
      for (int j = 0; j < N * 2; j++) {
        if (mp[i][j] >= 4) {
          flag = 1;
          int now = mp[i][j] / 4;
          mp[i + 1][j] += now;
          mp[i - 1][j] += now;
          mp[i][j + 1] += now;
          mp[i][j - 1] += now;
          mp[i][j] -= now * 4;
        }
      }
    }
  }
  for (int i = 1; i <= t; i++) {
    int x, y;
    scanf("%d%d", &x, &y);
    if (abs(x) > N || abs(y) > N) {
      printf("0\n");
    } else {
      printf("%d\n", mp[x + N][y + N]);
    }
  }
  return 0;
}
