#include <bits/stdc++.h>
using namespace std;
int main(void) {
  int n, k, hnum;
  scanf("%d %d", &n, &k);
  scanf("%d", &hnum);
  vector<int> holidays(hnum + 1);
  for (int j = 1; j <= hnum; j++) scanf("%d", &holidays[j]);
  int pnum = 0;
  int lastreceived = 1;
  int hcount = 1;
  for (int j = 1; j <= n; j++, lastreceived++) {
    if (hnum > 0)
      if (j == holidays[hcount]) {
        hcount++;
        lastreceived = 0;
        pnum++;
        continue;
      }
    if (lastreceived == k) {
      lastreceived = 0;
      pnum++;
    }
  }
  printf("%d\n", pnum);
  return 0;
}
