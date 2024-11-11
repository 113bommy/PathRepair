#include <bits/stdc++.h>
using namespace std;
int dp[2][260][1 << 16];
bool f[2][260][1 << 16];
int r[20], b[20];
char col[20];
struct node {
  bool isrednull;
  int other, mask;
  node(bool isrednull, int other, int mask)
      : isrednull(isrednull), other(other), mask(mask) {}
};
int main() {
  memset(dp, 0x7F, sizeof(dp));
  int n;
  scanf("%d", &n);
  int numr = 0, numb = 0;
  for (int i = 1; i <= n; i++) {
    char s[10];
    scanf("%s", s);
    col[i] = s[0];
    scanf("%d %d", &r[i], &b[i]);
    if (r[i] > n) {
      numr += r[i] - n;
      r[i] = n;
    }
    if (b[i] > n) {
      numb += b[i] - n;
      b[i] = n;
    }
  }
  queue<node> q;
  f[1][0][0] = 1;
  dp[1][0][0] = 0;
  q.push(node(1, 0, 0));
  while (!q.empty()) {
    bool isrednull = q.front().isrednull;
    int R = 0, B = 0;
    int other = q.front().other;
    if (isrednull)
      B = other;
    else
      R = other;
    int mask = q.front().mask;
    q.pop();
    int At = 0, Bt = 0;
    for (int i = 1; i <= n; i++)
      if (mask & (1 << i - 1)) {
        if (col[i] == 'R')
          At++;
        else
          Bt++;
      }
    for (int i = 1; i <= n; i++) {
      if (mask & (1 << i - 1)) continue;
      int needR = max(0, r[i] - At);
      int needB = max(0, b[i] - Bt);
      int pmask = mask | (1 << i - 1);
      int step = max(needB - B, needR - R);
      int pB = B + step;
      int pR = R + step;
      pB -= needB;
      pR -= needR;
      int pisrednull, pother;
      if (pR == 0) {
        pisrednull = 1;
        pother = pB;
      } else {
        pisrednull = 0;
        pother = pR;
      }
      dp[pisrednull][pother][pmask] = min(
          dp[pisrednull][pother][pmask], dp[isrednull][other][mask] + step + 1);
      if (!f[pisrednull][pother][pmask]) {
        q.push(node(pisrednull, pother, pmask));
        f[pisrednull][pother][pmask] = 1;
      }
    }
  }
  int ans = INT_MAX;
  for (int i = 0; i < 2; i++)
    for (int j = 0; j <= n * n; j++) {
      int ret = dp[i][j][(1 << n) - 1];
      if (ret == 0x7F7F7F7F) continue;
      int pnumb = numb;
      int pnumr = numr;
      if (i == 0)
        pnumr -= j;
      else
        pnumb -= j;
      ans = min(ans, ret + max(pnumb, pnumr));
    }
  printf("%d\n", ans);
  return 0;
}
