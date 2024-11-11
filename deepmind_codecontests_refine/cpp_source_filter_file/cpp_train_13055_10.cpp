#include <bits/stdc++.h>
int cnt[5];
int main() {
  int n;
  int a;
  scanf("%d", &n);
  for (int i = 0; i < n; i++) {
    scanf("%d", &a);
    cnt[a]++;
  }
  int ans = 0;
  if (cnt[1] <= cnt[2]) {
    ans += cnt[1];
    cnt[3] += cnt[1];
    cnt[2] -= cnt[1];
    cnt[1] = 0;
    ans += cnt[2] * 2 / 3;
    cnt[3] += cnt[2] / 3;
    int left = (2 * cnt[2]) % 3;
    if (left == 1) {
      if (cnt[3])
        ans += 1;
      else if (cnt[4] >= 2)
        ans += 2;
      else
        ans = -1;
    } else if (left == 2) {
      if (cnt[4])
        ans++;
      else if (cnt[3] >= 2)
        ans += 2;
      else
        ans = -1;
    }
    printf("%d\n", ans);
  } else {
    ans += cnt[2];
    cnt[3] += cnt[2];
    cnt[1] -= cnt[2];
    cnt[2] = 0;
    ans += 2 * (cnt[1] / 3);
    cnt[3] += cnt[1] / 3;
    cnt[1] -= cnt[1] / 3 * 3;
    if (cnt[1] == 1) {
      if (cnt[3])
        ans++;
      else if (cnt[4] >= 2)
        ans += 2;
      else
        ans = -1;
    } else if (cnt[1] == 2) {
      if (cnt[4])
        ans += 2;
      else if (cnt[3] >= 2)
        ans += 2;
      else
        ans = -1;
    }
    printf("%d\n", ans);
  }
  return 0;
}
