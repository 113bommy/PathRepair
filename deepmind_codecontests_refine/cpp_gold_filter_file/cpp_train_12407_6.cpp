#include <bits/stdc++.h>
int n;
int s[105];
int a[105], b[105], cnt, ans;
int main() {
  scanf("%d", &n);
  for (int i = 1; i <= n; i++) scanf("%1d", s + i), cnt += s[i];
  ans = cnt;
  for (int i = 1; i <= n; i++) scanf("%d%d", a + i, b + i);
  for (int t = 1; t <= 10000; t++) {
    for (int i = 1; i <= n; i++) {
      if (t >= b[i]) {
        if ((t - b[i]) % a[i] == 0) {
          s[i] = !s[i];
          if (s[i])
            cnt++;
          else
            cnt--;
        }
      }
    }
    ans = std::max(cnt, ans);
  }
  printf("%d\n", ans);
  return 0;
}
