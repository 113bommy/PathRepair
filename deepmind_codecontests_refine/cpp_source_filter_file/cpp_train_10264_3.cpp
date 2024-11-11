#include <bits/stdc++.h>
using namespace std;
const int maxn = 80;
const int INF = 99999999;
int dp[maxn][maxn][maxn][2];
char str[maxn];
vector<int> V, K, X;
int vlen, klen, xlen;
int n;
void init() {
  V.clear();
  K.clear();
  X.clear();
  memset(str, 0, sizeof(str));
  memset(dp, -1, sizeof(dp));
}
int mycal(int v, int k, int x, int val) {
  int sum = 0;
  for (int i = v; i < vlen; i++) {
    if (V[i] < val)
      sum++;
    else
      break;
  }
  for (int i = k; i < klen; i++) {
    if (K[i] < val)
      sum++;
    else
      break;
  }
  for (int i = x; i < xlen; i++) {
    if (X[i] < val)
      sum++;
    else
      break;
  }
  return sum;
}
int DP(int vnum, int knum, int xnum, int status) {
  int &ans = dp[vnum][knum][xnum][status];
  if (ans != -1) return ans;
  if (vnum == 0 && knum == 0 && xnum == 0) return ans = 0;
  ans = INF;
  int vtmp = 0, ktmp = 0, xtmp = 0, statustmp = 0;
  if (status == 0) {
    if (knum > 0) {
      ans = min(ans, DP(vnum, knum - 1, xnum, 0) +
                         mycal(vnum, knum - 1, xnum, K[knum - 1]));
    }
    if (xnum > 0) {
      int step = mycal(vnum, knum, xnum - 1, X[xnum - 1]);
      ans = min(ans, DP(vnum, knum, xnum - 1, 0) + step);
      ans = min(ans, DP(vnum, knum, xnum - 1, 1) + step);
    }
  } else {
    if (vnum > 0) {
      int step = mycal(vnum - 1, knum, xnum, V[vnum - 1]);
      ans = min(ans, DP(vnum - 1, knum, xnum, 0) + step);
      ans = min(ans, DP(vnum - 1, knum, xnum, 1) + step);
    }
  }
  return ans;
}
int main() {
  while (~scanf("%d", &n)) {
    init();
    scanf("%s", str);
    for (int i = 0; i < n; i++) {
      if (str[i] == 'V')
        V.push_back(i);
      else if (str[i] == 'K')
        K.push_back(i);
      else
        X.push_back(i);
    }
    vlen = V.size();
    klen = V.size();
    xlen = X.size();
    printf("%d\n", min(DP(vlen, klen, xlen, 0), DP(vlen, klen, xlen, 1)));
  }
  return 0;
}
