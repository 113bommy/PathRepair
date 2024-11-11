#include <bits/stdc++.h>
using namespace std;
int n, t[5005][3], s[3], h[3], ans, minn, maxx, score[3], tag[3],
    dp[2][90][90][90], now, pre, my;
inline int read() {
  int f = 1, w = 0;
  char ch = 0;
  while (ch < '0' || ch > '9') {
    if (ch == '-') f = -1;
    ch = getchar();
  }
  while (ch >= '0' && ch <= '9')
    w = (w << 1) + (w << 3) + ch - '0', ch = getchar();
  return f * w;
}
inline int calc(int s, int p) { return p ? s / 250 * (250 - abs(p)) : 0; }
int sc(int x) {
  int ret = 0;
  for (int i = 0; i < 3; i++) ret += calc(score[i], t[x][i]);
  return ret;
}
int solve() {
  int ret = 0;
  memset(dp, 0, sizeof(dp)), now = 1, my = 0;
  for (int i = 0; i < 3; i++) my += tag[i] * 100 + calc(score[i], t[1][i]);
  for (int l = 2; l <= n; l++)
    if (sc(l) > my) {
      swap(now, pre), ++ret;
      for (int i = 0; i <= tag[0]; i++)
        for (int j = 0; j <= tag[1]; j++)
          for (int k = 0; k <= tag[2]; k++) dp[now][i][j][k] = dp[pre][i][j][k];
      for (int i = 0; i <= 1; i++)
        for (int j = 0; j <= 1; j++)
          for (int k = 0; k <= 1; k++) {
            if ((!i && t[l][0] >= 0) || (!j && t[l][1] >= 0) ||
                (!k && t[l][2] >= 0))
              continue;
            int sum = calc(score[0], t[l][0]) * i +
                      calc(score[1], t[l][1]) * j + calc(score[2], t[l][2]) * k;
            if (sum <= my)
              for (int I = i ^ 1; I <= tag[0]; I++)
                for (int J = j ^ 1; J <= tag[1]; J++)
                  for (int K = k ^ 1; K <= tag[2]; K++)
                    dp[now][I][J][K] =
                        max(dp[now][I][J][K],
                            dp[pre][I - (i ^ 1)][J - (j ^ 1)][K - (k ^ 1)] + 1);
          }
    }
  return ret - dp[now][tag[0]][tag[1]][tag[2]] + 1;
}
void dfs(int k) {
  if (k == 3) {
    ans = min(solve(), ans);
    return;
  }
  for (int i = 1; i <= 6; i++) {
    minn = i == 6 ? 0 : (n >> i) + 1, maxx = n >> i - 1;
    if (s[k] >= minn && s[k] - h[k] <= maxx)
      score[k] = 500 * i, tag[k] = min(h[k], s[k] - minn), dfs(k + 1);
  }
}
int main() {
  ans = n = read();
  for (int i = 1; i <= n; i++)
    for (int j = 0; j < 3; j++)
      t[i][j] = read(), s[j] += (t[i][j] != 0), h[j] += (t[i][j] < 0);
  if (h[0] + h[1] + h[2] >= 90) return puts("1"), 0;
  dfs(0), printf("%d\n", ans);
  return 0;
}
