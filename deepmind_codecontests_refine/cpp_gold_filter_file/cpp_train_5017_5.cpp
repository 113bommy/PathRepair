#include <bits/stdc++.h>
using namespace std;
int inord[100010], outord[100010], incar[100010];
pair<int, int> rec[100010];
bool add = false;
int main() {
  int n;
  scanf("%d", &n);
  for (int i = 1; i <= n; i++) {
    int t;
    scanf("%d", &t);
    inord[t] = i;
    incar[i] = t;
  }
  for (int i = 1; i <= n; i++) {
    int t;
    scanf("%d", &t);
    outord[t] = i;
  }
  int ans = 0;
  int pre_stac_end = -1;
  for (int i = 1; i <= n; i++) {
    int ti = incar[i];
    if (inord[ti] > outord[ti]) {
      ans++;
    } else if (inord[ti] < outord[ti]) {
      if (outord[ti] < pre_stac_end) ans++;
      pre_stac_end = max(pre_stac_end, outord[ti]);
    } else {
      if (inord[ti] < pre_stac_end) ans++;
    }
  }
  printf("%d\n", ans);
  return 0;
}
