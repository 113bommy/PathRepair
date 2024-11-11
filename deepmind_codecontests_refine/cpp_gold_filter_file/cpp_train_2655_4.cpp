#include <bits/stdc++.h>
using namespace std;
int main() {
  int n;
  scanf("%d", &n);
  int dir = 1, start, flag = 0;
  int a;
  int A[1005];
  for (int i = 0; i < n; i++) {
    scanf("%d", &a);
    if (!a && !flag) {
      start = i;
      flag = 1;
    }
    A[i] = a;
  }
  int marked = 0;
  int curval = 0;
  int ans = 0;
  bool f = true;
  int vis[1005] = {0};
  while (marked < n) {
    if (dir == 1) {
      if (!f) ans++;
      int i;
      if (f)
        i = start;
      else
        i = 0;
      while (i < n) {
        if (!vis[i] && curval >= A[i]) {
          vis[i] = 1;
          marked++;
          curval++;
        }
        i++;
      }
      if (marked == n) break;
      dir = 0;
      f = false;
    } else {
      ans++;
      int i = n - 1;
      while (i >= 0) {
        if (!vis[i] && curval >= A[i]) {
          vis[i] = 1;
          marked++;
          curval++;
        }
        i--;
      }
      if (marked == n) break;
      dir = 1;
    }
  }
  printf("%d\n", ans);
  return 0;
}
