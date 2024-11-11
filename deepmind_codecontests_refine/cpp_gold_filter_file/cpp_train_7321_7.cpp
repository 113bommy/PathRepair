#include <bits/stdc++.h>
using namespace std;
long long dp[100010][2][2];
const int INF = 1500000000;
struct node {
  int x, y, id;
};
node a[300010], b[100010];
node pre[100010][2][2];
bool cmp(const node &a, const node &b) { return a.y > b.y; }
set<int> mp;
int J, K, L;
long long get(long long num1, long long num2, int j, int k, int l, int pree) {
  if (num2 <= num1)
    return num1;
  else {
    pre[j][k][l].x = K;
    pre[j][k][l].y = L;
    if (pree != -1)
      pre[j][k][l].id = a[pree].id;
    else
      pre[j][k][l].id = -1;
    return num2;
  }
}
int main() {
  int n;
  while (scanf("%d", &n) == 1) {
    mp.clear();
    for (int i = 0; i < n; i++) {
      scanf("%d%d", &a[i].x, &a[i].y);
      a[i].id = i + 1;
      mp.insert(a[i].y);
    }
    int m;
    scanf("%d", &m);
    for (int i = 0; i < m; i++) {
      scanf("%d%d", &b[i].x, &b[i].y);
      b[i].id = i + 1;
      if (mp.find(b[i].y) == mp.end()) {
        a[n].x = INF;
        a[n++].y = b[i].y;
        mp.insert(b[i].y);
      }
      if (mp.find(b[i].y + 1) == mp.end()) {
        a[n].x = INF;
        a[n++].y = b[i].y + 1;
        mp.insert(b[i].y + 1);
      }
    }
    sort(a, a + n, cmp);
    sort(b, b + m, cmp);
    int pos = 0;
    memset(dp, -1, sizeof(dp));
    dp[0][0][0] = 0;
    for (int j = 0; j < m; j++) {
      while (pos < n && a[pos].y > b[j].y + 1) pos++;
      for (int k = 0; k < 2; k++)
        for (int l = 0; l < 2; l++) {
          J = j;
          K = k;
          L = l;
          if (dp[j][k][l] == -1) continue;
          if (k == 0 && b[j].x >= a[pos].x) {
            if (j != m - 1 && a[pos].y == b[j + 1].y + 1)
              dp[j + 1][1][l] = get(dp[j + 1][1][l], dp[j][k][l] + a[pos].x,
                                    j + 1, 1, l, pos);
            else if (j != m - 1 && a[pos + 1].y == b[j + 1].y + 1)
              dp[j + 1][l][0] = get(dp[j + 1][l][0], dp[j][k][l] + a[pos].x,
                                    j + 1, l, 0, pos);
            else
              dp[j + 1][0][0] = get(dp[j + 1][0][0], dp[j][k][l] + a[pos].x,
                                    j + 1, 0, 0, pos);
          }
          if (l == 0 && b[j].x >= a[pos + 1].x) {
            if (j != m - 1 && a[pos].y == b[j + 1].y + 1)
              dp[j + 1][k][1] = get(dp[j + 1][k][1], dp[j][k][l] + a[pos + 1].x,
                                    j + 1, k, 1, pos + 1);
            else if (j != m - 1 && a[pos + 1].y == b[j + 1].y + 1)
              dp[j + 1][1][0] = get(dp[j + 1][1][0], dp[j][k][l] + a[pos + 1].x,
                                    j + 1, 1, 0, pos + 1);
            else
              dp[j + 1][0][0] = get(dp[j + 1][0][0], dp[j][k][l] + a[pos + 1].x,
                                    j + 1, 0, 0, pos + 1);
          }
          if (j != m - 1 && a[pos].y == b[j + 1].y + 1)
            dp[j + 1][k][l] =
                get(dp[j + 1][k][l], dp[j][k][l], j + 1, k, l, -1);
          else if (j != m - 1 && a[pos + 1].y == b[j + 1].y + 1)
            dp[j + 1][l][0] =
                get(dp[j + 1][l][0], dp[j][k][l], j + 1, l, 0, -1);
          else
            dp[j + 1][0][0] =
                get(dp[j + 1][0][0], dp[j][k][l], j + 1, 0, 0, -1);
        }
    }
    long long ans = -1;
    int kk, ll;
    for (int k = 0; k < 2; k++)
      for (int l = 0; l < 2; l++) {
        if (dp[m][k][l] == -1) continue;
        if (dp[m][k][l] > ans) {
          kk = k;
          ll = l;
          ans = dp[m][k][l];
        }
      }
    int tkk = kk, tll = ll;
    printf("%I64d\n", ans);
    int cntt = 0;
    for (int i = m; i >= 1; i--) {
      int idd = pre[i][kk][ll].id;
      if (idd != -1) cntt++;
      int tkk = pre[i][kk][ll].x;
      int tll = pre[i][kk][ll].y;
      kk = tkk;
      ll = tll;
    }
    printf("%d\n", cntt);
    kk = tkk;
    ll = tll;
    for (int i = m; i >= 1; i--) {
      int idd = pre[i][kk][ll].id;
      if (idd != -1) printf("%d %d\n", b[i - 1].id, idd);
      int tkk = pre[i][kk][ll].x;
      int tll = pre[i][kk][ll].y;
      kk = tkk;
      ll = tll;
    }
  }
  return 0;
}
