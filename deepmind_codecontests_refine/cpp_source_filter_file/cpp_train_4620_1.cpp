#include <bits/stdc++.h>
using namespace std;
const int N = 1e5 + 7;
const int M = 4;
const int inf = 777777777;
const long long base = 1e18;
const double pi = acos(-1);
const double ep = 1e-9;
int a[4][4];
int dp[N * 4][4][4];
int x[N];
int n, q;
void read(int &x) {
  char c;
  for (c = getchar(); c > '9' || c < '0'; c = getchar())
    ;
  x = 0;
  for (; c >= '0' && c <= '9'; c = getchar()) x = x * 10 + c - '0';
}
void update(int i, int l, int r, int pos, int val) {
  if (l == pos && r == pos) {
    memset(dp[i], 0, sizeof(dp[i]));
    x[pos] = val;
    if (val == 0) {
      for (int j = (int)1; j < (int)M; j++) dp[i][j][j] = 1;
    } else
      dp[i][val][val] = 1;
    return;
  }
  int g = (l + r) >> 1, next = i << 1;
  if (pos <= g)
    update(next, l, g, pos, val);
  else
    update(next + 1, g + 1, r, pos, val);
  for (int u = (int)1; u < (int)M; u++)
    for (int v = (int)1; v < (int)M; v++) dp[i][u][v] = 0;
  for (int u1 = (int)1; u1 < (int)M; u1++) {
    for (int v1 = (int)1; v1 < (int)M; v1++) {
      if (a[u1][v1]) {
        for (int u = (int)1; u < (int)M; u++)
          for (int v = (int)1; v < (int)M; v++)
            dp[i][u][v] += (long long)dp[next][u][u1] * dp[next + 1][v1][v];
      }
    }
  }
  for (int u = (int)1; u < (int)M; u++)
    for (int v = (int)1; v < (int)M; v++) dp[i][u][v] %= inf;
}
int main() {
  read(n);
  read(q);
  for (int i = (int)1; i < (int)M; i++)
    for (int j = (int)1; j < (int)M; j++) read(a[i][j]);
  for (int i = (int)1; i < (int)n + 1; i++) update(1, 1, n, i, 0);
  int er = 0;
  while (q-- > 0) {
    int pos, val;
    read(pos);
    read(val);
    update(1, 1, n, pos, val);
    int ans = 0;
    for (int u = (int)1; u < (int)M; u++)
      for (int v = (int)1; v < (int)M; v++) ans = (ans + dp[1][u][v]) % inf;
    printf("%d\n", ans);
  }
}
