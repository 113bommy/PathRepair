#include <bits/stdc++.h>
using namespace std;
int f[100005], b[100005];
int main() {
  int i, j, t;
  int n, m;
  int hash1[100005] = {0};
  int mapp[100005];
  scanf("%d%d", &n, &m);
  int flag1 = 1;
  for (i = 1; i <= n; i++) {
    scanf("%d", &f[i]);
    hash1[f[i]]++;
    mapp[f[i]] = i;
  }
  for (i = 1; i <= m; i++) {
    scanf("%d", &b[i]);
  }
  int flag3 = 1;
  for (i = 1; i <= m; i++) {
    if (!hash1[b[i]]) {
      flag3 = 0;
      break;
    } else if (hash1[b[i]] > 1) {
      flag1 = 0;
    }
  }
  if (!flag3) {
    printf("Impossible\n");
  } else if (!flag1) {
    printf("Ambiguity\n");
  } else {
    printf("Possible\n");
    for (i = 1; i <= m; i++) {
      printf("%d ", mapp[b[i]]);
    }
    printf("\n");
  }
  return 0;
}
