#include <bits/stdc++.h>
using namespace std;
const long double eps = 1e-16, inf = 1e9 + 9;
struct db {
  long double vl;
  bool operator<(const db &temp) const { return vl < temp.vl - eps; }
};
map<db, long long> hs[44][44];
map<db, long long> ha[44][44];
map<db, long long>::iterator it, ht;
int r, c;
long double lose[66][66], ma[66][66], mi[66][66];
long double dp[44][44][44][44], cc[66][66];
char str[66];
int main() {
  scanf("%d%d", &r, &c);
  scanf("%s", str);
  int i, j, s, p, q;
  for (i = 0; i <= 2 * (r + c); i++)
    for (j = 0; j <= i; j++) {
      if (j == 0 || j == i)
        cc[i][j] = 1;
      else
        cc[i][j] = (cc[i - 1][j] + cc[i - 1][j - 1]);
    }
  memset(dp, 0, sizeof(dp));
  dp[0][0][0][0] = 1;
  for (i = 0; i < r; i++)
    for (j = 0; j <= 2 * c && i + j <= r + c; j++)
      for (s = 0; s < r; s++)
        for (p = 0; j + p <= 2 * c && s + p <= r + c; p++) {
          if (dp[i][j][s][p] == 0) continue;
          dp[i + 1][j][s][p] += dp[i][j][s][p] * (2. * r - i - s) /
                                (2. * r + 2. * c - i - j - s - p);
          if (j + 1 <= 2 * c)
            dp[i][j + 1][s][p] += dp[i][j][s][p] * (2. * c - j - p) /
                                  (2. * r + 2. * c - i - j - s - p);
          dp[i][j][s + 1][p] += dp[i][j][s][p] * (2. * r - i - s) /
                                (2. * r + 2. * c - i - j - s - p);
          if (p + 1 <= 2 * c)
            dp[i][j][s][p + 1] += dp[i][j][s][p] * (2. * c - j - p) /
                                  (2. * r + 2. * c - i - j - s - p);
        }
  for (j = 0; j <= 2 * c; j++)
    for (s = 0; s < r; s++)
      for (p = 0; p <= 2 * c; p++) {
        lose[r + j][s + p] += dp[r][j][s][p];
      }
  for (i = 0; i <= r + c; i++)
    for (j = 0; j <= r + c; j++) {
      if (i >= 1) lose[i][j] /= cc[i + j - 1][i - 1];
    }
  for (i = 0; i <= r + c; i++)
    for (j = 0; j <= r + c; j++) {
      ma[i][j] = -inf;
      mi[i][j] = inf;
    }
  ma[0][0] = mi[0][0] = 0;
  for (i = 0; i <= r + c; i++)
    for (j = 0; j <= r + c; j++) {
      if (i - 1 >= 0) {
        ma[i][j] = max(ma[i][j], ma[i - 1][j] + lose[i][j]);
        mi[i][j] = min(mi[i][j], mi[i - 1][j] + lose[i][j]);
      }
      if (j - 1 >= 0) {
        ma[i][j] = max(ma[i][j], ma[i][j - 1]);
        mi[i][j] = min(mi[i][j], mi[i][j - 1]);
      }
    }
  db now;
  now.vl = 0;
  ha[r + c][r + c][now];
  long double low, high;
  low = -inf;
  high = inf;
  for (i = r + c; i >= 0; i--)
    for (j = r + c; j >= 0; j--) {
      for (it = ha[i][j].begin(); it != ha[i][j].end(); it++) {
        now = it->first;
        if (now.vl + mi[i][j] > 0.5 - eps) high = min(now.vl + mi[i][j], high);
        if (now.vl + ma[i][j] < 0.5 + eps) low = max(now.vl + ma[i][j], low);
        if (now.vl + mi[i][j] > 0.5 + eps || now.vl + ma[i][j] < 0.5 - eps)
          continue;
        if (i - 1 >= 0) {
          now.vl += lose[i][j];
          ha[i - 1][j][now];
        }
        now = it->first;
        if (j - 1 >= 0) ha[i][j - 1][now];
      }
    }
  memset(dp, 0, sizeof(dp));
  dp[0][0][0][0] = 1;
  for (i = 0; i < r; i++)
    for (j = 0; j <= 2 * c && i + j <= r + c; j++)
      for (s = 0; s < r; s++)
        for (p = 0; j + p <= 2 * c && s + p <= r + c; p++) {
          if (dp[i][j][s][p] == 0) continue;
          if (str[i + j + s + p] != 'B') {
            dp[i + 1][j][s][p] += dp[i][j][s][p] * (2. * r - i - s) /
                                  (2. * r + 2. * c - i - j - s - p);
            if (j + 1 <= 2 * c)
              dp[i][j + 1][s][p] += dp[i][j][s][p] * (2. * c - j - p) /
                                    (2. * r + 2. * c - i - j - s - p);
          }
          if (str[i + j + s + p] != 'A') {
            dp[i][j][s + 1][p] += dp[i][j][s][p] * (2. * r - i - s) /
                                  (2. * r + 2. * c - i - j - s - p);
            if (p + 1 <= 2 * c)
              dp[i][j][s][p + 1] += dp[i][j][s][p] * (2. * c - j - p) /
                                    (2. * r + 2. * c - i - j - s - p);
          }
        }
  memset(lose, 0, sizeof(lose));
  for (j = 0; j <= 2 * c; j++)
    for (s = 0; s < r; s++)
      for (p = 0; p <= 2 * c; p++) lose[r + j][s + p] += dp[r][j][s][p];
  int sa[66], sb[66];
  memset(sa, 0, sizeof(sa));
  memset(sb, 0, sizeof(sb));
  int maa = 0, mbb = 0;
  sa[0] = sb[0] = 0;
  for (i = 0; i < 2 * (r + c); i++) {
    if (str[i] == 'A')
      maa++;
    else if (str[i] == 'B')
      mbb++;
    sa[i + 1] = maa;
    sb[i + 1] = mbb;
  }
  for (i = 0; i <= r + c; i++)
    for (j = 0; j <= r + c; j++) {
      if (i + j == 0) continue;
      if (str[i + j - 1] == 'B') continue;
      int one = 0;
      if (str[i + j - 1] == '?') one++;
      if (i >= sa[i + j] + one && j >= sb[i + j])
        lose[i][j] /=
            cc[i - sa[i + j] + j - sb[i + j] - one][i - sa[i + j] - one];
    }
  for (i = 0; i <= r + c; i++)
    for (j = 0; j <= r + c; j++) ha[i][j].clear();
  now.vl = 0;
  ha[r + c][r + c][now] = 1;
  for (i = r + c; i >= 0; i--)
    for (j = r + c; j >= 0; j--) {
      for (it = ha[i][j].begin(); it != ha[i][j].end(); it++) {
        now = it->first;
        if (now.vl + ma[i][j] < low - eps) continue;
        if (now.vl + mi[i][j] > high + eps) continue;
        if (i - 1 >= 0 && str[i + j - 1] != 'B') {
          now.vl += lose[i][j];
          ha[i - 1][j][now] += it->second;
        }
        now = it->first;
        if (j - 1 >= 0 && str[i + j - 1] != 'A')
          ha[i][j - 1][now] += it->second;
      }
    }
  long long ans = 0;
  double ch[2];
  int nc;
  if (fabs(low - 0.5) < fabs(high - 0.5) - eps) {
    nc = 1;
    ch[0] = low;
  } else if (fabs(low - 0.5) > fabs(high - 0.5) + eps) {
    nc = 1;
    ch[0] = high;
  } else {
    nc = 2;
    ch[0] = low;
    ch[1] = high;
  }
  for (it = ha[0][0].begin(); it != ha[0][0].end(); it++) {
    now = it->first;
    for (j = 0; j < nc; j++) {
      if (fabs(now.vl - ch[j]) < eps) {
        ans += it->second;
        break;
      }
    }
  }
  printf("%lld\n", ans);
  return 0;
}
