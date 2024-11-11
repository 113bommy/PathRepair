#include <bits/stdc++.h>
using namespace std;
const int MOD = 1000000007;
int n, m, k;
typedef struct State {
  int len, cntlast, ways;
  State(int len, int cntlast, int ways)
      : len(len), cntlast(cntlast), ways(ways) {}
} State;
bool operator<(const State &a, const State &b) {
  if (a.len != b.len) return a.len < b.len;
  if (a.cntlast != b.cntlast) return a.cntlast < b.cntlast;
  if (a.ways != b.ways) return a.ways < b.ways;
  return false;
}
map<State, long long> dp[2];
int choose[101][101];
void run(int casenr) {
  for (int i = (0); i <= (100); ++i) {
    choose[i][0] = choose[i][i] = 1;
    for (int j = (1); j < (i); ++j) {
      choose[i][j] = choose[i - 1][j - 1] + choose[i - 1][j];
      if (choose[i][j] >= 101) choose[i][j] = 101;
    }
  }
  scanf("%d%d%d", &n, &m, &k);
  int at = 0;
  for (int i = (1); i <= (n); ++i) dp[1 - at][State(i, i, 1)]++;
  long long ret = 0;
  for (int mm = (2); mm <= (m); ++mm) {
    at = 1 - at;
    dp[1 - at].clear();
    for (map<State, long long>::iterator it = dp[at].begin();
         it != dp[at].end(); ++it) {
      int len = it->first.len, cntlast = it->first.cntlast,
          ways = it->first.ways;
      if (len + cntlast <= n) {
        ret += (m - mm + 1) * it->second;
      }
      for (int curcnt = (cntlast + 1); curcnt <= (n - len); ++curcnt) {
        int nlen = len + curcnt, ncntlast = curcnt - cntlast,
            nways = ways * choose[curcnt - 1][cntlast - 1];
        if (nways > k) continue;
        dp[1 - at][State(nlen, ncntlast, nways)] += it->second;
      }
    }
  }
  ret %= MOD;
  cout << ret << endl;
}
int main() {
  run(1);
  return 0;
}
