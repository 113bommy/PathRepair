#include <bits/stdc++.h>
using namespace std;
inline int ni() {
  int a;
  scanf("%d", &a);
  return a;
}
const int maxn = 5011;
const int inf = 1000000000;
int hs[maxn], d[maxn][maxn];
int main() {
  int n = ni();
  for (int i = 0; i < int(n); i++) hs[i] = ni();
  for (int i = 0; i < int(maxn); i++)
    for (int j = 0; j < int(maxn); j++) d[i][j] = inf;
  d[1][1] = 0;
  for (int taken = 1; taken <= n; taken++) {
    int lastSize = 0, curSize = 0, curPtr = taken;
    for (int lastSeg = 1; lastSeg <= taken; lastSeg++) {
      lastSize += hs[taken - lastSeg];
      while (curPtr < n && curSize < lastSize) {
        curSize += hs[curPtr];
        ++curPtr;
      }
      int minNeedTaken = -1;
      if (curSize >= lastSize) {
        minNeedTaken = curPtr - taken;
      }
      if (minNeedTaken != -1) {
        d[taken + minNeedTaken][minNeedTaken] =
            min(d[taken + minNeedTaken][minNeedTaken],
                d[taken][lastSeg] + (minNeedTaken - 1));
      }
      d[taken + 1][lastSeg + 1] =
          min(d[taken + 1][lastSeg + 1], d[taken][lastSeg] + 1);
    }
  }
  int res = inf;
  for (int i = 0; i < int(maxn); i++) res = min(res, d[n][i]);
  cout << res << endl;
  return 0;
}
