#include <bits/stdc++.h>
using namespace std;
int IN() {
  int c, f, x;
  while (!isdigit(c = getchar()) && c != '-')
    ;
  c == '-' ? (f = 1, x = 0) : (f = 0, x = c - '0');
  while (isdigit(c = getchar())) x = (x << 1) + (x << 3) + c - '0';
  return !f ? x : -x;
}
const int N = 120 + 19;
int A[N][5], cnt[5], val[5];
int n, l, r, m, res;
int cal(int x) {
  int res = 0;
  for (int i = 0; i < 5; i++)
    if (~A[x][i]) {
      res += val[i] - val[i] * A[x][i] / 250;
    }
  return res;
}
bool check(int x) {
  memset(cnt, 0, sizeof(cnt));
  for (int i = 1; i < n + 1; i++) {
    for (int j = 0; j < 5; j++)
      if (~A[i][j]) cnt[j]++;
  }
  for (int i = 0; i < 5; i++) {
    if (~A[1][i] && ~A[2][i] && A[1][i] > A[2][i]) cnt[i] += x;
  }
  for (int i = 0; i < 5; i++) {
    if (32ll * cnt[i] <= n + x)
      val[i] = 3000;
    else if (16ll * cnt[i] <= n + x)
      val[i] = 2500;
    else if (8ll * cnt[i] <= n + x)
      val[i] = 2000;
    else if (4ll * cnt[i] <= n + x)
      val[i] = 1500;
    else if (2ll * cnt[i] <= n + x)
      val[i] = 1000;
    else
      val[i] = 500;
  }
  return cal(1) > cal(2);
}
int main() {
  n = IN();
  for (int i = 1; i < n + 1; i++)
    for (int j = 0; j < 5; j++) A[i][j] = IN();
  for (int i = 0; i < 100 * n + 1; i++) {
    if (check(i)) {
      printf("%d\n", i);
      return 0;
    }
  }
  printf("%d\n", res);
}
