#include <bits/stdc++.h>
using namespace std;
int n;
int a[5];
const int inf = 0x7fffffff;
int go1() {
  int ret = inf;
  for (int i = 0; i <= a[1]; ++i) {
    int j = a[1] - i;
    if (i > 2 * j && i - 2 * j <= a[3]) {
      ret = min(ret, i);
    } else if (i <= 2 * j && 2 * j - i <= a[4]) {
      ret = min(ret, 2 * j);
    }
  }
  return ret == inf ? -1 : ret;
}
int go2() {
  int ret = inf;
  for (int i = 0; i <= a[2]; ++i) {
    int j = a[2] - i;
    if (2 * i > j && 2 * i - j <= a[3]) {
      ret = min(ret, 2 * i);
    } else if (2 * i <= j && j - 2 * i <= a[4]) {
      ret = min(ret, j);
    }
  }
  return ret == inf ? -1 : ret;
}
int main() {
  scanf("%d", &n);
  for (int i = 0; i < n; ++i) {
    int t;
    scanf("%d", &t);
    a[t]++;
  }
  int sol = 0;
  int tmp = min(a[1], a[2]);
  a[1] -= tmp;
  a[2] -= tmp;
  a[3] += tmp;
  sol += tmp;
  int r = 0;
  if (a[1]) {
    r = go1();
  } else if (a[2]) {
    r = go2();
  }
  if (r == -1) {
    printf("-1\n");
  } else {
    printf("%d\n", sol + r);
  }
  return 0;
}
