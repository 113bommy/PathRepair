#include <bits/stdc++.h>
using namespace std;
int a[35000];
int al;
int flag[15];
void dfs(int nn) {
  if (nn >= 10) {
    int num = 0;
    for (int i = 0; i < nn; i++) {
      num *= 10;
      num += flag[i];
    }
    a[al++] = num;
    return;
  }
  flag[nn] = 1;
  dfs(nn + 1);
  flag[nn] = 0;
  dfs(nn + 1);
}
int main() {
  al = 0;
  dfs(0);
  sort(a, a + al);
  int n;
  while (scanf("%d", &n) != EOF) {
    int ans = lower_bound(a, a + al, n) - a;
    printf("%d\n", ans);
  }
  return 0;
}
