#include <bits/stdc++.h>
using namespace std;
int main() {
  int n, m;
  int t1, t2, cnt = 0, mal1, mal2, mir1, mir2;
  scanf("%d", &n);
  int l1[n], r1[n];
  for (int i = 0; i < n; i++) {
    scanf("%d%d", &t1, &t2);
    l1[i] = t1;
    r1[i] = t2;
    if (i == 0) {
      mal1 = l1[i];
      mir1 = r1[i];
    } else {
      mal1 = max(mal1, l1[i]);
      mir1 = min(mir1, r1[i]);
    }
  }
  scanf("%d", &m);
  int l2[m], r2[m];
  for (int i = 0; i < m; i++) {
    scanf("%d%d", &t1, &t2);
    l2[i] = t1;
    r2[i] = t2;
    if (i == 0) {
      mal2 = l2[i];
      mir2 = r2[i];
    } else {
      mal2 = max(mal2, l2[i]);
      mir2 = min(mir2, r2[i]);
    }
  }
  t1 = mal1 - mir2;
  t2 = mal2 - mir1;
  cnt = max(t1, t2);
  if (cnt < 0)
    printf("0");
  else
    printf("%d", cnt);
  return 0;
}
