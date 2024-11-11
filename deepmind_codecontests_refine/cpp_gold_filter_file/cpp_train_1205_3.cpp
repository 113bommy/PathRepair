#include <bits/stdc++.h>
using namespace std;
char s[104][105];
int n, m;
struct arr {
  int x, y;
} ans1[50005], ans2[50005];
void work(int bo, int i, int j, arr a[]) {
  if (bo) {
    if (s[i][j] == 'U' && s[i][j + 1] == 'U') return;
    if (s[i][j] == 'L' && s[i + 1][j] == 'L') {
      ++a[0].x;
      a[a[0].x] = {i, j};
      s[i][j] = s[i][j + 1] = 'U';
      s[i + 1][j] = s[i + 1][j + 1] = 'D';
    }
    if (s[i][j] == 'L' && s[i + 1][j] == 'U') {
      work(0, i + 1, j, a);
      ++a[0].x;
      a[a[0].x] = {i, j};
      s[i][j] = s[i][j + 1] = 'U';
      s[i + 1][j] = s[i + 1][j + 1] = 'D';
    }
    if (s[i][j] == 'U' && s[i][j + 1] == 'L') work(1, i, j + 1, a);
  } else {
    if (s[i][j] == 'U' && s[i][j + 1] == 'U') {
      ++a[0].x;
      a[a[0].x] = {i, j};
      s[i][j] = s[i + 1][j] = 'L';
      s[i][j + 1] = s[i + 1][j + 1] = 'R';
    }
    if (s[i][j] == 'L' && s[i + 1][j] == 'L') return;
    if (s[i][j] == 'L' && s[i + 1][j] == 'U') work(0, i + 1, j, a);
    if (s[i][j] == 'U' && s[i][j + 1] == 'L') {
      work(1, i, j + 1, a);
      ++a[0].x;
      a[a[0].x] = {i, j};
      s[i][j] = s[i + 1][j] = 'L';
      s[i][j + 1] = s[i + 1][j + 1] = 'R';
    }
  }
}
void solve(arr a[]) {
  if (m % 2 == 1) {
    for (int i = 1; i < n; i++)
      for (int j = 0; j < m - 1; j++) {
        if (s[i][j] == 'U' && s[i][j + 1] == 'U') continue;
        if (s[i][j] == 'L' && s[i + 1][j] == 'L') {
          ++a[0].x;
          a[a[0].x] = {i, j};
          s[i][j] = s[i][j + 1] = 'U';
          s[i + 1][j] = s[i + 1][j + 1] = 'D';
        }
        if (s[i][j] == 'L' && s[i + 1][j] == 'U') {
          work(0, i + 1, j, a);
          ++a[0].x;
          a[a[0].x] = {i, j};
          s[i][j] = s[i][j + 1] = 'U';
          s[i + 1][j] = s[i + 1][j + 1] = 'D';
        }
        if (s[i][j] == 'U' && s[i][j + 1] == 'L') work(1, i, j + 1, a);
      }
  } else {
    for (int i = 1; i < n; i++)
      for (int j = 0; j < m - 1; j++) {
        if (s[i][j] == 'U' && s[i][j + 1] == 'U') {
          ++a[0].x;
          a[a[0].x] = {i, j};
          s[i][j] = s[i + 1][j] = 'L';
          s[i][j + 1] = s[i + 1][j + 1] = 'R';
        }
        if (s[i][j] == 'L' && s[i + 1][j] == 'L') continue;
        if (s[i][j] == 'L' && s[i + 1][j] == 'U') work(0, i + 1, j, a);
        if (s[i][j] == 'U' && s[i][j + 1] == 'L') {
          work(1, i, j + 1, a);
          ++a[0].x;
          a[a[0].x] = {i, j};
          s[i][j] = s[i + 1][j] = 'L';
          s[i][j + 1] = s[i + 1][j + 1] = 'R';
        }
      }
  }
}
int main() {
  scanf("%d%d", &n, &m);
  for (int i = 1; i <= n; i++) {
    int len = 0;
    while (!len) scanf("%s", s[i]), len = strlen(s[i]);
  }
  solve(ans1);
  for (int i = 1; i <= n; i++) {
    int len = 0;
    while (!len) scanf("%s", s[i]), len = strlen(s[i]);
  }
  solve(ans2);
  int len1 = ans1[0].x, len2 = ans2[0].x;
  printf("%d\n", len1 + len2);
  for (int i = 1; i <= len1; i++) printf("%d %d\n", ans1[i].x, ans1[i].y + 1);
  for (int i = len2; i; i--) printf("%d %d\n", ans2[i].x, ans2[i].y + 1);
}
