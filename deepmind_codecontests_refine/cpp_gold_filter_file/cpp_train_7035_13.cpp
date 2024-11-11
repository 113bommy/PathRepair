#include <bits/stdc++.h>
using namespace std;
char tStr[200005];
int order[200005];
char pStr[200005];
int tlen, plen;
vector<int> rVec;
int main() {
  int t;
  scanf("%s", tStr + 1);
  scanf("%s", pStr + 1);
  tlen = strlen(tStr + 1);
  plen = strlen(pStr + 1);
  for (int i = 1; i <= tlen; i++) {
    scanf("%d", &t);
    order[t] = i;
  }
  int l = 0, r = tlen;
  while (l < r) {
    int mid = (l + r + 1) / 2;
    bool flag = false;
    int m = 0;
    for (int i = 1; i <= tlen; i++) {
      if (order[i] > mid && tStr[i] == pStr[m + 1]) {
        m++;
        if (m == plen) break;
      }
    }
    if (m == plen) flag = true;
    if (flag)
      l = mid;
    else
      r = mid - 1;
  }
  printf("%d\n", l);
  return 0;
}
