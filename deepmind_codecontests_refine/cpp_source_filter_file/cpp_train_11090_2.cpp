#include <bits/stdc++.h>
using namespace std;
char s[100010];
int a[100010], ans[100010];
int main() {
  memset(a, 0, sizeof(a));
  memset(ans, 0, sizeof(ans));
  scanf("%s", &s);
  int n = strlen(s);
  for (int i = 1; i <= n; i++) a[i] = s[i - 1] - '0';
  int l = 1, r = n, flag = 1;
  if (a[l] != a[r]) {
    a[l]--;
    a[l + 1] += 10;
    if (a[l] == 0) l++;
  }
  while (l <= r) {
    if (a[l] != a[r]) {
      if (a[l] - a[r] >= 10) {
        a[r] += 10;
        a[r - 1]--;
      }
      if (a[l] - a[r] == 1) {
        a[l]--;
        a[l + 1] += 10;
      }
    }
    if (a[l] != a[r]) {
      flag = 0;
      break;
    }
    if (l != r) {
      ans[l] = a[l] - a[r] / 2;
      ans[r] = a[r] / 2;
    } else {
      if (a[l] % 2 == 1) {
        flag = 0;
        break;
      }
      ans[l] = a[r] / 2;
    }
    if (ans[l] < 0 || ans[l] > 9 || ans[r] < 0 || ans[l] > 9) {
      flag = 0;
      break;
    }
    l++;
    r--;
  }
  if (flag == 0 || l <= r) {
    printf("0\n");
    return 0;
  }
  int cnt = 1;
  while (ans[cnt] == 0) cnt++;
  for (int i = cnt; i <= n; i++) printf("%d", ans[i]);
  printf("\n");
  return 0;
}
