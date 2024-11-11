#include <bits/stdc++.h>
typedef int arr[100010 + 10];
int tot, n;
arr l, t;
long long drk[100010], r;
int main() {
  scanf("%d%I64d", &n, &r);
  for (int i = 1; i <= n; i++) scanf("%d", l + i);
  for (int i = 1; i <= n; i++) scanf("%d", t + i);
  long long res = 0, T = 0, ans = 0;
  int ok = 1;
  for (int i = 1; i <= n && ok; i++) {
    if (t[i] >= l[i]) {
      if (res >= l[i]) {
        T += l[i];
        res -= l[i];
      } else {
        int req = 2 * l[i] - t[i];
        if (res >= req) {
          T += res + 2 * (l[i] - res);
          res = 0;
        } else {
          int ned = req - res;
          int now = (ned + r - 1) / r;
          ans += now;
          res = r * now - ned;
          T += t[i];
          long long temp = T - ned;
          for (; temp < T && tot <= 100010; temp += r) {
            drk[++tot] = temp;
          }
        }
      }
    } else
      ok = 0;
  }
  if (ok) {
    printf("%I64d\n", ans);
    if (tot <= 100000) {
      for (int i = 1; i <= tot; i++) printf("%d%c", drk[i], " \n"[i == tot]);
    }
  } else {
    printf("-1\n");
  }
}
