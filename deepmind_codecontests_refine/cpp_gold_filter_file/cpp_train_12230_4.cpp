#include <bits/stdc++.h>
using namespace std;
const int M = 105;
const int Q = 1e9 + 7;
vector<pair<pair<int, int>, int> > g;
int dp[M][M], pr[M][M];
void print(int l, int r) {
  if (l > r) return;
  print(l + 1, pr[l][r]);
  printf("%d ", l);
  print(pr[l][r] + 1, r);
}
int main() {
  srand(time(NULL));
  int i, n, c, d, k, tq, j, s, f, t;
  char s1[10];
  bool ok;
  scanf("%d%d", &n, &c);
  for (i = 0; i < c; i++) {
    scanf("%d%d %s", &s, &f, s1);
    if (s == f) {
      printf("IMPOSSIBLE");
      return 0;
    }
    if (s1[0] == 'L') {
      g.push_back(make_pair(make_pair(s, f), 0));
    } else
      g.push_back(make_pair(make_pair(s, f), 1));
  }
  for (i = 1; i <= n + 2; i++)
    for (j = 1; j <= i; j++) {
      dp[i][j] = true;
      pr[i][j] = i;
    }
  for (d = 2; d <= n; d++)
    for (i = 1; i <= n - d + 1; i++) {
      j = i + d - 1;
      for (t = i; t <= j; t++) {
        if (!dp[i + 1][t] || !dp[t + 1][j]) continue;
        ok = true;
        for (k = 0; k < (int)g.size(); k++) {
          s = g[k].first.first;
          f = g[k].first.second;
          tq = g[k].second;
          if (s == i) {
            if (tq == 0) {
              if (!(i + 1 <= f && f <= t)) ok = false;
            } else {
              if (!(t + 1 <= f && f <= j)) ok = false;
            }
          }
          if (i + 1 <= s && s <= t && (f == i || (t + 1 <= f && f <= j)))
            ok = false;
          if (t + 1 <= s && s <= j && (f == i || (i + 1 <= f && f <= t)))
            ok = false;
        }
        if (ok) {
          dp[i][j] = true;
          pr[i][j] = t;
          break;
        }
      }
    }
  if (!dp[1][n]) {
    printf("IMPOSSIBLE");
    return 0;
  }
  print(1, n);
  return 0;
}
