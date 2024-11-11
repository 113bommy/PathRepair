#include <bits/stdc++.h>
using namespace std;
const int INF = 0x3f3f3f3f;
const int MAXN = 80;
int n, k, s;
int q[MAXN * 2];
int dp1[2][MAXN][2 * MAXN * MAXN];
int dp2[2][MAXN][2 * MAXN * MAXN];
int main() {
  scanf("%d%d%d", &n, &k, &s);
  for (int i = (0); i < (n); i++) scanf("%d", &q[i]);
  int cnt = min(k, n - k);
  for (int i = (0); i < (2); i++)
    for (int j = (1); j < (MAXN); j++)
      for (int t = (0); t < (2 * MAXN * MAXN); t++) dp1[i][j][t] = -INF;
  int(*cur)[MAXN * MAXN * 2] = dp1[0];
  int(*nxt)[MAXN * MAXN * 2] = dp1[1];
  int pp = 2 * MAXN * MAXN;
  cur[0][0] = 0;
  for (int i = (k)-1; i >= (0); i--) {
    cur[0][0] = 0;
    for (int j = (1); j < (cnt + 1); j++)
      for (int t = (0); t < (pp); t++) {
        if (t < k - 1 - i)
          nxt[j][t] = cur[j][t];
        else
          nxt[j][t] = max(cur[j][t], cur[j - 1][t - k + i + 1] + q[i]);
      }
    swap(cur, nxt);
  }
  int(*a)[MAXN * MAXN * 2] = cur;
  cur = dp2[0];
  nxt = dp2[1];
  for (int i = (0); i < (2); i++)
    for (int j = (1); j < (MAXN); j++)
      for (int t = (0); t < (2 * MAXN * MAXN); t++) dp2[i][j][t] = INF;
  cur[0][0] = 0;
  for (int i = (k); i < (n); i++) {
    cur[0][0] = 0;
    for (int j = (1); j < (cnt + 1); j++)
      for (int t = 0; t < pp; t++) {
        if (t < i - k)
          nxt[j][t] = cur[j][t];
        else
          nxt[j][t] = min(cur[j][t], cur[j - 1][t + k - i] + q[i]);
      }
    swap(cur, nxt);
  }
  int(*b)[MAXN * MAXN * 2] = cur;
  int ans = 0;
  for (int i = (1); i < (cnt + 1); i++)
    for (int j = (1); j < (pp); j++) {
      a[i][j] = max(a[i][j], a[i][j - 1]);
    }
  for (int i = (1); i < (cnt + 1); i++)
    for (int j = (1); j < (pp); j++) {
      b[i][j] = min(b[i][j], b[i][j - 1]);
    }
  for (int i = (1); i < (cnt + 1); i++) {
    int tmp = s - i;
    for (int j = (0); j < (pp); j++) {
      if (tmp - j >= 0)
        ans = max(ans, a[i][j] - b[i][min(tmp - j, pp - 1)]);
      else
        break;
    }
  }
  int res = 0;
  for (int i = (0); i < (k); i++) res += q[i];
  cout << res - ans << endl;
}
