#include <bits/stdc++.h>
using namespace std;
const int MOD = 1000000007;
char s[5001];
int slen;
int minprints[5001][5002];
int ways[5001][5002];
inline void update(int si, int sj, int ti, int tj, int extra) {
  if ((ways[ti][tj] += ways[si][sj]) >= MOD) ways[ti][tj] -= MOD;
  if (minprints[ti][tj] == -1 || minprints[si][sj] + extra < minprints[ti][tj])
    minprints[ti][tj] = minprints[si][sj] + extra;
}
int nextzero[5001];
bool islowerequal(int a, int b, int len) {
  bool ret = true;
  while (len > 0) {
    int da = nextzero[a] - a, db = nextzero[b] - b;
    if (da >= len && db >= len) break;
    if (da != db) {
      ret = da < db;
      break;
    }
    a += da + 1;
    b += db + 1;
    len -= da + 1;
  }
  return ret;
}
void run() {
  scanf("%s", s);
  slen = strlen(s);
  nextzero[slen] = slen;
  for (int i = slen - 1; i >= 0; --i)
    nextzero[i] = s[i] == '0' ? i : nextzero[i + 1];
  memset(minprints, -1, sizeof(minprints));
  memset(ways, 0, sizeof(ways));
  ways[0][1] = 1;
  minprints[0][1] = 0;
  for (int i = (0); i < (slen); ++i)
    if (s[i] == '1')
      for (int j = (1); j <= (slen - i); ++j)
        if (minprints[i][j] != -1) {
          update(i, j, i, j + 1, 0);
          bool ok = i + 2 * j > slen || islowerequal(i, i + j, j);
          update(i, j, i + j, j + (ok ? 0 : 1), 1);
        }
  int totways = 0;
  for (int j = (1); j <= (slen); ++j)
    if ((totways += ways[slen][j]) >= MOD) totways -= MOD;
  int totminlen = INT_MAX;
  for (int j = (1); j <= (slen); ++j)
    if (minprints[slen][j] != -1) {
      int curminlen = 0;
      for (int i = (0); i < (j); ++i)
        curminlen = (curminlen * 2 + s[slen - j + i] - '0') % MOD;
      curminlen = (curminlen + minprints[slen][j]) % MOD;
      if (curminlen < totminlen && (totminlen == INT_MAX || j <= 20))
        totminlen = curminlen;
    }
  printf("%d\n%d\n", totways, totminlen);
}
int main() {
  run();
  return 0;
}
