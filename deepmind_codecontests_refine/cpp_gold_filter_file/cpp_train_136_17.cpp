#include <bits/stdc++.h>
int vis[1000005];
int a, b, c;
int ff(int a, int b, int c, int wait) {
  int lenth = a * c;
  int lenth2 = (wait + c) * b;
  if (lenth2 >= lenth)
    return 1;
  else
    return 0;
}
int main() {
  while (~scanf("%d%d%d", &a, &b, &c)) {
    memset(vis, 0, sizeof(vis));
    int le = 0, ri = 1000005, mid;
    while (le <= ri) {
      mid = (le + ri) / 2;
      if (ff(a, b, c, mid) == 1)
        ri = mid - 1;
      else
        le = mid + 1;
    }
    printf("%d\n", le);
  }
  return 0;
}
