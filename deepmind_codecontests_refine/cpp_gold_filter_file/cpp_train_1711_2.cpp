#include <bits/stdc++.h>
using namespace std;
bool mark[1000011];
int resnum = -1;
int res[1000011];
int sm = 1000001;
int n, k[1000011];
int main() {
  scanf("%d", &n);
  for (int i = 0; i < n; i++) {
    scanf("%d", &k[i]);
    mark[k[i]] = 1;
  }
  int bs = 0;
  for (int i = 0; i < n; i++) {
    if (!mark[sm - k[i]]) {
      resnum++;
      res[resnum] = sm - k[i];
      mark[sm - k[i]] = 1;
    } else {
      bs++;
    }
  }
  for (int i = 1; i < sm; i++) {
    if (bs == 0) break;
    if (!mark[i]) {
      resnum++;
      res[resnum] = i;
      resnum++;
      res[resnum] = sm - i;
      bs -= 2;
      mark[i] = 1;
      mark[sm - i] = 1;
    }
  }
  resnum++;
  printf("%d\n", resnum);
  for (int i = 0; i < resnum; i++) printf("%d ", res[i]);
  return 0;
}
