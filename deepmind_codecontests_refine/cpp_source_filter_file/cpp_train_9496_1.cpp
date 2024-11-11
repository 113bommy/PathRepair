#include <bits/stdc++.h>
using namespace std;
int num[120][30];
int num2[120][30];
int num3[120][30];
int num4[120][30];
char ans[120];
char str[((20000) + 10)];
int sum, len;
int main() {
  int n, c;
  scanf("%d", &n);
  if (n == 1) {
    printf("? 1 1\n");
    fflush(stdout);
    scanf("%s", ans);
    printf("! %s\n", ans);
    fflush(stdout);
    return 0;
  } else if (n == 2) {
    printf("? 1 1\n");
    fflush(stdout);
    scanf("%s", ans);
    printf("? 2 2\n");
    fflush(stdout);
    scanf("%s", &ans[1]);
    printf("! %s\n", ans);
    fflush(stdout);
    return 0;
  }
  c = n;
  n = n / 2;
  printf("? 1 %d\n", n);
  fflush(stdout);
  sum = n * (n + 1) / 2;
  while (sum--) {
    scanf("%s", str);
    len = (int)strlen(str);
    for (int i = 0; i < len; ++i) ++num[len][str[i] - 'a'];
  }
  if (n != 1) {
    printf("? 2 %d\n", n);
    fflush(stdout);
    sum = n * (n - 1) / 2;
    while (sum--) {
      scanf("%s", str);
      len = (int)strlen(str);
      for (int i = 0; i < len; ++i) ++num2[len][str[i] - 'a'];
    }
    for (int i = 1; i <= n; ++i) {
      for (int j = 0; j < 26; ++j)
        if (num[i][j] != num2[i][j]) ans[i - 1] = 'a' + j;
      for (int j = 0; j < i; ++j) ++num2[i + 1][ans[j] - 'a'];
    }
  } else
    ans[0] = str[0];
  n = c;
  printf("? 1 %d\n", n);
  fflush(stdout);
  sum = n * (n + 1) / 2;
  while (sum--) {
    scanf("%s", str);
    len = (int)strlen(str);
    for (int i = 0; i < len; ++i) ++num3[len][str[i] - 'a'];
  }
  c = (n - 1) / 2;
  for (int i = 1; i <= c; ++i) {
    for (int j = 0; j < 26; ++j) num4[i][j] = num3[i + 1][j] - num3[i][j];
  }
  for (int i = 1; i <= c; ++i) {
    int x = -1, y = -1;
    for (int j = 0; j < 26; ++j) {
      if (num3[i][j] - i * num4[i][j] != 0) {
        if (x == -1)
          x = j;
        else
          y = j;
      }
    }
    if (y == -1) y = x;
    if (ans[i - 1] == x + 'a')
      ans[n - i] = y + 'a';
    else
      ans[n - i] = x + 'a';
    for (int j = i; j <= c; ++j) {
      num3[j][x] -= i;
      num3[j][y] -= i;
    }
  }
  if (n & 1) {
    for (int i = 1; i <= c; ++i)
      --num3[1][ans[i - 1] - 'a'], --num3[1][ans[n - i] - 'a'];
    for (int i = 0; i < 26; ++i) {
      if (num3[1][i] == 1) ans[c] = 'a' + i;
    }
  } else {
    int x = -1, y = -1;
    for (int i = 1; i <= c; ++i)
      --num3[1][ans[i - 1] - 'a'], --num3[1][ans[n - i] - 'a'];
    for (int i = 0; i < 26; ++i) {
      if (num3[1][i] == 2)
        x = y = i;
      else if (num3[1][i] == 1) {
        if (x == -1)
          x = i;
        else
          y = i;
      }
    }
    if (ans[c] == x + 'a')
      ans[c + 1] = y + 'a';
    else
      ans[c + 1] = x + 'a';
  }
  printf("! %s\n", ans);
  fflush(stdout);
  return 0;
}
