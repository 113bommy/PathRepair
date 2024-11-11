#include <bits/stdc++.h>
using namespace std;
#pragma comment(linker, "/STACK:1024000000,1024000000")
int _MAX(int a, int b) { return a > b ? a : b; }
int _MIN(int a, int b) { return a > b ? b : a; }
int Scan() {
  int res = 0, flag = 0;
  char ch;
  if ((ch = getchar()) == '-')
    flag = 1;
  else if (ch >= '0' && ch <= '9')
    res = ch - '0';
  while ((ch = getchar()) >= '0' && ch <= '9') res = res * 10 + (ch - '0');
  return flag ? -res : res;
}
void Out(int a) {
  if (a < 0) {
    putchar('-');
    a = -a;
  }
  if (a >= 10) Out(a / 10);
  putchar(a % 10 + '0');
}
int n, a[1005][3], sum[3], hack[3], cnt, dp[2][95][95][95], sco[6][2];
int cal(int x, int y, int z) {
  if (sco[x][0] > sco[x][1] || sco[y][0] > sco[y][1] || sco[z][0] > sco[z][1])
    return n - 1;
  if (sum[0] - hack[0] > sco[x][1] || sum[1] - hack[1] > sco[y][1] ||
      sum[2] - hack[2] > sco[z][1])
    return n - 1;
  if (sum[0] < sco[x][0] || sum[1] < sco[y][0] || sum[2] < sco[z][0])
    return n - 1;
  int h1 = min(sum[0] - sco[x][0], hack[0]);
  int h2 = min(sum[1] - sco[y][0], hack[1]);
  int h3 = min(sum[2] - sco[z][0], hack[2]);
  int mysco = (h1 + h2 + h3) * 100 +
              (a[1][0] != 0) * (x + 1) * 500 * (250 - abs(a[1][0])) / 250 +
              (a[1][1] != 0) * (y + 1) * 500 * (250 - abs(a[1][1])) / 250 +
              (a[1][2] != 0) * (z + 1) * 500 * (250 - abs(a[1][2])) / 250;
  int flag = 0, tot = 0;
  for (int(i) = (0); (i) <= (h1); ++(i))
    for (int(j) = (0); (j) <= (h2); ++(j))
      for (int(k) = (0); (k) <= (h3); ++(k)) dp[0][i][j][k] = 1000000000;
  dp[0][0][0][0] = 0;
  for (int(i) = (2); (i) <= (n); ++(i)) {
    int hesco = (a[i][0] != 0) * (x + 1) * 500 * (250 - abs(a[i][0])) / 250 +
                (a[i][1] != 0) * (y + 1) * 500 * (250 - abs(a[i][1])) / 250 +
                (a[i][2] != 0) * (z + 1) * 500 * (250 - abs(a[i][2])) / 250;
    if (a[i][0] >= 0 && a[i][1] >= 0 && a[i][2] >= 0) {
      if (hesco > mysco) tot++;
      continue;
    } else if (hesco <= mysco)
      continue;
    int wei = 0;
    for (int(j) = (0); (j) <= (2); ++(j)) {
      if (a[i][j] < 0)
        wei = wei * 2 + 1;
      else
        wei <<= 1;
    }
    for (int(q1) = (0); (q1) <= (h1); ++(q1))
      for (int(q2) = (0); (q2) <= (h2); ++(q2))
        for (int(q3) = (0); (q3) <= (h3); ++(q3))
          dp[flag ^ 1][q1][q2][q3] = 1000000000;
    for (int(q1) = (0); (q1) <= (h1); ++(q1))
      for (int(q2) = (0); (q2) <= (h2); ++(q2))
        for (int(q3) = (0); (q3) <= (h3); ++(q3)) {
          if (dp[flag][q1][q2][q3] > n) continue;
          for (int(j) = (0); (j) <= ((wei >> 2) & 1); ++(j))
            for (int(k) = (0); (k) <= ((wei >> 1) & 1); ++(k))
              for (int(l) = (0); (l) <= (wei & 1); ++(l)) {
                int shesco = (j == 0 && a[i][0]) * (x + 1) * 500 *
                                 (250 - abs(a[i][0])) / 250 +
                             (k == 0 && a[i][1]) * (y + 1) * 500 *
                                 (250 - abs(a[i][1])) / 250 +
                             (l == 0 && a[i][2]) * (z + 1) * 500 *
                                 (250 - abs(a[i][2])) / 250;
                if (shesco > mysco)
                  dp[flag ^ 1][q1 + j][q2 + k][q3 + l] =
                      min(dp[flag ^ 1][q1 + j][q2 + k][q3 + l],
                          dp[flag][q1][q2][q3] + 1);
                else
                  dp[flag ^ 1][q1 + j][q2 + k][q3 + l] =
                      min(dp[flag ^ 1][q1 + j][q2 + k][q3 + l],
                          dp[flag][q1][q2][q3]);
              }
        }
    flag ^= 1;
  }
  int ans = 1000000000;
  for (int(i) = (0); (i) <= (h1); ++(i))
    for (int(j) = (0); (j) <= (h2); ++(j))
      for (int(k) = (0); (k) <= (h3); ++(k)) ans = min(ans, dp[flag][i][j][k]);
  return ans + tot;
}
int main() {
  scanf("%d", &n);
  for (int(i) = (1); (i) <= (n); ++(i)) {
    scanf("%d%d%d", &a[i][0], &a[i][1], &a[i][2]);
    for (int(j) = (0); (j) <= (2); ++(j)) sum[j] += (a[i][j] != 0);
    if (i != 1)
      for (int(j) = (0); (j) <= (2); ++(j)) hack[j] += (a[i][j] < 0);
  }
  if (hack[1] + hack[2] + hack[0] >= 90) {
    puts("1");
    return 0;
  }
  int P = 1;
  for (int(i) = (0); (i) <= (4); ++(i))
    sco[i][0] = n / (2 * P) + 1, sco[i][1] = n / P, P *= 2;
  sco[5][0] = 0, sco[5][1] = n / 32;
  int ans = 1000000000;
  for (int(i) = (0); (i) <= (5); ++(i))
    for (int(j) = (0); (j) <= (5); ++(j))
      for (int(k) = (0); (k) <= (5); ++(k)) ans = min(ans, cal(i, j, k));
  printf("%d\n", ans + 1);
  return 0;
}
