#include <bits/stdc++.h>
bool mat[1005][1005] = {false};
bool find = false;
void test(int x, int y, int n) {
  int dx[9] = {-1, 0, 1, 1, 1, 0, -1, -1, 0};
  int dy[9] = {1, 1, 1, 0, -1, -1, -1, 0, 0};
  for (int i = y - 1; i < y + 2; i++) {
    bool flag = true;
    for (int j = 0; j < 9; j++) {
      int tx = x + dx[j];
      int ty = i + dy[j];
      if (!mat[tx][ty] || tx <= 0 || ty <= 0 || tx > n || ty > n) flag = false;
    }
    if (flag) find = true;
  }
}
int main() {
  int a, b;
  int n, m, ans = 0;
  scanf("%d %d", &n, &m);
  find = false;
  while (m--) {
    scanf("%d %d", &a, &b);
    mat[a][b] = true;
    if (find) continue;
    test(a - 1, b, n);
    test(a, b, n);
    test(a + 1, b, n);
    ans++;
  }
  if (find)
    printf("%d\n", ans);
  else
    printf("-1\n");
}
