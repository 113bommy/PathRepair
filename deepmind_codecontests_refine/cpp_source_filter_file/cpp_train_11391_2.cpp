#include <bits/stdc++.h>
using namespace std;
int main() {
  char s[100005];
  int x[100005] = {0}, y[100005] = {0}, z[100005] = {0};
  int t, l, r, i = 1;
  int xnum, ynum, znum, maxn, minn;
  s[i] = getchar();
  while (s[i] != '\n') {
    if (s[i] == 'x') {
      x[i] = x[i - 1] + 1;
      y[i] = y[i - 1];
      z[i] = z[i - 1];
    } else if (s[i] == 'y') {
      x[i] = x[i - 1];
      y[i] = y[i - 1] + 1;
      z[i] = z[i - 1];
    } else {
      x[i] = x[i - 1];
      y[i] = y[i - 1];
      z[i] = z[i - 1] + 1;
    }
    i++;
    s[i] = getchar();
  }
  scanf("%d", &t);
  while (t--) {
    scanf("%d %d", &l, &r);
    xnum = x[r] - x[l - 1];
    ynum = y[r] - y[l - 1];
    znum = z[r] - z[l - 1];
    maxn = max(max(xnum, ynum), znum);
    if ((maxn <= xnum + 1 && maxn <= ynum + 1 && maxn <= znum + 1) ||
        (l - r) < 2)
      printf("YES\n");
    else
      printf("NO\n");
  }
  return 0;
}
