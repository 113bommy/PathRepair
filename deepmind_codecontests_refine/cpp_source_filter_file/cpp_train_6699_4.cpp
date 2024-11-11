#include <bits/stdc++.h>
using namespace std;
int u[111111], d[111111], all[222222];
int res = 222222;
int n;
void check(int k) {
  int i, m = 0, tres = 0;
  for (i = 0; i < n; i++)
    if (u[i] == k) m++;
  for (i = 0; i < n; i++) {
    if (m * 2 >= n) {
      if (res > tres) res = tres;
      return;
    }
    if (d[i] == k && u[i] != k) m++, tres++;
  }
  if (m * 2 >= n)
    if (res > tres) res = tres;
  return;
}
int main(void) {
  while (scanf(" %d", &n) != EOF) {
    int i, l, t;
    res = 222222;
    for (i = 0; i < n; i++)
      scanf("%d %d", &u[i], &d[i]), all[i * 2] = u[i], all[i * 2 + 1] = d[i];
    sort(all, all + 2 * n);
    t = all[0];
    l = 1;
    for (i = 1; i < 2 * n; i++) {
      if (all[i] == t)
        l++;
      else {
        l = 1;
        t = all[i];
      }
      if (l * 2 >= n) {
        check(t);
        while (i < 2 * n && all[i] == t) i++;
      }
    }
    if (res == 222222) res = -1;
    printf("%d\n", res);
  }
  return 0;
}
