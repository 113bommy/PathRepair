#include <bits/stdc++.h>
int a[101000];
int n;
int cnt[101000];
int ans[101000];
int main() {
  scanf("%d", &n);
  for (int i = 0; i < n; i++) scanf("%d", &a[i]);
  for (int i = 0; i < a[n - 1]; i++) cnt[i] = 1;
  int last = a[n - 1] - 1;
  int cst = a[n - 1] + 1;
  for (int i = n - 1; i >= 0; i--) {
    bool flag = false;
    if (i == 0) {
      flag = (a[i] == 1) ? true : false;
      ans[i] = 0;
    } else {
      flag = (a[i] != a[i - 1]) ? true : false;
      ans[i] = a[i - 1];
    }
    if (!flag) {
      if (last > a[i]) {
        ans[i] = last;
        cnt[last] = 0;
      } else
        ans[i] = cst;
    }
    cnt[ans[i]] = 0;
    while (last >= 0 && !cnt[last]) last--;
  }
  for (int i = 0; i < a[n - 1]; i++)
    if (cnt[i] > 0) {
      printf("%d\n", -1);
      return 0;
    }
  for (int i = 0; i < n; i++) printf("%d ", ans[i]);
  return 0;
}
