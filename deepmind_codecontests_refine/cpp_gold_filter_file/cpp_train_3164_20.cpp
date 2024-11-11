#include <bits/stdc++.h>
using namespace std;
bool debug = false;
int n, m, k;
int dx[4] = {1, 0, -1, 0}, dy[4] = {0, 1, 0, -1};
long long ln, lk, lm;
int w, h;
char row[1005][1005], col[1005][1005];
int ans[1005][1005];
void ok() {
  puts("YES");
  for (int(i) = 0; (i) < (int)(h); (i)++) {
    for (int(j) = 0; (j) < (int)(w); (j)++) printf("%d ", ans[i][j]);
    puts("");
  }
  exit(0);
}
void err() {
  puts("NO");
  exit(0);
}
void drow() {
  for (int(i) = 0; (i) < (int)(h); (i)++) {
    ans[i][0] = 1;
    for (int j = 1; j < w; j++) {
      if (row[i][j - 1] == 'E')
        ans[i][j] = ans[i][j - 1];
      else
        ans[i][j] = 3 - ans[i][j - 1];
    }
    if (i == 0) continue;
    int ub = 0;
    for (int(j) = 0; (j) < (int)(w); (j)++) {
      if (col[i - 1][j] == 'E' && ans[i - 1][j] != ans[i][j]) ub++;
      if (col[i - 1][j] != 'E' && ans[i - 1][j] == ans[i][j]) ub++;
    }
    if (ub * 2 > w) {
      for (int(j) = 0; (j) < (int)(w); (j)++) ans[i][j] = 3 - ans[i][j];
    }
  }
}
void dcol() {
  for (int(j) = 0; (j) < (int)(w); (j)++) {
    ans[0][j] = 1;
    for (int i = 1; i < h; i++) {
      if (col[i - 1][j] == 'E')
        ans[i][j] = ans[i - 1][j];
      else
        ans[i][j] = 3 - ans[i - 1][j];
    }
    if (j == 0) continue;
    int ub = 0;
    for (int(i) = 0; (i) < (int)(h); (i)++) {
      if (row[i][j - 1] == 'E' && ans[i][j] != ans[i][j - 1]) ub++;
      if (row[i][j - 1] != 'E' && ans[i][j] == ans[i][j - 1]) ub++;
    }
    if (ub * 2 > h) {
      for (int(i) = 0; (i) < (int)(h); (i)++) ans[i][j] = 3 - ans[i][j];
    }
  }
}
int main() {
  scanf("%d%d%d", &h, &w, &k);
  int ub = 0;
  int tt = h * (w - 1) + (h - 1) * w;
  for (int(i) = 0; (i) < (int)(h + h - 1); (i)++) {
    if (i % 2 == 0) {
      scanf("%s", row[i / 2]);
      for (int j = 0; row[i / 2][j]; j++)
        if (row[i / 2][j] == 'N') ub++;
    } else {
      scanf("%s", col[i / 2]);
      for (int j = 0; col[i / 2][j]; j++)
        if (col[i / 2][j] == 'N') ub++;
    }
  }
  if (k == 1) {
    if (ub * 4 > tt)
      err();
    else {
      for (int(i) = 0; (i) < (int)(h); (i)++)
        for (int(j) = 0; (j) < (int)(w); (j)++) ans[i][j] = 1;
      ok();
    }
  } else {
    if (h <= w)
      drow();
    else
      dcol();
    ok();
  }
  return 0;
}
