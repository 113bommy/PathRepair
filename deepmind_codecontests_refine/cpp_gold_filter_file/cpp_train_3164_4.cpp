#include <bits/stdc++.h>
char mp[2222][2222];
int ans[2222][2222];
bool flag[1010][1010][4];
int h, w, k;
bool AC() {
  int cnt1 = 0, cnt2 = 0;
  for (int i = 1; i <= 2 * h - 1; i++) {
    int len = strlen(mp[i] + 1);
    for (int j = 1; j <= len; j++) {
      cnt1++;
      if (mp[i][j] == 'E') cnt2++;
    }
  }
  return (1.0 * cnt2) >= cnt1 * 0.75;
}
void AC1() {
  ans[1][1] = 0;
  for (int j = 2; j <= w; j++) {
    if (flag[1][j][1])
      ans[1][j] = ans[1][j - 1];
    else
      ans[1][j] = 1 - ans[1][j - 1];
  }
  for (int i = 2; i <= h; i++) {
    ans[i][1] = 0;
    for (int j = 2; j <= w; j++) {
      if (flag[i][j][1])
        ans[i][j] = ans[i][j - 1];
      else
        ans[i][j] = 1 - ans[i][j - 1];
    }
    int cnt = 0;
    for (int j = 1; j <= w; j++) {
      if (flag[i][j][2] && ans[i][j] == ans[i - 1][j]) cnt++;
      if (!flag[i][j][2] && ans[i][j] != ans[i - 1][j]) cnt++;
    }
    if (w - cnt > cnt) {
      for (int j = 1; j <= w; j++) {
        ans[i][j] = 1 - ans[i][j];
      }
    }
  }
}
void AC2() {
  ans[1][1] = 0;
  for (int i = 2; i <= h; i++) {
    if (flag[i][1][2])
      ans[i][1] = ans[i - 1][1];
    else
      ans[i][1] = 1 - ans[i - 1][1];
  }
  for (int j = 2; j <= w; j++) {
    ans[1][j] = 0;
    for (int i = 2; i <= h; i++) {
      if (flag[i][j][2])
        ans[i][j] = ans[i - 1][j];
      else
        ans[i][j] = 1 - ans[i - 1][j];
    }
    int cnt = 0;
    for (int i = 1; i <= h; i++) {
      if (flag[i][j][1] && ans[i][j] == ans[i][j - 1]) cnt++;
      if (!flag[i][j][1] && ans[i][j] != ans[i][j - 1]) cnt++;
    }
    if (h - cnt > cnt) {
      for (int i = 1; i <= h; i++) {
        ans[i][j] = 1 - ans[i][j];
      }
    }
  }
}
int main() {
  scanf("%d%d%d", &h, &w, &k);
  for (int i = 1; i <= 2 * h - 1; i++) {
    scanf("%s", mp[i] + 1);
  }
  for (int i = 1; i <= 2 * h - 1; i += 2) {
    for (int j = 1; j < w; j++) {
      if (mp[i][j] == 'E') {
        flag[i / 2 + 1][j][0] = true;
        flag[i / 2 + 1][j + 1][1] = true;
      }
    }
  }
  for (int i = 2; i <= 2 * h - 1; i += 2) {
    for (int j = 1; j <= w; j++) {
      if (mp[i][j] == 'E') {
        flag[i / 2][j][3] = true;
        flag[i / 2 + 1][j][2] = true;
      }
    }
  }
  if (k == 1) {
    if (!AC())
      printf("NO\n");
    else {
      printf("YES\n");
      for (int i = 1; i <= h; i++) {
        for (int j = 1; j <= w; j++) {
          printf("1 ");
        }
        puts("");
      }
    }
    return 0;
  }
  printf("YES\n");
  if (h <= w) {
    AC1();
  } else {
    AC2();
  }
  for (int i = 1; i <= h; i++) {
    for (int j = 1; j <= w; j++) {
      printf("%d ", ans[i][j] + 1);
    }
    puts("");
  }
}
