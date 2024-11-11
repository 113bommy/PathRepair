#include <bits/stdc++.h>
const int MAXN = 1000010;
int c[MAXN];
int main() {
  memset(c, 0, sizeof(c));
  int n;
  scanf("%d", &n);
  for (int i = 0; i < n; i++) {
    int x;
    scanf("%d", &x);
    c[x]++;
  }
  int ans = 0;
  bool flag = true;
  if (c[1] >= c[2]) {
    c[3] += c[2];
    c[1] -= c[2];
    ans += c[2];
    int tmp = c[1] / 3;
    c[3] += tmp;
    c[1] -= tmp * 3;
    ans += tmp * 2;
    if (c[1] == 1) {
      if (c[3] >= 1)
        ans++;
      else if (c[4] >= 2)
        ans += 2;
      else
        flag = false;
    } else if (c[1] == 2) {
      if (c[4] >= 1)
        ans += 2;
      else if (c[3] >= 2)
        ans += 2;
      else
        flag = false;
    }
  } else {
    c[3] += c[1];
    c[2] -= c[1];
    ans += c[1];
    int tmp = c[2] / 3;
    c[2] -= tmp * 3;
    c[3] += tmp * 2;
    ans += tmp * 2;
    if (c[2] == 1) {
      if (c[4] >= 1)
        ans++;
      else if (c[3] >= 2)
        ans += 2;
      else
        flag = false;
    } else if (c[2] == 2) {
      if (c[3] >= 1)
        ans += 2;
      else if (c[4] >= 2)
        ans += 2;
      else
        flag = false;
    }
  }
  if (!flag)
    printf("-1\n");
  else
    printf("%d\n", ans);
  return 0;
}
