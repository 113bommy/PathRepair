#include <bits/stdc++.h>
using namespace std;
int n, m, l, r, a[100005], lnc[100005], rec[100005];
int main() {
  scanf("%d%d", &n, &m);
  for (int i = 1; i <= n; i++) {
    scanf("%d", a + i);
    if (a[i - 1] >= a[i])
      lnc[i] = 1 + lnc[i - 1];
    else
      lnc[i] = 1;
  }
  for (int i = n - 1; i >= 1; i--) {
    if (a[i] <= a[i + 1])
      rec[i] = rec[i + 1] + 1;
    else
      rec[i] = 1;
  }
  for (int i = 0; i < m; i++) {
    scanf("%d%d", &l, &r);
    if (lnc[r] + rec[l] > r - l + 1)
      printf("Yes\n");
    else
      printf("No\n");
  }
  return 0;
}
