#include <bits/stdc++.h>
#pragma warning(disable : 4996)
using namespace std;
int n, s, m, k;
const int bign = 1533;
int a[bign];
int l[bign], r[bign], p[bign];
int dp[bign][bign];
int nn;
int stdseg[bign];
int b[bign];
int maxj[bign];
int bn;
const int INF = 3 * bign;
int mq[bign];
bool cmp(const int& a1, const int& b1) { return l[a1] < l[b1]; }
int main() {
  scanf("%d%d%d%d", &n, &s, &m, &k);
  for (int i = 1; i <= n; i++) {
    scanf("%d", a + i);
    b[i - 1] = a[i];
  }
  sort(b, b + n);
  bn = unique(b, b + n) - b;
  b[bn++] = (1e9) + 10;
  for (int i = 0; i < s; i++) {
    p[i] = i;
    scanf("%d%d", l + i, r + i);
  }
  sort(p, p + s, cmp);
  stdseg[nn++] = p[0];
  for (int i = 1; i < s; i++) {
    while (nn && l[stdseg[nn - 1]] == l[p[i]] && r[stdseg[nn - 1]] <= r[p[i]]) {
      nn--;
    }
    if (!nn || r[p[i]] > r[stdseg[nn - 1]]) {
      stdseg[nn++] = p[i];
    }
  }
  int b1 = 0;
  int e1 = bn - 1;
  while (b1 <= e1) {
    int mid = (b1 + e1) >> 1;
    int nowb = b[mid];
    maxj[0] = 0;
    int mfront = 0, mtail = 0;
    for (int i = 1; i <= m; i++) {
      maxj[i] = -INF;
    }
    for (int i = 0; i < nn; i++) {
      for (int j = 0; j <= m; j++) dp[i][j] = -INF;
      while (mfront < mtail) {
        int u = mq[mfront];
        if (r[stdseg[u]] >= l[stdseg[i]]) {
          break;
        }
        for (int j = 1; j <= min(i, m); j++) {
          if (dp[u][j] > maxj[j]) {
            maxj[j] = dp[u][j];
          }
        }
        mfront++;
      }
      int mcnt = 0;
      for (int j = l[stdseg[i]]; j <= r[stdseg[i]]; j++) {
        if (a[j] < nowb) mcnt++;
      }
      for (int j = 0; j <= min(mfront, m); j++) {
        if (maxj[j] > -INF) dp[i][j + 1] = maxj[j] + mcnt;
      }
      if (mfront < mtail) {
        int crossu = mq[mfront];
        int ucnt = 0;
        for (int j = r[stdseg[crossu]] + 1; j <= r[stdseg[i]]; j++) {
          if (a[j] < nowb) ucnt++;
        }
        for (int j = 1; j <= min(mfront + 1, m); j++) {
          if (dp[crossu][j] > -INF) {
            dp[i][j + 1] = max(dp[crossu][j] + ucnt, dp[i][j + 1]);
          }
        }
      }
      mq[mtail++] = i;
    }
    while (mfront < mtail) {
      int u = mq[mfront++];
      for (int j = 1; j <= m; j++) {
        if (dp[u][j] > maxj[j]) {
          maxj[j] = dp[u][j];
        }
      }
    }
    int tmax = 0;
    for (int i = 1; i <= m; i++) {
      tmax = max(maxj[i], tmax);
    }
    if (tmax >= k) {
      e1 = mid - 1;
    } else {
      b1 = mid + 1;
    }
  }
  if (e1 == bn - 1)
    printf("-1\n");
  else
    printf("%d\n", b[e1]);
}
