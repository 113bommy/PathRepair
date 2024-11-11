#include <bits/stdc++.h>
int dp[200][3][3];
int fg[3000];
int debug = 0;
int mp[200][2];
int get_grundy(int n) {
  int i, j, k;
  int all, up, down;
  k = 0;
  for (i = 0; i < n; i++) {
    if (mp[i][0] && mp[i][1]) continue;
    all = up = down = 0;
    if (!mp[i][0] && !mp[i][1])
      all++;
    else if (!mp[i][0])
      up = 1;
    else if (!mp[i][1])
      up = 2;
    while (i < n) {
      i++;
      if (i >= n) break;
      if (mp[i][0] || mp[i][1]) {
        if (mp[i][0] && mp[i][1]) break;
        if (!mp[i][0]) down = 1;
        if (!mp[i][1]) down = 2;
        break;
      } else {
        all++;
      }
    }
    if (debug) printf("%d %d %d\n", all, up, down);
    k ^= dp[all][up][down];
  }
  return k;
}
int main() {
  int i, j, k, l, m, n;
  int all, up, down;
  int a, b;
  for (all = 0; all < 103; all++)
    for (up = 0; up < 3; up++)
      for (down = 0; down < 3; down++) {
        for (i = 0; i < 3000; i++) fg[i] = 0;
        n = all + 2;
        for (i = 0; i < n; i++)
          for (j = 0; j < 2; j++) mp[i][j] = 0;
        if (up != 1) mp[0][0] = 1;
        if (up != 2) mp[0][1] = 1;
        if (down != 1) mp[n - 1][0] = 1;
        if (down != 2) mp[n - 1][1] = 1;
        for (i = 0; i < n; i++)
          for (j = 0; j < 2; j++)
            if (mp[i][j] == 0) {
              mp[i][j]++;
              if (i - 1 >= 0) mp[i - 1][1 - j]++;
              mp[i][1 - j]++;
              if (i + 1 < n) mp[i + 1][1 - j]++;
              fg[get_grundy(n)]++;
              mp[i][j]--;
              if (i - 1 >= 0) mp[i - 1][1 - j]--;
              mp[i][1 - j]--;
              if (i + 1 < n) mp[i + 1][1 - j]--;
            }
        for (i = 0; i < 3000; i++)
          if (!fg[i]) break;
        dp[all][up][down] = i;
      }
  scanf("%d%d", &n, &m);
  for (i = 0; i < n; i++)
    for (j = 0; j < 2; j++) mp[i][j] = 0;
  while (m--) {
    scanf("%d%d", &i, &j);
    i--;
    j--;
    mp[i][j] = 1;
    if (i - 1 >= 0) mp[i - 1][1 - j] = 1;
    mp[i][1 - j] = 1;
    if (i + 1 < n) mp[i + 1][1 - j] = 1;
  }
  debug = 0;
  k = get_grundy(n);
  if (k == 0)
    puts("LOSE");
  else
    puts("WIN");
  return 0;
}
