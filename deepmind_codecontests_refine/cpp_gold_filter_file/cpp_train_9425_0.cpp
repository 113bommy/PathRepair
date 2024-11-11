#include <bits/stdc++.h>
using namespace std;
const int N = 100010;
int n, k, a[N], cnt = 0, c[N];
int main() {
  scanf("%d%d", &n, &k);
  for (int i = 0; i <= n; i++) {
    char s[10];
    scanf("%s", s);
    if (s[0] == '?')
      a[i] = 1;
    else {
      a[i] = 0;
      sscanf(s, "%d", &c[i]);
      cnt++;
    }
  }
  int flag;
  if (cnt == n + 1) {
    if (k == 0) {
      if (c[0] == 0)
        flag = 1;
      else
        flag = 0;
    } else {
      int now = -c[0];
      flag = 1;
      for (int i = 1; i <= n; i++) {
        if (now % k != 0) {
          flag = 0;
          break;
        }
        now /= k;
        now -= c[i];
      }
      if (flag && now != 0) flag = 0;
    }
  } else {
    if (k == 0) {
      if (a[0] == 0) {
        if (c[0] == 0)
          flag = 1;
        else
          flag = 0;
      } else {
        if (cnt % 2 == 1)
          flag = 1;
        else
          flag = 0;
      }
    } else {
      if (n % 2 == 1)
        flag = 1;
      else
        flag = 0;
    }
  }
  if (flag)
    printf("Yes\n");
  else
    printf("No\n");
}
