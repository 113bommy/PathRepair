#include <bits/stdc++.h>
char in[110];
int n, len, rcd[100][210][51][2];
int Max(int a, int b) { return a < b ? b : a; }
int dp(int flag, int pos, int res, int dir) {
  if (flag == len && res == 0) {
    return pos >= 100 ? pos - 100 : 100 - pos;
  } else if (flag == len && res)
    return 0;
  if (rcd[flag][pos][res][dir] != -1) return rcd[flag][pos][res][dir];
  int my_max = 0;
  if (in[flag] == 'F') {
    my_max = Max(my_max, dp(flag + 1, pos + (dir == 1 ? 1 : -1), res, dir));
    in[flag] = 'T';
    if (res) my_max = Max(my_max, dp(flag, pos, res - 1, 1 ^ dir));
    in[flag] = 'F';
  } else if (in[flag] == 'T') {
    my_max = Max(my_max, dp(flag + 1, pos, res, 1 ^ dir));
    in[flag] = 'F';
    if (res) my_max = Max(my_max, dp(flag, pos, res - 1, dir));
    in[flag] = 'T';
  }
  return rcd[flag][pos][res][dir] = my_max;
}
int main() {
  scanf("%s%d", in, &n);
  len = strlen(in);
  for (int i = 0; i < 100; i++) {
    for (int j = 0; j < 210; j++) {
      for (int k = 0; k < 51; k++) {
        for (int l = 0; l < 2; l++) {
          rcd[i][j][k][l] = -1;
        }
      }
    }
  }
  int ans = dp(0, 100, n, 1);
  printf("%d\n", ans);
}
