#include <bits/stdc++.h>
using namespace std;
int T;
int n, k;
int a[200010];
int minDist;
int minPos;
void checkDist(int l, int r, int realPos) {
  int curDistL = realPos - l;
  int curDistR = r - realPos;
  int curDist;
  if (curDistL < curDistR)
    curDist = curDistL;
  else
    curDist = curDistR;
  if ((minDist == -1) || (minDist > curDist)) {
    minDist = curDist;
    minPos = realPos;
  }
}
int main() {
  scanf("%d", &T);
  for (int ii = 0; ii < T; ii++) {
    scanf("%d%d", &n, &k);
    for (int i = 0; i < n; i++) scanf("%d", &(a[i]));
    minDist = -1;
    for (int l = 0; l < n - k; l++) {
      int r = l + k;
      int realNum = (a[l] + a[r]);
      int realPos;
      if (realNum % 2 == 0) {
        realPos = realNum / 2;
        checkDist(a[l], a[r], realPos);
      } else {
        realPos = realNum / 2;
        checkDist(a[l], a[r], realPos);
        checkDist(a[l], a[r], realPos + 1);
      }
    }
    printf("%d\n", minPos);
  }
  return 0;
}
