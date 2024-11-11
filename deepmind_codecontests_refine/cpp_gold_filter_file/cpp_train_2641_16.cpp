#include <bits/stdc++.h>
using namespace std;
const int N = 5 * int(1e5) + 50;
const long long inf = ~0ULL >> 4;
template <class T>
T abs(T x) {
  return x > 0 ? x : -x;
}
char cmap[N];
int n, hCnt, sCnt, tMax, lastH, spos[N];
long long calcTime(int ccnt) {
  if (ccnt + sCnt < hCnt) return inf;
  if (ccnt >= hCnt) return lastH;
  int cpos = 0, cEnd = max(lastH, spos[hCnt - ccnt]);
  long long res = inf, ctime = 0, dCnt = 0;
  for (cpos = 1; cpos <= cEnd && dCnt < hCnt; ++cpos) {
    ++ctime;
    if (cmap[cpos] == 'S')
      ++ccnt;
    else if (cmap[cpos] == 'H') {
      ++dCnt;
      if (ccnt > 0) {
        --ccnt;
        continue;
      }
      res = min(res, ctime + 2 * (cEnd - cpos));
      int tleft = 1, npos = cpos + 1;
      for (; tleft; ++npos) {
        if (cmap[npos] == 'S')
          --tleft;
        else if (cmap[npos] == 'H')
          ++tleft, ++dCnt;
      }
      ctime += (npos - cpos - 1) * 3;
      cpos = npos - 1;
    }
  }
  res = min(res, ctime);
  return res;
}
int main() {
  scanf("%d%d", &n, &tMax);
  scanf("%s", cmap + 1);
  while (n && cmap[n] == '.') --n;
  if (!n) {
    printf("0\n");
    return 0;
  }
  for (int i = 1; i <= n; ++i)
    if (cmap[i] == 'H')
      ++hCnt, lastH = i;
    else if (cmap[i] == 'S')
      spos[++sCnt] = i;
  int l = -1, r = n + 1;
  while (l + 1 < r) {
    int m = (l + r) / 2;
    if (calcTime(m) <= tMax)
      r = m;
    else
      l = m;
  }
  if (calcTime(r) > tMax)
    puts("-1");
  else
    printf("%d\n", r);
  return 0;
}
