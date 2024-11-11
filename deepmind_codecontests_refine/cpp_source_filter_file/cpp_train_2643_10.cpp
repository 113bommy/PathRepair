#include <bits/stdc++.h>
using namespace std;
const int N = 51, K = 5001, MOD = 1e9 + 7;
int n, k, a, b, dp1[2][N][N][201], dp2[2][N][N][201], C[N][N];
void build() {
  C[0][0] = 1;
  for (int i = 1; i < N; i++) {
    C[i][0] = 1;
    for (int j = 1; j <= i; j++)
      C[i][j] = (C[i - 1][j - 1] + C[i - 1][j]) % MOD;
  }
}
inline int mul(int a, int b) {
  return (int)(((long long)a * (long long)b) % MOD);
}
pair<int, int> calc(int c, int x, int y, int ss) {
  int x2 = a - x, y2 = b - y;
  if (x == 0 && y == 0) return make_pair(0, 1);
  if (ss == 100) return make_pair(1e9, 0);
  int &r1 = dp1[c][x][y][ss];
  int &r2 = dp2[c][x][y][ss];
  if (r1 != -1) return make_pair(r1, r2);
  r1 = 1e9;
  r2 = 0;
  if (c == 0) {
    for (int i = 0; i <= x; i++) {
      for (int j = 0; j <= y; j++) {
        if (!i && !j) continue;
        if (i * 50 + j * 100 <= k) {
          pair<int, int> res = calc(c ^ 1, x - i, y - j, ss + 1);
          res.second = mul(res.second % MOD, mul(C[x][i], C[y][j]));
          if (res.first + 1 < r1)
            r1 = res.first + 1, r2 = res.second;
          else if (res.first + 1 == r1)
            r2 = (r2 + res.second) % MOD;
        }
      }
    }
  } else {
    for (int i = 0; i <= x2; i++) {
      for (int j = 0; j <= y2; j++) {
        if (!i && !j) continue;
        if (i * 50 + j * 100 <= k) {
          pair<int, int> res = calc(c ^ 1, x + i, y + j, ss + 1);
          res.second = mul(res.second % MOD, mul(C[x2][i], C[y2][j]));
          if (res.first + 1 < r1)
            r1 = res.first + 1, r2 = res.second;
          else if (res.first + 1 == r1)
            r2 = (r2 + res.second) % MOD;
        }
      }
    }
  }
  return make_pair(r1, r2);
}
int main() {
  std::ios::sync_with_stdio(false);
  build();
  scanf("%d%d", &n, &k);
  a = 0, b = 0;
  for (int i = 0, x; i < n; i++) {
    scanf("%d", &x);
    if (x == 50)
      a++;
    else
      b++;
  }
  memset(dp1, -1, sizeof(dp1));
  memset(dp2, -1, sizeof(dp2));
  pair<int, int> ans = calc(0, a, b, 0);
  if (ans.first >= 1e9)
    puts("-1\n0");
  else
    printf("%d\n%d\n", ans.first, ans.second);
  return 0;
}
